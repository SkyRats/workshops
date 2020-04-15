#ifndef SHAPE_H
#define SHAPE_H

class Shape {
   protected:
      int width, height;
      
   public:
      Shape(int width, int height);

      void setWidth(int w);
      int getWidth();
      void setHeight(int h);
      int getHeight();

      void area();
};

#endif //SHAPE_H