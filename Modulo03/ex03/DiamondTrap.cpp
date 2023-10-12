#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap constructor called" << std::endl;
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
    this->_name = diamondtrapp.getDiamondName();
    this->ClapTrap::_name = diamondtrapp.getName();
	this->_hit = diamondtrapp.getHit();
	this->_energy = diamondtrapp.getEnergy();
	this->_attack = diamondtrapp.getAttack();
    return (*this);
}

void DiamondTrap::attack(const std::string &target) 
{
    this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "my name is: " << this->_name << std::endl;
    std::cout << "my name is: " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getDiamondName(void) const
{
    return (this->_name);
}