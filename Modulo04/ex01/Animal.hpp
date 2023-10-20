#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string.h>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal &cp);
        virtual ~Animal();

        Animal &operator=(const Animal &animal);
        
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif