#pragma once
#include <string>
#include <vector>

class DataBase {
public:
	DataBase();
	void ini();
	void getDataByPeopleCount();
	void getDataWithoutPeople();
	void readDB();
	std::string getDbPath();
private:
	std::string dbName;
};

// input operators and remove inheritance and make db handle all file writing
// fix the infinite loop in edit pic
//
class Picture : public DataBase {
public:
	Picture();
	void editPic();
	void addPic();
	void removePic();
	int findLineNumber(std::string Filename);
	void askNewEdits();
	void getPreviousInfo(int lineNumber);
private:
	std::string Filename, Desc, Location;
	int PeopleCount;
};