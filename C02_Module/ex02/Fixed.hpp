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
        ~Fixed();
        //Setters/Getters
        int  getRawBits(void) const;
        void  setRawBits(int const raw);
        //Modified constructors
        Fixed(int const num);
        Fixed(float const num);
        //Conversions
        float   toFloat(void) const;
        int     toInt(void) const;
        //Operators
        Fixed& operator = (const Fixed& other);
        bool operator == (const Fixed& other);
        bool operator != (const Fixed& other);
        bool operator < (const Fixed& other);
        bool operator > (const Fixed& other);
        bool operator >= (const Fixed& other);
        bool operator <= (const Fixed& other);
        //Arithmetic operators
        float operator * (const Fixed& other);
        float operator / (const Fixed& other);
        float operator + (const Fixed& other);
        float operator - (const Fixed& other);
        //Increment/Decrement operators
        Fixed& operator --(void);
        Fixed& operator ++(void);
        Fixed operator ++(int);
        Fixed operator --(int);
        //Max/Min functions
        static Fixed& min (Fixed& one, Fixed& two);
        static Fixed& max (Fixed& one, Fixed& two);
        static const Fixed& min (const Fixed& one, const Fixed& two);
        static const Fixed& max (const Fixed& one, const Fixed& two);

    private:
        int _value;
        static const int _fractionalBits;
};

std::ostream&   operator<<(std::ostream& os, const Fixed& fixed);

#endif