#pragma once
class workshop {
public:
	workshop(const int mechanic_count, const int customers_count);

	void set_mechanics_count(const int count);
	[[nodiscard]] int get_mechanics_count() const;
	void set_customers_count(const int count);
	[[nodiscard]] int get_customers_count() const;
	[[nodiscard]] mechanic* get_mechanics() const;
	[[nodiscard]] generic_queue<customer>* get_customers() const;

	void get_data(const std::string& mechanics_file, const std::string& customers_file) const;

	void process_customers() const;

	void output_appointments() const;

	void save_data();

	~workshop();

private:
	int m_mechanics_count_{};
	int m_customers_count_{};
	mechanic* m_mechanics_{};
	generic_queue<customer>* m_customers_{};

	void get_mechanics(const std::string& file_name) const;
	void get_customers(const std::string& file_name) const;

	void bubble_sort_customers() const;
};

