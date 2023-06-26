#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {
    return ;
}

Contact::~Contact(void) {
    return ;
}

void    Contact::set_firstname(std::string firstName)  {
    this->firstname = firstName;
};

void    Contact::set_lastname(std::string lastName)  {
    this->lastname = lastName;
};

void    Contact::set_nickname(std::string nickName)  {
    this->nickname = nickName;
};

void    Contact::set_phonenum(std::string phoneNum)  {
    this->phonenum = phoneNum;
};

void    Contact::set_darksecret(std::string darkSecret)  {
    this->darksecret = darkSecret;
};

const std::string&    Contact::get_firstname() {
    return (this->firstname);
};

const std::string&    Contact::get_lastname() {
    return (this->lastname);
};

const std::string&    Contact::get_nickname() {
    return (this->nickname);
};

const std::string&    Contact::get_phonenum() {
    return (this->phonenum);
};

const std::string&    Contact::get_darksecret() {
    return (this->darksecret);
};