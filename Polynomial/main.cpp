#include "Polynomial.h"
#include <iostream>

int main()
{
    using namespace std;
    using namespace Poly;

    cout << "Welcome! " << endl;
    cout << "We will do some Polynomial calculations. " << endl;
    cout << "Here we go!" << endl;
    cout << "Please input the number of polynomials for the first(q to quit): " ;

    int k1;
    cin >> k1;
    while (cin)
    {
        Polynomial t1(k1);
        cout << "Now the number of the second polynomial: ";
        int k2;
        cin >> k2;
        Polynomial t2(k2);

        cout << "Here is the calculating result: " << endl;
        cout << "Addition operation: " << endl;
        cout << (t1 + t2) << endl;
        cout << "And Subtraction: " << endl;
        cout << (t1 - t2) << endl;
        cout << "Then Multiplication operation, " << endl;
        cout << (t1 * t2) << endl;
        cout << "Done!" << endl; 

        cout << "Then let us do next(q to quit): ";
        cin >> k1;
    }

    cout << "Bye!" << endl;

    return 0;
}