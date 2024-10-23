#include "InfixToPostfix.h"

// Constructor: Initializes the object
InfixToPostfix::InfixToPostfix() {}

// Destructor: Cleans up when the object is destroyed
InfixToPostfix::~InfixToPostfix() {}

// Set the infix expression and convert it to postfix
void InfixToPostfix::getInfix(const std::string& expression) {
    infix = expression;  // Store the infix expression
    convertToPostfix();  // Convert to postfix
}

// Output the stored infix expression
void InfixToPostfix::showInfix() const {
    std::cout << "Infix Expression: " << infix << std::endl;
}

// Output the converted postfix expression
void InfixToPostfix::showPostfix() const {
    std::cout << "Postfix Expression: " << postfix << std::endl;
}

// Convert the infix expression to postfix notation
void InfixToPostfix::convertToPostfix() {
    postfix.clear(); // Clear any previous postfix expression
    std::stack<char> stack; // Stack to hold operators and parentheses

    // Process each symbol in the infix expression
    for (char sym : infix) {
        if (isOperand(sym)) {
            postfix += sym; // Append operands directly to postfix
        } else if (sym == '(') {
            stack.push(sym); // Push left parenthesis onto the stack
        } else if (sym == ')') {
            // Pop from stack until a left parenthesis is found
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top(); // Append operator to postfix
                stack.pop();
            }
            stack.pop(); // Discard the left parenthesis
        } else { // Operator
            // Pop operators from the stack that have greater or equal precedence
            while (!stack.empty() && precedence(stack.top(), sym)) {
                postfix += stack.top(); // Append operator to postfix
                stack.pop();
            }
            stack.push(sym); // Push current operator onto the stack
        }
    }

    // Pop any remaining operators in the stack
    while (!stack.empty()) {
        postfix += stack.top(); // Append remaining operators to postfix
        stack.pop();
    }
}

// Check if the character is an operand (alphanumeric)
bool InfixToPostfix::isOperand(char ch) const {
    return std::isalnum(ch); // Return true for alphanumeric characters
}

// Get the precedence level of an operator
int InfixToPostfix::getPrecedence(char op) const {
    switch (op) {
        case '+':
        case '-':
            return 1; // Lowest precedence
        case '*':
        case '/':
            return 2; // Higher precedence
        default:
            return 0; // Non-operator
    }
}

// Check if the first operator has greater or equal precedence than the second
bool InfixToPostfix::precedence(char op1, char op2) const {
    return getPrecedence(op1) >= getPrecedence(op2);
}