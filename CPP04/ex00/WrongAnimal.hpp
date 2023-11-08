#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string.h>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &cp);
        ~WrongAnimal();
        
        WrongAnimal &operator=(const WrongAnimal &wronganimal);
        
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif