# 2 - Concepts

### ADT - Abstract Data Type

An Abstract Data Type (ADT) is formally defined as a type (or class) for objects whose behavior is defined by a set of value and a set of operations. 

To be more clear, it basically let you define new type of data (not only having to work with int, char, double, etc). ADT's encapsulate data and different operations for any type of data and it also does not depend of how the data is stored or implemented. They are they "way" to abstract the real world because you could create any type of data.

### Class

A class is a data structure that implements an ADT. It represents the common characteristics in a group of objects (abstraction).

For example, we can think in a class called "car" and create objects that may have different characteristics, like different colors or different names, but they all have something in common, they all have 4 wheels, a motor, a gear mechanism, etc.

<img
    src="/images/clssobjc.png"
    alt="class representation"
/>

The image above shows how a <code>Car</code> object can be the template for many other <code>Car</code> instances. A class not only can define a <code>Car</code> object's atributtes (color, number of passengers it can take, etc), but it also can define how it is going to work, or what are going to be its methods (operations). For example, we could create a method <code>accelerate</code> that changes the object's current speed.

### Object

An object is simply an instance of a class, an element of the computer system. It has its singular characteristcs as *Behavior*, *State* and *Identity*.

Example: Lamp

* Behavior - Turn On, Turn Off, getState.
* State - On, Off.
* Identity - Living Room Lamp.

### Attribute

An attribute is basically a class' property. It represents the data.

### Operation

An operation is just specifies which functionality an object supports, but it has no implementation. It is similar to a function prototype as we usually see in C language.

### Method

A method is a implementation of an operation. 

**Note:** We usually don't use the term operation, we refer as methods.