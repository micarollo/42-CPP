#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap fragtrap("frag1");
    ScavTrap scavtrap("scav1");

    scavtrap.attack("human");
    scavtrap.guardGate();
    fragtrap.attack("another human");
    fragtrap.highFiveGuys();
    fragtrap.takeDamage(30);
    fragtrap.beRepaired(30);
    fragtrap.takeDamage(60);    
}