#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *horde;
    horde = zombieHorde(3, "Mica");
    for (int i = 0; i < 3; i++)
        horde->announce();
    delete[] horde;

    horde = zombieHorde(5, "rollo");
    for (int i = 0; i < 5; i++)
        horde->announce();
    delete[] horde;
}
