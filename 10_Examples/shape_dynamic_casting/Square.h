#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

#include <string>
using namespace std;

class Square : public Shape{
    private:
        int side;

    public:
        Square(string S_name, int value);

        int getSide();

        void get_info();
};

#endif // SQUARE_H