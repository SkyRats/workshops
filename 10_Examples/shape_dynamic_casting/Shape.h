#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape{
  private:
    string s_name;

  public:
    Shape(string name);
    
    string getName();

    virtual void get_info();
};

#endif // SHAPE_H