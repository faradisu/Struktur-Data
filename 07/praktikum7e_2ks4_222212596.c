#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MAX=20;

typedef struct node {
    int value;
    struct node *next;
} *queue;

queue createNode(int num) {
    queue newNode;
    newNode = (queue) malloc(sizeof(struct node));
    newNode->value = num;
    newNode->next = NULL;
    return(newNode);
}

int size(queue front) {
    int count = 0;
    queue cursor;
    cursor = front;
    while (cursor != NULL) {
        count+=1;
        cursor = cursor->next;
    }
    free(cursor);
    return count;
}

int position(queue front, int find) {
    int pos=1;
    queue temp=front;
    while (temp!=NULL && temp->value!=find) {
        pos++;
        temp=temp->next;
    }

    if (temp==NULL) {
        free(temp);
        return 0;
    } else{
        return pos;
    }
}

bool isFull(queue front) {
    return (size(front)>=MAX);
}

bool isEmpty(queue front) {
    return front==NULL;
}

void enqueue(queue *front, queue *rear, int num) {
    if (isFull(*front))
        printf("Antrian penuh\n");
    else {
        queue temp = createNode(num);
        if (*front==NULL) {
            *front=temp;
            *rear=temp;
        } else {
            (*rear)->next=temp;
            *rear=temp;
        }
        printf("Antrian bertambah\n");
    }
}

queue dequeue(queue front) {
    if (isEmpty(front)){
        printf("Antrian kosong\n");
        return NULL;
    }
    else {
        queue temp = front;
        front=front->next;
        temp->next = NULL;
        free(temp);
        printf("Antrian berkurang\n");
        return front;
    }
}

int main() {
    queue front=NULL, rear=NULL;
    int choice, ticketNo, waitingTime;
    bool again=true;
//    initialize(&front, &rear, &frontNo);

    int counter=0;
    do {
        printf("Program Antrian Pasien\n");
        printf("  1. Ambil antrian\n");
        printf("  2. Lihat sisa antrian\n");
        printf("  3. Estimasi tunggu antrian\n");
        printf("  4. Selesai dilayani\n");
        printf("  5. Keluar\n");
        printf("=> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                counter++;
                enqueue(&front, &rear, counter);
                break;
            case 2:
                if (isEmpty(front))
                    printf("Antrian kosong\n");
                else
                    printf("  Tersisa %d orang dalam antrian\n"
                       "  Nomor antrian paling depan: %d\n"
                       "  Nomor antrian paling belakang: %d\n", size(front), front->value, rear->value);
                break;
            case 3:
                printf("  Nomor antrianmu: ");
                scanf("%d", &ticketNo);
                waitingTime= (position(front, ticketNo)-1)*15;
                if (waitingTime<0)
                    printf("  Nomor antrian tidak ada\n");
                else
                    printf("  Estimasi menunggu: %d menit\n", waitingTime);
                break;
            case 4:
                front=dequeue(front);
                break;
            case 5:
                again=false;
                break;
            default:
                printf("Input Error\n");
        }
        printf("\n");
    } while (again);
}