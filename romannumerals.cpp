/* Program name: Roman Numeral
Author: Heritage Adigun
Date last updated: 10/21/2024
Purpose: A program that converts a number entered in Roman numerals to decimal form */

#include <iostream>
#include <string>
#include <map>

class romanType { //Define the romantype class
    public: 
    void setRoman (const std::string& roman);
    void printRoman() const;
    void printInteger() const;

    private:
    std::string romanNumeral;
    int integerEquivalent;

    int romanToInteger (const std::string& roman);
};

//implementation of romantype class methods
void romanType::setRoman(const std::string& roman) {
    romanNumeral = roman;
    integerEquivalent = romanToInteger(roman);
}
void romanType::printRoman() const {
    std::cout << "Roman Numeral: " << romanNumeral << std::endl;
}
void romanType::printInteger() const {
    std::cout << "Integer Equivalent: " << integerEquivalent << std::endl;
}
int romanType::romanToInteger(const std::string& roman) {
    std::map <char, int> romanValues = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };
    int total= 0;
    int length = roman.size();

    for (int i = 0; i < length; ++i) {
        if (i + 1 < length && romanValues [roman[i]] < romanValues[roman[i + 1]]) {
            total -= romanValues[roman[i]];
        } else {
            total += romanValues[roman[i]];
        }

    }
    return total;
}

//main function to test romantype
int main() {
    romanType romanNumber;

    romanNumber.setRoman("MCXIV");
    romanNumber.printRoman();
    romanNumber.printInteger();

    romanNumber.setRoman("CCCLIX");
    romanNumber.printRoman();
    romanNumber.printInteger();

    romanNumber.setRoman("MDCLXVI");
    romanNumber.printRoman();
    romanNumber.printInteger();

    return 0;
}