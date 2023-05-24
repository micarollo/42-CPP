#include <iostream>
#include "Phonebook.hpp"

void    Phonebook::set_num(int num)  {
    this->count = num;
};

int    Phonebook::get_num(void)  {
    return (this->count);
};

void	Phonebook::add_contact() {
	std::string	input;
	// Contact	NewContact;

	// if (this->count == 8) {
    //     for (int i = 0; i < 7; i++) {
    //         this->contacts[i] = this->contacts[i + 1];
    //     }
    //     this->count--;
    // }
	if (this->count == 8)
		this->count == 0; 
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	this->contacts[count].set_firstname(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	this->contacts[count].set_lastname(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	this->contacts[count].set_nickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	this->contacts[count].set_phonenum(input);
	std::cout << "Secret number: ";
	std::getline(std::cin, input);
	this->contacts[count].set_darksecret(input);

	// this->contacts[this->count] = NewContact;
	this->count++;
}

void	Phonebook::search() {
	std::string	input;

	std::cout << "Contact name: ";
	std::getline(std::cin, input);	
	for (int i = 0; i < 7; i++) {
		if (this->contacts[i].get_firstname().compare(input) == 0) {
			
		}
	}
}