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

int size(stack top) {
    int count = 0;
    stack cursor;
    cursor = top;
    while (cursor != NULL) {
        count += 1;
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

int main() {
    stack top = NULL;
    char word[100], chara;

    do {
        printf("Program Membalik Kata (input 00 untuk berhenti)\n");
        printf("  Masukkan kata: ");
        scanf("%s", word);

        int i = 0;
        while (word[i] != '\0') {
            chara = word[i];
            push(&top, chara);
            i++;
        }

        printf("  Kata terbalik: ");
        while (top != NULL) {
            printf("%c", top->value);
            top = pop(top);
        }
        printf("\n\n");
    } while (strcmp(word, "00")!=0);
}