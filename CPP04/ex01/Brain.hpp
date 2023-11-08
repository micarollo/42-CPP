#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain(void);
        ~Brain(void);
        Brain(Brain const &cp);

        Brain &operator=(Brain const &brain);

        std::string getIdeas(int i) const;
        void setIdeas(int i, std::string idea);
    
    protected:
        std::string _ideas[100];
};

#endif