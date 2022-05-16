#ifndef A_H_INCLUDED
#define A_H_INCLUDED
#include <iostream>
using namespace std;
class A{
    private:
        string nombre;
        int edad;

    public:

        A(string nombre, int edad);
        void operator>(A d);


};

#endif // A_H_INCLUDED
