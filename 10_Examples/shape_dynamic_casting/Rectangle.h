#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

#include <string>
using namespace std;

class Rectangle : public Shape{
    private:
        int length;
        int width;

    public:
        Rectangle(string S_name, int len, int wid);

        int getLength();
        int getWidth();

        void get_info();
};

#endif // RECTANGLE_H