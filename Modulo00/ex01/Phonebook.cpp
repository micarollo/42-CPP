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

void    Phonebook::set_total(int total)  {
    this->total = total;
};

int    Phonebook::get_total(void)  {
    return (this->total);
};

static std::string get_input(std::string text) {
    std::string	input;

    input = "";
    while (input == "")
    {
        std::cout << text << ": ";
        std::getline(std::cin, input);
        if (!std::cin)
            exit (1);
    }
    return (input);
}

void	Phonebook::add_contact() {
	std::string	input;

	if (this->count == 8)
		this->count = 0;
    if (this->total < 8)
        this->total++;
    this->contacts[count].set_firstname(get_input("First name"));
    this->contacts[count].set_lastname(get_input("Last name"));
    this->contacts[count].set_nickname(get_input("Nickname"));
    this->contacts[count].set_phonenum(get_input("Phone number"));
    this->contacts[count].set_darksecret(get_input("Darkest secret"));
	this->count++;
}

void Phonebook::displayContacts() {
    std::cout << std::right << std::setw(10) << "Index" << " | "
              << std::setw(10) << "First name" << " | "
              << std::setw(10) << "Last name" << " | "
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    for (int i = 0; i < this->total; i++) {
        std::cout << std::right << std::setw(10) << i + 1 << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_firstname().length() > 10 ? this->contacts[i].get_firstname().substr(0, 9) + '.' : this->contacts[i].get_firstname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_lastname().length() > 10 ? this->contacts[i].get_lastname().substr(0, 9) + '.' : this->contacts[i].get_lastname())
                  << " | "
                  << std::setw(10) << std::left << (this->contacts[i].get_nickname().length() > 10 ? this->contacts[i].get_nickname().substr(0, 9) + '.' : this->contacts[i].get_nickname())
                  << std::endl;
    }
}

// void Phonebook::searchContact(int i) {
//     std::cout << std::right << std::setw(10) << "Index" << " | "
//                 << std::setw(10) << "First name" << " | "
//                 << std::setw(10) << "Last name" << " | "
//                 << std::setw(10) << "Nickname" << std::endl;
//     std::cout << std::string(50, '-') << std::endl;
//     std::cout << std::right << std::setw(10) << i + 1<< " | "
//                 << std::setw(10) << std::left << (this->contacts[i].get_firstname().length() > 10 ? this->contacts[i].get_firstname().substr(0, 9) + '.' : this->contacts[i].get_firstname())
//                 << " | "
//                 << std::setw(10) << std::left << (this->contacts[i].get_lastname().length() > 10 ? this->contacts[i].get_lastname().substr(0, 9) + '.' : this->contacts[i].get_lastname())
//                 << " | "
//                 << std::setw(10) << std::left << (this->contacts[i].get_nickname().length() > 10 ? this->contacts[i].get_nickname().substr(0, 9) + '.' : this->contacts[i].get_nickname())
//                 << std::endl;
// }

void Phonebook::searchContact(int i) {
    std::cout << "First name: " << this->contacts[i].get_firstname() << std::endl;
    std::cout << "Last name: " << this->contacts[i].get_lastname() << std::endl;
    std::cout << "Nickname: " << this->contacts[i].get_nickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[i].get_phonenum() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[i].get_darksecret() << std::endl;
}

int	Phonebook::search() {
    std::string input;
    int i;

    i = this->get_total();
    if (i == 0)
    {
        std::cout << "Empty Phonebook" << std::endl;
        return (0);
    }
    displayContacts();
	std::cout << "Choose a num between 1 and 8 " << std::endl;
    std::getline(std::cin, input);
    if (!std::cin)
        return (1);
    while (atoi(input.c_str()) < 1 || atoi(input.c_str()) > i || input.length() > 1)
    {
        std::cout << "Wrong number" << std::endl;
        std::cout << "Choose a num between 1 and 8 " << std::endl;
        std::getline(std::cin, input);
        if (!std::cin)
            return (1);
    }
    searchContact(atoi(input.c_str()) - 1);
    return (0);
}