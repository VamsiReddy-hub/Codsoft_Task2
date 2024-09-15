#include <iostream>
#include <cmath>   
#include <vector>   
#include <limits>    

struct Calculation {
    double num1;
    double num2;
    char operation;
    double result;
};

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void displayHistory(const std::vector<Calculation>& history) {
    if (history.empty()) {
        std::cout << "No calculations performed yet." << std::endl;
        return;
    }

    std::cout << "\nHistory of Calculations: " << std::endl;
    for (size_t i = 0; i < history.size(); ++i) {
        std::cout << history[i].num1 << " " << history[i].operation << " " 
                  << history[i].num2 << " = " << history[i].result << std::endl;
    }
    std::cout << std::endl;
}


double performCalculation(double num1, double num2, char operation, bool& validOperation) {
    double result = 0;
    validOperation = true;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: Division by zero is undefined." << std::endl;
                validOperation = false;
            } else {
                result = num1 / num2;
            }
            break;
        case '%':
            if (num2 == 0) {
                std::cout << "Error: Modulus by zero is undefined." << std::endl;
                validOperation = false;
            } else {
                result = static_cast<int>(num1) % static_cast<int>(num2);
            }
            break;
        case '^':
            result = std::pow(num1, num2);
            break;
        case 'r':
            if (num1 < 0) {
                std::cout << "Error: Cannot calculate square root of a negative number." << std::endl;
                validOperation = false;
            } else {
                result = std::sqrt(num1);
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
            validOperation = false;
            break;
    }
    return result;
}

int main() {
    std::vector<Calculation> history;  
    char choice;
    double num1, num2, result;
    char operation;
    bool validOperation;
    
    std::cout << "Welcome to the Advanced Calculator!" << std::endl;

    do {
        std::cout << "Enter the first number: ";
        while (!(std::cin >> num1)) {
            clearInput();
            std::cout << "Invalid input. Please enter a number: ";
        }

        std::cout << "Enter an operation (+, -, *, /, %, ^, r for square root): ";
        std::cin >> operation;

      
        if (operation != 'r') {
            std::cout << "Enter the second number: ";
            while (!(std::cin >> num2)) {
                clearInput();
                std::cout << "Invalid input. Please enter a number: ";
            }
        } else {
            num2 = 0; 
        }

        result = performCalculation(num1, num2, operation, validOperation);

        if (validOperation) {
            std::cout << "Result: " << result << std::endl;

            
            history.push_back({num1, num2, operation, result});
        }

        std::cout << "Do you want to see the history of calculations? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            displayHistory(history);
        }

       
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;

        clearInput();
    } while (choice == 'y' || choice == 'Y');

    std::cout << "Thank you for using the Advanced Calculator. Goodbye!" << std::endl;

    return 0;
}
