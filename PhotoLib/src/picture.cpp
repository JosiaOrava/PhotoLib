#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/db.h"


Picture::Picture() {
	Filename = "";
	Desc = "";
	Location = "";
	PeopleCount = 0;
	tags.clear();
}

void Picture::askNewEdits() {
	bool state = true;
	int choice;
	while (state) {
		std::cout << "What do you want to edit? (1: Description, 2: Location, 3: People count, 4: stop): ";
		std::cin >> choice;
		if (choice < 1 || choice > 4) {
			std::cout << "Give valid number." << std::endl;
			continue;
		}
		switch (choice)
		{
		case 1:
			std::cout << "Give new description:";
			std::getline(std::cin >> std::ws, Desc);
			break;
		case 2:
			std::cout << "Give new location:";
			std::getline(std::cin >> std::ws, Location);
			break;
		case 3:
			std::cout << "Give new people count:" << std::endl;
			std::cin >> PeopleCount;
			break;
		case 4:
			state = false;
		}
	}
}

void Picture::editPic()
{
	std::cout << "Give filename to edit: ";
	std::cin >> Filename;
	std::string line, path;
	path = DataBase::getDbPath();
	int lineCount = 1;
	int lineNumber = findLineNumber(Filename);
	std::ifstream input(path);
	std::ofstream output(path, std::ios::out || std::ios::trunc);
	if (lineNumber == -1) {
		std::cout << "No such file found." << std::endl;
	}
	else {
		getPreviousInfo(lineNumber);
		askNewEdits();
		while (getline(input, line)) {
			if (lineCount != lineNumber) {
				output << line << std::endl;
			}
			else {
				output << "\n" <<  Filename << "," << Desc << "," << Location << "," << PeopleCount << ",";
			}
			lineCount++;
		}
	}
	input.close();
	output.close();
}

void Picture::addPic()
{
	std::string tag, path;
	std::cout << "Filename (with extension (.jpg, .png) etc.): ";
	std::getline(std::cin >> std::ws, Filename);
	std::cout << "Description for photo:";
	std::getline(std::cin >> std::ws, Desc);
	std::cout << "Location: ";
	std::getline(std::cin >> std::ws, Location);
	std::cout << "People count: ";
	std::cin >> PeopleCount;

	std::ofstream myFile;
	path = DataBase::getDbPath();
	myFile.open(path, std::ios::app);
	myFile << "\n" << Filename << ", " << Desc << ", " << Location << ", " << PeopleCount << ", ";
	myFile.close();

}

void Picture::removePic()
{
	std::cout << "Give filename to remove: ";
	std::cin >> Filename;
	std::string line, path;
	path = DataBase::getDbPath();
	int lineCount = 1;
	int lineNumber = findLineNumber(Filename);
	std::ifstream input(path);
	std::ofstream output(path, std::ios::out || std::ios::trunc);
	if (lineNumber == -1) {
		std::cout << "No such file found." << std::endl;
	}
	else {
		while (getline(input, line)) {
			if (lineCount != lineNumber) {
				output << line << std::endl;
			}
			lineCount++;
		}
	}
	input.close();
	output.close();
}

int Picture::findLineNumber(std::string Filename) {
	std::string line, path;
	path = DataBase::getDbPath();
	std::ifstream myFile(path);
	int lineNumber = 1;
	while (getline(myFile, line)) {
		if (line.find(Filename) != std::string::npos) {
			return lineNumber;
		}
		lineNumber++;
	}
	return -1;
	myFile.close();
}

void Picture::getPreviousInfo(int lineNumber) {
	
	std::string line, path;
	path = DataBase::getDbPath();
	int lineCount = 1;
	std::ifstream input(path);
	while (getline(input, line)) {
		std::stringstream ss(line);
		if (lineCount == lineNumber) {
			
			std::getline(ss, Filename, ',');
			std::getline(ss, Desc, ',');
			std::getline(ss, Location, ',');
			ss >> PeopleCount;
		}
		lineCount++;
	}
	input.close();
}