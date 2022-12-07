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
	void searchTags(std::vector<std::string> tags);
	std::string getDbPath();
private:
	std::string dbName;
};

class Picture : public DataBase {
public:
	Picture();
	void editPic();
	void addPic();
	void removePic();
private:
	std::string Filename, Desc, Location;
	int PeopleCount;
	std::vector<std::string> tags;
};