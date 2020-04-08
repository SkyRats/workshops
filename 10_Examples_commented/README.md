## 10 - Examples (commented)



1. The Following code shows how a class is defined in C++.

    ```c++
    #include <iostream>

    using namespace std;

    class Lamp {
        public:
            Lamp(); // constructor
            ~Lamp(); // destructor

            void turnOn();
            void turnOff();
            void print();
            
        private:
            bool on;
            double power;
    };
    ```

    Now let's see how the class' methods were implemented in this case.

    ```c++
    Lamp::Lamp(){
        on = false;
    }

    Lamp::~Lamp(){
        cout << "Lamp destructed" << endl;
    }

    void Lamp::turnOn() {
        on = true;
    }

    void Lamp::turnOff() {
        on = false;
    }

    void Lamp::print() {
        cout << on << endl;
    }

    ```

#### Useful Links

<a href="https://docs.google.com/document/d/136qoVExYsV5zqmuF49-Rm3RgqCdc9mjc4prDhwLXV2U/edit">Plot</a> written to help the workshop given in 12/22/2019.

<a href="http://www.trytoprogram.com/cplusplus-programming/access-specifiers/">OOP reference</a>