#include <iostream>
#include <stdlib.h>

int function (int& y){ // y will be the address of the caller's variable x.
    std::cout << "Address of y is: " << &y << std::endl;
    y = 1;
    return y; // Copy y into the function's return value.
}

int main(int argc, char const *argv[])
{
    int x = 2;
    std::cout << "Address of x is " << &x << std::endl;
    int z = function(x); //z will be a copy of func's return value.
    std::cout << "Address of z is: " << &z << std::endl;
    std::cout << "After calling function(), x = " << x << std::endl;
    std::cout << "After calling function(), z = " << z << std::endl;
    return 0;
}