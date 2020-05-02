#include "Shape.h"
#include <iostream>

using namespace std;
 
Shape::Shape(int width, int height) : width (width), height (height){
}

void Shape::area(){
   cout << "Shape area: " << getWidth() * getHeight() << endl;
}

void Shape::setWidth(int w){
   this->width = w;
}

int Shape::getWidth(){
   return this->width;
}

void Shape::setHeight(int h){
   this->height = h;
}
int Shape::getHeight(){
   return this->height;
}