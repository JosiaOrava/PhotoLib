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


class Picture : public DataBase {
	friend std::ostream& operator<<(std::ostream& out, const std::string s);
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
	std::vector<std::string> info;
};