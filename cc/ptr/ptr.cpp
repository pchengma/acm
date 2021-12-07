#include <iostream>

using namespace std;

int main() {

    // 1.1 Test assigning addr of variable a to variable b:
    int a = 1;  // ptr data type
    int b = a;  // value of a is assigned to variable b
    // addr of a is not equal to addr of b, so assigning addr can be done in this way.
    std::cout << &a << std::endl;  // 0x7ffeefaa993c
    std::cout << &b << std::endl;  // 0x7ffeefaa9938

    // 1.2 Test assigning addr of pointer/object c to pointer/object d:
    int *c = new int[2];  // new an int pointer
    int *d = c;  // addr of pointer *c is assigned to pointer *d; no &c here
    c[0] = 1;  // initialize a value to c[0]
    c[1] = 2;  // initialize a value to c[1]
    // c, &(*c), d and &(*d) are addrs
    // addr of *c is equal to addr of *d, so assigning addr can be done in this way.
    std::cout << c << std::endl;  // 0x7fdc66c059f0
    std::cout << &(*c) << std::endl;  // 0x7f8b96c059f0
    std::cout << d << std::endl;  // 0x7fdc66c059f0
    std::cout << &(*d) << std::endl;  // 0x7f8b96c059f0
    // *c, *(c+1) and *(c+2) are values. The values of uninitialized variable are determined by language.
    std::cout << *c << std::endl;  // 1
    std::cout << *(c + 1) << std::endl;  // 2
    std::cout << *(d + 1) << std::endl;  // 2

    // 1.3 Test assigning addr of a pointer/object or a ptr data type to a pointer/object:
    // addr of a pointer/object can be assigned to another pointer/object in this way.
    int *e;  // Remember an addr can only be assigned to a pointer.
    e = c;
    // addr of a ptr data type can be assigned to a pointer/object in this way.
    int *f;  // Remember an addr can only be assigned to a pointer.
    f = &a;
    // addr of a pointer can also be assigned to another pointer
    f = e;
    return 0;
}
