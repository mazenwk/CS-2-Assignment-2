#include "console_manager.h"

int console_manager::get_int_input(std::string prompt) {
	std::cout << prompt;

	int input{};
	std::cin >> input;

	return input;
}

mechanic console_manager::get_mechanic_info(const int index) {
	auto m = mechanic();

	std::cout << "Mechanic #" << index + 1 << ":\n";

	std::cout << "Input mechanic's name: ";
	std::string name;
	std::cin >> name;
	m.set_name(name);

	return m;
}

customer console_manager::get_customer_info(const int index) {
	auto c = customer();
	std::cout << "Customer #" << index + 1 << ":\n";

	std::cout << "Input customer's name: ";
	std::string name;
	std::cin >> name;
	c.set_name(name);

	std::cout << "Input customer's appointment hour: ";
	std::string hour;
	std::cin >> hour;

	std::cout << "Input customer's appointment minute: ";
	std::string minute;
	std::cin >> minute;

	c.set_appointment(person::appointment(hour, minute));

	return c;
}
