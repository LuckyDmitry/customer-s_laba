#pragma once
#include <string>
#include <ostream>

class Customer
{
public:
	Customer(const std::string name, int card_num) {
		this->name = name;
		this->card_number = card_num;
	
	};
	Customer() {  };
	friend std::ostream& operator<<(std::ostream& os, const Customer& person) {
		os << person.name << ' ' << person.card_number;
		return os;
	}
	~Customer(){}

private:
	std::string name;
	int card_number = 0;
};
