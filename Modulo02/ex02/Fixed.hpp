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

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &fix1, Fixed &fix2);
        static Fixed &max(Fixed &fix1, Fixed &fix2);
        static const Fixed &min(const Fixed &fix1, const Fixed &fix2);
        static const Fixed &max(const Fixed &fix1, const Fixed &fix2);

        int getRawBits(void) const;
        void setRawBits(const int raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif