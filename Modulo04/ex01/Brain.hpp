#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string.h>

class Brain
{
    public:
        Brain(void);
        ~Brain(void);
        Brain(const Brain &cp);
        Brain & operator=(Brain const &brain);
    protected:
        std::string _ideas[100];
};

#endif