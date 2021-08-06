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
#ifdef LEAK
    void setPtr(std::shared_ptr<A> p) {
        std::shared_ptr<A> tmp = p;
#else
    void setPtr(std::weak_ptr<A> p) {
        std::shared_ptr<A> tmp = p.lock();
#endif
        std::cout << "A::A(" << var << ")->setPtr(A(" << tmp->getVar() << "))" << std::endl;
        ptr = p;
    }
    int getVar() {
        return var;
    }
private:
#ifdef LEAK
    std::shared_ptr<A> ptr;
#else
    std::weak_ptr<A> ptr;
#endif
    int var;
};

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::shared_ptr<A> a1 = std::make_shared<A>(1);
    std::shared_ptr<A> a2 = std::make_shared<A>(2);
    a1->setPtr(a2);
    a2->setPtr(a1);
    std::cout << "<<<<<<<<<< main()" << std::endl;
}