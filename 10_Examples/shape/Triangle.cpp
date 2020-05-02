#include "Triangle.h"
#include <iostream>

using namespace std;

Triangle::Triangle(int w, int h) : Shape(w, h){
    this->width = w;
    this->height = h;
}
      
void Triangle::area() { 
    cout << "Triangle class area: " << 
        (getWidth() * getHeight()) / 2 << endl;
}