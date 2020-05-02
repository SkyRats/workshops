#include "Shape.h"
#include "Square.h"
#include "Rectangle.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    Shape *quadrilateral = new Shape("Quadliteral");
    // Trying to downcast the parent class pointer to
    // the child class pointer.

    Square *sq = dynamic_cast<Square*>(quadrilateral);

    if(sq == NULL){
        cout << "Invalid casting." << endl;
        cout << sq << endl;
    }
    // dynamic_cast returns returns null if the type
    // to be casted into is a pointer and the cast
    // is unsuccessful.

    Rectangle *rect = new Rectangle("rectangle", 4, 5);
    rect->get_info();

    // An example of a valid upcasting
    Shape *rt = dynamic_cast<Shape*>(rect);
    rt->get_info();
    
    // An example of invalid downcasting
    Square* sq1 = dynamic_cast<Square*>(rt);

    if(sq1 == NULL){
        cout << sq1 << endl;
        cout << "Invalid casting." << endl;
    }

    return 0;
}