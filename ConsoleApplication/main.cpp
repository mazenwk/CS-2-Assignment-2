#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "console_manager.h"
#include "customer.h"
#include "data_manager.h"
#include "generic_queue.h"
#include "mechanic.h"
#include "person.h"
#include <iostream>

#include "workshop.h"

const std::string mechanics_file = "mechanics.txt";
const std::string customers_file = "customers.txt";

void f();

void f() {
	const int mechanics_count{ console_manager::get_int_input("Input number of mechanics: ") };
	const int customers_count{ console_manager::get_int_input("Input number of customers: ") };
	auto ws = workshop(mechanics_count, customers_count);

	ws.get_data(mechanics_file, customers_file);
	ws.process_customers();
	ws.output_appointments();
}

/**
 * \brief Main Entry Point
 * \return 0
 */
int main()
{
	f();

	_CrtDumpMemoryLeaks();
}

void save_all_data(const std::string& mechanics_data, const std::string& customers_data) {
	data_manager::save_data_in_file(mechanics_file, mechanics_data);
	data_manager::save_data_in_file(customers_file, customers_data);
}

// Output:
//	Customers:
//		Ahmed at 1 : 00, Sara at 4 : 00, Kareem at 3 : 00, Mohammed at 1 : 00
//	Mechanics:
//		Ayman, Khaled, Mai
