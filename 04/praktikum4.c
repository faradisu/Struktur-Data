#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node* ptrnode;

ptrnode createNode(int nilai) { 
    ptrnode p; 
    p = (ptrnode)malloc(sizeof(struct node)); 
    p->value = nilai; 
    p->next = NULL ; 
    return(p); 
}

void showList(ptrnode head) {
    ptrnode cursor;
    cursor = head;
    while (cursor != NULL) {
        printf("%d\n", cursor->value);
        cursor = cursor->next;
    }
}

ptrnode insert_head(ptrnode head, int nilai) { 
    ptrnode new_node = createNode(nilai); 
    new_node->next = head; 
    head = new_node; 
 
    return(head); 
}

ptrnode insert_tail(ptrnode head, int nilai) { 
    /* iterasi mencari node terakhir*/ 
    ptrnode tail = head; 
    while(tail->next != NULL) 
        tail = tail->next; 

    /* buat node baru */ 
    ptrnode new_node = createNode(nilai); 
    tail->next = new_node; 
 
    return(head); 
}

ptrnode insert_after(ptrnode head, int nilai, int prev_nilai) { 
     /* cari node sebelumnya, starting from the first node*/ 
    ptrnode cursor = head; 
    while(cursor->value != prev_nilai) 
        cursor = cursor->next; 
 
    ptrnode new_node = createNode(nilai); 
    new_node->next = cursor->next; 
    cursor->next = new_node; 
 
    return(head); 
}

ptrnode insert_before(ptrnode head, int nilai, int next_nilai) { 
   if (head->value == next_nilai) 
       head = insert_head(head, nilai); 
   else { 
       ptrnode cursor, prevcursor; 
       cursor = head; 
       do 
       { prevcursor = cursor; 
         cursor = cursor->next; 
       } 
       while (cursor->value != next_nilai); 
        
       ptrnode new_node = createNode(nilai); 
       new_node->next = cursor; 
       prevcursor->next = new_node; 
   } 
   return(head); 
}

int main() {
    //inisialisasi 
    ptrnode head = NULL; 
    head = (ptrnode)malloc(sizeof(struct node)); 
    head->value = 10; 
    head->next = NULL;

    //membuat simpul baru, cara 1 
    struct node node_dua; 
    ptrnode dua = &node_dua; 
    dua->value = 20; 
    dua->next = NULL;
    head->next = dua;

    //membuat simpul baru, cara 2 
    ptrnode tiga = NULL; 
    ptrnode empat = NULL; 
    
    tiga = (ptrnode)malloc(sizeof(struct node)); 
    empat = (ptrnode)malloc(sizeof(struct node)); 
    
    dua->next = tiga; 
    
    tiga->value = 30; 
    tiga->next = empat; 
    
    empat->value = 40; 
    empat->next = NULL;

    //membuat simpul baru, cara 3 
    ptrnode lima = createNode(50); 
    empat->next = lima;
    
    //menampilkan nilai linked list
    showList(head);
    printf("\n");

    /* Tambahkan node baru dengan value = 99 sebagai head */ 
    head = insert_head(head, 99);

    /* Tambahkan node baru dengan value = 11 sebagai tail */ 
    head = insert_tail(head, 11);

    /* Tambahkan node baru dengan value = 60 setelah node dengan value 50 */ 
    head = insert_after(head, 60, 50);

    /* Tambahkan node baru dengan value = 35 sebelum node dengan value 99 */ 
    head = insert_before(head, 35, 40);
    
    //menampilkan list setelah insert beberapa node
    showList(head);
    printf("\n");

    return 0;
}