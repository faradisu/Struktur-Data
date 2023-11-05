#include <stdio.h>

char theAChar='A';
char theBChar='B';

void printChar(char cToPrint) {
    printf("%c", cToPrint);
}

int main(int args) {
    printChar(theAChar);
    theAChar=theBChar; // now theAChar variable has 'B' inside;
// lets suppose the B Char is not B but some other "language" a character.
    printChar(theAChar);  //now this prints B
}