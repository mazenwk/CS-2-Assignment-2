#pragma once
#include "customer.h"
#include "mechanic.h"
#include <iostream>

/**
 * \brief Console Manager Class.
 */
class console_manager {
public:
	/**
	 * \brief Gets an integer input from the user from a prompt.
	 * \param prompt User Prompt.
	 * \return User input.
	 */
	static int get_int_input(const std::string& prompt);

	/**
	 * \brief Gets the Mechanic info from user input.
	 * \param index Index of the Mechanic. Used for output indexing only.
	 * \param m The mechanic to assign the info to.
	 */
	static void get_mechanic_info(const int index, mechanic* m);

	/**
	 * \brief Gets the Customer info from user input.
	 * \param index Index of the Customer. Used for output indexing only.
	 * \param c The Customer to assign the info to.
	 */
	static void get_customer_info(const int index, customer* c);
};

