#include <iostream>
#include <memory>

class A {
public:
    A() {}
    ~A() {}
};

int main() {
    std::cout << "std::shared_ptr<A> a1 = std::make_shared<A>();"  << std::endl;
    std::shared_ptr<A> a1 = std::make_shared<A>();
    std::cout << "// a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    std::cout << "std::shared_ptr<A> a2 = std::shared_ptr<A> (a1);" << std::endl;
    std::shared_ptr<A> a2 = std::shared_ptr<A> (a1);
    std::cout << "// a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    std::shared_ptr<A> a3 = std::shared_ptr<A> (a1);
    std::cout << "std::shared_ptr<A> a3 = std::shared_ptr<A> (a1);" << std::endl;
    std::cout << "// a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    a1 = std::move(a2);
    std::cout << "a1 = std::move(a2);" << std::endl;
    std::cout << "// a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    a1 = std::move(a3);
    std::cout << "a1 = std::move(a3);" << std::endl;
    std::cout << "// a1.use_count() = " << a1.use_count();
    std::cout << ",  a1.unique() = " << (a1.unique() ? "True" : "False") << std::endl;

    return 0;
}