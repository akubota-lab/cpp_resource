#include <iostream>
#include <memory>

class A {
public:
    A(int i) { var = i; }
    ~A() {}
    void getVar() {}
private:
    int var;
};

int main() {
    const std::auto_ptr<A> a1(new A(5));
    std::auto_ptr<A> a2 = a1; // compile error

    a2->getVar();
    a1->getVar();

    return 0;
}