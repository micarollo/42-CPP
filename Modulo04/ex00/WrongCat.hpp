#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string.h>
#include "Animal.hpp"

class WrongCat : public Animal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat &cp);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &cat);
        void makeSound(void) const;
};

#endif