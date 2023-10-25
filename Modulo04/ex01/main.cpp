#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
   Animal *animals[6];

    //crear array
   for (int i = 0; i < 6; i++)
   {
    if (i < 3)
        animals[i] = new Cat();
    else
        animals[i] = new Dog();
   }

    //sound 
   for (int i = 0; i < 6; i++)
   {
    animals[i]->makeSound();
   }

   // delete
   for (int i = 0; i < 6; i++)
   {
    delete animals[i];
   }

    std::cout << "" << std::endl;
    Cat *cat = new Cat();
    std::cout << "ADD ONE THOUGHT" << std::endl;
	cat->getBrain().setIdeas(1, "pensamiento 1");
    Cat *cat2 = new Cat(*cat);
    cat->getBrain().setIdeas(1, "solo cambio yo");
    std::cout << cat->getBrain().getIdeas(1) << std::endl;
    std::cout << cat2->getBrain().getIdeas(1) << std::endl;
}