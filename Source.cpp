#include "Header1.h""

using namespace std;

// input example
// name
//1 2 3
//item1, item2, item3...


int main() {
	travel_data data;
	int ch = 0;
	bool is_data = false;
	while (ch != 7) {
		std::cout << "1. Add data\n";
		std::cout << "2. Search for person\n";
		std::cout << "3. Delete person\n";
		std::cout << "4. Sort people\n";
		std::cout << "5. List info\n";
		std::cout << "6. Add person\n";
		std::cout << "7. Save to file and exit\n";
		std::cout << ">>";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
		{
			start(data);
			is_data = true;
			break;
		}
		case 2:
		{
			if (is_data){
				if (search(data)) {
					std::cout << "Person printed\n";
				}
				else {
					std::cout << "Person not found\n";
				}
			}
			else {
				std::cout << "There is no data yet!\n";
			}
			break;
		}
		case 3:
		{
			if (is_data) {
				if (delete_person(data)) {
					std::cout << "Person deleted\n";
				}
				else {
					std::cout << "Person not found\n";
				}
			}
			else {
				std::cout << "There is no data yet!\n";
			}
			break;
		}
		case 4:
		{
			if (is_data) {
				data.people.sort(cmp_by_name);
				std::cout << "People sorted\n";
			}
			else {
				std::cout << "There is no data yet!\n";
			}
			break;
		}
		case 5:
		{
			if (is_data) {
				print_data(data);
			}
			else {
				std::cout << "There is no data yet!\n";
			}
			break;
		}
		case 6:
		{
			if (is_data) {
				add_person(data);
			}
			else {
				std::cout << "There is no data yet!\n";
			}
			break;
		}
		case 7:
		{
			if (is_data) {
				std::ofstream fout("text.txt");
				if (fout.is_open()) {
					fout << "Location: " << data.location << std::endl;
					fout << "Duration: from " << data.start[0] << "." << data.start[1] << "." << data.start[2] << " to " << data.end[0] << "." << data.end[1] << "." << data.end[2] << std::endl;
					fout << "People: " << std::endl;
					for (std::list<person>::iterator it = data.people.begin(); it != data.people.end(); ++it) {
						person Person = *it;
						fout << "Name: " << Person.name << std::endl;
						fout << "Items: ";
						for (std::list<item>::iterator itt = Person.items.begin(); itt != Person.items.end(); ++itt) {
							item Item = *itt;
							fout << Item.name << " " << Item.amount << " / ";
						}
						fout << std::endl;
					}
					fout.close();
				}
				std::cout << "Saved to the file\n";
			}
			else {
				std::cout << "No data found, exit without saving\n";
			}
			break;
		}
		default:
			std::cout << "Incorrect input\n";
			break;
		}
	}
	return 0;
}