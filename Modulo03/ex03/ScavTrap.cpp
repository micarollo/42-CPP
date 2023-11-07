#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_name = name;
    this->_hit = 100;
    this->_energy = 50;
    this->_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap &cp) : ClapTrap(cp)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = cp;
    return ;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "SacavTrap destructor called" << std::endl;
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &scavtrap)
{
    this->_name = scavtrap.getName();
	this->_hit = scavtrap.getHit();
	this->_energy = scavtrap.getEnergy();
	this->_attack = scavtrap.getAttack();
    return (*this);
}

void ScavTrap::attack(const std::string &target) {
    if (this->_energy > 0 || this->_hit > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_hit << " points of damage." << std::endl;
        this->_energy--;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout << "SacavTrap is now in gate keeper mode" << std::endl;
}
