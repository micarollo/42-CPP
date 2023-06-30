#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    clap1("ClapOne");
    ClapTrap    clap2("ClapTwo");

    clap1.attack("ClapTwo");
    clap2.takeDamage(10);
    clap2.beRepaired(30);
}