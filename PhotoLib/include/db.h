#pragma once
#include <string>
#include <vector>


class DataBase {
public:
	DataBase();
	void ini(); // DONE
	void getDataByPeopleCount(); // NEED TO DO
	void getDataWithoutPeople(); // NEED TO DO
	void readDB(); // DONE EXEPCT FORMATTING
	std::string getDbPath(); // DONE
private:
	std::string dbName;
};

class Picture : public DataBase {
public:
	Picture();
	void editPic(); // NEED TO DO
	void addPic(); // DONE
	void removePic(); // DONE BUT HAS BUG
	int findLineNumber(std::string Filename); // DONE
	void askNewEdits(); // GET PREVIOUS INFO
	void getPreviousInfo(int lineNumber);
private:
	std::string Filename, Desc, Location;
	int PeopleCount;
	std::vector<std::string> tags;
};