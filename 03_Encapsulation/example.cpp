#include <iostream>
using namespace std;

class Employee {
  private:
    int salary; // The salary attribute is private, which have restricted access.

  public:
    void setSalary(int s) {
      salary = s; 
      // The public setSalary() method takes a parameter (s) and 
      // assigns it to the salary attribute (salary = s).
    }
    int getSalary() {
      return salary; 
      // The public getSalary() method returns the value of 
      // the private salary attribute.
    }
};

// Inside main(), we create an object of the Employee class. 
// Now we can use the setSalary() method to set the value of the 
// private attribute to 50000. Then we call the getSalary() 
// method on the object to return the value.

int main() {
  Employee* MrFeather = new Employee();

  MrFeather->setSalary(50000);
  cout << MrFeather->getSalary() << endl;

  return 0;
}