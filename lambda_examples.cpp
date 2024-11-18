#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void demonstrateLambdaExpressions() {
    // 1. Simplest Lambda: No parameters, no capture
    std::cout << "1. Basic Lambda (No parameters):\n";
    auto simpleLambda = []() { 
        std::cout << "Hello from a simple lambda!\n"; 
    };
    simpleLambda(); // Invoke the lambda

    // 2. Lambda with parameters
    std::cout << "\n2. Lambda with Parameters:\n";
    auto addNumbers = [](int a, int b) { 
        return a + b; 
    };
    std::cout << "5 + 3 = " << addNumbers(5, 3) << std::endl;

    // 3. Capture by value
    std::cout << "\n3. Capture by Value:\n";
    int x = 10;
    auto captureByValue = [x]() { 
        std::cout << "Captured value: " << x << std::endl; 
    };
    captureByValue(); // x is captured by value

    // 4. Capture by reference
    std::cout << "\n4. Capture by Reference:\n";
    int y = 20;
    auto captureByReference = [&y]() { 
        y += 5; // Modifies the original variable
        std::cout << "Modified y: " << y << std::endl; 
    };
    captureByReference();
    std::cout << "y after lambda: " << y << std::endl;

    // 5. Capture all by value and reference
    std::cout << "\n5. Capture All:\n";
    int a = 1, b = 2, c = 3;
    auto captureAll = [=, &b]() { 
        // Captures a and c by value, b by reference
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        b += 10; // Modifies b
    };
    captureAll();
    std::cout << "b after lambda: " << b << std::endl;

    // 6. Lambda with STL algorithms
    std::cout << "\n6. Lambda with STL Algorithms:\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Filter even numbers
    std::vector<int> evenNumbers;
    std::copy_if(numbers.begin(), numbers.end(), 
                 std::back_inserter(evenNumbers), 
                 [](int n) { return n % 2 == 0; });
    
    std::cout << "Even numbers: ";
    for (int num : evenNumbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 7. Mutable Lambda
    std::cout << "\n7. Mutable Lambda:\n";
    int counter = 0;
    auto mutableLambda = [counter]() mutable { 
        return ++counter; 
    };
    std::cout << "First call: " << mutableLambda() << std::endl;
    std::cout << "Second call: " << mutableLambda() << std::endl;

    // 8. Complex Lambda: Returning another function
    std::cout << "\n8. Lambda Returning a Function:\n";
    auto multiplier = [](int factor) {
        return [factor](int x) { 
            return x * factor; 
        };
    };
    
    auto doubler = multiplier(2);
    auto tripler = multiplier(3);
    
    std::cout << "Double 5: " << doubler(5) << std::endl;
    std::cout << "Triple 5: " << tripler(5) << std::endl;
}

int main() {
    demonstrateLambdaExpressions();
    return 0;
}
