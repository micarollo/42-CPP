#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private: 
        int _raw;
        static const int _fb = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed &fixed);
        Fixed &operator=(const Fixed&fixed);
        int getRawBits(void) const;
        void setRawBits(const int raw);
};

#endif