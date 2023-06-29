#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <istream>
#include <string>

class ClapTrap {
private:
    std::string _name;
    int _hit;
    int _energy;
    int _attack;

public:
    ClapTrap(std::string name);
    ~ClapTrap(void);
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
}
