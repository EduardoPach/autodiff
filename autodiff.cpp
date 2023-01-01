#include "dual.h"
#include <cmath>
#include <iostream>

int main()
{
    // Compute the derivative of sin(x) at x = 1
    Dual x(1.0, 1.0); // x = 1, dx/dx = 1
    Dual y = sin(x);  // y = sin(1), dy/dx = cos(1)
    std::cout << "y = " << y.value() << ", dy/dx = " << y.derivative() << std::endl;
    return 0;
}