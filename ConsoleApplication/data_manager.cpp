#include "data_manager.h"
#include "generic_queue.h"
#include <fstream>
#include <iostream>
#include <vector>

#pragma region Methods

void data_manager::save_data_in_file(const std::string& file_name, const std::string& content) {
	std::ofstream out_file;

	out_file.open(file_name);

	if (!out_file.is_open()) {
		std::cout << "failed to open " << file_name << '\n';
	}
	else {
		out_file << content;
	}

	out_file.close();
}

void data_manager::load_mechanics_from_file(const std::string& file_name, std::vector<mechanic>& mechanics) {
	std::ifstream in_file(file_name);
	std::string line{};

	auto app = person::appointment();
	bool got_hours{ false };
	bool got_minutes{ false };

	int data_count{};
	int index{};
	auto current_mechanic = mechanic();
	while (std::getline(in_file, line)) {
		
		if (line.find('#') != std::string::npos) {
			mechanics.push_back(current_mechanic);
			index++;
			data_count = 0;
			current_mechanic = mechanic();
			continue;
		}

 		switch (data_count) {
			case 0:
				current_mechanic.set_name(line);
				data_count++;
				break;
			case 1:
				current_mechanic.set_age(std::stoi(line));
				data_count++;
				break;
			case 2:
				current_mechanic.set_id(std::stoi(line));
				data_count++;
				break;
			case 3:
				// Counter is ignored, calculated when adding appointments
				// m.set_counter(std::stoi(line));
				data_count++;
				break;
			default:
				if (data_count % 2 == 0) {
					app.hours = line;
					got_hours = true;
				}
				else {
					app.minutes = line;
					got_minutes = true;
				}

				if (got_hours && got_minutes) {
					current_mechanic.add_appointment(app);
					got_hours = got_minutes = false;
				}

				data_count++;

				break;
		}
	}

	in_file.close();

	//return mechanics;
}

void data_manager::load_customers_from_file(const std::string& file_name, const int customers_count, generic_queue<customer>* customers) {
	std::ifstream in_file(file_name);
	std::string line{};

	auto c = customer();

	auto app = person::appointment();
	bool got_hours{ false };
	bool got_minutes{ false };

	int data_count{};
	int index{};
	while (std::getline(in_file, line)) {

		if (line.find('#') != std::string::npos) {
			try {
				if (index < customers_count)
					customers->push(c);

				c = customer();
			}
			catch (...) {
				break;
			}

			index++;
			data_count = 0;
			continue;
		}

		switch (data_count) {
		case 0:
			c.set_name(line);
			data_count++;
			break;
		case 1:
			c.set_age(std::stoi(line));
			data_count++;
			break;
		case 2:
			c.set_id(std::stoi(line));
			data_count++;
			break;
		case 3:
			c.set_mechanic_id(std::stoi(line));
			data_count++;
			break;

		default:
			if (data_count % 2 == 0) {
				app.hours = line;
				got_hours = true;
			}
			else {
				app.minutes = line;
				got_minutes = true;
			}

			if (got_hours && got_minutes) {
				c.set_appointment(app);
				got_hours = got_minutes = false;
			}

			data_count++;

			break;
		}
	}

	in_file.close();
}

#pragma endregion