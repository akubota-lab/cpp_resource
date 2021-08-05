#include <iostream>
#include <memory>
#include <typeinfo>

class A {
public:
    A() {
        std::cout << "  // -> A::A()\n" << std::endl;
    }
    ~A() {
        std::cout << "  // -> A::~A()\n" << std::endl;
    }
};

class B {
public:
    B() {
        std::cout << "  // -> B::B()\n" << std::endl;
    }
    ~B() {
        std::cout << "  // -> B::~B()\n" << std::endl;
    }
};

int main() {
    std::cout << "int main() {" << std::endl;
    std::cout << "  A *a = new A();" << std::endl;
    A *a = new A();
    std::cout << "  std::unique_ptr<B> b(new B());" << std::endl;
    std::unique_ptr<B> b(new B());
    std::cout << "  delete a;" << std::endl;
    delete a;
    std::cout << "  return 0;" << std::endl;
    std::cout << "}" << std::endl;
    return 0;
}