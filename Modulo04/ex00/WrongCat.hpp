#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string.h>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat &cp);
        virtual ~WrongCat();
        
        WrongCat &operator=(const WrongCat &wrongcat);
        void makeSound(void) const;
};

#endif