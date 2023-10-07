#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAX=50;

typedef struct node {
    int value;
    struct node *prev;
} *stack;

stack createNode(int num) {
    stack temp;
    temp = (stack) malloc(sizeof(struct node));
    temp->value = num;
    temp->prev = NULL;
    return(temp);
}

int size(stack top) {
    int count = 0;
    stack cursor;
    cursor = top;
    while (cursor != NULL) {
        count+=1;
        cursor = cursor->prev;
    }
    return count;
}

bool isFull(stack top) {
    return (size(top)>MAX);
}

bool isEmpty(stack top) {
    return (size(top)==0);
}

void push(stack* top, int num) {
    if (isFull(*top))
        printf("Bilangan terlalu besar!\n");
    else {
        stack temp = createNode(num);
        temp->prev=*top;
        *top=temp;
    }
}

stack pop(stack top) {
    if (isEmpty(top))
        return NULL;
    else {
        stack temp = top->prev;
        top->prev = NULL;
        top = temp;
        return top;
    }
}

void main() {
    stack top=NULL;
    int decNum, remainder;

    printf("Program konversi Desimal ke Biner\n\n");
    printf("Masukkan bilangan desimal = ");
    scanf("%d", &decNum);

    if (decNum==0) printf("Hasil konversi ke biner = 0");
    else {
        for(int n= abs(decNum);n>0;n=n/2) {
            remainder=n%2;
            push(&top,remainder);
        }

        printf("Hasil konversi ke biner = ");
        if (decNum<0)
            printf("-");
        while (top!=NULL) {
            printf("%d", top->value);
            top= pop(top);
        }
    }
}