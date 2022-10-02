#pragma once
#include "customer.h"
#include "mechanic.h"
#include <iostream>

class console_manager {
public:
	static int get_int_input(std::string prompt);

	/**
	 * \brief Gets the Mechanic info from user input.
	 * \param index Index of the Mechanic. Used for output indexing only.
	 * \return A mechanic object with the inputted information.
	 */
	static mechanic get_mechanic_info(const int index);

	/**
	 * \brief Gets the Customer info from user input.
	 * \param index Index of the Customer. Used for output indexing only.
	 * \return A customer object with the inputted information.
	 */
	static customer get_customer_info(const int index);
};

