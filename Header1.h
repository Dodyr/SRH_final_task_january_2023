#pragma once
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

	std::list<item> items;

	person(std::string Name, std::list<item> Items) :
		name(Name), items(Items)
	{}
};

struct item {
	std::string name;
	int amount;

	item(std::string Name, int Amount) :
		name(Name), amount(Amount)
	{}
};

void read_file(std::ifstream& fin, travel_data& data);

void start(travel_data & data);

person start_people();
