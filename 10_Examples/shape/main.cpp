#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

int main() {
   Shape* shape;

   Rectangle* rec = new Rectangle(10,7);
   Triangle* tri = new Triangle(10,5);

   rec->area();
   tri->area();

   shape = dynamic_cast<Shape*>(tri);
   shape->area();

   return 0;
}