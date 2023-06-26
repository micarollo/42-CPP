#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name){
}

Zombie::Zombie(void) {
    return ;
}

Zombie::~Zombie() {
    std::cout << this->_name << " has been destroyed." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name) {
    this->_name = name;
}