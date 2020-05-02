# 6 - Abstract Classes and Multiple Inheritance

An abstract class is, conceptually, a class that cannot be instantiated and is usually implemented as a class that has one or more pure virtual (abstract) methods.

A pure virtual methods is one which **must be overridden** by any concrete derived class. This is indicated in the declaration with the syntax **" = 0"** in the member method's declaration.

```c++
class AbstractClass {
public:
  virtual void AbstractMemberFunction() = 0; // Pure virtual function makes
                                             // this class an Abstract class.
  virtual void NonAbstractMemberFunction1(); // Virtual method.

  void NonAbstractMemberFunction2();
};
```

Abstract class cannot be used as a parameter type, a function return type, or the type of an explicit conversion, and not to declare an object of an abstract class. It can be used to declare pointers and references to an abstract class.

#### Pure Abstract Class

An abstract class is one in which there is a declaration but no definition for a member function. The way this concept is expressed in C++ is to have the member function declaration assigned to zero.

```c++
class PureAbstractClass {
public:
  virtual void AbstractMemberFunction() = 0;
};
```