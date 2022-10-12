#pragma once
#include "customer.h"
#include "generic_queue.h"
#include "mechanic.h"
#include <string>

/**
 * \brief Data Manager Class.
 */
class data_manager {
public:
	/**
	 * \brief Saves the given content into the given file.
	 * \param file_name File name to save data in.
	 * \param content Content to save.
	 */
	static void save_data_in_file(const std::string& file_name, const std::string& content);

	/**
	 * \brief Reads the given number of mechanics from the
	 * given mechanics file and updates the given array
	 * with the loaded data.
	 * \param file_name Mechanics File Name.
	 * \param mechanics_count Number of Mechanics.
	 * \param mechanics Mechanics Array.
	 */
	static void load_mechanics_from_file(const std::string& file_name, std::vector<mechanic>& mechanics);

	/**
	 * \brief Reads the given number of customers from the
	 * given customers file and updates the given queue
	 * with the loaded data.
	 * \param file_name Customers File Name.
	 * \param customers_count Number of Customers
	 * \param customers Customers Queue.
	 */
	static void load_customers_from_file(const std::string& file_name, const int customers_count, generic_queue<customer>* customers);
};

