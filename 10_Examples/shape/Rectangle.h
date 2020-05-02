#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle: public Shape {
   public:
      Rectangle(int w, int h); // mandatory constructor

      void area();
};

#endif // RECTANGLE_H