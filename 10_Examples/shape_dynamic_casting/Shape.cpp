#include "Shape.h"

#include <iostream>
#include <string>
using namespace std;

Shape::Shape(string name): s_name(name){}

string Shape::getName(){
    return s_name;
}

/*void Shape::get_info(){
    cout << getName() << endl;
}*/