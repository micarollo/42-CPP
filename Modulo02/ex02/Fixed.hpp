#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private: 
        int _raw;
        static const int _fb = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &fixed);
        Fixed(const int n);
        Fixed(const float f);
        ~Fixed();

        Fixed &operator=(const Fixed&fixed);
        bool operator>(const Fixed&fixed) const;
        bool operator<(const Fixed&fixed) const;
        bool operator>=(const Fixed&fixed) const;
        bool operator<=(const Fixed&fixed) const;
        bool operator==(const Fixed&fixed) const;
        bool operator!=(const Fixed&fixed) const;

        Fixed operator+(const Fixed&fixed) const;
        Fixed operator-(const Fixed&fixed) const;
        Fixed operator*(const Fixed&fixed) const;
        Fixed operator/(const Fixed&fixed) const;

        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif