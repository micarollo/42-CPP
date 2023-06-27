#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type);
    ~Weapon(void);
    std::string getType(void);
    void setType(std::string type);
};

#endif