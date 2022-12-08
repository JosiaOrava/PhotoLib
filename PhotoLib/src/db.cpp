#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/db.h"


DataBase::DataBase() {
	dbName = "data/db.csv";
}

void DataBase::ini() {
	std::ofstream myFile;
	myFile.open(dbName);
	if (!myFile.is_open()) {
		std::cout << "Error initing file" << std::endl;
	}
	myFile << "Filename,Description,Location,PeopleNumber,tags";
	myFile.close();
	
}

void DataBase::getDataByPeopleCount()
{
}

void DataBase::getDataWithoutPeople()
{
}

void DataBase::readDB()
{
	std::ifstream myFile;
	std::string line;
	myFile.open(dbName);
	if (!myFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
	}
	// Printing out the whole file
	// TODO: make the formatting prettier
	while (getline(myFile, line, ',')) {
		std::cout << std::setw(25) << line;
	}
	myFile.close();
	
}

// TODO: if time, implement tags
void DataBase::searchTags(std::vector<std::string> tags)
{
}

std::string DataBase::getDbPath()
{
	return dbName;
}