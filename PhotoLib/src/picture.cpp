#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/db.h"


Picture::Picture() {
	Filename = "";
	Desc = "";
	Location = "";
	PeopleCount = 0;
	tags.clear();
}

void Picture::editPic()
{
	std::cout << "Give filename to edit: ";
	std::cin >> Filename;
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
	std::cout << "Tags for photo (enter stop to stop adding tags): \n";
	while (true) {
		std::cout << "Tag: ";
		std::cin >> tag;
		if (tag == "stop" || tag == "STOP") {
			break;
		}
		tags.push_back(tag);
	}

	std::ofstream myFile;
	path = DataBase::getDbPath();
	myFile.open(path, std::ios::app);
	myFile << Filename << "," << Desc << "," << Location << "," << PeopleCount << "," << std::endl;
	myFile.close();

}

void Picture::removePic()
{
	std::cout << "Give filename to remove: ";
	std::cin >> Filename;
	std::ifstream myFile;
	std::string line, path;
	std::size_t found;
	path = DataBase::getDbPath();
	myFile.open(path);
	while (getline(myFile, line)) {
		found = line.find(Filename);
		if (found != std::string::npos) {

		}
	}
}