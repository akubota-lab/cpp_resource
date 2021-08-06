#include <iostream>
#include <memory>

class A {
public:
    A() { std::cout << "// -> A::A()" << std::endl; }
    ~A() { std::cout << "// -> A::~A()" << std::endl; }
};

int main() {
    std::cout << "std::shared_ptr<A> a1 = std::make_shared<A>();"  << std::endl;
    std::shared_ptr<A> a1 = std::make_shared<A>();
    std::cout << "  // a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    std::cout << "std::weak_ptr<A> a2 = std::shared_ptr<A> (a1);" << std::endl;
    std::weak_ptr<A> a2 = std::shared_ptr<A> (a1);
    std::cout << "  // a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;
    std::cout << "  // a2.use_count() = " << a2.use_count();
    std::cout << ",  a2.expired() = " << (a2.expired() ? "True" : "False") << std::endl;

    std::cout << "std::shared_ptr<A> a3 = a2.lock();" << std::endl;
    std::shared_ptr<A> a3 = a2.lock();
    std::cout << "  // a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;
    std::cout << "  // a2.use_count() = " << a2.use_count();
    std::cout << ",  a2.expired() = " << (a2.expired() ? "True" : "False") << std::endl;

    std::cout << "a3.reset();" << std::endl;
    a3.reset();
    std::cout << "  // a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;
    std::cout << "  // a2.use_count() = " << a2.use_count();
    std::cout << ",  a2.expired() = " << (a2.expired() ? "True" : "False") << std::endl;

    std::cout << "a1.reset()" << std::endl;
    a1.reset();
    std::cout << "  // a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;
    std::cout << "  // a2.use_count() = " << a2.use_count();
    std::cout << ",  a2.expired() = " << (a2.expired() ? "True" : "False") << std::endl;

    return 0;
}