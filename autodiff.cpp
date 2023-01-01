#include "dual.h"
#include <cmath>
#include <iostream>

int main()
{
    Dual x(1.0);
    Dual y(1.0, 0.0);

    Dual expr_wrt_x = y * y + exp(x);

    y.setDerivative(1.0);
    x.setDerivative(0.0);

    Dual expr_wrt_y = y * y + exp(x);

    std::cout << "dexpr/dx: " << expr_wrt_x.derivative() << std::endl;
    std::cout << "dexpr/dy: " << expr_wrt_y.derivative() << std::endl;

    return 0;
}