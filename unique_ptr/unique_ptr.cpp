#include <iostream>
#include <memory>
#include <typeinfo>

class A {
public:
    A() {
        std::cout << "A::A()" << std::endl;
    }
    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "B::B()" << std::endl;
    }
    ~B() {
        std::cout << "B::~B()" << std::endl;
    }
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    A *a = new A();                 // A::A()
    std::unique_ptr<B> b(new B());  // B::B()
    delete a;                       // A::~A()
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}                                   // B::~B()