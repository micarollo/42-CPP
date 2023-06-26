#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    return ;
}

Zombie::~Zombie() {
    std::cout << this->get_name() << " has been destroyed." << std::endl;
}

const std::string& Zombie::get_name(){
    return (this->name);
}

void Zombie::announce(void) {
    std::cout << this->get_name() << "BraiiiiiiinnnzzzZ..." << std::endl;
}