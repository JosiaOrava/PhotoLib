#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "../include/db.h"



DataBase::DataBase() {
	dbName = "data/db.csv";
}

void DataBase::ini() {
	std::ofstream myFile;
	myFile.open(dbName);
	if (!myFile.is_open()) {
		std::cout << "Error initing file" << std::endl;
		return;
	}
	myFile << "Filename,Description,Location,PeopleNumber,";
	myFile.close();
	
}

void DataBase::getDataByPeopleCount()
{
	std::ifstream myFile, myFile2;
	std::string line, completeLine, sections;
	std::stringstream ss;
	int countOfPeople = 0, commaCount = 1, tmp;
	myFile.open(dbName);
	myFile2.open(dbName);
	if (!myFile.is_open() ||!myFile2.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	std::cout << "Least ammount of people?: ";
	std::cin >> countOfPeople;
	getline(myFile, line);
	getline(myFile2, completeLine);
	ss.str(line);
	while (getline(ss, sections, ',')) {
		std::cout << sections << std::setw(30);
	}
	std::cout << std::endl;
	ss.clear();
	while (getline(myFile, line, ',')) {
		if (commaCount == 4) {
			getline(myFile2, completeLine);
			tmp = stoi(line);
			if (tmp >= countOfPeople) {
				ss.str(completeLine);
				while (getline(ss,sections, ',')) {
					std::cout <<std::left<< std::setw(30) << sections;
				}
				ss.clear();
			}
			commaCount = 0;
		}
		commaCount++;
	}
	std::cout << std::endl;
	myFile.close();
}

void DataBase::getDataWithoutPeople()
{
	std::ifstream myFile, myFile2;
	std::string line, completeLine, sections;
	std::stringstream ss;
	int countOfPeople = 0, commaCount = 1;
	myFile.open(dbName);
	myFile2.open(dbName);
	if (!myFile.is_open() || !myFile2.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	getline(myFile, line);
	getline(myFile2, completeLine);
	ss.str(line);
	while (getline(ss, sections, ',')) {
		std::cout << std::left << std::setw(30) << sections;
	}
	std::cout << std::endl;
	ss.clear();
	while (getline(myFile, line, ',')) {
		if (commaCount == 4) {
			getline(myFile2, completeLine);
			countOfPeople = stoi(line);
			ss.str(completeLine);
			if (countOfPeople == 0) {
				std::cout << "* ";
				while (getline(ss, sections, ',')) {
					std::cout << std::left << std::setw(30) << sections;
				}
				ss.clear();
			}
			else {
				while (getline(ss, sections, ',')) {
					std::cout << std::left << std::setw(30) << sections;
				}
				ss.clear();
			}
			commaCount = 0;
		}
		commaCount++;
	}
	std::cout << std::endl;
	myFile.close();
}

void DataBase::readDB()
{
	std::ifstream myFile;
	std::string line;
	myFile.open(dbName);
	if (!myFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	
	while (getline(myFile, line, ',')) {
		std::cout << line << std::setw(30);
	}
	std::cout << std::endl;
	myFile.close();
	
}

std::string DataBase::getDbPath()
{
	return dbName;
}