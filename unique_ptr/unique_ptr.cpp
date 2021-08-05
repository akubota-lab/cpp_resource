#include <iostream>
#include <memory>

int main() {
    //auto_ptr
    std::auto_ptr<int> aPtr1(new int(1));
    std::auto_ptr<int> aPtr2;
    aPtr1 = aPtr2;

    //unique_ptr
    std::unique_ptr<int> uPtr1(new int(1));
    std::unique_ptr<int> uPtr2;
    uPtr1 = uPtr2;
}