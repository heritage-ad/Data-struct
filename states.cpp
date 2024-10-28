/* 
    Program name: State  
    Author: Heritage Adigun
    Date last updated: 10/28/2024
    Purpose: A program that stores pairs of each state and its capital in a map and displays expected output with intended input.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

// Open file and handle file open error
void loadStates(std::map<std::string, std::string>& states, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << "Malformed line: " << line << std::endl;
            continue;
        }

        std::string state = line.substr(0, commaPos);
        std::string capital = line.substr(commaPos + 1);
        states[state] = capital;
    }

    file.close();
}

// Output capital for a given state
void printCapital(const std::string& state, const std::string& capital) {
    std::cout << "The capital of " << state << " is " << capital << "." << std::endl;
}

int main() {
    // Map to store state-capital pairs
    std::map<std::string, std::string> states;
    std::string filename = "/Users/heritageadigun/Downloads/DATA STRUCT/states.txt"; // File path 
    loadStates(states, filename);

    if (states.empty()) {
        std::cerr << "No state information loaded. Exiting program." << std::endl; 
        return 1;
    }

    std::string input;
    while (true) {
        std::cout << "Enter state name (or 'exit' to quit): ";
        std::getline(std::cin, input);

        if (input == "exit") {
            break;
        }

        auto it = states.find(input);
        if (it != states.end()) {
            printCapital(it->first, it->second);
        } else {
            std::cerr << "Invalid state name entered." << std::endl;
        }
    } 

    return 0;
}
