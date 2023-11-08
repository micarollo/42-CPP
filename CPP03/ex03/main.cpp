#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d2("d2");
    DiamondTrap d3("d3");
    
    d2.whoAmI();
    
    d2 = d3;
    
    d2.whoAmI();
    d3.whoAmI();
}