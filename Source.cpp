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

	person(std::string Name, std::list<std::string> Items, int Underwear, int Pants, int Socks):
		name(Name), items(Items), underwear(Underwear), pants(Pants), socks(Socks)
	{}
};

void read_file(std::ifstream& fin, travel_data& data)
{
	while (!fin.eof()) {
		std::string name;
		std::list<std::string> items;
		int underwear;
		int pants;
		int socks;
		getline(fin, name);
		fin >> underwear >> pants >> socks;
		fin.ignore();
		while () {
			std::string item;
			getline(fin, item, ',');
			items.push_back(item);
		}
		person Person(name, items, underwear, pants, socks);
		data.people.push_back(Person);
	}
}

// input example
// name
//1 2 3
//item1, item2, item3...


int main() {
	std::ifstream fin("text.txt");
	int j = 0;
	if (fin.is_open()) {
		travel_data data;
		fin.close();
	}
	return 0;
}