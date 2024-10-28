/* Program name: Text File  
Author: Heritage Adigun
Date last updated: 10/28/2024
Purpose: A program that reads words from a text file and displays all the non-duplicate words.*/


#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main() {
    //Create set to store the non-duplicate words
    set<string> words;

    //Read the words from the file
    ifstream infile("file.txt");
    string word;
    while (infile >> word) {
        words.insert(word);
    }
    infile.close();

    //Print the non-duplicate words in ascending order
    for (string word : words) {
        cout << word << endl;
    }
    return 0;
}