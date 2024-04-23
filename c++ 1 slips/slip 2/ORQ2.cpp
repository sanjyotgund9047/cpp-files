/*Write a C++ program to copy the contents of one file to another*/

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("input.txt");  // Open input file
    std::ofstream outputFile("output.txt");  // Open output file

    // Check if both files are opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file!" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file!" << std::endl;
        return 1;
    }

    // Copy contents from input file to output file
    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(ch);
    }

    // Close files
    inputFile.close();
    outputFile.close();

    std::cout << "File copied successfully!" << std::endl;

    return 0;
}
