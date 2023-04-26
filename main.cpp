#include <iostream>
#include "rational.cpp"
#include "rational.h"

using namespace std;

int main()
{
    Rational a(1, 5);
    Rational b(1, 6);
    cin>>b;

    Rational add_result, sub_result ,multip_result;
    add_result = a + b;
    sub_result = a - b;
    multip_result= a * b;
    add_result.print();
    sub_result.print();
    multip_result.print();
    return 0;
}
