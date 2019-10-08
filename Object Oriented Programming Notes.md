# Object Oriented Programming Notes

## Introduction

What is OOP?

Why do we need OOP? Why do we need abstraction?



## Principles

- Encapsulation - Hide unnecessary/private variables
  - Getters & Setters
  - Namespaces
- Abstraction - Hide the implementation and expose an interface
- Inheritance - Reuse classes and add more things on top
- Polymorphism - Use the same interface on different classes from the inheritance tree



## How to avoid memory leaks

The memory leak result is in the Output window in Visual Studio (bottom left)

```C++
// This code goes at the top of the cpp file
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> // Include necessary libraries for debugging
#include <crtdbg.h> // Ditto
#ifdef _DEBUG // If the program is executed in debug mode (can be changed in VS to Release/Debug)
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) // define new to be debug new
#endif // Debug new shows in which file and on which line the memory leak happened
```

```C++
// Your main() will look like this:
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // The above line will call the memory leak analysis each time the program leaves a scope (for example at the end of main)
    // Your code here...
}
```

Source https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2017



## Classes and Objects

What is a class and what is an object?

- Class is the template/specification for the object

Difference between declaration and definition?

- Declaration specifies what the function/class should do
- Definition specifies how the function/class does it

Declaration should be done in a header file

- Declare functions/classes, but do not define them

Definition of the methods is done separately. Why?

- We expose the interface but hide the implementation

Classes can be declared in different scopes and they are visible only in the scope they are in 

Classes can be defined inside functions but they must have only inline methods because otherwise we'll have function in a function which makes no sense

Objects from classes defined in the scope of a function can be created only in the scope of the function

If a class is defined in a function it cannot call the function



## Methods and Data Fields

Fields and methods can have different visibility levels

- `private` - can be seen only in the class itself
- `public` - can be seen from anywhere
- `protected` - private to the outside but visible from the derived classes

Fields cannot be objects of the same class (recursion is no allowed)

Fields can be pointers to object of the same class

We use setters and getters to encapsulate the data in the object and restrict access

Methods can return anything, even objects of the same class

We can use methods to work with the data stored in the object (by accessing it directly) or

We can use functions to work with the data in the object by getters and setters

Getters should be const because we do not alter any data in the object

If the declaration of a function is inside the class it's automatically inline

What is inline function?

- Copied everywhere where it appears instead of doing calls to it

When should we use inline functions?

- When they're short and we need speed

If we want to declare a method outside we have to declare it as inline if we want it to be inline

`this` pointer - const pointer to the current object

`this` pointer is implicitly passed to all methods (in other languages it is explicitly passed as an argument like in python)

The code of each method of a class is stored once and when we call the method on an object it calls it with `this` so the method knows which memory block to use, in that sense a method is very similar to a function

If a method takes in a parameter X which has the same name as a field of the class

- The parameter overwrites the name so when we use X we are referring to the parameter
- If we want to access the field of the class from within the method we can access it with `this->X`

Method chaining

- Allows us to do `MyObject.DoA().DoB().DoC();`
- We can choose to return reference to the object or a copy depending on the situation



**Static variable in function**

Static variable in a function is initialized only once and can be accessed only from inside the function.

```C++
int foo() {
	static int i = 0;
	return i++;
}

int main() {
	std::cout << foo(); // Prints 0
	std::cout << foo(); // Prints 1
	std::cout << foo(); // Prints 2
}
```



### Static methods/fields

Static fields are bound to the Class itself, not to each object. That means that every object of the given class has the access to the exact same static variable, it's allocated once for the class, not for each object

Memory is not allocated for static variables until they are declared outside of the class (see line 5 in the example)

Static fields are initialized outside of classes

**Static field syntax**

```C++
class MyClass {
public: // Can be private but std::cout won't work and we will need another way to access MyVar
  static int MyVar;
};
int MyClass::MyVar = 5; // Can be initialized even if MyVar is private
// Initialization is done outside of functions, in the global scope
int main() {
	std::cout << MyClass::MyVar; // Prints 5
}
```

Static methods can be called on an object or on the class itself



**Static methods syntax**

```C++
class MyClass {
public:
  static print() {
      std::cout << 10;
  }
};
int main() {
    MyClass::print(); // Prints 10
    MyClass obj;
    obj.print(); // Prints 10
}
```



## Constructors

**Syntax**

```C++
class MyClass {
private:
    int one, two;
    char ch;
public:
    MyClass(int One, char ch, int Two) : two(Two) {
        this->ch = ch;
        one = One;
    }
};
```

Constructors initialize objects with default or provided values

Constructors have no return type

Constructors silently return `this` pointer

Constructors have the same name as the class

Constructors can only be called when initializing an object (happens only once)

Calling constructors, aka initializing objects

- `MyClass var1 = MyClass(parameters)` - Old way
- `MyClass var2(parameters)` - Old way
- `MyClass var3 = parameter` - Good for using `auto` and one parameter, but bad practice
- `MyClass var4 { parameters }` - New way, safer because it doesn't do silent casting (it won't cast a double to an int but will throw an error)
  - Silent casting chain char -> short -> int -> long long
  - Silent casting chain float -> double
  - The compiler will try to find a function with the exact same parameters but if it can't it will try to cast the parameters to other objects to find a suitable function which might be undesired behavior, but it allows us to pass an explicit string ("example text") to a function that accepts object of type `string`

If we do not declare constructor/destructor/copy constructor/operator= they get a default declaration

Constructor declared as private restricts the creation of objects of the class (Useful for singletons)

We can define multiple constructors

- We can either define them with different parameters or different number of parameters or
- We can use optional parameters to generate multiple constructors

Ways to initialize constructors

- Assign the fields their values in the body or
- Use the initialization list `MyClass(val1, val2,...) : field1(val1), field2(val2),... { ... }`

Using an initialization list is better and faster because

- If the constructor parameters are other objects we can call their constructors directly
- If we have fields that are objects their default constructors will be called first (before the body of the constructor), so if we do not use the initialization list we will be doing double work - once default constructor, once copy constructor which is slower
- Initialization list allows us to initialize const fields

We do not need an initialization list if the fields and parameters are primitive types (int, char, bool, etc.) because they do not have default constructors



## Destructors

**Syntax**

```C++
class MyClass {
private:
    int * ptr;
    int a;
public:
    MyClass() {
        ptr = new int[100];
    }
    ~MyClass() { // We delete only memory allocated with new and new[]
        delete[] ptr;
    }
};
```

Destructors clean the memory so we can dispose of the object without memory leaks

Alternative syntax? (for jokes only)

- `comlp MyClass() { ... }` - Using alternative tokens
- Source https://en.cppreference.com/w/cpp/language/operator_alternative

There are 2 ways to call the destructor

- Using the `delete` operator or
- When the object goes out of scope it is called automatically

Only one destructor can be defined per class

If a destructor is not defined explicitly the compiler will make a default destructor



## Copy constructors

**Syntax**

```C++
class MyClass {
private:
    int * ptr;
    int size;
public:
    MyClass(int Size) : size(Size) {
        ptr = new int[size];
    }
    MyClass(const MyClass & ObjectToCopy) : size(ObjectToCopy.size) {
    	ptr = new int[size]; // Already copied
		for (int i = 0; i < size; i++) {
            ptr[i] = ObjectToCopy.ptr[i];
        };
    }
};
```

Copy constructors allow us to initialize an object by copying another object

Copy constructors are called when

- An object is passed to a function by value

- A function returns an object

- Initializing an object from another object:

- ```C++
  MyClass objOne;
  MyClass objTwo(objOne); // Copy constructor called
  ```



## Operator=

**Syntax**

```C++
MyClass & operator=(const MyClass & ObjectToCopy) { // Cannot use initialization list because it is not a constructor
    if (&ObjectToCopy != this) {
        // Delete old data
        // Copy new data
    }
    return *this;
}
```

operator= allows us to safely copy one object from another after the first has already been initialized earlier

operator= should check if the object passed is the object itself because the following scenario happens

- Let `X` be our object
- `X = X` calls the copy constructor
- In the copy constructor we first free the old data (so we can avoid memory leaks)
- Then we copy the new data, but we are in `X` and we just deleted `X`'s data so we have nothing to copy
- This results in unwanted behavior where we delete the object's data instead of doing nothing as we should



## Example with Constructors and Destructor

#### Array.h

```C++
#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	int * values;
	int size;
public:
	Array(int Size = 0);
	Array(const Array & rhs);
	Array & operator=(const Array & rhs);
	~Array();
};

#endif // !ARRAY_H
```

#### Array.cpp

```C++
#include "Array.h"

Array::Array(int Size) : size(Size) {
	values = new int[size];
}

Array::Array(const Array & rhs) : size(rhs.size) {
	values = new int[size];
	for (int i = 0; i < size; i++) {
		values[i] = rhs.values[i];
	};
}

Array & Array::operator=(const Array & rhs) {
	if (&rhs != this) {
		delete[] values;
		size = rhs.size;
		values = new int[size];
		for (int i = 0; i < size; i++) {
			values[i] = rhs.values[i];
		}
	}
	return *this;
}

Array::~Array() {
	delete[] values;
}
```

#### Main.cpp

```C++
#include <iostream>
using namespace std;
#include "Array.h"

int main() {
	Array a(5); // Constructor called
	Array b = a; // Copy constructor called
	Array * c = new Array(a); // Copy constructor called
	b = *c; // Operator= called
	delete c; // Destructor for c called
	Array * d = new Array[10]; // Call the default constructor 10 times
	delete[] d; // Call the destructor on the 10 objects
	return 0; // Destructor for a and b called
}
```



## Friend Functions

**Syntax**

```C++
class MyClass {
    friend int MyFunction(MyClass Obj);
private:
    int a = 3;
};
int MyFunction(MyClass Obj) {
    std::cout<< Obj.a; // Prints 3 because MyFunction is a friend function and can access the private fields of MyClass 
}
```

Friend functions have access to the private fields/methods of the class they are friend of



## Friend Classes

**Syntax**

```c++
class B {
	void print(A Obj) {
		Obj.print(); // Can be called because B is a friend of A
	}
	int readA(A Obj) {
		return Obj.a; // Can be accessed because B is a friend of A
	}
};
class A {
	friend class B; // Declare B as a friend of A
	int a = 5;
	void print() { // private scope by default
		cout << 7;
	}
};
```

Declaring a class as a friend of another class means that the second can use all methods of the first class and has access to all fields (even private) of the first class.



## Operator Redefinition

Operator redefinition is used when we want to change the behavior of the C++ operators when used on our class

### Increment/Decrement

```C++
class MyClass {
public:
    MyClass & operator++() { //Prefix
        // Increment here
        return *this;
    }
    MyClass operator++(int) { // Postfix
        MyClass tmp(*this); // Make a temporary copy
        operator++(); // Use the prefix ++
        return tmp; // Return old value
    }
};
```

### Stream operators

**String.h**

```c++
class String {
private:
	char * data = nullptr;
	friend std::istream & operator>>(std::istream & stream, String & object);
	friend std::ostream & operator<<(std::ostream & stream, const String & object);
};

std::istream & operator>>(std::istream & stream, String & object) {
	delete[] object.data; // we have access to data because operator>> is a friend function 
	char buffer[1000];
	stream >> buffer;
	int size = strlen(buffer);
	object.data = new char[size + 1];
	strcpy(object.data, buffer);
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const String & object) {
	if (object.data != nullptr) {
		stream << object.data;
	}
	return stream;
}
```

### Comparison operators

```C++
bool operator< (const MyClass & lhs, const MyClass & rhs) {
    // Compare here
}
bool operator> (const MyClass & lhs, const MyClass & rhs) {
    return rhs < lhs;
}
bool operator<=(const MyClass & lhs, const MyClass & rhs) {
    return !(lhs > rhs);
}
bool operator>=(const MyClass & lhs, const MyClass & rhs) {
    return !(lhs < rhs);
}
bool operator==(const X& lhs, const X& rhs) {
    // Compare here
}
bool operator!=(const X& lhs, const X& rhs) {
    return !(lhs == rhs);
}
```

Source https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

Source https://en.cppreference.com/w/cpp/language/operators



## Streams and Files

**Reading/Writing to files example**

```C++
#include<fstream>
int main() {
    // Read from file
	std::ifstream Reader;
	Reader.open("MyFile.txt");
	char buffer[1000];
	if (Reader.is_open()) {
		char ch = 0;
		int i = 0;
		while (Reader.get(ch)) {
			buffer[i] = ch;
			i++;
		}
		buffer[i] = 0; // Terminating 0
	}
	Reader.close();
    
	// Write to file
	std::ofstream Writer("MyFile.txt");
	if (Writer.is_open()) {
		Writer << buffer << "\nPlus more text at the end.";
		Writer.close();
	}
	return 0;
}
```



## Exceptions

**Exception example**

```C++
#include <iostream>
int SafeDivide(int a, int b) {
	if (b == 0) {
		throw 0;
	}
	return a / b;
}
int main() {
	try {
		SafeDivide(5, 0);
	}
	catch (int ex) {
		if (ex == 0) {
			std::cout << "Zero division error";
		}
	}
	return 0;
}
```



## Templates

Templates allow us to write a function/class once but make it work for many types/classes

Templates make a blueprint for a generic functionality (function or class)

The code for a template class/function is not generated until it is used, this makes debugging harder because there can be a bug but the code is not even compiled so we don't know of it

We put `template <class T, class U,...>` before a template function/class where T, U... are the different template types

`template <class T>` is the same as `<template <typename T>`

### Template functions

What the compiler does with a template function:

1. Let's say we have a template function `foo<T>()`
2. The compiler does NOT compile the code for the function
3. We call `foo<int>()` for the first time
4. The code for `foo<int>()` is generated
5. `foo<int>()` is executed
6. We call `foo<int>()` a second time
7. `foo<int>()` is executed (this time without need of compilation because the code already exists)
8. We call `foo<char>()` for the first time
9. The code for `foo<char>()` is generated
10. `foo<char>()` is executed

**Example**

```C++
#include <iostream>

template <class T>
T max(const T & lhs, const T & rhs) {
	if (lhs < rhs)
		return rhs;
	return lhs;
}

int main() {
	std::cout << max(2, 5); // Prints 5
	std::cout << max<double>(3.5, 7.1); // Prints 7.1
	return 0;
}
```

### Template classes example

#### Array.hpp

```C++
#ifndef ARRAY_H
#define ARRAY_H

template <class T>
class Array {
private:
	int size;
	T * values;
public:
	Array(int Size = 0) : size(Size) {
		values = new T[size];
	}
	Array(const Array & rhs) : size(rhs.size) {
		values = new T[size];
		for (int i = 0; i < size; i++) {
			values[i] = rhs.values[i];
		};
	}
	Array & operator=(const Array & rhs) {
		if (&rhs != this) {
			delete[] values;
			size = rhs.size;
			values = new T[size];
			for (int i = 0; i < size; i++) {
				values[i] = rhs.values[i];
			}
		}
		return *this;
	}
	~Array() {
		delete[] values;
	}
	T Get(int Index) const;
	void Set(int Index, T Value);
};

template <class T>
inline T Array<T>::Get(int Index) const {
	return values[Index];
}
template <typename T>
void Array<T>::Set(int Index, T Value) {
	values[Index] = Value;
}
#endif // !ARRAY_H
```

#### Main.cpp

```C++
#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> a(5); // Constructor called
	a.Set(1, 15); // Sets the 2nd element to 15
	std::cout << a.Get(1); // Prints 15
	Array<int> b = a; // Copy constructor called
	Array<int> * c = new Array<int>(a); // Copy constructor called
	b = *c; // Operator= called
	delete c; // Destructor for c called
	Array<int> * d = new Array<int>[10]; // Call the default constructor for Array<int> 10 times
	delete[] d; // Call the destructor on the 10 objects
	return 0; // Destructor for a and b called
}
```

### Template class with static fields

**Example**

TemplateStatic.hpp

```C++
#ifndef TEMPLATESTATIC_HPP
#define TEMPLATESTATIC_HPP

template <class T>
struct A {
	static int i;
	static T t;
};

template <class T>
int A<T>::i = 5;

template <class T>
T A<T>::t = 5.5;

#endif // !TEMPLATESTATIC_HPP
```

Main.cpp

```C++
#include "TemplateStatic.hpp"
using namespace std;

int main() {
	A<int> a;
	cout << a.t << "\n"; // Prints 5
	cout << A<double>::t << "\n"; // Prints 5.5
}
```



## Inheritance

**Syntax**

```C++
class A {
	int a;
};
class B {
	int b;
};
class C : private A, public B {
    int c;  
};
```

We can inherit classes as

- public - all fields and methods remain with the same accessibility
- protected - public fields and methods become protected
- private - all fields and methods become private

Inheritance access table

| Access specifier in base class | Access specifier inherited publicly | Access specifier inherited protectedly | Access specifier inherited privately |
| ------------------------------ | ----------------------------------- | -------------------------------------- | ------------------------------------ |
| public                         | public                              | protected                              | private                              |
| protected                      | protected                           | protected                              | private                              |
| private                        | inaccessible                        | inaccessible                           | inaccessible                         |

Default inheritance is private, i.e if we omit the inheritance level and have just `class C : B { ... }` B will be inherited privately

protected means that the derived class can access the fields directly but they are not accessible outside of the class, i.e protected fields are seen as private from outside the class, but are seen as public from inside the derived classes

We can have fields with the same name in inherited classes, then the parent field is hidden and can be accessed by its full name (using `BaseClass::FieldName`)

Constructor from the child class can call the constructor of the base class (by calling the base constructor in the initializer list)

If we do not call a base constructor the default one will be called automatically

If the base class has no default constructor and we do not call any of its constructors from the derived class we will get a compilation error

Constructors are called from small to big while destructors are called from big to small (small = base class, big = deepest derived class in the inheritance tree)

There's no need to explicitly call the base destructor, that's done automatically

Derived classes can call the base class copy constructor from their initialization list

We can call the base class `operator=` by referencing its full name using `BaseClass::operator=`



## Casting in C++

Casting derived class to base is safe but base to derived is not.

Use `dynamic_cast` for converting pointers/references within an inheritance hierarchy.

Use `static_cast` for ordinary type conversions like in C. (equivalent to `(int)object`)

Use `reinterpret_cast` for low-level reinterpreting of bit patterns. Use with extreme caution.

Use `const_cast` for casting away `const/volatile`. Avoid this unless you are stuck using a const-incorrect API.

Source https://embeddedartistry.com/blog/2017/2/28/c-casting-or-oh-no-we-broke-malloc

When to use `reinterpret_cast`? - https://stackoverflow.com/a/573574



## Template Inheritance

We can inherit a class as a template or as a specific type

**Example**

```C++
template <class T>
struct A {
	T var;
};

struct B : A<int> { // Inherit A as int container A<int>
};

template <class T>
struct C : A<T> { // Inherit A as a generic container A<T>
};
```



## Multiple Inheritance

The constructor of a class which inherits more than 1 class calls the constructors of the base classes in their order in the inheritance list 

The destructor of a class which inherits more than 1 class calls the destructors of the base classes in reverse order of their ordering in the inheritance list (opposite of constructors)



## The Diamond problem

Diamond inheritance is if we have the following, where D inherits A twice through B and through C

```C++
class A {};
class B : A {};
class C : A {};
class D : B, C {};
```

Having multiple instances of a base class in memory will make its methods/fields ambiguous so we have to use the full names when referencing them.(`BaseClass::FieldName`) 

We can use casting to get access to the ambiguous fields, but we cannot change them that way because casting is making a temporary copy of the object

**Example**

```C++
#include <iostream>

struct A {
	int a;
};
struct B : public A {
	B() {
		a = 1;
	}
};
struct C : public A {
	C() {
		a = 2;
	}
};
struct D : public B, public C {
    // contains int a; twice
};

int main() {
	D obj;
	std::cout << ((B)obj).a; // Prints 1
	std::cout << ((C)obj).a; // Prints 2
}
```



## Virtual classes

We declare a virtual class by writing `virtual` in front of the base class in the inheritance list

```C++
class A { };
class B : virtual public A { }; // A is inherited as a virtual class
```

If we use virtual inheritance with The Diamond the derived class will have only one instance of the base class

When calling the constructor of a child of a virtual class we have to call the virtual base class constructor explicitly because it is not being called by the inherited classes

Virtual classes constructors are called before the other classes constructors

When we have multiple virtual classes inherited their constructors are called in the order of the initialization list

**Example fix the problem above**

```C++
struct A {
	int a;
};
struct B : virtual public A {
	int b;
};
struct C : virtual public A {
	int c;
};
struct D : public B, public C {
    int d;
    // int a; once
    // int b,c; once
};
```

 

## Virtual functions and Polymorphism

A class with at least one virtual function is called polymorphic

Static methods (normal methods, not ones using `static` keyword) means that they are resolved during compilation, which is faster

Dynamic methods (aka virtual functions) means that they are resolved during execution, which is slower

If we have a virtual function we can specify exactly which version of the function we want to call and make a static connection by referencing the function by its full name

Constructors cannot be virtual

Virtual functions cannot be declared as friend functions

Class with virtual functions must be inherited as `public`

If a function in a base class is declared virtual it remains virtual in the derived classes again even if the `virtual` keyword is skipped

We can use the keyword `override` to show a virtual function from a base class is being overridden in a derived class, but it is not necessary. It is only used to make the code more readable

Virtual functions are called via a pointer to a class (derived or base)

**Example**

```C++
#include <iostream>

struct Base {
	virtual void print() { // virtual function is resolved during execution
		std::cout << 1;
	}
};
struct Derived : public Base {
	void print() override { // print() is virtual here too because it was virtual in A
		std::cout << 2;
	}
};

int main() {
	Base * a = new Base; // Object A pointed by A-pointer
	Base * b = new Derived; // Object B pointed by A-pointer
	a->print(); // Prints 1
	b->print(); // Prints 2, if print() wasn't virtual this line would print 1 as well
}
```

Upcasting is when we write a function to do something with a base class but we can pass its derived classes as well and it will work fine - makes use of virtual functions

We can use polymorphism to abuse the access to private/protected members by casting objects up/down the hierarchy to an object where the field/method we want to access is public but that is very bad practice and not recommended

### Virtual destructors

When we upcast (use a pointer to a base class to point to a new object of a derived class) we need to declare the destructors virtual otherwise the destructor of the base class will not be called.

Declaring the destructor of one class virtual makes all its derived classes' destructors virtual

```C++
#include <iostream>

struct Base {
	void virtual print() { }
	virtual ~Base() { }
};
struct Derived : public Base{
	void print() { }
	virtual ~Derived() { }
};

int main() {
	Base * a = new Derived;
	delete a; // calls ~Derived()
	return 0;
}
```

## Abstract classes and pure virtual functions

Pure virtual functions are declared `virtual int foo() = 0;` and they have no body

Pure virtual functions must be overridden in the derived classes because they have no body in the base class

Abstract class is a class that has at least one pure virtual function

We cannot create objects from an abstract class

Polymorphic or Heterogenous structures are structures which can hold data from different types, the objects and the class itself are declared separately and the class references the objects by pointers using polymorphism
