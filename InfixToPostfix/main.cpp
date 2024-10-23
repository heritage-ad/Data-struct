/* Program name: Infix To Postfix
Author: Heritage Adigun
Date last updated: 10/23/2024 
Purpose: A program that converts an infix expression into an equivalent postfix expression*/


#include "InfixToPostfix.h"
#include <fstream>

int main() {
    InfixToPostfix converter; // Create an instance of the InfixToPostfix class
    std::ifstream inputFile("/Users/heritageadigun/Downloads/DATA STRUCT/InfixToPostfix/expressions.txt"); // Open the input file
    std::string line; // Variable to store each line of the input file

    // Check if the file opened successfully
    if (!inputFile) {
        std::cerr << "Unable to open file expressions.txt";
        return 1; // Exit if file cannot be opened
    }

    // Read each line from the file
    while (std::getline(inputFile, line)) {
        converter.getInfix(line); // Set the current line as infix expression
        converter.showInfix(); // Output the infix expression
        converter.showPostfix(); // Output the corresponding postfix expression
        std::cout << std::endl; // Print a new line for readability
    }

    inputFile.close(); // Close the input file
    return 0; // Successful execution
}