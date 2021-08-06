#include <iostream>
#include <memory>

class A {
public:
    A() {}
    ~A() {}
};

void writeAddr(std::string var, void *addr) {
    if (addr) {
        std::cout << "// " << var << ": " << addr << std::endl;
    } else {
        std::cout << "// " << var << ": NULL pointer" << std::endl;
    }
}

int main() {
    std::cout << "std::shared_ptr<A> a1(new A());" << std::endl;
    std::cout << "std::shared_ptr<A> a2(new A());" << std::endl;
    std::shared_ptr<A> a1(new A());
    std::shared_ptr<A> a2(new A());
    writeAddr("a1", a1.get());
    writeAddr("a2", a2.get());

    std::cout << "a1 = a2;            // copy" << std::endl;
    a1 = a2;
    writeAddr("a1", a1.get());
    writeAddr("a2", a2.get());

    std::cout << "a2 = std::move(a1); // move" << std::endl;
    a2 = std::move(a1);                  // A::~A(2)
    writeAddr("a1", a1.get());
    writeAddr("a2", a2.get());
    return 0;
}                                        // A::~A(1), C::~C(2)