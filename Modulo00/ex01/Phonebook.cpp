#include <iostream>
#include <iomanip>
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

void Phonebook::displayContacts() {
    // Encabezado de columnas
    std::cout << std::right << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First name" << " | "
              << std::setw(10) << "Last name" << " | "
              << std::setw(10) << "Nickname" << std::endl;

    // Línea separadora
    std::cout << std::string(44, '-') << std::endl;

    // Mostrar los contactos
    for (size_t i = 0; i < this->count; i++) {
        std::cout << std::right << std::setw(10) << i << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_firstname().length() > 10 ? this->contacts[i].get_firstname().substr(0, 9) + '.' : this->contacts[i].get_firstname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_lastname().length() > 10 ? this->contacts[i].get_lastname().substr(0, 9) + '.' : this->contacts[i].get_lastname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_nickname().length() > 10 ? this->contacts[i].get_nickname().substr(0, 9) + '.' : this->contacts[i].get_nickname())
                  << std::endl;
    }
}

void	Phonebook::search() {
	
}