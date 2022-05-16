#include <iostream>
#include "A.h"

using namespace std;

A::A(string nombre_, int edad_){
    nombre=nombre_;
    edad=edad_;
}
void A::operator>(A d){
    cout<<"Su nombre es :"<<nombre<<endl;
    cout<<"Su edad es : "<<edad<<endl;
}