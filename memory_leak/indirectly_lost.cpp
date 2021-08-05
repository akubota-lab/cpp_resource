#include <iostream>

class A {
public:
    A() {
        var = new int(5);
    }
    ~A() {
        delete var;
    }
private:
    int *var;
};

int main() {
    A *a = new A();
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "a in main(): allocated memory address is " << (void*)a << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
#ifndef LEAK
    delete a;
#endif
    return 0;
}