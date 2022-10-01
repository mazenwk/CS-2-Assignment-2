#include "customer.h"
#include "generic_queue.h"
#include "mechanic.h"
#include "person.h"
#include <iostream>

mechanic get_mechanic_info(const int index) {
	auto m = mechanic();

	std::cout << "Mechanic #" << index + 1 << ":\n";

	std::cout << "Input mechanic's name: ";
	std::string name;
	std::cin >> name;
	m.set_name(name);

	return m;
}

customer get_customer_info(const int index) {
	auto c = customer();
	std::cout << "Customer #" << index + 1 << ":\n";

	std::cout << "Input customer's name: ";
	std::string name;
	std::cin >> name;
	c.set_name(name);

	std::cout << "Input customer's appointment hour: ";
	int hour;
	std::cin >> hour;

	std::cout << "Input customer's appointment minute: ";
	int minute;
	std::cin >> minute;

	c.set_appointment(person::appointment(hour, minute));

	return c;
}

int main()
{
	int mechanics_count{};
	std::cout << "Input number of mechanics: ";
	std::cin >> mechanics_count;

	int customers_count{};
	std::cout << "Input number of customers: ";
	std::cin >> customers_count;

	auto* mechanics = new mechanic[mechanics_count];
	generic_queue<customer> customers(customers_count);


	for (int i = 0; i < mechanics_count; ++i) {
		mechanics[i] = get_mechanic_info(i);
	}

	for (int i = 0; i < customers_count; ++i) {
		customers.push(get_customer_info(i));
	}

	int current_mechanic_index{};
	while (!customers.is_empty()) {
		if (mechanics[current_mechanic_index].is_available(customers.front().get_appointment())) {
			mechanics[current_mechanic_index].add_appointment(customers.front().get_appointment());
			std::cout << "Customer " << customers.front().get_name() << " is assigned to mechanic " << mechanics[current_mechanic_index].get_name()
				<< " at " << customers.front().get_appointment().hours << ':' << customers.front().get_appointment().minutes << '\n';
			customers.pop();
		}
		current_mechanic_index++;

		if (current_mechanic_index >= mechanics_count)
			current_mechanic_index = 0;
	}
}

//customers:
//	Ahmed at 1 : 00, Sara at 4 : 00, Kareem at 3 : 00, Mohammed at 1 : 00
//mechanics :
//	Ayman, Khaled, Mai
