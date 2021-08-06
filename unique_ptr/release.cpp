#include <iostream>
#include <memory>

class A {
public:
    A() {
        std::cout << "A::A()" << std::endl;
    }
    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::unique_ptr<A> a1(new A()); // A::A()
    A *a2 = a1.release();
#ifndef LEAK
    delete a2;                      // A::~A()
#endif
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}