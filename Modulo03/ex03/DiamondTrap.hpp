#ifndef DIAMOND_TRAPP
#define DIAMOND_TRAPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ClapTrap, public FragTrap
{
    private:
        std::string _name;
        DiamondTrap(void);

    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & cp);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &diamondtrap);
        void attack(const std::string &target);
        void whoAmI(void);
};

#endif