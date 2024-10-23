#ifndef INFIXTOPREFIX_H
#define INFIXTOPREFIX_H

#include <iostream>
#include <string>
#include <stack>

// Class to handle the conversion of infix expressions to postfix
class InfixToPostfix {
private:
    std::string infix;   // Stores the infix expression
    std::string postfix;  // Stores the resulting postfix expression

public:
    InfixToPostfix();         // Constructor
    ~InfixToPostfix();        // Destructor

    void getInfix(const std::string& expression); // Set the infix expression
    void showInfix() const;   // Output the infix expression
    void showPostfix() const;  // Output the postfix expression
    void convertToPostfix();   // Convert infix to postfix
    bool precedence(char op1, char op2) const;  // Check operator precedence

private:
    bool isOperand(char ch) const; // Check if a character is an operand
    int getPrecedence(char op) const; // Get precedence level of an operator
};

#endif