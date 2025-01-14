#ifndef FIXED_HPP
#define FIXED_CPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        //Orthodox Canonical Form
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator = (const Fixed& other);
        ~Fixed();
        //Setters/Getters
        int  getRawBits(void) const;
        void  setRawBits(int const raw);
        //New
        Fixed(int const num);
        Fixed(float const num);
        float   toFloat(void) const;
        int     toInt(void) const;
    private:
        int _value;
        static const int _fractionalBits;
};

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);

#endif