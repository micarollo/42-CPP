#include <iostream>
#include "Phonebook.hpp"

int main() {
    std::string	input;
    Phonebook phonebook;

    while (1) {
        std::cout << "Choose 1 option: ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input.compare("ADD") == 0)
            phonebook.add_contact();
        else if (input.compare("SEARCH") == 0)
            phonebook.search();
        else if (input.compare("EXIT") == 0)
            return (0);
        else
            std::cout << "Wrong option" << std::endl;
    }
}