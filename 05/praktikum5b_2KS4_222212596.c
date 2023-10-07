#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>

struct node{ 
    int id;
    char name[50];
    struct node *next; 
    struct node *prev; 
}; 
typedef struct node *ptrnode;

ptrnode createNode(int nim, char nama[50]) { 
    ptrnode p; 
    p = (ptrnode)malloc(sizeof(struct node)); 
    p->id = nim; 
    strcpy(p->name, nama);
    p->next = NULL; 
    p->prev = NULL;
    return(p); 
}

ptrnode insertHead(ptrnode head, int nim, char nama[50]) { 
    ptrnode temp = createNode(nim, nama); 
    temp->next = head; 
    head->prev = temp; 
    head = temp; 
 
    return(head); 
}

ptrnode insertTail(ptrnode tail, int nim, char nama[50]) {
    /* buat node baru */ 
    ptrnode temp = createNode(nim, nama); 
    tail->next = temp; 
    temp->prev = tail;
    tail = temp;
 
    return(tail);
}

ptrnode insertBefore(ptrnode head, int nim, char nama[50], int nimTarget) { 
    if (head->id == nimTarget) 
        head = insertHead(head, nim, nama); 
    else { 
    //pencarian nilai sama seperti insert after, tidak perlu 2 cursor 
        ptrnode cursor = head; 
        while(cursor->id != nimTarget) 
            cursor = cursor->next; 
        
        ptrnode temp = createNode(nim, nama); 
        temp->prev = cursor->prev; 
        cursor->prev->next = temp; 
        temp->next = cursor; 
        cursor->prev = temp;    
    } 
    return(head); 
}

ptrnode insertAfter(ptrnode head, int nim, char nama[50], int nimTarget) { 
     /* cari node sebelumnya, starting from the first node*/ 
    ptrnode cursor = head; 
    while(cursor->id != nimTarget) 
        cursor = cursor->next; 
 
    ptrnode temp = createNode(nim, nama); 
    temp->next = cursor->next; 
    cursor->next->prev = temp;
    temp->prev = cursor; 
    cursor->next = temp; 
 
    return(head); 
}

ptrnode deleteHead(ptrnode head) {
    if(head == NULL) 
        return; 
 
    ptrnode temp = head; 
    head = head->next; 
    head->prev = NULL; 
    temp->next = NULL; 
 
    free(temp); 
 
    return(head);
}

ptrnode deleteTail(ptrnode tail) {
    ptrnode temp = tail->prev;

    tail->prev->next = NULL; 
    tail->prev = NULL; 
    free(tail); 
    tail =  temp;
    return(tail);
}

ptrnode deleteMiddle(ptrnode head, int nimTarget) {
    ptrnode cursor = head; 
    while(cursor != NULL) { 
        if(cursor->next->id == nimTarget) 
            break; //keluar dari iterasi 
        cursor = cursor->next; 
    } 
 
    if(cursor != NULL) { 
        ptrnode temp = cursor->next; 
        cursor->next = temp->next; 
        temp->next->prev = cursor; 
        temp->next = NULL; 
        temp->prev = NULL;
        free(temp); 
    } 
 
    return(head);
}

int nodeCount(ptrnode head) {
    int count;
    ptrnode cursor;
    cursor = head;
    while (cursor != NULL) {
        count+=1;
        cursor = cursor->next;
    }
    
    return count;
}

void showList(ptrnode head) {
    ptrnode cursor;
    cursor = head;
    while (cursor != NULL) {
        printf("- %d\n", cursor->id);
        printf("  %s\n", cursor->name);
        cursor = cursor->next;
    }
}

void showListBack(ptrnode tail) {
    ptrnode cursor;
    cursor = tail;
    while (cursor != NULL) {
        printf("- %d\n", cursor->id);
        printf("  %s\n", cursor->name);
        cursor = cursor->prev;
    }
}

int main() {
    int choice, choice2, nim;
    char name[50];
    ptrnode head, tail;
    
    do
    {
        printf("------------MENU------------\n");
        printf("1. Buat data mahasiswa baru\n");
        printf("2. Tambah mahasiswa\n");
        printf("3. Hapus mahasiswa\n");
        printf("4. Jumlah mahasiswa\n");
        printf("5. Keluar\n");
        printf("=> ");
        scanf("%d", &choice);
        switch (choice)
        {
          case 1: {
                printf("---------DATA BARU--------\n");
                printf("NIM: ");
                scanf("%d", &nim);
                printf("Nama: ");
                scanf(" %[^\n]s", &name);

                head = createNode(nim, name);
                tail = head;
                // printf("--------------------------\n");
            };
            break;
          case 2: {
                printf("---------INSERT--------\n");
                printf("NIM: ");
                scanf("%d", &nim);
                printf("Nama: ");
                scanf(" %[^\n]s", &name);

                printf("\nInsert location\n");
                printf("1. Insert head\n");
                printf("2. Insert tail\n");
                printf("3. Insert before\n");
                printf("4. Insert after\n");
                printf("=> ");
                scanf("%d", &choice);

                switch (choice)
                {
                  case 1:
                    head=insertHead(head, nim, name);
                    break;
                  case 2:
                    tail=insertTail(tail, nim, name);
                    break;
                  case 3:
                    {  
                        int target;
                        printf("\n");
                        showList(head);
                        printf("=> Insert before nim: ");
                        scanf("%d", &target);
                        insertBefore(head, nim, name, target);
                    }
                    break;
                  case 4:
                    {  
                        int target;
                        printf("\n");
                        showList(head);
                        printf("=> Insert after nim: ");
                        scanf("%d", &target);
                        insertAfter(head, nim, name, target);
                    }
                    break;
                
                default:
                    break;
                }
                // printf("-----------------------\n");
            };
            break;
          case 3: {
                printf("---------DELETE--------\n");
                printf("1. Delete head\n");
                printf("2. Delete tail\n");
                printf("3. Delete middle\n");
                printf("=> ");
                scanf("%d", &choice);

                switch (choice)
                {
                  case 1:
                    head=deleteHead(head);
                    break;
                  case 2:
                    tail=deleteTail(tail);
                    break;
                  case 3:
                    {
                        showList(head);
                        printf("\n");
                        printf("Delete nim: ");
                        scanf("%d", &nim);
                        head=deleteMiddle(head, nim);
                    }
                    break;
                default:
                    break;
                }
                // printf("-----------------------\n");
            }
            break;
          case 4: {
            printf("\nJumlah mahasiswa: %d\n", nodeCount(head));
            showList(head);
          }
            break;
          case 5:
            exit(0);
            break;
        
        default:
            break;
        }
        // printf("----------------------------\n");
    } while (true);
    
    return 0;
}