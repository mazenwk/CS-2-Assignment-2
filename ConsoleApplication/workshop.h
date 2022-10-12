#pragma once
#include "generic_queue.h"
#include <vector>

/**
 * \brief Workshop Class.
 */
class workshop {
public:
	/**
	 * \brief Default Parameterized Constructor.
	 * \param mechanic_count Number of Mechanics.
	 * \param customers_count Number of Customers.
	 */
	workshop(const int mechanic_count, const int customers_count);

	/**
	 * \brief Sets the number of Mechanics.
	 * \param count Number of Mechanics.
	 */
	void set_mechanics_count(const int count);
	/**
	 * \brief Gets the number of Mechanics.
	 * \return The number of Mechanics. 
	 */
	[[nodiscard]] int get_mechanics_count() const;

	/**
	 * \brief Sets the number of Customers.
	 * \param count Number of Customers.
	 */
	void set_customers_count(const int count);

	/**
	 * \brief Gets the number of Customers.
	 * \return The number of Customers.
	 */
	[[nodiscard]] int get_customers_count() const;

	/**
	 * \brief Gets the Workshop's Mechanics Vector.
	 * \return Mechanics Vector.
	 */
	[[nodiscard]] std::vector<mechanic> get_mechanics() const;

	/**
	 * \brief Gets the Workshop's Customers Queue.
	 * \return Customers Queue.
	 */
	[[nodiscard]] generic_queue<customer>* get_customers() const;

	/**
	 * \brief Loads or Gets the Mechanics & Customers data from files or from user input.
	 * \param mechanics_file Mechanics file name.
	 * \param customers_file Customers file name.
	 */
	void get_data(const std::string& mechanics_file, const std::string& customers_file);

	/**
	 * \brief Processes the customers through the mechanics schedules.
	 */
	void process_customers();

	/**
	 * \brief Outputs scheduled customer appointments.
	 */
	void output_appointments();

	/**
	 * \brief Saves the processed data back into files.
	 * \param mechanics_file Mechanics file name.
	 * \param customers_file Customers file name.
	 */
	void save_data(const std::string& mechanics_file, const std::string& customers_file);

	/**
	 * \brief Destructor.
	 */
	~workshop();

private:
	/**
	 * \brief Number of Mechanics.
	 */
	int m_mechanics_count_{};

	/**
	 * \brief Number of Customers.
	 */
	int m_customers_count_{};

	/**
	 * \brief Mechanics Vector.
	 */
	std::vector<mechanic> m_mechanics_{};

	/**
	 * \brief Customers Queue.
	 */
	generic_queue<customer>* m_customers_{};

	/**
	 * \brief Loads the Mechanics data (if any) from the file.
	 * \param file_name Mechanics file name.
	 */
	void get_mechanics(const std::string& file_name);

	/**
	 * \brief Loads the Customers data (if any) from the file.
	 * \param file_name Customers file name.
	 */
	void get_customers(const std::string& file_name);

	/**
	 * \brief Bubble Sorts the Customers Queue.
	 */
	void bubble_sort_customers() const;

	/**
	 * \brief Gets the Mechanic's name using their ID.
	 * \param id The ID of the Mechanic to search for.
	 * \return The Target Mechanic's Name, if found.
	 */
	[[nodiscard]] std::string get_mechanic_name_by_id(const int id);
};

