# C++ Lambda Expressions Examples

This project demonstrates various uses of lambda expressions in C++, ranging from basic to advanced concepts. Each example builds upon the previous one to show the versatility and power of lambda expressions in modern C++.

## Prerequisites

- C++11 or later
- A C++ compiler (g++ or clang++)
- Standard C++ libraries

## Building the Project

```bash
g++ -std=c++11 lambda_examples.cpp -o lambda_examples
./lambda_examples
```

## Examples Overview

### 1. Basic Lambda (No Parameters)
The simplest form of a lambda expression:
```cpp
[]() { std::cout << "Hello from a simple lambda!\n"; }
```
- `[]`: Empty capture clause
- `()`: No parameters
- Simple statement inside the lambda body

### 2. Lambda with Parameters
Demonstrates how to pass parameters to a lambda:
```cpp
[](int a, int b) { return a + b; }
```
- Takes two integers as parameters
- Returns their sum
- No capture clause needed

### 3. Capture by Value
Shows how to capture external variables by value:
```cpp
[x]() { std::cout << "Captured value: " << x << std::endl; }
```
- `[x]`: Captures variable x by value (makes a copy)
- Cannot modify the captured variable
- Value is frozen at the point of capture

### 4. Capture by Reference
Demonstrates capturing variables by reference:
```cpp
[&y]() { 
    y += 5; // Modifies the original variable
    std::cout << "Modified y: " << y << std::endl; 
}
```
- `[&y]`: Captures y by reference
- Can modify the original variable
- Changes are visible outside the lambda

### 5. Mixed Capture Modes
Shows how to use different capture modes together:
```cpp
[=, &b]() { /* ... */ }
```
- `=`: Captures all variables by value
- `&b`: Explicitly captures b by reference
- Demonstrates fine-grained capture control

### 6. Lambda with STL Algorithms
Practical example using lambda with STL algorithms:
```cpp
std::copy_if(numbers.begin(), numbers.end(), 
             std::back_inserter(evenNumbers), 
             [](int n) { return n % 2 == 0; });
```
- Used with `std::copy_if` to filter even numbers
- Shows how lambdas integrate with STL algorithms
- Clean and readable alternative to function objects

### 7. Mutable Lambda
Demonstrates modifying captured variables:
```cpp
[counter]() mutable { return ++counter; }
```
- `mutable` keyword allows modification of captured variables
- Each call can modify its own copy of the captured variables
- Useful for maintaining state between calls

### 8. Complex Lambda (Function Factory)
Advanced example showing lambda returning another lambda:
```cpp
auto multiplier = [](int factor) {
    return [factor](int x) { return x * factor; };
};
```
- Creates a closure that generates customized functions
- Inner lambda captures factor from outer lambda
- Demonstrates function composition and factories

## Output Example
Running the program will demonstrate each type of lambda expression with clear output showing the results of each operation.

## Notes
- Lambda expressions provide a convenient way to define anonymous function objects
- They are particularly useful for short functions used in a limited scope
- Capture clauses provide flexibility in how external variables are accessed
- Modern C++ encourages the use of lambdas for cleaner, more maintainable code

## Further Reading
- [C++ Lambda Expressions (cppreference.com)](https://en.cppreference.com/w/cpp/language/lambda)
- [C++11 Lambda Expressions](https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp)
