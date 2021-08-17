#include <iostream>
#include <memory>
#include <typeinfo>

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
    std::unique_ptr<A> a1(new A());
    std::cout << "std::unique_ptr<A> a1(new A());" << std::endl;
    writeAddr("a1", a1.get()); // a1: address

    std::unique_ptr<A> a2 = std::move(a1);
    std::cout << "std::unique_ptr<A> a2 = std::move(a1);" << std::endl;
    writeAddr("a1", a1.get()); // a1: NULL pointer
    writeAddr("a2", a2.get()); // a2: address

    std::unique_ptr<A> a3(std::move(a2));
    std::cout << "std::unique_ptr<A> a3(std::move(a2));" << std::endl;
    writeAddr("a2", a2.get()); // a2: NULL pointer
    writeAddr("a3", a3.get()); // a3: address

    return 0;
}