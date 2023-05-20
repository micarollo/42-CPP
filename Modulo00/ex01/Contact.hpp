#include <iostream>

class Contact {
private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenum;
    std::string darksecret;

public:
    void    set_firstname(std::string firstName);
    void    set_lastname(std::string lastName);
    void    set_nickname(std::string nickName);
    void    set_phonenum(std::string phoneNum);
    void    set_darksecret(std::string darkSecret);
};