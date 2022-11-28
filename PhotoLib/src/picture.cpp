#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "../include/db.h"


Picture::Picture() {
	Filename = "";
	Desc = "";
	Location = "";
	PeopleCount = 0;
	tags.clear();
}