# autodiff
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
