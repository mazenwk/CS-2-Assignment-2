#include "console_manager.h"

#pragma region Methods
int console_manager::get_int_input(const std::string& prompt) {
	std::cout << prompt;

	int input{};
	std::cin >> input;

	return input;
}

void console_manager::get_mechanic_info(const int index, mechanic *m) {

	std::cout << "Mechanic #" << index + 1 << ":\n";

	std::cout << "Input mechanic's name: ";
	std::string name;
	std::cin >> name;

	std::cout << "Input mechanic's Id: ";
	int id;
	std::cin >> id;

	m->set_name(name);
	m->set_id(id);

}

void console_manager::get_customer_info(const int index, customer* c) {
	std::cout << "Customer #" << index + 1 << ":\n";

	std::cout << "Input customer's name: ";
	std::string name;
	std::cin >> name;
	c->set_name(name);

	std::cout << "Input customer's appointment hour: ";
	std::string hour;
	std::cin >> hour;

	std::cout << "Input customer's appointment minute: ";
	std::string minute;
	std::cin >> minute;

	c->set_appointment(person::appointment(hour, minute));
}

#pragma endregion