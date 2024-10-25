/* Program name: Hash Table Program
Author: Heritage Adigun
Date last updated: 10/25/2024
Purpose: A program that defines search, isItemAtEqual, retrieve, remove, print, constructor, and destructor for class hashT */


#include <iostream>
#include <vector>
#include <functional>

const int TABLE_SIZE = 10;

class hashT {
private:
    std::vector<int> table[TABLE_SIZE];

    int hashFunction1(int key) {
        return key % TABLE_SIZE;
    }

    int hashFunction2(int key) {
        return (key * 17) % TABLE_SIZE;
    }

    int hashFunction3(int key) {
        return std::hash<int>{}(key) % TABLE_SIZE;
    }

public:
    hashT() {
        // Constructor: Initialize the hash table
    }

    void insert(int key) {
        int index = hashFunction1(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction1(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    bool isItemAtEqual(int key, int index) {
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
        return false;
    }

    int retrieve(int key) {
        int index = hashFunction1(key);
        for (int value : table[index]) {
            if (value == key) {
                return value;
            }
        }
        return -1; // Not found
    }

    bool remove(int key) {
        int index = hashFunction1(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            std::cout << "Bucket " << i << ": ";
            for (int value : table[i]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }

    ~hashT() {
        // Destructor: Clean up the hash table
    }
};

int main() {
    hashT hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(45);

    std::cout << "Using Hash Function 1:" << std::endl;
    hashTable.print();
    std::cout << "Searching for 25: " << hashTable.search(25) << std::endl;
    std::cout << "Retrieved value for 15: " << hashTable.retrieve(15) << std::endl;
    std::cout << "Removing 35: " << hashTable.remove(35) << std::endl;
    hashTable.print();

    return 0;
}