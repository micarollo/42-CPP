#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string name) {
            this->name = name;
        }

    void announce() {
        std::cout << name << "BraiiiiiiinnnzzzZ..." << std::endl;
    }

    ~Zombie() {
      std::cout << name << " has been destroyed." << std::endl;
    }
};