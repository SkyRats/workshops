#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int w, int h) : Shape(w, h){
    this->width = w;
    this->height = h;
}

void Rectangle::area(){ 
    cout << "Rectangle area: " << getWidth() * getHeight() << endl;
}