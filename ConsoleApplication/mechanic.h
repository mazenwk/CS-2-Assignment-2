#pragma once
#include "person.h"
#include <string>

class mechanic : public person {
private:
	int m_counter_{};
	appointment* m_appointments_{};

public:
	mechanic();
	explicit mechanic(int max_appointments);

	void set_counter(int counter);
	int get_counter() const;

	void set_appointments(appointment* appointments, int counter);
	appointment* get_appointments() const;

	void add_appointment(const appointment& appointment);

	bool is_available(const appointment& appointment) const;

	std::string get_data() override;
};

