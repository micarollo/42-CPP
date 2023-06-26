#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook(void) {
    return ;
}

Phonebook::~Phonebook(void) {
    return ;
}

void    Phonebook::set_num(int num)  {
    this->count = num;
};

int    Phonebook::get_num(void)  {
    return (this->count);
};

static std::string get_input(std::string text) {
    std::string	input;

    input = "";
    while (input == "")
    {
        std::cout << text << ": ";
        std::getline(std::cin, input);
    }
    return (input);
}

void	Phonebook::add_contact() {
	std::string	input;

	if (this->count == 8)
		this->count = 0; 
	// std::cout << "First Name: ";
	// // std::getline(std::cin, input);
    // std::cin >> input;
	// this->contacts[count].set_firstname(input);
    this->contacts[count].set_firstname(get_input("First name"));
    this->contacts[count].set_lastname(get_input("Last name"));
    this->contacts[count].set_nickname(get_input("Nickname"));
    this->contacts[count].set_phonenum(get_input("Phone number"));
    this->contacts[count].set_darksecret(get_input("Secret number"));
	// std::cout << "Last Name: ";
	// std::getline(std::cin, input);
	// this->contacts[count].set_lastname(input);
	// std::cout << "Nickname: ";
	// std::getline(std::cin, input);
	// this->contacts[count].set_nickname(input);
	// std::cout << "Phone number: ";
	// std::getline(std::cin, input);
	// this->contacts[count].set_phonenum(input);
	// std::cout << "Secret number: ";
	// std::getline(std::cin, input);
	// this->contacts[count].set_darksecret(input);
	this->count++;
}

void Phonebook::displayContacts(int i) {
    std::cout << std::right << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First name" << " | "
              << std::setw(10) << "Last name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    // for (int i = 0; i < this->count; i++) {
        std::cout << std::right << std::setw(10) << i << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_firstname().length() > 10 ? this->contacts[i].get_firstname().substr(0, 9) + '.' : this->contacts[i].get_firstname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_lastname().length() > 10 ? this->contacts[i].get_lastname().substr(0, 9) + '.' : this->contacts[i].get_lastname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_nickname().length() > 10 ? this->contacts[i].get_nickname().substr(0, 9) + '.' : this->contacts[i].get_nickname())
                  << std::endl;
    // }
}

void	Phonebook::search() {
    std::string input;
    int i;

	std::cout << "Choose a num between 1 and 8 " << std::endl;
    std::getline(std::cin, input);
    i = std::stoi(input);
    if (i >= 0 && i < 8)
        displayContacts(i);
    else
        std::cout << "Wrong number" << std::endl;
}