#include "dual.h"
#include <cmath>
#include <iostream>

double derivative(const Dual &expr, const Dual &var)
{
    Dual tmp = expr;                       // Make a copy of the expression
    tmp.setDerivative(1.0);                // Set the derivative of the expression to 1
    tmp.setValue(0.0);                     // Set the value of the expression to 0
    return tmp.value() / var.derivative(); // Return the derivative of the expression with respect to var
}

int main()
{
    Dual x(1.0); // Dual object for x with value 5 and derivative 1
    Dual y(1.0); // Dual object for y with value 3 and derivative 0

    Dual expr = y * y + exp(x); // Calculate the expression y^2 + exp(x)

    // Calculate the derivative of the expression with respect to x
    double dx = derivative(expr, x);
    std::cout << "derivative of expr with respect to x: " << dx << std::endl;

    // Calculate the derivative of the expression with respect to y
    double dy = derivative(expr, y);
    std::cout << "derivative of expr with respect to y: " << dy << std::endl;

    std::cout << "derivative of expr: " << expr.derivative() << std::endl;

    return 0;
}
