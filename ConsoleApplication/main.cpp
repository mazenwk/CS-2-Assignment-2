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

const std::string mechanics_file = "mechanics.txt";
const std::string customers_file = "customers.txt";

void get_mechanics(const std::string& file_name, const int count, mechanic* mechanics);
void get_customers(const std::string& file_name, const int count, generic_queue<customer>* customers);
void process_customers(mechanic* mechanics, const int mechanics_count, generic_queue<customer>* customers, generic_queue<customer>* processed_customers);
std::string get_mechanics_data(mechanic* mechanics, const int mechanics_count);
void bubble_sort(customer* array, generic_queue<customer>* queue, const int size);
std::string get_customers_data(customer* customers, const int size);
void output_workshop_appointments(customer* customers, mechanic* mechanics, const int size);
void save_all_data(const std::string& mechanics_data, const std::string& customers_data);

void WS();
/**
 * \brief Main Entry Point
 * \return 0
 */
int main()
{
	
	WS();

	_CrtDumpMemoryLeaks();
}

void WS()
{
	//TODO: Clear previous data from input
	//TODO: Refactoring
	const int mechanics_count{ console_manager::get_int_input("Input number of mechanics: ") };
	const auto mechanics = new mechanic[mechanics_count];
	get_mechanics(mechanics_file, mechanics_count, mechanics);

	const int customers_count{ console_manager::get_int_input("Input number of customers: ") };
	const auto customers = new generic_queue<customer>(customers_count);
	const auto processed_customers = new generic_queue<customer>(customers_count);
	get_customers(customers_file, customers_count, customers);

	process_customers(mechanics, mechanics_count, customers, processed_customers);
	const int processed_customers_count = customers->count();

	const std::string mechanics_data{ get_mechanics_data(mechanics, mechanics_count) };

	const auto sorted_customers = new customer[customers->count()];
	bubble_sort(sorted_customers,processed_customers, customers->count());
	const std::string customers_data{ get_customers_data(sorted_customers, processed_customers_count) };

	output_workshop_appointments(sorted_customers, mechanics, processed_customers_count);

	save_all_data(mechanics_data, customers_data);

	delete processed_customers;
	delete customers;
	delete[] mechanics;
	delete[] sorted_customers;
}
void get_mechanics(const std::string& file_name, const int count, mechanic* mechanics) {
	data_manager::load_mechanics_from_file(file_name, count, mechanics);
	if (mechanics[0].get_name().empty()) {
		for (int i = 0; i < count; ++i) {
			mechanics[i] = console_manager::get_mechanic_info(i);
		}
	}

	//return mechanics;
}

void get_customers(const std::string& file_name, const int count, generic_queue<customer>* customers) {

	if (customers->count() == 0) {
		for (int i = 0; i < count; ++i) {
			customers->push(console_manager::get_customer_info(i));
		}
	}
}

void process_customers(mechanic* mechanics, const int mechanics_count, generic_queue<customer>* customers, generic_queue<customer>* processed_customers) {

		int current_mechanic_index{};
	int rejected_count{};
	while (!customers->is_empty()) {
		if (mechanics[current_mechanic_index].is_available(customers->front()->get_appointment())) {
			mechanics[current_mechanic_index].add_appointment(customers->front()->get_appointment());

			customers->front()->set_mechanic_id(mechanics[current_mechanic_index].get_id());
			processed_customers->push(*customers->front());
			customers->pop();
			rejected_count = 0;
		}
		current_mechanic_index++;
		rejected_count++;


		if (current_mechanic_index >= mechanics_count)
			current_mechanic_index = 0;
		if (rejected_count > mechanics_count) {
			std::cout << "No empty slots for customer " << customers->front()->get_name()
				<< " at " << customers->front()->get_appointment().hours << ':' << customers->front()->get_appointment().minutes << '\n';

			customers->pop();
		}
	}
}

std::string get_mechanics_data(mechanic* mechanics, const int mechanics_count) {
	std::string mechanics_data{};

	for (int i = 0; i < mechanics_count; ++i) {
		mechanics_data += mechanics[i].get_data();
	}

	return mechanics_data;
}

void bubble_sort(customer* array, generic_queue<customer>* queue, const int size) {

	for (int i = 0; i < size; ++i) {
		array[i] = *queue->front();
		queue->pop();
	}

	if (size == 1) {
		return;
	}

	for (int step = 0; step < (size - 1); ++step) {

		int swapped = 0;

		for (int i = 0; i < (size - step - 1); ++i) {

			if (array[i] > array[i + 1]) {

				const customer temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
}

std::string get_customers_data(customer* customers, const int size) {
	std::string customers_data{};

	for (int i = 0; i < size; ++i) {
		customers_data += customers[i].get_data();
	}

	return customers_data;
}

void output_workshop_appointments(customer* customers, mechanic* mechanics, const int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << "Customer " << customers[i].get_name() << " is assigned to mechanic " << mechanics[customers[i].get_mechanic_id() - 1].get_name()
			<< " at " << customers[i].get_appointment().hours << ':' << customers[i].get_appointment().minutes << '\n';
	}
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
