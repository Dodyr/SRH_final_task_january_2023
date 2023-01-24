#include <iostream>
#include <string>
#include <list>

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


int main() {

}