#include <iostream>
#include <memory>

class A {
public:
    A(int i) {}
    ~A() {}
    void getVar() {}
private:
    int var;
};

int main() {
    std::unique_ptr<A> a1(new A(5));
    std::unique_ptr<A> a2 = a1;

    a2->getVar();
    a1->getVar();

    return 0;
}