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
        std::cout << "  // " << var << ": " << addr << std::endl;
    } else {
        std::cout << "  // " << var << ": NULL pointer" << std::endl;
    }
}

int main() {
    std::cout << "int main() {" << std::endl;
    std::cout << "  std::unique_ptr<A> a1(new A());\n" << std::endl;
    std::unique_ptr<A> a1(new A());
    writeAddr("a1", a1.get());
    std::cout << std::endl;

    std::cout << "  std::unique_ptr<A> a2 = std::move(a1)\n" << std::endl;
    std::unique_ptr<A> a2 = std::move(a1);

    writeAddr("a1", a1.get());
    writeAddr("a2", a2.get());
    std::cout << std::endl;

    std::cout << "  std::unique_ptr<A> a3(std::move(a2))\n" << std::endl;
    std::unique_ptr<A> a3(std::move(a2));
    writeAddr("a2", a2.get());
    writeAddr("a3", a3.get());
    std::cout << std::endl;

    std::cout << "  return 0;" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << &a1 << std::endl;
    std::cout << &a2 << std::endl;
    std::cout << &a3 << std::endl;
    return 0;
}