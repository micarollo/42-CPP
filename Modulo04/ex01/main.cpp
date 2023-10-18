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
}