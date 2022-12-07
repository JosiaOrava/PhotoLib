#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/db.h"



int main() {
	DataBase db;
	Picture pic;
	int choice = 0;
	while (true) {
		std::cout << "Add picture (1) | Delete picture (2) | Edit picture (3) | Print all files (4) | Picture by people count (5) | Pictures without people (6) | Initialize database (7)" << std::endl;
		std::cin >> choice;
		if (choice < 1 || choice > 7) {
			std::cout << "Give correct number" << std::endl;
		}
		else {
			switch (choice) {
			case 1:
				pic.addPic();
			case 2:
				pic.removePic();
			case 3:
				pic.editPic();
			case 4:
				db.readDB();
			case 5:
				db.getDataByPeopleCount();
			case 6:
				db.getDataWithoutPeople();
			case 7:
				db.ini();
			}
		}
	}
	return 0;
}