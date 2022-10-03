#include "console_manager.h"
#include "data_manager.h"
#include "mechanic.h"
#include "workshop.h"
#include <string>
workshop::workshop(const int mechanic_count, const int customers_count) {
	set_mechanics_count(mechanic_count);
	set_customers_count(customers_count);

	m_mechanics_ = new mechanic[m_mechanics_count_];
	m_customers_ = new generic_queue<customer>(m_customers_count_);
}

void workshop::set_mechanics_count(const int count) {
	m_mechanics_count_ = count;
}

int workshop::get_mechanics_count() const {
	return m_mechanics_count_;
}

void workshop::set_customers_count(const int count) {
	m_customers_count_ = count;
}

int workshop::get_customers_count() const {
	return m_customers_->count();
}

mechanic* workshop::get_mechanics() const {
	return m_mechanics_;
}

generic_queue<customer>* workshop::get_customers() const {
	return m_customers_;
}

void workshop::get_data(const std::string& mechanics_file, const std::string& customers_file) const {
	get_mechanics(mechanics_file);
	get_customers(customers_file);
}

void workshop::process_customers() const {
	int current_mechanic_index{};
	int rejected_count{};
	int processed_customers{};
	while (processed_customers < m_customers_->count()) {
		if (m_mechanics_[current_mechanic_index].is_available(m_customers_->front()->get_appointment())) {

			m_mechanics_[current_mechanic_index].add_appointment(m_customers_->front()->get_appointment());
			m_customers_->front()->set_mechanic_id(m_mechanics_[current_mechanic_index].get_id());

			const auto temp_customer = *m_customers_->front();
			m_customers_->pop();
			m_customers_->push(temp_customer);

			rejected_count = 0;
			processed_customers++;
		} else {
			rejected_count++;

			if (rejected_count > m_mechanics_count_) {
				std::cout << "No empty slots for customer " << m_customers_->front()->get_name()
					<< " at " << m_customers_->front()->get_appointment().hours << ':' << m_customers_->front()->get_appointment().minutes << '\n';
				rejected_count = 0;
				processed_customers++;
				m_customers_->pop();
			}
		}
		current_mechanic_index++;
		

		if (current_mechanic_index >= m_mechanics_count_)
			current_mechanic_index = 0;
	}
}

void workshop::output_appointments() const {
	bubble_sort_customers();

	for (int i = 0; i < get_customers_count(); ++i) {
		std::cout << "Customer " << m_customers_->front()->get_name() << " is assigned to mechanic " << m_mechanics_[m_customers_->front()->get_mechanic_id() - 1].get_name()
			<< " at " << m_customers_->front()->get_appointment().hours << ':' << m_customers_->front()->get_appointment().minutes << '\n';

		const customer temp_customer = *m_customers_->front();
		m_customers_->pop();
		m_customers_->push(temp_customer);
	}
}

workshop::~workshop() {
	delete[] m_mechanics_;
	delete m_customers_;
}

void workshop::get_mechanics(const std::string& file_name) const {
	data_manager::load_mechanics_from_file(file_name, m_mechanics_count_, m_mechanics_);
	if (m_mechanics_[0].get_name().empty()) {
		for (int i = 0; i < m_mechanics_count_; ++i) {
			m_mechanics_[i] = console_manager::get_mechanic_info(i);
		}
	}
}

void workshop::get_customers(const std::string& file_name) const {
	data_manager::load_customers_from_file(file_name, m_customers_count_, m_customers_);
	if (m_customers_->count() == 0) {
		for (int i = 0; i < m_customers_count_; ++i) {
			m_customers_->push(console_manager::get_customer_info(i));
		}
	}
}

void workshop::bubble_sort_customers() const {
	const int size = m_customers_->count();
	const auto array = new customer[size];

	for (int i = 0; i < size; ++i) {
		array[i] = *m_customers_->front();
		m_customers_->pop();
	}

	if (size == 1) {
		return;
	}

	for (int step = 0; step < (size - 1); ++step) {

		int swapped = 0;

		for (int i = 0; i < (size - step - 1); ++i) {

			if (array[i] > array[i + 1]) {

				const customer temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}

	for (int i = 0; i < size; ++i) {
		m_customers_->push(array[i]);
	}

	delete[] array;
}
