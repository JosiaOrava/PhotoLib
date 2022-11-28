#pragma once
#include <string>
#include <vector>


class DataBase {
public:
	DataBase();
	void ini();
	void getData();
	void readDB();
	void searchTags(std::vector<std::string> tags);
	void getDbPath();
private:
	std::string dbName;
};

class Picture : public DataBase {
public:
	Picture();
	void editPic(std::string Filename, std::string Desc, std::string Location,
		std::string PeopleCount, std::vector<std::string> tags);
	void addPic(std::string Filename, std::string Desc, std::string Location,
		std::string PeopleCount, std::vector<std::string> tags);
	void removePic(std::string Filename);
private:
	std::string Filename, Desc, Location;
	int PeopleCount;
	std::vector<std::string> tags;
};