#include <iostream>
#include <iomanip>
#include <fstream>
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
		std::cout << line << std::setw(30);
	}
	std::cout << std::endl;
	myFile.close();
	
}

std::string DataBase::getDbPath()
{
	return dbName;
}