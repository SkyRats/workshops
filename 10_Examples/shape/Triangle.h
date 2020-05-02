#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle: public Shape {
   public:
      Triangle(int w, int h);
      
      void area();
};

#endif // TRIANGLE_H