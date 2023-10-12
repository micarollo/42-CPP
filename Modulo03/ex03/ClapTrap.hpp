#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:
    std::string _name;
    unsigned int _hit;
    unsigned int _energy;
    unsigned int _attack;
    ClapTrap(void);

public:
    ClapTrap(std::string name);
    ~ClapTrap(void);
    ClapTrap(ClapTrap const &cp);
    ClapTrap &	operator=( ClapTrap const & claptrap );
    std::string	getName( void ) const;
	
    int			getHit( void ) const;
	int			getEnergy( void ) const;
	int			getAttack( void ) const;
    
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
