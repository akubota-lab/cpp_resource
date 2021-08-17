#include <iostream>
#include <memory>

class A {
public:
    A(int i) {
        std::cout << "A::A(" << i << ")" << std::endl;
        var = new int(i);
    }
    ~A() {
        std::cout << "A::~A()" << std::endl;
    }
    void close() {
        std::cout << "A::close()" << std::endl;
        delete var;
    }
private:
    int *var;
};

void deleteA(A *a) {
    std::cout << ">>>>>>>>>> deleteA()" << std::endl;
    a->close();                                                   // A::close()
    std::cout << "<<<<<<<<<< deleteA()" << std::endl;
    delete a;
}                                                                 // A::~A()

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
#ifdef LEAK
    std::unique_ptr<A> a(new A(5));                               // A::A(5)
#else
    std::unique_ptr<A, decltype(&deleteA)> a(new A(5), &deleteA); // A::A(5)
#endif
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}                                                                 // deleteA()