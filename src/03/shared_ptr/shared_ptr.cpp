#include <iostream>
#include <memory>
#include <typeinfo>

class A {
public:
    A(int i) {
        std::cout << "A::A(" << i << ")" << std::endl;
        var = i;
    }
    ~A() {
        std::cout << "A::~A(" << var << ")" << std::endl;
    }
private:
    int var;
};

class B {
public:
    B(int i) {
        std::cout << "B::B(" << i << ")" << std::endl;
        var = i;
    }
    ~B() {
        std::cout << "B::~B(" << var << ")" << std::endl;
    }
private:
    int var;
};

class C {
public:
    C(int i) {
        std::cout << "C::C(" << i << ")" << std::endl;
        var = i;
    }
    ~C() {
        std::cout << "C::~C(" << var << ")" << std::endl;
    }
private:
    int var;
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::shared_ptr<A> a1(new A(1));     // A::A(1)
    {
        std::shared_ptr<B> b1(new B(1)); // B::B(1)
    }                                    // B::~B(1)
    std::shared_ptr<C> c1;
    {
        std::shared_ptr<C> c2(new C(2)); // C::C(2)
        c1 = c2;
    }
    std::shared_ptr<A> a2(new A(2));     // A::A(2)
    a2 = std::move(a1);                  // A::~A(2)
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}                                        // A::~A(1), C::~C(2)