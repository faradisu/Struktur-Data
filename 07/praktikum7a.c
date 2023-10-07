#include<stdio.h>
#include<string.h> 
 
#define MAX 50 
#define MAX_CHARS 16 
char QUEUE[MAX_CHARS][MAX]; 
int rear, front;


void enqueue(char item[]) {
    if(rear == MAX - 1) {
        printf("Antrian penuh \n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    //karena antrian bertipa char, maka enqueue tidak bisa
    //dilakukan dengan cara QUEUE[rear]=item
    strcpy(QUEUE[rear], item);
}

void dequeue() {
    if(rear == -1) {
        printf("Antrian kosong \n");
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

void generateBinaryNumbers(int N) {
    char bin[] = "1";
    enqueue(bin);

    for(int i=0; i < N; i++) {
        char temp[MAX_CHARS] = "";
        char temp2[MAX_CHARS] = "";

        strcpy(temp, QUEUE[front]);
        strcpy(temp2, QUEUE[front]);

        printf("%s ", temp);
        dequeue();

        strcat(temp,"0");
        enqueue(temp);

        strcat(temp2,"1");
        enqueue(temp2);
    }
}

int main() {
    rear=-1; front=-1;
    int n;

    printf("N: ");
    scanf("%d", &n);
    generateBinaryNumbers(n);
    return 0;
}
