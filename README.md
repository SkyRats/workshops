# C++ Basics



### Mission

This guide was developed to help members from Skyrats - Autonomous Drones Team from Escola Politécnica da Universidade de São Paulo - to understand the basic concepts of C++.



**It assumes that the person who is reading this guide already have some basic programming experience in any other language, or even C++ and this can be used as a refreshing material.**

Since it is a routine for the members to be asked to install Linux (Ubuntu 16.04 LTS) when they enter the team, some instructions are given to be inserted on a Linux Terminal.

If that may be an issue, you can easily follow this guide using an IDE (Codeblocks is a good starting IDE).



### Prerequisites

* **Compilers**:

  * GCC (Linux)

  * MinGW (Windows)

    

## Contents

* Basic Programming 
* What is C++?
* Quick Start - Hello World
* Variables
* Operators
* References and Pointers
* Defining Functions
* Hands On - Examples

</br>


## What is C++?

C++ was developed by Bjarne Stroustrup at Bell labs in 1979, as an extension to the C laguage.

It can be used to create high-performance applications and ate the same time it gives programmers a high level of control over system resources and memory.

Why use it?

It is one of the world's most popular programming languages, so used that it's usually found in operating systems, Graphical User Interfaces and embedded systems. It also is an object oriented language, giving a clear structure to programs and allowing code to be reused, lowering development costs.

As C++ is close to C# and Java, it makes it easy for programmers to switch to C++ or vice versa.




## Quick Start - Hello World

Traditionally we almost always start a language by printing "Hello World". So I don't see a problem to do same here. Therefore, the code bellow is from my helloworld.cpp file.



```c++
#include <iostream> // standard library

using namespace std; // accept this for now, I'll explain it later

// a c++ program will always have its 'int main()' function
// functions are any code inside its curly bracktes {'code that will be executed'}

int main() {
  cout << "Hello World!" << endl; // cout is an object that prints the text
    							  // Every statement in C/C++ ends with ';'
    							  // endl is a function to skip to the next line
  return 0;						  // return 0 ends the main function
}

//  there are 2 types of comments, single-line and multi-line comments
/*  single-line comments come after 2 slash, 
	and multi-line comments come between slashs and asterisks */
```



For those who are already used to programming with C, C++ won't be any issue.

If you do not fit in that profile don't worry we will explain every line of code.



In the beginning of the code, the first thing to do is to include the Standard Library "iostream" which is the C's correspondent to "stdio.h".

To include it just type down: 

> #include <iostream>
>
> 
>
> using namespace std;

This will allow you mainly to use the input and output objects ("cin" and cout"). 



The same Hello World program without "using namespace std;" would look like this:

```c++ 
#include <iostream>

int main() {
  std::cout << "Hello World!" << std::endl;
  return 0;
}
```

So in order to not having to type "std::" before each "cout" or any other object, we add "using namespace std;" right after including <iostream>.



**Note 1:** The same code could also be written as:

```c++
#include <iostream> 
int main(){std::cout << "Hello World" << std::endl; return 0;}
```

The compiler ignores white spaces. However, multiple lines make the code better to read.



**Note 2:** instead of using the object "endl;" you can also use "\n" to  insert a new line:

```c++
#include <iostream>
using namespace std;

int main() {
  cout << "I am learning C++ \n";
  return 0;
}
```

Similar syntax is used when you need to add a TAB, in this case you have to type "\t".



**Note 3:** All standard libraries are included between "<>":

```c++
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
```







## Variables

If you are **NOT** used to programming in C language this part is mandatory for better understanding of the whole content. If this is not your case you may skip it. 



Variables are containers for storing data values, in other words, is the memory size that the compiler will allocate to store that type of information that you are manipulating. and it surely depends on the type of variable you are using.



The most common type of variables are:

* int - stores integers (whole numbers), such as 123 or -123

* double - stores floating point numbers, such as 19.99 or -19.99

* char - stores single characters, such as 'a' or 'B', or even '%'

* string - stores text, such as "Hello World"

* bool - stores values with two states: true or false



#### Declaring Variables

To create a variable, you **must** specify the type and assign it a value.



**Syntax**

> type variable = value;



**Example**

```c++
int myVar = 15; // myVar is 15
myVar = 10; // now myVar is 10
cout << myVar; // outputs 10
```



#### Constants

You can add 'const' keyword if you don't want others (or yourself) to override existing values (this will declare the variable as **read-only**).

```c++
const int myVar = 15; // myVar will always be 15
myVar = 10;  // error: assignment of read-only variable 'myVar'
```



**Other Examples**

```c++
int myNum = 5;
double myFloatNum = 5.99;
char myLetter = 'L';
string myText = "Skyrats";
bool myBoolean = true;
```



#### Basic Data Types Sizes

|     TYPE      | STORAGE SIZE (in bytes) |           VALUE RANGE           |
| :-----------: | :---------------------: | :-----------------------------: |
|   short int   |            2            |        -32,768 to 32,767        |
|      int      |            4            |    -2147483648 to 2147483647    |
|   long int    |            4            | -2,147,483,648 to 2,147,483,647 |
| unsigned int  |            4            |         0 to 4294967295         |
|     char      |            1            |     -127 to 127 or 0 to 255     |
| unsigned char |            1            |            0 to 255             |
|     float     |            4            |       1.2E-38 to 3.4E+38        |
|    double     |            8            |      2.3E-308 to 1.7E+308       |
|  long double  |           12            |     3.4E-4932 to 1.1E+4932      |
|    string     |           32            |                -                |
|     bool      |            1            |                -                |





## Operators



### Arithmetic Operators

| Operator |              Description               |
| :------: | :------------------------------------: |
|    +     |        Adds together two values        |
|    -     |    Subtracts one value from another    |
|    *     |         Multiplies two values          |
|    /     |     Divides one value from another     |
|    %     |     Returns the division remainder     |
|    ++    | Increases the value of a variable by 1 |
|    --    | Decreases the value of a variable by 1 |



### Assignment Operators

| Operator |  Same as   |
| :------: | :--------: |
|    +=    | x = x + 3  |
|    -=    | x = x - 3  |
|    *=    | x = x * 3  |
|    /=    | x = x / 3  |
|    %=    | x = x % 3  |
|    &=    | x = x & 3  |
|   \|=    | x = x \| 3 |
|    ^=    | x = x ^ 3  |
|   >>=    | x = x >> 3 |
|   <<=    | x = x << 3 |



### Comparison Operators

| Operator |           Name           |
| :------: | :----------------------: |
|    ==    |         Equal to         |
|    !=    |        Not equal         |
|    >     |       Greater than       |
|    <     |        Less than         |
|    >=    | Greater than or equal to |
|    <=    |  Less than or equal to   |



### Logical Operators

| Operator |    Name     |
| :------: | :---------: |
|    &&    | Logical and |
|   \|\|   | Logical or  |
|    !     | Logical not |





## References and Pointers



### References

A reference variable is a "reference" to an existing variable. Check the code below:

```c++
string food = "Pizza";
string &meal = food;

// now we can use either the variable name 'food' or the
// reference name 'meal' to refer to the 'food' variable

cout << food << "\n";  // Outputs Pizza
cout << meal << "\n";  // Outputs Pizza
```



##### Memory Address

In the example above, the '&' operator was used to create a reference variable. But it can also be used to get the memory address of a variable, which is the location of where the variable is stored on the computer.

Obs: When a variable is created, a memory address is assigned to the variable. And when we assign a value to the variable, it is stored in this memory address.

To access it, use the '&' operator, and the result will represent where the variable is stored:

```c++
string food = "Pizza";

cout << &food; // Outputs 0x6dfed4
```



### Pointers

A pointer is simply a variable that **stores the memory address as its value**.

A pointer variable points to a data type (like int or string) of the same type, and is created with the '*' operator. The address of the variable you are working with is assigned to the pointer:

```c++
string food = "Pizza";  // A food variable of type string
string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

// Output the value of food (Pizza)
cout << food << "\n";

// Output the memory address of food (0x6dfed4)
cout << &food << "\n";

// Output the memory address of food with the pointer (0x6dfed4)
cout << ptr << "\n";

// Output the value of food, using ist pointer (Pizza)
cout << *ptr << "\n";
```







## Defining Functions

The next example is here to show how we can define other functions.



The first thing to define on a function is the type that it will return (int, char, string, float, double, etc), or set "void" if it does not return anything.

If the function has any parameter you have to set it between parenthesis "()" and set each parameter type, for example:



```c++
int sum (int parameter1, int parameter2){
      return parameter1 + parameter2;
}
```



Not every function has to return some value, check the example below:



```c++
#include <iostream>

using namespace std;

void printSum (int a, int b){
    int c = a + b;
    cout << a << " + " << b << " = " << c << endl;
}

int main(){
    int num1 = 2;
    int num2 = 3;
    
    printSum(num1, num2);
    
    return 0;
}
```

The output of this program would look like this

```
2 + 3 = 5
```







## Hands On - Examples



#### Compiling and Running

Usually the C++ files have the ".cpp" extension and to compile it on a Linux terminal is quite simple if you already have the GCC complier installed.



Let's say I want to compile a file and its name is "file.cpp", the command I should put on the Terminal is:

```sh
g++ file.cpp -o executable
```



The "-o" is to indicate what is going to be called the executable program that is generated after the compiling, in this case I named it as "executable", but you can named it as you like.



To run the program just do it as any other script on a Linux Terminal:

```sh
./executable
```





#### Examples

After all this new information, the best thing to do is to make it become something that may be useful for your daily life. Check out the examples below.



**Example 1:**

```c++
#include <iostream> // std Library

using namespace std;

int multiply (int banana, int apple) {
    int result;

    result = banana * apple;
    
    return result;
}

int main() {
    int x = 0, y = 0; 	// initiate the two variables

    cout << "Type x: ";
    cin >> x; 			// reads the first input

    cout << "Type y: ";
    cin >> y;			// reads the second input

    cout << endl;		// skips a line
    cout << x;			// prints only the variable x, 
    					// not skipping the line in the end
    
    cout << " * " << y << " = " << multiply (x, y) << endl;
    
    return 0; 			// convention to finish the main() function
}
```



**Example 2:**

```c++
#include <string>		// string std library
#include <iostream>

using namespace std;

int main() {
    string name;
    
    cout << "Type the name: ";
    cin >> name;

   if(name == "Peter"){
       cout << "It is the same as Peter" << endl;
   }else if(name == "Joe"){
       cout << "It is the same as Joe" << endl;
   }else{
       cout << "It is not the same" << endl;
   }
    
   // the following condition is just to show how for works in C++
    
   for(int i = 0; i < 10; i++){
       cout << " " << i;
   }

    char initial = name[0]; // a string is just an char array
    						// and it can be manipulated as one

    cout << endl;
    cout << initial << endl; // it will print the first name's character
    cout << endl;
    cout << name << endl;

    return 0;
}
```



Go ahead and test out those programs checking their outputs. 

# cpp_workshop
