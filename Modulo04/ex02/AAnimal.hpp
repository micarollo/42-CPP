#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>
#include <string.h>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal (void);
        AAnimal (std::string type);
        AAnimal (const AAnimal &cp);
        virtual ~AAnimal();

        AAnimal &operator=(const AAnimal &animal);
        
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif