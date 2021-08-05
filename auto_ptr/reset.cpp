#include <iostream>
#include <memory>

class A {
public:
    A(int i) {
        std::cout << "  // -> A::A() (m_var = " << i << ")\n" << std::endl;
        m_var = i;
    }
    ~A() {
        std::cout << "  // -> A::~A() (m_var = " << m_var << ")\n" << std::endl;
    }
private:
    int m_var;
};

int main() {
    std::cout << "int main() {" << std::endl;
    std::cout << "  std::auto_ptr<A> a(new A(5))" << std::endl;
    std::auto_ptr<A> a(new A(5));
    std::cout << "  a.reset(new A(10))" << std::endl;
    a.reset(new A(10));
    std::cout << "  return 0;" << std::endl;
    std::cout << "}" << std::endl;
    return 0;
}