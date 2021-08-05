#include <iostream>
#include <memory>

class A {
public:
    A(int i) {
        std::cout << "  // -> A::A() (var = " << i << ")\n" << std::endl;
    }
    ~A() {
        std::cout << "  // -> A::~A() (var = " << var << ")\n" << std::endl;
    }
    void getVar() {
        std::cout << "  // var = " << var << "\n" << std::endl;
    }
private:
    int var;
};

int main() {
    std::cout << "int main() {" << std::endl;
    std::cout << "  std::auto_ptr<A> a1(new A(5))" << std::endl;
    std::auto_ptr<A> a1(new A(5));
    std::cout << "  std::auto_ptr<A> a2 = a1" << std::endl;
    std::auto_ptr<A> a2 = a1;

    std::cout << std::endl;
    std::cout << "  a2->getVar() // OK" << std::endl;
    a2->getVar();
    std::cout << "  a1->getVar() // NG" << std::endl;
    a1->getVar();

    std::cout << "  return 0;" << std::endl;
    std::cout << "}" << std::endl;
    return 0;
}