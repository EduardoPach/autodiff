# autodiff

My humble attempt to try to implement myself Forward autodiff in C++ (too much python lately)

## Dual Class for Automatic Differentiation in C++

This repository contains an implementation of a Dual class for performing automatic differentiation in C++. The Dual class overloads basic math operators (e.g., `+`, `-`, `*`, `/`) and functions from the `cmath` library (e.g., `sin`, `cos`, `exp`) to allow users to easily compute the derivative of a function at a given point.

### Usage

To use the Dual class, simply include the `dual.h` header file in your code and use the Dual class like you would any other numeric type. For example:

```cpp
#include "dual.h"

int main() {
  Dual x(3.0, 1.0); // 3.0 + 1.0*epsilon
  Dual y(4.0, 0.0); // 4.0 + 0.0*epsilon
  Dual z = x + y;   // 7.0 + 1.0*epsilon
  return 0;
}
```

The Dual class also overloads the << operator for easy printing:

```cpp
#include <iostream>
#include "dual.h"

int main() {
  Dual x(3.0, 1.0);
  std::cout << x << std::endl; // prints "3 + 1*epsilon"
  return 0;
}
```

### Limitations and Next Steps

The current state of my implementation there's no easy way to get derivatives of expressions wrt to variables in it!

So right now if you want to get $\dfrac{d}{dx}\left( y^2 + e^x\right) = exp(x)$ and $\dfrac{d}{dy}\left( y^2 + e^x\right) = 2y$ you'd have to do

```cpp
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
```

This is far from ideal, so the next step is to create a function that does this, but I'm probably making some mistakes in the calculus side.
