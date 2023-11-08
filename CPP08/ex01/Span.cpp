#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
    return ;
}

Span::Span(Span const &cp) : _arr(cp._arr), _n(cp._n)
{
    *this = cp;
}

Span::~Span(void)
{
    return ;
}

Span &Span::operator=(Span const &src)
{
    if ( this == &src)
        return (*this);
    _n = src._n;
    _arr = src._arr;
    return (*this);
}

void Span::addNumber(int n)
{
	if (_arr.size() == _n)
		throw Span::MaxException();
	_arr.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end) 
    {
        addNumber(*begin);
        ++begin;
    }
}

int Span::shortestSpan() const
{
    if (_arr.size() < 2)
        throw Span::MinException();
    std::vector<int> copy = _arr;
    std::sort(copy.begin(), copy.end());
    int min = copy[1] - copy[0];
    for (size_t i = 2; i < copy.size(); i++)
    {
        int sp = copy[i] - copy[i - 1];
        if (sp < min)
            min = sp;
    }
    return (min);
}

int Span::longestSpan() const
{
    if (_arr.size() < 2)
        throw Span::MinException();
    std::vector<int> copy = _arr;
    std::sort(copy.begin(), copy.end());
    int max = copy[copy.size() - 1] - copy[0];
    return max;
}

const char *	Span::MaxException::what() const throw()
{
	return ("Max elements");
}

const char *	Span::MinException::what() const throw()
{
	return ("Min elements needed");
}