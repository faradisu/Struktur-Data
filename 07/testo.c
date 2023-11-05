#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX=50;
int top=-1;
char stack[MAX];

bool isFull() {
    return top>MAX;
}

bool isEmpty() {
    return top==-1;
}

void push(char *x) {
    if (isFull())
        printf("Overflow");
    else {
        top+=1;
        strcat(stack, x);
    }
}

void pop() {
    if (isEmpty())
        printf("Empty");
    else {

    }
}

int main(){
    char c='z';
    char b;
    strcpy(b,c);

    printf(b);
}