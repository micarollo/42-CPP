#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const & cp);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &fragtrap);
        void attack(const std::string &target);
        void highFiveGuys(void);

    private:
        FragTrap(void);
};

#endif