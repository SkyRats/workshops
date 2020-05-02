# 7 - Error Handling

### Exceptions in C++

**Exceptions** provide a way to react to exceptional circumstances (like divisions by zero or runtime errors) in programs by transferring control to special functions called handlers.

To **catch** exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion of code in a **try-block**. When an exceptional circumstance arises within that block, an exception is **thrown** that transfers the control to the exception handler. If no exception is thrown, the code continues normally and all handlers are ignored.

There is the Standard Library which defines basic exceptions, and it is necessary to add: 
```c++
#include <stdexcept>
using namespace std;
``` 

Some of the exceptions treated by the standard library are:

<img
    src="/images/errors.png"
    alt="class representation"
/>

#### Error Handling Techniques

* Return an Error Code
* End the program
* Register the issue in a log
    * Log file 
* Return a neuter value
    * Ex: method that "draws" something in the screen
* Return the same value as before
    * Ex: Temperature sensor
* Show an error message to the user

The decision of what technique to use depends on the situation you're dealing.

#### Example

```c++
#include <iostream>
using namespace std;

int main(){
    try {
        int age = 15;

        if (age > 18) {
            cout << "Access granted - you are old enough.";
        }else{
            throw (age);
        }
    }
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old.\n" << endl;
        cout << "Age is: " << myNum << endl;
    }

    return 0;
}
```