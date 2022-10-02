#pragma once
#include "person.h"
#include <string>

class mechanic : public person {
private:
	/**
	 * \brief Number of Appointments for this Mechanic.
	 */
	int m_counter_{};

	/**
	 * \brief The Appointments for this Mechanic.
	 */
	appointment* m_appointments_{};

public:
	/**
	 * \brief Default Constructor
	 */
	mechanic();
	~mechanic();

	/**
	 * \brief Default Parameterized Constructor.
	 * \param max_appointments Maximum number of Appointments for this Mechanic.
	 */
	explicit mechanic(int max_appointments);

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
	 * \param counter Number of Appointments for this Mechanic.
	 */
	void set_appointments(appointment* appointments, int counter);
	/**
	 * \brief Gets the Appointments for this Mechanic.
	 * \return The Appointments for this Mechanic.
	 */
	[[nodiscard]] appointment* get_appointments() const;

	/**
	 * \brief Adds an Appointment to this Mechanic.
	 * \param appointment The Appointment to add.
	 */
	void add_appointment(const appointment& appointment);

	/**
	 * \brief Checks if the Target Appointment time slot is available for this Mechanic.
	 * \param appointment The Target Appointment to compare Against.
	 * \return Whether or not this Appointment time slot is available.
	 */
	[[nodiscard]] bool is_available(const appointment& appointment) const;

	/**
	 * \brief Gets the Mechanic's data in a unified string format.
	 * \return The data of the Mechanic in string format. Stored in files using a unified format.
	 */
	std::string get_data() override;
};

