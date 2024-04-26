#include <iostream>

int main() {
    char operation;
    double num1, num2;

    std::cout << "Welcome to Simple Calculator\n";
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero!\n";
            }
            break;
        default:
            std::cout << "Error: Invalid operation!\n";
            break;
    }

    return 0;
}
