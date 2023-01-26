#include "Header1.h"

void read_file(std::ifstream& fin, travel_data& data)
{
	while (!fin.eof()) {
		std::string name;
		std::list<item> items;
		getline(fin, name);
		fin.ignore();
		/*while () {
			std::string item;
			getline(fin, item, ',');
			items.push_back(item);
		}*/
		person Person(name, items);
		data.people.push_back(Person);
	}
}

void start() {
	std::string Location;
	std::cout << "Enter your destination: ";
	std::cin >> Location;
	std::cout << std::endl;

	int Start[3];
	int End[3];
	std::cout << "Enter the date of arrival(format dd mm yyyy): ";
	std::cin >> Start[0] >> Start[1] >> Start[2];
	std::cout << std::endl;
	std::cout << "Enter the date of returnal(format dd mm yyyy): ";
	std::cin >> End[0] >> End[1] >> End[2];
	std::cout << std::endl;

	int people;
	std::cout << "How many people will go: ";
	std::cin >> people;
	std::cout << std::endl;
	for (int i = 0; i < people; i++) {

	}
}

void start_people() {
	std::string name;
	std::list<item> items;
	std::cout << "Enter name: ";
	std::cin >> ""
}