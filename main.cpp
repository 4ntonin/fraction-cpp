#include <iostream>
#include "Fraction.h"
using namespace std;


int main()
{
    Fraction a(4,5);
    Fraction b(2);
    Fraction c,d;
    c = a+b;
    d = a*b;
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " * " << b << " = " << d << endl;
    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;
    return 0;
}
