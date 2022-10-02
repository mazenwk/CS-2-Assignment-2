#pragma once
#include <string>


class person {
protected:
	std::string m_name_{};
	int m_id_{};
	int m_age_{};

public:
	virtual ~person() = default;
	person();

	void set_name(const std::string& name);
	std::string get_name();

	void set_id(int id);
	int get_id() const;

	void set_age(int age);
	int get_age() const;

	void print_info() const;

	virtual std::string get_data() = 0;

	struct appointment {
		appointment();
		appointment(const std::string& hour, const std::string& minute);

		std::string hours{};
		std::string minutes{};

		bool operator >(const appointment& appointment) const;
		bool operator <(const appointment& appointment) const;
		bool operator ==(const appointment& appointment) const;
	};
};

