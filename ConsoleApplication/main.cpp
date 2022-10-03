#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "console_manager.h"
#include "workshop.h"

const std::string mechanics_file = "mechanics.txt";
const std::string customers_file = "customers.txt";

/**
 * \brief Main Entry Point
 * \return 0
 */
int main()
{
	const int mechanics_count{ console_manager::get_int_input("Input number of mechanics: ") };
	const int customers_count{ console_manager::get_int_input("Input number of customers: ") };
	const auto ws = workshop(mechanics_count, customers_count);

	ws.get_data(mechanics_file, customers_file);
	ws.process_customers();
	ws.output_appointments();
	ws.save_data(mechanics_file, customers_file);

	// No memory leaks; workshop data and constant strings not released yet as still in main.
	_CrtDumpMemoryLeaks();
}

/*
 Output:
	Customers:
		Ahmed at 1 : 00, Sara at 4 : 00, Kareem at 3 : 00, Mohammed at 1 : 00
	Mechanics:
		Ayman, Khaled, Mai
*/
