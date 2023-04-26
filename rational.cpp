#include "rational.h"
#include <iostream>

Rational::Rational(int num, int den) : num_(num) {
    if (den) {
        den_ = den;
    } else {
        den_ = 1;
    }
}

//void Rational::set(int num, int den) {
//    num_ = num;
//    if (den) {
//        den_ = den;
//    }
//}

//int Rational::num() const {
//    return num_;
//}

//int Rational::den() const {
//    return den_;
//}

//void Rational::set_num(int num) {
//    num_ = num;
//}

//void Rational::set_den(int den) {
//    if (den) {
//        den_ = den;
//    }
//}

Rational Rational::operator+(const Rational &rhs) const {
    return Rational(num_ * rhs.den_ + rhs.num_ * den_,
                    den_ * rhs.den_);
}

Rational Rational::operator-(const Rational &rhs) const {
    return Rational(num_ * rhs.den_ - rhs.num_ * den_,
                    den_ * rhs.den_);
}

Rational Rational::operator*(const Rational &rhs) const{
    return Rational(num_ *rhs.num_, den_*rhs.den_);
}
void Rational::print() const {
    if (den_ == 1) {
        std::cout << num_;
    } else {
        std::cout << num_ << "/" << den_<<std::endl;
    }
}

std::ostream &operator<<(std::ostream &str, Rational &rhs){
    if (rhs.den_ == 1) {
        str << rhs.num_;
    } else {
        str << rhs.num_ << "/" << rhs.den_;
    }
    return str;
}

std::istream &operator>>(std::istream& str, Rational& rhs) {
    std::string input;
    str >> input; //value inputed stored in a string first

    std::size_t index = input.find("/"); //searching for index of / sign is rational else it is a normal number
    if (index == -1) { // if index -1 no slash
        rhs.num_ = std::stoi(input); //converting string to intiger
        rhs.den_ = 1;
    } else {
        rhs.num_ = std::stoi(input.substr(0, index));
        rhs.den_ = std::stoi(input.substr(index + 1));
    }

    return str;
}
