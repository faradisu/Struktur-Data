#include<stdio.h>
#include<string.h>

#define MAX 50
#define MAX_CHARS 16
char QUEUE[MAX_CHARS][MAX];
int rear, front;

void enqueue(char item[]) {
    if(rear == MAX - 1) {
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    strcpy(QUEUE[rear], item);
}

void dequeue() {
    if(rear == -1) {
        return;
    }

    if(front == rear)
        front = rear = -1;
    else {
        for(int i = 0; i < rear; i++) {
            strcpy(QUEUE[i], QUEUE[i + 1]);
        }
        rear--;
        front = 0;
    }
}

void reverseWord(char word[]) {

}

int main() {
    rear=-1; front=-1;
    char word[MAX];

    printf("N: ");
    scanf("%s", &word);
    reverseWord(word);
    return 0;
}
