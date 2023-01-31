#include "Header1.h""

using namespace std;

// input example
// name
//1 2 3
//item1, item2, item3...


int main() {
	travel_data data;
	int ch = 0;
	while (ch != 8) {
		std::cout << "1. Add data\n";
		std::cout << "2. Search for person\n";
		std::cout << "3. Edit details\n";
		std::cout << "4. Delete person\n";
		std::cout << "5. Sort people\n";
		std::cout << "6. List info\n";
		std::cout << "7. Add person\n";
		std::cout << "8. Save to file and exit";
		std::cout << ">>";
		std::cin >> ch;
		switch (ch)
		{
		case 1:
		{
			start(data);
		}
		case 2:
		{

		}
		case 3:
		{

		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{
			print_data(data);
		}
		case 7:
		{

		}
		case 8:
		{
			std::cout << "Saved to the file";
		}
		default:
			break;
		}
	}
	/*std::ifstream fin("text.txt");
	if (fin.is_open()) {
		travel_data data;
		fin.close();
	}*/
	return 0;
}