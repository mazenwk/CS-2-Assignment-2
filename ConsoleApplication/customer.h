#pragma once
#include "person.h"
#include <string>

/**
 * \brief The Customer Class. Derived from Person.
 */
class customer : public person {
public:
	/**
	 * \brief Default Constructor
	 */
	customer();

	/**
	 * \brief Sets the Mechanic ID.
	 * \param mechanic_id The ID of the Mechanic to be scheduled by the customer.
	 */
	void set_mechanic_id(int mechanic_id);

	/**
	 * \brief Gets the Mechanic ID scheduled by the customer.
	 * \return The Mechanic ID scheduled by the customer.
	 */
	[[nodiscard]] int get_mechanic_id() const;

	/**
	 * \brief Sets the Appointment of the customer.
	 * \param appointment appointment The Appointment to schedule.
	 */
	void set_appointment(const appointment& appointment);

	/**
	 * \brief Gets the Appointment schedules by the customer.
	 * \return The Appointment scheduled by the customer.
	 */
	[[nodiscard]] appointment get_appointment() const;

	/**
	 * \brief Gets the Customer's data in a unified string format.
	 * \return The data of the Customer in string format. Stored in files using a unified format.
	 */
	[[nodiscard]] std::string get_data() override;

	/**
	 * \brief Checks if the target Customer's appointment is after this Customer's appointment
	 * \param customer The Target Customer to compare with.
	 * \return True if target Customer's appointment is after this Customer's appointment
	 */
	bool operator < (const customer& customer) const;

	/**
	 * \brief Checks if the target Customer's appointment is before this Customer's appointment
	 * \param customer The Target Customer to compare with.
	 * \return True if the target Customer's appointment is before this Customer's appointment
	 */
	bool operator > (const customer& customer) const;

	/**
	 * \brief Checks if the target Customer's appointment is equal to this Customer's appointment
	 * \param customer The Target Customer to compare with.
	 * \returnTrue if the target Customer's appointment is equal to this Customer's appointment
	 */
	bool operator == (const customer& customer) const;

private:
	/**
	 * \brief The ID of the Mechanic scheduled by the customer.
	 */
	int m_mechanic_id_{};

	/**
	 * \brief The appointment of the customer.
	 */
	appointment m_appointment_{};
};

