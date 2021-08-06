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
    void setValue(int i) {
        std::cout << "A::setValue(" << i << ")" << std::endl;
        var = i;
    }
    void writeValue() {
        std::cout << "A::writeValue() => " << var << std::endl;
    }
private:
    int var;
};

void func(std::unique_ptr<A> a) {
    std::cout << ">>>>>>>>>> func()" << std::endl;
    a->setValue(10); // A::setValue(10)
    a->writeValue(); // A::writeValue() => 10
    std::cout << "<<<<<<<<<< func()" << std::endl;
}                    // A::~A(10)

int main() {
    std::cout << ">>>>>>>>>> main()" << std::endl;
    std::unique_ptr<A> a = std::make_unique<A>(5); // A::A(5)
    a->writeValue();                               // A::writeValue() => 5
    func(std::move(a));                            // -> func()
    a->writeValue();                               // segmentation fault
    std::cout << "<<<<<<<<<< main()" << std::endl;
    return 0;
}