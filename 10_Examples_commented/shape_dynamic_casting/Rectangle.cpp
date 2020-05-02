#include "Rectangle.h"

#include <iostream>
#include <string>
using namespace std;

Rectangle::Rectangle(string S_name, int len, int wid)
            : Shape(S_name), length(len), width(wid){}

int Rectangle::getLength(){
    return this->length;
}

int Rectangle::getWidth(){
    return this->width;
}

/*void Rectangle::get_info(){
    cout << "Area of the Rectangle is: " << getLength() * getWidth() << endl;
}*/