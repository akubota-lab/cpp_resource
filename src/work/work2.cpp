#include<iostream>
#include<typeinfo>

class A {
public:
    int val = 5.0;
};

class B {
public:
    double val = 5;
};

class C {
public:
    char val[1024];
};

template<class T>
void detail_ptr(const T val){
    std::cout << val << std::endl;
    std::cout << typeid(val).name() << std::endl;
    std::cout << sizeof(val) << "\n" << std::endl;
}

template<class T>
void detail_cls_obj(const T val){
    std::cout << typeid(val).name() << std::endl;
    std::cout << sizeof(val) << "\n" << std::endl;
}

template<class T>
void detail_1st_obj(const T val){
    std::cout << val << std::endl;
    std::cout << typeid(val).name() << std::endl;
    std::cout << sizeof(val) << "\n" << std::endl;
}


int main(){
    int int1 = 5;
    int int2 = 5;
    int int3 = 5;
    int int4 = 5;
    
    double double1 = 5;
    double double2 = 5;
    
    A *a_ptr1 = new A();
    A *a_ptr2 = new A();

    A a1;
    A a2;

    B *b_ptr1 = new B();
    B *b_ptr2 = new B();

    B b1;
    B b2;

    C *c_ptr1 = new C();
    C *c_ptr2 = new C();

    C c1;
    C c2;

    detail_1st_obj(int1);

    detail_ptr(a_ptr1);
    detail_cls_obj(a1);

    detail_ptr(b_ptr1);
    detail_cls_obj(b1);

    detail_ptr(c_ptr1);
    detail_cls_obj(c1);

    return 0;
}