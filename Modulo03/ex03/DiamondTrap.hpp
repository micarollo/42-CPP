#ifndef DIAMOND_TRAPP
#define DIAMOND_TRAPP

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
        DiamondTrap(void);

    public:
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & cp);
        ~DiamondTrap(void);
        DiamondTrap &operator=(const DiamondTrap &diamondtrap);
        
        std::string	getDiamondName( void ) const;

        void attack(const std::string &target);
        void whoAmI(void);
};

#endif