#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string.h>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(const Cat &cp);
        ~Cat();
        Cat &operator=(const Cat &cat);
        void makeSound(void) const;
    private:
        Brain*  _brain;
};

#endif