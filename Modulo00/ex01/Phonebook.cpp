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
	Contact	NewContact;

	if (this->count == 8) {
        // Si el phonebook ya tiene 8 contactos, eliminar el más antiguo
        for (int i = 0; i < 7; i++) {
            this->contacts[i] = this->contacts[i + 1];
        }
        this->count--;
    }
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	NewContact.set_firstname(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	NewContact.set_lastname(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	NewContact.set_nickname(input);
	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	NewContact.set_phonenum(input);
	std::cout << "Secret number: ";
	std::getline(std::cin, input);
	NewContact.set_darksecret(input);

	this->contacts[this->count] = NewContact;
	this->count++;
}