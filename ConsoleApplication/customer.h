#pragma once
#include "person.h"
#include <string>


class customer : public person {
private:
	int m_mechanic_id_{};
	appointment m_appointment_{};

public:
	customer();

	void set_mechanic_id(int mechanic_id);
	int get_mechanic_id() const;

	void set_appointment(const appointment &appointment);
	appointment get_appointment() const;

	bool operator < (const customer& customer) const;
	bool operator > (const customer& customer) const;
	bool operator == (const customer& customer) const;

	std::string get_data() override;
};

