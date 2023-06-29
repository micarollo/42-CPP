#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string _name;
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _attack;

public:
    ClapTrap(std::string name);
    ~ClapTrap(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
