#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>


struct travel_data {
	std::string location;

	int start[3];
	int end[3];

	std::list<person> people;
};

struct person {
	std::string name;

	std::list<std::string> items;

	int underwear;
	int pants;
	int socks;
};

person read_file(std::ifstream & fin, travel_data & data)
{
	person result;
	while (!fin.eof()) {

	}
	return result;
}

int main() {
	std::ifstream fin("text.txt");
	int j = 0;
	if (fin.is_open()) {
		travel_data data;
		fin.close();
	}
	return 0;
}