#include "customer.h"
#include "data_manager.h"
#include <iostream>
#include <string>

#pragma region Constructors

customer::customer() = default;

#pragma endregion

#pragma region Getters & Setters

void customer::set_mechanic_id(const int mechanic_id) {
	m_mechanic_id_ = mechanic_id;
}

int customer::get_mechanic_id() const {
	return m_mechanic_id_;
}

void customer::set_appointment(const appointment& appointment) {
	m_appointment_ = appointment;
}

person::appointment customer::get_appointment() const {
	return m_appointment_;
}

#pragma endregion

#pragma region Methods

std::string customer::get_data() const{
	// Building a string with the data
	std::string data{};
	data += m_name_ + '\n';
	data += std::to_string(m_age_) + '\n';
	data += std::to_string(m_id_) + '\n';
	data += std::to_string(m_mechanic_id_) + '\n';
	data += m_appointment_.hours + '\n';
	data += m_appointment_.minutes + '\n';

	data += "#\n";

	return data;
}

#pragma endregion

#pragma region Operators

bool customer::operator<(const customer& customer) const {
	return m_appointment_ < customer.m_appointment_;
}

bool customer::operator>(const customer& customer) const {
	return m_appointment_ > customer.m_appointment_;
}

bool customer::operator==(const customer& customer) const {
	return m_appointment_ == customer.m_appointment_;
}

#pragma endregion