#pragma once
#include <string>

/**
 * \brief The Person Class.
 */
class person {
public:
	/**
	 * \brief Default Constructor
	 */
	person();

	/**
	 * \brief Sets the Name of the Person.
	 * \param name Name of the Person.
	 */
	void set_name(const std::string& name);
	std::string get_name();

	/**
	 * \brief Sets the ID of the Person.
	 * \param id ID of the Person.
	 */
	void set_id(int id);
	[[nodiscard]] int get_id() const;

	/**
	 * \brief Sets the Age of the Person.
	 * \param age Age of the Person.
	 */
	void set_age(int age);
	[[nodiscard]] int get_age() const;

	/**
	 * \brief Prints the Info of the Person (Name, ID, Age).
	 */
	void print_info() const;

	/**
	 * \brief Appointment Struct.
	 */
	struct appointment {
		/**
		 * \brief Default Constructor.
		 */
		appointment();

		/**
		 * \brief Default Parameterized Constructor.
		 * \param hour Appointment Hour.
		 * \param minute Appointment Minute.
		 */
		appointment(const std::string& hour, const std::string& minute);

		/**
		 * \brief Appointment Hour.
		 */
		std::string hours{};
		/**
		 * \brief Appointment Minutes.
		 */
		std::string minutes{};

		/**
		 * \brief  Checks if the Target Appointment is before this Appointment.
		 * \param appointment The Target Appointment to compare against.
		 * \return True if the Target Appointment is before this Appointment.
		 */
		bool operator <(const appointment& appointment) const;
		/**
		 * \brief  Checks if the Target Appointment is after this Appointment.
		 * \param appointment The Target Appointment to compare against.
		 * \return True if the Target Appointment is after this Appointment.
		 */
		bool operator >(const appointment& appointment) const;

		/**
		 * \brief  Checks if the Target Appointment is equal to this Appointment.
		 * \param appointment The Target Appointment to compare against.
		 * \return True if the Target Appointment is equal to this Appointment.
		 */
		bool operator ==(const appointment& appointment) const;
	};

protected:
	/**
	 * \brief The Person's Name
	 */
	std::string m_name_{};

	/**
	 * \brief The Person's ID
	 */
	int m_id_{};

	/**
	 * \brief The Person's Age
	 */
	int m_age_{};
};

