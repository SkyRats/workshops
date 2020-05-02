#ifndef SHAPE_H
#define SHAPE_H

class Shape {
   protected:
      int width, height;
      
   public:
      Shape(int width, int height);

      void setWidth(int w);
      void setHeight(int h);

      int getHeight();
      int getWidth();

      void area();
};

#endif //SHAPE_H