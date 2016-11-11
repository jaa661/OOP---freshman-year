/* 
 * File:   Rational.cpp
 * Author: Jacob Abbott
 * 
 * Created on November 13, 2015, 8:12 AM
 */

#include "Rational.h"
#include <string>
#include <iostream>

namespace CS1124{
    Rational::Rational(int numerator, int denominator) : num(numerator), denom(denominator) {}
 
    std::ostream& operator <<(std::ostream &os, const Rational& rhs){
        if (rhs.denom == 0)
            os << "sorry but this is undefined";
        else if(rhs.denom == 1)
            os << rhs.num;
        else if(rhs.num == 0)
            os << "0";
        else 
            os << rhs.num << "/" << rhs.denom;
        return os;
    }
    std::istream& operator >>(std::istream &is, Rational& rhs){
        /*char firstChar;
        char secondChar;
        is >> firstChar;
        if (firstChar == '-'){
            is >> firstChar;
            rhs.num = (0 - firstChar);
        }
        else
            rhs.num = firstChar;
        is >> secondChar;
        if (secondChar == 0){
            std::cerr << " I'm sorry dave, but I can't let you do that\n";
            exit(1);
        } 
        else if (secondChar == '-'){
            is >> secondChar;
            rhs.num = (0 - secondChar);
        }
        else
            rhs.num = secondChar;*/
        char divide;
        is >> rhs.num >> divide >> rhs.denom ;
        rhs.normalize();
        return is;
    }    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    void Rational::normalize() {
        if (denom < 0) {
            num *= -1;
            denom *= -1;
        }
        int gcd = greatestCommonDivisor(abs(num), abs(denom));
        num /= gcd;
        denom /= gcd;
    }
    Rational Rational::operator +=( Rational& rhs){
        num = (num * rhs.denom) + (rhs.num * denom);
        denom = (denom * rhs.denom);
        normalize();
        return *this;
    }// a += b   or   this.operator+=(rhs))
    Rational operator +(Rational& lhs, Rational& rhs){
        Rational left = lhs;
        lhs.operator+=(rhs);
        return lhs;
    }// a + b    or lhs + rhs
    bool operator ==(Rational& lhs , Rational& rhs) {
        lhs.normalize();
        rhs.normalize();
        return ((lhs.num == rhs.num) && (lhs.denom == rhs.denom));
    }// a == b
    bool operator ==(int lhs , Rational& rhs) {
        rhs.normalize();
        return ((lhs == rhs.num) && (rhs.denom == 1));
    }// a == b
    bool operator !=( Rational& lhs , Rational& rhs){
        return !(lhs == rhs);
    }
        Rational Rational::operator ++(){
        num = (num + denom);
        return *this;
    }
    Rational Rational::operator ++(int i){
        Rational tempRational(num, denom);
        num = (num + denom);
        return tempRational;
    }  
    Rational& operator --(Rational& lhs){
        Rational tempNegative(-1, 1);
        lhs += tempNegative;
        return lhs;
    }
    Rational operator --(Rational& lhs , int){
        Rational tempRational(lhs);
        Rational tempNegative(-1, 1);
        lhs += tempNegative;
        return tempRational;
    }

}