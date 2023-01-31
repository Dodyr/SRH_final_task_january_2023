#include "Header1.h"
//not finished
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


void start(travel_data & data) {
	std::string Location;
	std::cout << "Enter your destination: ";
	std::cin >> data.location;
	std::cout << std::endl;

	std::cout << "Enter the date of arrival(format dd mm yyyy): ";
	std::cin >> data.start[0] >> data.start[1] >> data.start[2];
	std::cout << std::endl;
	while (!check_date(data.start)) {
		std::cout << "Enter valid date: ";
		std::cin >> data.start[0] >> data.start[1] >> data.start[2];
		std::cout << std::endl;
	}

	std::cout << "Enter the date of returnal(format dd mm yyyy): ";
	std::cin >> data.end[0] >> data.end[1] >> data.end[2];
	std::cout << std::endl;
	while (!check_date(data.end)) {
		std::cout << "Enter valid date: ";
		std::cin >> data.end[0] >> data.end[1] >> data.end[2];
		std::cout << std::endl;
	}


	int people;
	std::cout << "How many people will go: ";
	std::cin >> people;
	std::cout << std::endl;
	while (people <= 0) {
		std::cout << "Enter correct amount of people: ";
		std::cin >> people;
		std::cout << std::endl;
	}
	for (int i = 0; i < people; i++) {
		person Person = start_people();
		data.people.push_back(Person);
		std::cout << "Person added\n";
	}
}

bool check_date(int Date[3]) {
	if ((Date[0] <= 0) && (Date[1] <= 0) && (Date[2] <= 0) && (Date[0] > 31) && (Date[1] > 12)) {
		return false;
	}
	return true;
}

person start_people() {
	std::string person_name;
	std::list<item> items;
	std::cout << "Enter name: ";
	std::cin >> person_name;
	int ch = 1;
	while (ch != 2) {
		std::cout << "1. Add new item\n" << "2. Don't add more items\n" << ">>";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
		{
			std::string name;
			std::cout << "Enter item's name: ";
			std::cin >> name;
			std::cout << std::endl;

			int amount;
			std::cout << "Enter amount: ";
			std::cin >> amount;
			std::cout << std::endl << "New Item added\n";

			item Item(name, amount);
			items.push_back(Item);
			break;
		}
		case 2:
		{
			break;
		}
		default:
		{
			std::cout << "Enter 1 or 2\n";
			std::cin >> ch;
			break;
		}
		}
	}
	person Person(person_name, items);
	return Person;
}


void print_data(travel_data data) {
	std::cout << "Location: " << data.location << std::endl;
	std::cout << "Duration: from " << data.start[0] << "." << data.start[1]<< "." << data.start[2] << " to " << data.end[0] << "." << data.end[1] << "." << data.end[2] << std::endl;
	std::cout << "People: " << std::endl;
	for (std::list<person>::iterator it = data.people.begin(); it != data.people.end(); ++it) {
		person Person = *it;
		std::cout << "Name: " << Person.name << std::endl;
		std::cout << "Items: ";
		for (std::list<item>::iterator itt = Person.items.begin(); itt != Person.items.end(); ++itt) {
			item Item = *itt;
			std::cout << Item.name << " " << Item.amount << " / ";
		}
		std::cout << std::endl;
	}
}