/* Program name: Recursive Star Pattern
Author: Heritage Adigun
Date last updated: 10/30/2024
Purpose: A program that generates a pattern of stars by taking the parameter of a nonnegative integer . */



#include <iostream>

using namespace std;

// Recursive function to display lines in the specified pattern
void dispLines(int n) {
    if (n == 1) {
        cout << "*" << endl;
        cout << "*" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << "*";
        }
        cout << endl;
        dispLines(n - 1);
        for (int i = 1; i <= n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter a non-negative integer to display the star pattern: ";
    cin >> n;

    if (n > 0) {
        dispLines(n);
    } else {
        cout << "Please enter a positive integer!" << endl;
    }

    return 0;
}
