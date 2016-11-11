/* 
 * File:   Rational.h
 * Author: Jacob Abbott
 *
 * Created on November 13, 2015, 8:12 AM
 */

#ifndef RATIONAL_H
#define RATIONAL_H
#include <string>
#include <iostream>

namespace CS1124{
    class Rational {
        friend std::ostream& operator <<(std::ostream &os, const Rational& rhs);
        friend std::istream& operator >>(std::istream &is, Rational& rhs);
        friend bool operator ==(Rational& lhs , Rational& rhs);
        friend bool operator ==(int lhs , Rational& rhs);
    public:
        Rational(int numerator = 1, int denominator = 1);
        void normalize();
        Rational operator +=(Rational& rhs);
        Rational operator ++();
        Rational operator ++(int);
        
    private:
        int num;
        int denom;
    };
    
    Rational operator +(Rational& lhs, Rational& rhs);
    bool operator !=( Rational& lhs, Rational& rhs);
    Rational& operator --(Rational& lhs);
    Rational operator --(Rational& lhs , int);
    int greatestCommonDivisor(int x, int y);
}

#endif /* RATIONAL_H */

