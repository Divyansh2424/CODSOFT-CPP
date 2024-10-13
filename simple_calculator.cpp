#include <iostream>
using namespace std;

int main() {
    char operation;
    float num1, num2;

    // Display options
    cout << "Simple Calculator" << endl;
    cout << "Select an operation (+, -, *, /): ";
    cin >> operation;

    // Take two numbers as input
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Perform the calculation based on the chosen operation
    switch (operation) 
    {
        case '+':
            cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }
    return 0;
}