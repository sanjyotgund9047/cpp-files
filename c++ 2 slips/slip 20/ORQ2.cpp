/*Write a C++ program to read the contents of a “Sample.txt” file. Store all the uppercase
characters in ”Upper.txt”, lowercase characters in ”Lower.txt” and digits in “Digit.txt” files.
Change the case of each character from “Sample.txt” and store it in “Convert.txt” file*/

#include <cstdio>
#include <cctype>

int main() {
    FILE* inputFile = fopen("Sample.txt", "r");
    if (!inputFile) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* uppercaseFile = fopen("Upper.txt", "w");
    FILE* lowercaseFile = fopen("Lower.txt", "w");
    FILE* digitFile = fopen("Digit.txt", "w");
    FILE* convertFile = fopen("Convert.txt", "w");
    if (!uppercaseFile || !lowercaseFile || !digitFile || !convertFile) {
        printf("Error opening output files.\n");
        fclose(inputFile);
        return 1;
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            fputc(ch, uppercaseFile);
            fputc(tolower(ch), convertFile);
        } else if (islower(ch)) {
            fputc(ch, lowercaseFile);
            fputc(toupper(ch), convertFile);
        } else if (isdigit(ch)) {
            fputc(ch, digitFile);
            fputc(ch, convertFile);
        } else {
            fputc(ch, convertFile);
        }
    }

    fclose(inputFile);
    fclose(uppercaseFile);
    fclose(lowercaseFile);
    fclose(digitFile);
    fclose(convertFile);

    printf("Contents of Sample.txt processed and stored in Upper.txt, Lower.txt, Digit.txt, and Convert.txt.\n");

    return 0;
}

/*Output:-
Contents of Sample.txt processed and stored in Upper.txt, Lower.txt, Digit.txt, and Convert.txt.
*/