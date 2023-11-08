#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap	instanceC("Clap");
	ScavTrap	instanceS("Scav");

	std::cout << std::endl;
	
	std::cout << instanceC.getName() << std::endl;
	std::cout << "Hitpoints: " << instanceC.getHit() << std::endl;
	std::cout << "Energy Points: " << instanceC.getEnergy() << std::endl;
	std::cout << "Attack Damage: "<< instanceC.getAttack() << std::endl;
	instanceC.attack("Enemy");
	//	instanceC.guardGate();

	std::cout << std::endl;

	std::cout << instanceS.getName() << std::endl;
	std::cout << "Hitpoints: " << instanceS.getHit() << std::endl;
	std::cout << "Energy Points: " << instanceS.getEnergy() << std::endl;
	std::cout << "Attack Damage: "<< instanceS.getAttack() << std::endl;
	instanceS.attack("Enemy");
	instanceS.guardGate();

	std::cout << std::endl;
	
	return (0);
}