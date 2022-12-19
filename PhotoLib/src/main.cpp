#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../include/db.h"



int main() {
	DataBase db;
	Picture pic;
	int choice = 0;
	bool state = true;
	while (state) {
		std::cout << "Add picture (1) | Delete picture (2) | Edit picture (3) | Print all files (4) | Picture by people count (5) | Pictures without people (6) | Initialize database (7) | Stop program (8)" << std::endl;
		std::cin >> choice;
		if (choice < 1 || choice > 8) {
			std::cout << "Give correct number" << std::endl;
			continue;
		}
		else {
			switch (choice) {
			case 1:
				pic.addPic();
				break;
			case 2:
				pic.removePic();
				db.clearEmptyLines();
				break;
			case 3:
				pic.editPic();
				db.clearEmptyLines();
				break;
			case 4:
				db.readDB();
				break;
			case 5:
				db.getDataByPeopleCount();
				break;
			case 6:
				db.getDataWithoutPeople();
				break;
			case 7:
				db.ini();
				break;
			case 8:
				state = false;
			}
		}
	}
	return 0;
}