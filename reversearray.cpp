/* Program name: Reverse Array 
Author: Heritage Adigun
Date last updated: 10/30/2024
Purpose: A program that reverses elements of an array between two specified indices using recursion . */

#include <iostream>
#include <vector>
using namespace std;

// Function to reverse elements in the array between low and high indices
void reverseArray(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    // Swap elements at low and high
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;

    // Recursive call for the next pair
    reverseArray(arr, low + 1, high - 1);
}

int main() {
    int length, low, high;

    // Prompt user for the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> length;

    // Create an array of the given length
    vector<int> intArray(length);

    // Prompt user for the array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < length; ++i) {
        cin >> intArray[i];
    }

    // Prompt user for low and high indices
    cout << "Enter the low index: ";
    cin >> low;
    cout << "Enter the high index: ";
    cin >> high;

    // Ensure low and high are valid
    if (low >= 0 && high < length && low < high) {
        // Call the recursive function to reverse the array
        reverseArray(intArray, low, high);

        // Output the modified array
        cout << "Array after reversing elements between indices " << low << " and " << high << ":" << endl;
        for (int i = 0; i < length; ++i) {
            cout << intArray[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid indices. Please ensure 0 <= low < high < length." << endl;
    }

    return 0;
}