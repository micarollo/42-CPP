#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack(void) {}
    MutantStack(MutantStack const &cp) : std::stack<int>(cp)
    {
        *this = cp;
        return ;
    }
    ~MutantStack(void) {}

    MutantStack & operator=( MutantStack const & rhs )
    {
        std::stack<T>::operator=(rhs);
        return (*this);
    }

    typedef typename MutantStack<T>::stack::container_type::iterator iterator;
    iterator begin( void ) {return this->c.begin();}
    iterator end( void ) {return this->c.end();}
};

#endif