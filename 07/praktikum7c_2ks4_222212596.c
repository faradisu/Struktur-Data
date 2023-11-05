#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int MAX = 50;

typedef struct node {
    char value;
    struct node *prev;
} *stack;

stack createNode(char x) {
    stack newNode;
    newNode = (stack) malloc(sizeof(struct node));
    newNode->value = x;
    newNode->prev = NULL;
    return (newNode);
}

bool isBracket(char bracket) {
    if (bracket=='('||bracket==')'||bracket=='['||bracket==']'||bracket=='{'||bracket=='}')
        return true;
    else return false;
}

int size(stack top) {
    int count = 0;
    stack cursor;
    cursor = top;
    while (cursor != NULL) {
        count++;
        cursor = cursor->prev;
    }
    return count;
}

bool isFull(stack top) {
    return (size(top) >= MAX);
}

bool isEmpty(stack top) {
    return (top == NULL);
}

void push(stack *top, char x) {
    if (isFull(*top))
        printf("Karakter melebihi batas!\n");
    else {
        stack temp = createNode(x);
        temp->prev = *top;
        *top = temp;
    }
}

stack pop(stack top) {
    if (isEmpty(top))
        return NULL;
    else {
        stack temp = top;
        top = top->prev;
        temp->prev = NULL;
        free(temp);
        return top;
    }
}

void dispose(stack *top) {
    while (!isEmpty(*top)) {
        *top=pop(*top);
    }
}

int main() {
    stack top;
    char bracket[100], chara;
    bool showOutput;

    do {
        showOutput=true;
        top=NULL;

        printf("Program Tanda Kurung Seimbang (input 00 untuk berhenti)\n");
        printf("  Input: ");
        scanf("%s", &bracket);

        int i = 0;
        while (bracket[i] != '\0') {
            chara = bracket[i];
            if (!isBracket(chara)){
                printf("Input harus berupa tanda kurung!");
                showOutput=false;
                break;
            }

            if (isEmpty(top))
                push(&top, chara);
            else if (chara=='('||chara=='['||chara=='{')
                push(&top, chara);
            else {
                switch (chara) {
                    case ')':
                        if (top->value=='(')
                            top= pop(top);
                        break;
                    case ']':
                        if (top->value=='[')
                            top= pop(top);
                        break;
                    case '}':
                        if (top->value=='{')
                            top= pop(top);
                        break;
                }
            }
            i++;
        }

        if (showOutput) {
            if (isEmpty(top))
                printf("Benar");
            else
                printf("Salah");
        }
        dispose(&top);
        printf("\n\n");
    } while (strcmp(bracket, "00")!=0);
}