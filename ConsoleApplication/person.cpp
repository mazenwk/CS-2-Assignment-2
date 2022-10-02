#include "person.h"
#include <iostream>

#pragma region Constructors

person::~person() = default;

person::person() = default;

#pragma endregion

#pragma region Getters & Setters
void person::set_name(const std::string& name) {
	m_name_ = name;
}

std::string person::get_name() {
	return m_name_;
}

void person::set_id(const int id) {
	m_id_ = id;
}

int person::get_id() const {
	return m_id_;
}

void person::set_age(const int age) {
	m_age_ = age;
}

int person::get_age() const {
	return m_age_;
}

#pragma endregion

#pragma region Methods

void person::print_info() const {
	std::cout << "Name: " << m_name_ << '\n';
	std::cout << "ID: " << m_id_ << '\n';
	std::cout << "Age: " << m_age_ << '\n';
}

#pragma endregion

#pragma region Appointment Struct

person::appointment::appointment() = default;

person::appointment::appointment(const std::string& hour, const std::string& minute) {
	hours = hour;
	minutes = minute;
}

bool person::appointment::operator>(const appointment& appointment) const {
	if (std::stoi(hours) == std::stoi(appointment.hours)) {
		return std::stoi(minutes) > std::stoi(appointment.minutes);
	}

	return std::stoi(hours) > std::stoi(appointment.hours);
}

bool person::appointment::operator<(const appointment& appointment) const {
	if (std::stoi(hours) == std::stoi(appointment.hours)) {
		return std::stoi(minutes) < std::stoi(appointment.minutes);
	}

	return std::stoi(hours) < std::stoi(appointment.hours);
}

bool person::appointment::operator==(const appointment& appointment) const {
	return (std::stoi(hours) == std::stoi(appointment.hours))
		&& (std::stoi(minutes) == std::stoi(appointment.minutes));
}

#pragma endregion