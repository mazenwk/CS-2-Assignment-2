#pragma once
#include "person.h"
#include <string>
#include <vector>

/**
 * \brief The Mechanic Class.
 */
class mechanic: public person {
public:
	/**
	 * \brief Default Constructor.
	 */
	mechanic();

	/**
	 * \brief Sets the number of Appointments for this Mechanic.
	 * \param counter Number of Appointments for this Mechanic.
	 */
	void set_counter(int counter);
	/**
	 * \brief Gets the number of Appointments for this Mechanic.
	 * \return The number of Appointments for this Mechanic.
	 */
	[[nodiscard]] int get_counter() const;

	/**
	 * \brief Sets the Appointments for this Mechanic.
	 * \param appointments The Appointments for this Mechanic.
	 */
	void set_appointments(const std::vector<appointment>& appointments);
	/**
	 * \brief Gets the Appointments for this Mechanic.
	 * \return The Appointments for this Mechanic.
	 */
	[[nodiscard]] std::vector<appointment> get_appointments() const;

	/**
	 * \brief Adds an Appointment to this Mechanic.
	 * \param appointment The Appointment to add.
	 */
	void add_appointment(const appointment& appointment);

	/**
	 * \brief Checks if the Target Appointment time slot is available for this Mechanic.
	 * \param appointment The Target Appointment to compare Against.
	 * \return True if this Appointment time slot is available.
	 */
	[[nodiscard]] bool is_available(const appointment& appointment) const;

	/**
	 * \brief Gets the Mechanic's data in a unified string format.
	 * \return The data of the Mechanic in string format. Stored in files using a unified format.
	 */
	[[nodiscard]] std::string get_data() override;

private:
	/**
	 * \brief Number of Appointments for this Mechanic.
	 */
	int m_counter_{};

	/**
	 * \brief The Appointments for this Mechanic.
	 */
	std::vector<appointment> m_appointments_{};
};

