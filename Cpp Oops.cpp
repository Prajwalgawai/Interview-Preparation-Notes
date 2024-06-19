// C++ Important Topics : 
int sum(int a, int b){
    return a+b;
}
int a=4, b=8;
sum(a, b);
sum(a, b);
sum(a, b);
sum(a, b);
sum(a, b);
sum(a, b);  //Like this when we call the function multiple times, everytime following things happens : 
            //steps when function is called : evaluates the aurguments and push the aurguments on stack or on register then it store the address of the next line code on the 
            //stack so that after the execution of function control will goes to the next line.
            //Enter the function defination, push all the local variables on the stack then. place the return value in approprite register then adjust the stack pointer to remove all
            //local variables and finally remove the return address means where control should return back 

            //so it's a unnecessary overhead for the compiler to do all these thing everytime when the function is called if function defination is very very small
            //so if we use the inline keyword before the return type then it replaces the function defination with the function call and avoiding all the above overhead.

// Restrictions for inline: 
// we can use the inline with static function but can not use the inline function for the functions with the static variables because static variable initialises first time
// only then everytime when the function get's call it ignores the initialisation of static variable.












// OOPs, or Object-Oriented Programming is a programming model or paradigm which revolves around the concept of “OBJECTS”. Objects can be considered as real-world instances of 
// entities like class, that contain some characteristics and behaviors specified in the class template.




#include <bits/stdc++.h>
using namespace std;
 
int main()
{ 
// Composition Aggregation and Association : 

//Association : 

// association is a type of relationship where object of one class is aware of the object of the another class. there is no dependency among 
// the objects of the class and there is no ownership exists between the objects.
// there is simple knows-a or uses-a relationship between classes in association.
//has-a relationship but not whole part relationship.
class Course {
    // Course class members
};

class Student {
    Course* course; // Association with Course class    //If this class is destroyed then course class won't be destroyed.
    // Other Student class members
};

//Aggregation : 

// Aggregation is a specialized form of association in which an object of one class "owns" objects of another class, but the objects can exist
// independently of each other. It represents a "has-a" relationship. In aggregation, the lifecycle of the contained objects can exist independently 
// of the lifecycle of the containing object.
//whole-part and has-a relationship, not as strong whole-part relationship as composition.

class Engine {
    // Engine class members
};

class Car {
    Engine* engine; // Aggregation with Engine class
public:
    void setEngine(Engine* e) {
        engine = e;
    }
    Engine* getEngine() {
        return engine;
    }
};

int main() {
    Engine engine;
    Car car;
    car.setEngine(&engine); // Car depends on an Engine instance
    return 0;
}




//Composition : 
// Composition is a stronger form of the whole-part relationship compared to aggregation. In composition, the parts are considered to be owned 
// exclusively by the whole. This means that the parts have a strong lifecycle dependency on the whole, and they cannot exist independently of 
// it. When the whole is destroyed, its parts are also destroyed.
// It also shows has-a relationship.

class Engine {
public:
    Engine() {
        std::cout << "Engine created\n";
    }

    ~Engine() {
        std::cout << "Engine destroyed\n";
    }

    void start() {
        std::cout << "Engine started!\n";
    }

    void stop() {
        std::cout << "Engine stopped!\n";
    }
};

class Car {
private:
    Engine engine; // Car has an Engine as a part using composition
public:
    Car() {
        std::cout << "Car created\n";
    }

    ~Car() {
        std::cout << "Car destroyed\n";
    }

    void startCar() {
        engine.start(); // Accessing Engine functionality
    }

    void stopCar() {
        engine.stop(); // Accessing Engine functionality
    }
};

int main() {
    Car myCar; // Creating an instance of Car
    myCar.startCar(); // Starting the car
    myCar.stopCar(); // Stopping the car
}

// Engine created
// Car created
// Engine started!
// Engine stopped!
// Car destroyed
// Engine destroyed

//⭐ Note : difference between association and aggregation : 
association has weak relationship while aggregation has strong relationship 
we can understand better from following example : 

// association : 

#include <iostream>
using namespace std;

class Book {
public:
    string title;
    Book(string t) : title(t) {}
};

class Library {
public:
    void addBook(Book* book) {
        cout << "Library knows about the book: " << book->title << endl;
    }
};

int main() {
    Book myBook("The Great Gatsby");
    Library myLibrary;
    myLibrary.addBook(&myBook); // Association: Library knows about Book
    return 0;
}

// Aggregation :

#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title;
    Book(string t) : title(t) {}
};

class Library {
public:
    vector<Book*> books; // Aggregation: Library contains Books
    void addBook(Book* book) {
        books.push_back(book);
    }
    void showBooks() {
        for (Book* book : books) {
            cout << "Library has book: " << book->title << endl;
        }
    }
};

int main() {
    Book book1("The Great Gatsby");
    Book book2("1984");
    Library library;
    library.addBook(&book1); // Library aggregates Book
    library.addBook(&book2);
    library.showBooks();
    return 0;
}

}




// constructor overloading : 


#include<iostream>
using namespace std;

class complex{
    int a, b;
    public:

     complex(int x, int y){                             //  we can also write the constructor body within the class itself
    a=x;
    b=y;
    cout<<"hello"<<endl;
}

complex(int x){                       // overloaded constructor
    a=x;
     b=0;
}
void printdata(){
    cout<<"our complex no is : "<<a<<"+"<<b<<"i"<<endl;
}
};

 
int main(){
// complex c(1 , 5), d(5, 8);
// c.printdata();
// d.printdata();

 //  or
complex c(1 , 5) ;
c.printdata();
complex d(8);
d.printdata();


return 0;
}                                         


                             //          constructor overloading with default aurguments



// #include<iostream>
// using namespace std;

// class simple{
//     int a, b, c;
//     public:
 
// simple(int x, int y=5, int z=6){          // here 5 and 6 are default aurguments which get executed if not given the aurguments from the main   
//     a=x;
//      b=y;
//      c=z;
// }
//  void printing();
 
// };
// void simple::printing(){
// cout<<"the value of a,  b and c is "<<a<<" ,"<< b<<" and "<<c<<endl;
// }
 
// int main(){
 
// simple c(2,  8) ;      // if we havent pass any aurgument for any parameter like this then he will take the default aurgument
// c.printing();
 
// return 0;
// }  

// Contructors : 
// copy constructor : The copy constructor in C++ is a special constructor that is used to initialize a new object as a copy of an existing object. It takes a reference 
// to an object of the same class as its parameter and creates a new object by copying the contents of the existing object. 

// it is must to pass the address of object if we are making the copy contructor like below : 
// class Sample {
// 	int id;

// public:
// 	// default constructor with empty body
// 	Sample() {}
// 	// parameterized constructor
// 	Sample(int x) { id = x; }

// 	// copy constructor
// 	Sample(Sample& t) { id = t.id; }

// 	void display() { cout << "ID=" << id; }
// };

// // driver code
// int main()
// {
// 	Sample obj1(10);
// 	obj1.display();
// 	cout << endl;

// 	// copy constructor called
// 	Sample obj2(obj1); // or obj2=obj1;
// 	obj2.display();


//operator overloading in cpp

// C++ Program to Demonstrate
// Operator Overloading
#include <iostream>
using namespace std;

class Complex {
private:
	int real, imag;

public:
	Complex(int r = 0, int i = 0)
	{
		real = r;
		imag = i;
	}

	// This is automatically called when '+' is used with
	// between two Complex objects
	Complex operator+(Complex const& obj)
	{
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { cout << real << " + i" << imag << '\n'; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
}

// output: 
// 12 + i9

//method overloading  : 
// function overloading means same name but variable no. of parameter list to a function of same class
// if the return type is different then it is not the desirable feature of the function overloading, rather it creates the ambiguity.


// method overriding : same type of function in different classes : 
//Note : If we created the pointer object of  base class and pointed it to the object of the derived class & tried to call
// the overrided function of derived class then it will still call the function of base class so inorder to chage this default
// behaviour we use virtual function (use virtual keyword before the function declaration and use override keyword with the overriden method(optional) near the ()).


//⭐Inheritance : 
// 1. single inheritance
// 2. Multiple inheritance : derived class inherits from the multiple base classes.
// first the constructors of the parent classes will be called as per the sequenced mentioned while inheriting and then the current derived class constructor will 
// be called.

// 3. Multilevel inheritance: derived class inherits from the other derived class.
// first the constructor of the top most parent class will be called then 2nd top most in this way it will come down and finally the constructor of the currently 
// derived class will be called.

// 4.Hierarchical Inheritance: In this type of inheritance, more than one subclass is inherited from a single base class. i.e. more than one derived class is created from a
// single base class.

// 5.Hybrid (Virtual) Inheritance: Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple 
// Inheritance.

// In hybrid inheritance, 💎diamond problem can occur : 
// two ways to resolve this ambiguity : 
// 1) Avoiding ambiguity using the scope resolution operator:
// obj.ClassB::a = 10;       //obj is a object of the class D  //a is a variable present in both the classes i.e B and C
// obj.ClassC::a = 100;      // Statement 4

// 2) Avoiding ambiguity using the virtual base class: 
// class ClassA
// {
//   public:
//     int a;
// };
 
// class ClassB : virtual public ClassA
// {
//   public:
//     int b;
// };
 
// class ClassC : virtual public ClassA
// {
//   public:
//     int c;
// };
 
// class ClassD : public ClassB, public ClassC
// {
//   public:
//     int d;
// };

// this virtual base class will pass only the single copy of members in case of multiple inheritance if base classes are inherited from the common base class.

//Abstract Classes and pure virtual function : 

// Sometimes implementation of all functions cannot be provided in a base class because we don’t know the implementation. Such a class is called an abstract class.
// A pure virtual function (or abstract function) in C++ is a virtual function for which we can have an implementation, But we must override that function in the derived class, 
// otherwise, the derived class will also become an abstract class. A pure virtual function is declared by assigning 0 in the declaration.
// 1. A class is abstract if it has at least one pure virtual function.

// class Test {
    // private member variable
//     int x;
 
// public:
    // pure virtual function
    // virtual void show() = 0;
 
    // getter function to access x
//     int getX() { return x; }
// };

// 2. We can have pointers and references of abstract class type.
// Base* bp = new Derived();
    // calling the show() function using the   //show is a virtual function of base classes overrided in derived class.
    // pointer
//     bp->show();

// 3. If we do not override the pure virtual function in the derived class, then the derived class also becomes an abstract class, Means we can not create the object of 
// derived class also.

// 4. An abstract class can have constructors and the constructor of the abstract class can be called from the derived class like below : 

// public:
    // pure virtual function
    // virtual void fun() = 0;
 
    // constructor of Base class
//     Base(int i)
//     {
//         x = i;
//         cout << "Constructor of base called\n";
//     }
// };
 
// class Derived : public Base {
    // private member variable
//     int y;
 
// public:
    // calling the constructor of Base class
    // Derived(int i, int j)
    //     : Base(i)
    // {
    //     y = j;
    // }
 
    // implementation of pure virtual function
//     void fun()
//     {
//         cout << "x = " << x << ", y = " << y << '\n';
//     }
// };

// 5. An abstract class in C++ can also be defined using struct keyword instead of class keyword.

// Note : 
// In Java, a class can be made abstract by using an abstract keyword. Similarly, a function can be made pure virtual or abstract by using an abstract keyword.

// Interface vs Abstract Classes
// An interface does not have an implementation of any of its methods, it can be considered as a collection of method declarations. In C++, an interface can be simulated by
// making all methods pure virtual. In Java, there is a separate keyword for the interface.
























//⭐Friend Function : 
A friend function can be:

A global function
A member function of another class

1. Global Function as Friend Function                        (⭐Important )

// C++ program to create a global function as a friend
// function of some class
#include <iostream>
using namespace std;

class base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}
	
	// friend function declaration
	friend void friendFunction(base& obj);
};


// friend function definition
void friendFunction(base& obj)
{
	cout << "Private Variable: " << obj.private_variable
		<< endl;
	cout << "Protected Variable: " << obj.protected_variable;
}

// driver code
int main()
{
	base object1;
	friendFunction(object1);

	return 0;
}

2. Member Function of Another Class as Friend Function

#include <iostream>
using namespace std;

class base; // forward definition needed                                   //⭐very important 
// another class in which function is declared
class anotherClass {
public:
	void memberFunction(base& obj);
};

// base class for which friend is declared
class base {
private:
	int private_variable;

protected:
	int protected_variable;

public:
	base()
	{
		private_variable = 10;
		protected_variable = 99;
	}

	// friend function declaration
	friend void anotherClass::memberFunction(base&);
};

// friend function definition
void anotherClass::memberFunction(base& obj)
{
	cout << "Private Variable: " << obj.private_variable
		<< endl;
	cout << "Protected Variable: " << obj.protected_variable;
}

// driver code
int main()
{
	base object1;
	anotherClass object2;
	object2.memberFunction(object1);

	return 0;
}

// Features of Friend Functions
//  A friend function is a special function in C++ that in spite of not being a member function of a class has the privilege to access the private and protected data of a class.
// A friend function is a non-member function or ordinary function of a class, which is declared as a friend using the keyword “friend” inside the class. By declaring a function as a friend, all the access permissions are given to the function.
// The keyword “friend” is placed only in the function declaration of the friend function and not in the function definition or call.
// A friend function is called like an ordinary function. It cannot be called using the object name and dot operator. However, it may accept the object as an argument whose value it wants to access.
// A friend function can be declared in any section of the class i.e. public or private or protected.


//Four Pillars with real world example : 
Example : Coffee machine.

Abstraction : 
user just need to interact with the user interface like buttons for getting the different types of the coffee and he dont need to know the internal complex
implementations like how water is heated and how beans are ground , how beans, water and milk is getting mixed.

Encapsulation : 
it means binding the data members and member functions under the single entity and hiding the required members using access specifiers so here let's say
there are variables like water level and bean_level and they are private and initialise the value using constructor and there are public functions like make makeEspresso(), 
makeHotChocholate() and inside these function we are calling other function( i.e heatWater(), grindBeans(), addMilk(), pourCoffe()) which are private to the class so here we are 
binding the data member and function under the single entity and also protecting the required data members.

Polymorphism :
for polymorphism we can create a abstract class which has a pure virtual function makeCoffee()=0 & there will be seperate classes for different types of the coffee and those
classes will inherite from parent abstract class so every child class will contain the overrided virtual function, there will be a global function with object as a parameter
so using this global function we will call those overriden methods to achieve the run time polymorphism.
Important : When the function is made virtual, C++ determines which function is to be invoked at the runtime based on the type of the object pointed by the base class pointer.(instead of pointer it can be 
simply base class object).

In case of method overloading we can create the method makeCoffe with the variable parameters like 1. with default setting i.e for beans and water 2. with water level as parameter
3. with water level and beans level as a parameter.

Inheritance : 
while implementing the polymophism we have also implemented the inheritance as we are inheriting the derived classes of different coffee from the parent class.



//run time polymorphism code : 
#include <iostream>
using namespace std;

class Program{
  public:
  int a=0;
  void func(){
      cout<<"this is parent"<<endl;
  }
};

class ChildP:public Program{
  public: 
    void func(){
      cout<<"this is child"<<endl;
  }
};

int main()
{
   Program p;             
   p.func();
   ChildP p2;
   p=p2;
   p.func();
    
 or 
Program *p=new Program();             
   p->func();
   ChildP *p2=new ChildP;
   p=p2;                       //it's also ok if I did like *p=*p2; but p=*p2 or *p=p2 this is not valid as there wil a conversion issue with it.
   p->func();
    return 0;
}

// Note : Instead of above code if we inherited child from base class and just overrided the function of base in child and call them using the object of respective class then
// it will call their respective methods of class not always base class methods and it will not be run time polymorphism, run time polymorphism is when we are using the base class 
// pointer or object and pointing it to child class object.










//⭐Web development : 

Status Codes :
200-ok (request succeeded)
201-created (request succeeded and new resource has been created as a result)
204-no content (request succeeded but returning no content)
400-bad request (server could not understand the request due to invalid syntax)
401-unauthorized
403-forbiddon
404-not found
500-internal server error
503-service unavailable

//Api Structure : 
Method, Body and Headers : 

// Fetch example
fetch('https://api.example.com/data/1', {
  method: 'PUT',
  headers: {
    'Content-Type': 'application/json'
  },
  body: JSON.stringify({ key1: 'updatedValue', key2: 'updatedValue' })
})
.then(response => response.json())
.then(data => console.log(data))
.catch(error => console.error('Error:', error));

// Axios example
axios.put('https://api.example.com/data/1', {
  key1: 'updatedValue',
  key2: 'updatedValue'
}, {
  headers: {
    'Content-Type': 'application/json'
  }
})
.then(response => {
  console.log(response.data);
})
.catch(error => {
  console.error('Error:', error);
});