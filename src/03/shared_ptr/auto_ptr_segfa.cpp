#include <iostream>
#include <memory>

class A {
public:
    A(int i) {
        std::cout << "A::A(" << i << ")" << std::endl;
        var = i;
    }
    ~A() {
        std::cout << "A::~A(" << var << ")" << std::endl;
    }
    void getVar() {
        std::cout << "A::getVar() => " << var << std::endl;
    }
private:
    int var;
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::shared_ptr<A> a1(new A(5)); // A::A(5)
    std::shared_ptr<A> a2 = a1;

    a2->getVar();                  // A::getVar() => 5 // OK
    a1->getVar();                  // A::getVar() => 5 // OK

    std::cout << "<<<<<<<<<< main() end" << std::endl;
    return 0;
} // A::~A(5)