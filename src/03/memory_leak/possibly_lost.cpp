#include <iostream>

char *ptr;

int main() {
    char *var = new char[100];
    ptr = &var[10];
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "var in main(): allocated memory address is " << (void*)var << std::endl;
    std::cout << "ptr in main(): allocated memory address is " << (void*)ptr << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
#ifndef LEAK
    delete[] var;
#endif
    return 0;
}