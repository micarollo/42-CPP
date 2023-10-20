#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &cp)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = cp;
}

Brain & Brain::operator=(Brain const & brain)
{
    int i;

    i = 0;
    while (i < 100)
    {
        this->_ideas[i] = brain.getIdeas(i);
        i++;
    }
    return (*this);
}

std::string Brain::getIdeas(int i) const
{
    if (i >= 0 && i <= 99)
        return (this->_ideas[i]);
    else
        return ("");
}

void Brain::setIdeas(int i, std::string idea)
{
    if (i >= 0 && i <= 99)
        this->_ideas[i] = idea;
    return ;
}