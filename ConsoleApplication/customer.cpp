#include "customer.h"

customer::customer() = default;

void customer::set_mechanic_id(int mechanic_id) {
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

bool customer::operator<(const customer& customer) const {
	return m_appointment_ < customer.m_appointment_;
}

bool customer::operator>(const customer& customer) const {
	return m_appointment_ > customer.m_appointment_;
}

bool customer::operator==(const customer& customer) const {
	return m_appointment_ == customer.m_appointment_;
}
