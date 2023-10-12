#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->_name = name;
    this->_hit = 100;
    this->_energy = 100;
    this->_attack = 30;
}

FragTrap::FragTrap(const FragTrap &cp)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = cp;
    return ;
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}

FragTrap &FragTrap::operator=(FragTrap const &fragtrap)
{
    this->_name = fragtrap.getName();
	this->_hit = fragtrap.getHit();
	this->_energy = fragtrap.getEnergy();
	this->_attack = fragtrap.getAttack();
    return (*this);
}

void FragTrap::attack(const std::string &target) {
    if (this->_energy > 0)
    {
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_hit << " points of damage." << std::endl;
        this->_energy--;
    }
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap ask you high five" << std::endl;
    return ;
}