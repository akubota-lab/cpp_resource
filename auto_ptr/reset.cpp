#include <iostream>
#include <memory>

class A {
public:
    A(int i) {
        std::cout << "A::A(" << i << ")" << std::endl;
        m_var = i;
    }
    ~A() {
        std::cout << "A::~A(" << m_var << ")" << std::endl;
    }
private:
    int m_var;
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::auto_ptr<A> a(new A(5)); // A::A(5)
    a.reset(new A(10));           // A::A(10), A::~A(5)
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}                                 // A::~A(10)