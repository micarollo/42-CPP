#include "Fixed.hpp"

Fixed::Fixed(void) : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_raw = n << this->_fb;
}

Fixed::Fixed(float f)
{
    std::cout << "Foat constructor called" << std::endl;
    this->_raw = (int)roundf( f * (1 << this->_fb));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Assignation operator called" << std::endl;
    this->_raw = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}

int Fixed::toInt(void) const
{
    return((int)(roundf((float)_raw / (1 << _fb))));
}

float Fixed::toFloat(void) const
{
    return ((float)_raw / (1 << _fb));
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return (o);
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->_raw > fixed._raw);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->_raw < fixed._raw);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->_raw >= fixed._raw);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->_raw <= fixed._raw);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->_raw == fixed._raw);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->_raw != fixed._raw);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    (this->_raw)++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    (this->_raw)--;
    return (*this);
}

Fixed Fixed::operator++(int n)
{
    Fixed aux = *this;
    if (n < 0)
    {
        while (n <=0)
        {
            --*this;
            n++;
        }
    }
    else
    {
        while(n >= 0)
        {
            ++*this;
            n--;
        }
    }
    return (aux);
}

Fixed Fixed::operator--(int n)
{
    Fixed aux = *this;
    if (n < 0)
    {
        while (n <=0)
        {
            ++*this;
            n++;
        }
    }
    else
    {
        while(n >= 0)
        {
            --*this;
            n--;
        }
    }
    return (aux);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix2);
    return (fix1);
}

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix2);
    return (fix1);
}

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
    if (fix1 > fix2)
        return (fix1);
    return (fix2);
}