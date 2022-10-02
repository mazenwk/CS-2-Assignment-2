#pragma once
#include "customer.h"
#include "generic_queue.h"
#include "mechanic.h"
#include <string>


class data_manager {
public:
	static void save_data_in_file(const std::string& file_name, const std::string& content);
	static mechanic* load_mechanics_from_file(const std::string& file_name, int mechanics_count);
	static generic_queue<customer>* load_customers_from_file(const std::string& file_name, const int customers_count);
};

