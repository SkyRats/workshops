#include "Square.h"

#include <iostream>
#include <string>
using namespace std;

Square::Square(string S_name, int value)
            : Shape(S_name), side(value){}

int Square::getSide(){
    return this->side;
}

void Square::get_info(){
    cout << "Area of the Square is: " << getSide() * getSide() << endl;
}