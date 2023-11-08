#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon clubb = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.attack();
    clubb.setType("some other type of club");
    jim.attack();

    Weapon clubbb = Weapon("crude spiked club");
    HumanB mica("Mica");
    mica.setWeapon(clubbb);
    mica.attack();
    clubbb.setType("some other type of club");
    mica.attack();
}