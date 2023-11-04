#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
public:
    Span(unsigned int n);
    Span(Span const &cp);
    ~Span(void);

    Span &operator=(const Span &src);

    void addNumber(int n);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class MaxException : public std::exception
    {
    public:
        virtual const char *    what() const throw();
    };

    class MinException : public std::exception
    {
    public:
        virtual const char *    what() const throw();
    };

private:
    std::vector<int> 	_arr;
    unsigned int	    _n;
    Span( void );
};

#endif