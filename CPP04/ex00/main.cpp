#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "" << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "" << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "" << std::endl;

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* meta1 = new WrongAnimal();
    const WrongAnimal* j1 = new WrongCat();
    std::cout << j1->getType() << " " << std::endl;
    j1->makeSound();
    meta1->makeSound();
    return 0;
}