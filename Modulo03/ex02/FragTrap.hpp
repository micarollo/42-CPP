#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        FragTrap(void);

    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const & cp);
        ~FragTrap(void);
        FragTrap &operator=(const FragTrap &fragtrap);
        void highFiveGuys(void);
};

#endif