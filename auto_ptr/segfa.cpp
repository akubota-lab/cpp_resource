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
    std::auto_ptr<A> a1(new A(5)); // A::A(5)
    std::auto_ptr<A> a2 = a1;

    a2->getVar();                  // A::getVar() => 5 // OK
    a1->getVar();                  // Segmentation fault

    std::cout << "<<<<<<<<<< main() end" << std::endl;
    return 0;
}