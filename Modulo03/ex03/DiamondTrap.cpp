#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cp)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = cp;
    return ;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called" << std::endl;
    return ;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &diamondtrapp)
{
    this->_name = diamondtrapp.getName();
    this->ClapTrap::_name = diamondtrapp.getName() + "_clap_name";
	this->_hit = diamondtrapp.getHit();
	this->_energy = diamondtrapp.getEnergy();
	this->_attack = diamondtrapp.getAttack();
    return (*this);
}

void DiamondTrap::attack(const std::string &target) {
    if (this->_energy > 0)
    {
        std::cout << "DiamondTrap " << this->_name << " attacks " << target << ", causing " << this->_hit << " points of damage." << std::endl;
        this->_energy--;
    }
}