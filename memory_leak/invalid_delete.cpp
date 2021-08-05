#include <iostream>

int main() {
    char *var = new char('a');
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "var in main(): allocated memory address is " << (void*)var << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    delete var;
#ifdef LEAK
    delete var;
#endif
    return 0;
}