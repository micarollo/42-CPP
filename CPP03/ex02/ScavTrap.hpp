#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &cp);
        virtual ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &scavtrap);
        void attack(const std::string& target);
        void        guardGate();

    private:
        ScavTrap(void);
};

#endif