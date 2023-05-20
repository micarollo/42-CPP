#include <iostream>
#include "Contact.hpp"

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