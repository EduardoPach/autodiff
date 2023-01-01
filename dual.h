#ifndef DUAL_H
#define DUAL_H

#include <cmath>
#include <iostream>

// Forward declarations
class Dual;
Dual sin(const Dual &x);
Dual cos(const Dual &x);
Dual tan(const Dual &x);
Dual asin(const Dual &x);
Dual acos(const Dual &x);
Dual atan(const Dual &x);
Dual atan2(const Dual &y, const Dual &x);
Dual sinh(const Dual &x);
Dual cosh(const Dual &x);
Dual tanh(const Dual &x);
Dual asinh(const Dual &x);
Dual acosh(const Dual &x);
Dual atanh(const Dual &x);
Dual exp(const Dual &x);
Dual log(const Dual &x);
Dual log10(const Dual &x);
Dual sqrt(const Dual &x);
Dual cbrt(const Dual &x);
Dual fabs(const Dual &x);

class Dual
{
public:
    // Constructors
    Dual(double value, double derivative) : value_(value), derivative_(derivative) {}
    Dual(double value) : value_(value), derivative_(0.0) {}
    Dual() : value_(0.0), derivative_(0.0) {}

    // Accessors
    double value() const { return value_; }
    double derivative() const { return derivative_; }

    // Unary arithmetic operators
    Dual operator-() const { return Dual(-value_, -derivative_); }
    Dual &operator+=(const Dual &other);
    Dual &operator-=(const Dual &other);
    Dual &operator*=(const Dual &other);
    Dual &operator/=(const Dual &other);

    // Binary arithmetic operators
    friend Dual operator+(const Dual &a, const Dual &b);
    friend Dual operator-(const Dual &a, const Dual &b);
    friend Dual operator*(const Dual &a, const Dual &b);
    friend Dual operator/(const Dual &a, const Dual &b);

    // Comparision operators
    friend bool operator==(const Dual &a, const Dual &b);
    friend bool operator!=(const Dual &a, const Dual &b);
    friend bool operator<(const Dual &a, const Dual &b);
    friend bool operator>(const Dual &a, const Dual &b);
    friend bool operator<=(const Dual &a, const Dual &b);
    friend bool operator>=(const Dual &a, const Dual &b);

    // Stream operator
    friend std::ostream &operator<<(std::ostream &os, const Dual &a);

    // Math functions
    friend Dual sin(const Dual &x);
    friend Dual cos(const Dual &x);
    friend Dual tan(const Dual &x);
    friend Dual asin(const Dual &x);
    friend Dual acos(const Dual &x);
    friend Dual atan(const Dual &x);
    friend Dual atan2(const Dual &y, const Dual &x);
    friend Dual sinh(const Dual &x);
    friend Dual cosh(const Dual &x);
    friend Dual tanh(const Dual &x);
    friend Dual asinh(const Dual &x);
    friend Dual acosh(const Dual &x);

    friend Dual atanh(const Dual &x);
    friend Dual exp(const Dual &x);
    friend Dual log(const Dual &x);
    friend Dual log10(const Dual &x);
    friend Dual sqrt(const Dual &x);
    friend Dual cbrt(const Dual &x);
    friend Dual fabs(const Dual &x);

private:
    double value_;
    double derivative_;
};

// Unary arithmetic operators
inline Dual &Dual::operator+=(const Dual &other)
{
    value_ += other.value_;
    derivative_ += other.derivative_;
    return *this;
}

inline Dual &Dual::operator-=(const Dual &other)
{
    value_ -= other.value_;
    derivative_ -= other.derivative_;
    return *this;
}

inline Dual &Dual::operator*=(const Dual &other)
{
    derivative_ = value_ * other.derivative_ + derivative_ * other.value_;
    value_ *= other.value_;
    return *this;
}

inline Dual &Dual::operator/=(const Dual &other)
{
    derivative_ = (derivative_ * other.value_ - value_ * other.derivative_) / (other.value_ * other.value_);
    value_ /= other.value_;
    return *this;
}

// Binary arithmetic operators
inline Dual operator+(const Dual &a, const Dual &b)
{
    Dual result = a;
    result += b;
    return result;
}

inline Dual operator-(const Dual &a, const Dual &b)
{
    Dual result = a;
    result -= b;
    return result;
}

inline Dual operator*(const Dual &a, const Dual &b)
{
    Dual result = a;
    result *= b;
    return result;
}

inline Dual operator/(const Dual &a, const Dual &b)
{
    Dual result = a;
    result /= b;
    return result;
}

// Comparison operators
inline bool operator==(const Dual &a, const Dual &b)
{
    return a.value_ == b.value_ && a.derivative_ == b.derivative_;
}

inline bool operator!=(const Dual &a, const Dual &b)
{
    return !(a == b);
}

inline bool operator<(const Dual &a, const Dual &b)
{
    return a.value_ < b.value_;
}

inline bool operator>(const Dual &a, const Dual &b)
{
    return b < a;
}

inline bool operator<=(const Dual &a, const Dual &b)
{
    return !(b < a);
}

inline bool operator>=(const Dual &a, const Dual &b)
{
    return !(a < b);
}

// Math functions
inline Dual sin(const Dual &x)
{
    return Dual(std::sin(x.value_), x.derivative_ * std::cos(x.value_));
}

inline Dual cos(const Dual &x)
{
    return Dual(std::cos(x.value_), -x.derivative_ * std::sin(x.value_));
}

inline Dual acos(const Dual &x)
{
    return Dual(std::acos(x.value_), -x.derivative_ / std::sqrt(1 - x.value_ * x.value_));
}

inline Dual atan(const Dual &x)
{
    return Dual(std::atan(x.value_), x.derivative_ / (1 + x.value_ * x.value_));
}

inline Dual atan2(const Dual &y, const Dual &x)
{
    return Dual(std::atan2(y.value_, x.value_), (x.value_ * y.derivative_ - y.value_ * x.derivative_) / (x.value_ * x.value_ + y.value_ * y.value_));
}

inline Dual sinh(const Dual &x)
{
    return Dual(std::sinh(x.value_), x.derivative_ * std::cosh(x.value_));
}

inline Dual cosh(const Dual &x)
{
    return Dual(std::cosh(x.value_), x.derivative_ * std::sinh(x.value_));
}

inline Dual tanh(const Dual &x)
{
    double value = std::tanh(x.value_);
    return Dual(value, x.derivative_ * (1 - value * value));
}

inline Dual asinh(const Dual &x)
{
    return Dual(std::asinh(x.value_), x.derivative_ / std::sqrt(x.value_ * x.value_ + 1));
}

inline Dual acosh(const Dual &x)
{
    return Dual(std::acosh(x.value_), x.derivative_ / std::sqrt(x.value_ * x.value_ - 1));
}

inline Dual atanh(const Dual &x)
{
    return Dual(std::atanh(x.value_), x.derivative_ / (1 - x.value_ * x.value_));
}

inline Dual exp(const Dual &x)
{
    double value = std::exp(x.value_);
    return Dual(value, x.derivative_ * value);
}

inline Dual log(const Dual &x)
{
    return Dual(std::log(x.value_), x.derivative_ / x.value_);
}

inline Dual log10(const Dual &x)
{
    return Dual(std::log10(x.value_), x.derivative_ / (x.value_ * std::log(10)));
}

inline Dual sqrt(const Dual &x)
{
    double value = std::sqrt(x.value_);
    return Dual(value, x.derivative_ / (2 * value));
}

inline Dual cbrt(const Dual &x)
{
    double value = std::cbrt(x.value_);
    return Dual(value, x.derivative_ / (3 * value * value));
}

inline Dual fabs(const Dual &x)
{
    if (x.value_ < 0)
    {
        return Dual(-x.value_, -x.derivative_);
    }
    return Dual(x.value_, x.derivative_);
}

// Stream insertion operator
inline std::ostream &operator<<(std::ostream &os, const Dual &x)
{
    return os << x.value_ << " + " << x.derivative_ << "*epsilon";
}

#endif // DUAL_H