#include "mechanic.h"
#include <iostream>
#include <string>

#pragma region Constructors & Destructors

mechanic::mechanic() = default;

#pragma endregion

#pragma region Getters & Setters

void mechanic::set_counter(const int counter) {
	m_counter_ = counter;
}

int mechanic::get_counter() const {
	return m_counter_;
}

void mechanic::set_appointments(const std::vector<appointment>& appointments) {
	m_appointments_ = appointments;
	m_counter_ = static_cast<int>(appointments.size());
}

std::vector<person::appointment> mechanic::get_appointments() const {
	return m_appointments_;
}

#pragma endregion

#pragma region Methods

void mechanic::add_appointment(const appointment& appointment) {
	m_appointments_.push_back(appointment);
	m_counter_++;
}

bool mechanic::is_available(const appointment& appointment) const {
	bool is_available = true;

	for (int i = 0; i < m_counter_; ++i) {
		if (m_appointments_[i] == appointment) {
			is_available = false;
		}
	}

	return is_available;
}

std::string mechanic::get_data() {
	std::string data{};
	data += m_name_ + '\n';
	data += std::to_string(m_age_) + '\n';
	data += std::to_string(m_id_) + '\n';
	data += std::to_string(m_counter_) + '\n';

	for (int i = 0; i < m_counter_; ++i) {
		data += m_appointments_[i].hours + '\n';
		data += m_appointments_[i].minutes + '\n';
	}

	data += "#\n";

	return data;
}

#pragma endregion