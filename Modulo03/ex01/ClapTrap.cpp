#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0) {
    std::cout << "Constructor called" << std::endl;
    return ;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_energy > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_hit << " points of damage." << std::endl;
        this->_energy -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hit >= amount)
        this->_hit -= amount;
    else
        this->_hit = 0;
    std::cout << "ClapTrap " << this->_name << " was attacked with " << amount << " points. Now it has " << this->_hit << " hit points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_energy > 0)
    {
        this->_energy -= 1;
        this->_hit += amount;
        std::cout << "ClapTrap " << this->_name << " repairs itself. Now has " << this->_hit << " points." << std::endl;
    }
}