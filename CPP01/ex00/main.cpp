#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *a;

    a = newZombie("Mica");
    a->announce();
    randomChump("rollo");
    delete(a);
}
