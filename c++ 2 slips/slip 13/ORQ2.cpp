/*Write a C++ program to read the contents of a text file. Count and display number of characters,
words and lines from a file. Find the number of occurrences of a given word present in a file.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Function to count characters, words, and lines in a text file
void countFileContents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (getline(file, line)) {
        charCount += line.length();
        ++lineCount;

        istringstream iss(line);
        string word;
        while (iss >> word) {
            ++wordCount;
        }
    }

    file.close();

    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;
}

// Function to find the number of occurrences of a given word in a text file
int countWordOccurrences(const string& filename, const string& word) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return 0;
    }

    int count = 0;
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(word);
        while (pos != string::npos) {
            ++count;
            pos = line.find(word, pos + word.length());
        }
    }

    file.close();

    return count;
}

int main() {
    string filename, word;

    // Input file name from user
    cout << "Enter the name of the text file: ";
    getline(cin, filename);

    // Count characters, words, and lines
    countFileContents(filename);

    // Input word to find occurrences
    cout << "\nEnter the word to find occurrences: ";
    cin >> word;

    // Count occurrences of the word
    int occurrences = countWordOccurrences(filename, word);
    cout << "Number of occurrences of '" << word << "': " << occurrences << endl;

    return 0;
}

/*Output:-

*/