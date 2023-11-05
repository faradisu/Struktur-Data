#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[30];
    struct node* left;
    struct node* right;
};

struct node* newNode(char data[30])
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    strcpy(node->data,data);
    node->left = NULL;
    node->right = NULL;

    return node;
}

void displayPreorder(struct node* node)
{
    if(node == NULL)
        return;

    printf("%s || ", node->data); //root

    displayPreorder(node->left); //subtree kiri

    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node* node)
{
    if(node == NULL)
        return;

    displayInorder(node->left); //subtree kiri

    printf("%s || ", node->data); //root

    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node* node)
{
    if(node == NULL)
        return;

    displayPostorder(node->left); //subtree kiri

    displayPostorder(node->right); //subtree kanan

    printf("%s || ", node->data); //root
}


struct node* insert(struct node* root, char newData[30]) //Fungsi untuk menambahkan node baru dengan data = newData ke BST
{
    if(root == NULL)
    {
        root = newNode(newData);
    }
    else
    {
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;
        while(cursor != NULL)
        {
            prev = cursor;
            if(strcasecmp(newData, cursor->data)<0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
            else if(strcasecmp(newData, cursor->data)>0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }

        if(is_left == 1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }

    return root;
}

struct node* delete_node(struct node* root, char deletedData[30])
{
    if(root == NULL)
        return 0;

    struct node* cursor;
    if(strcasecmp(deletedData, root->data)>0)
        root->right = delete_node(root->right, deletedData);
    else if(strcasecmp(deletedData, root->data)<0)
        root->left = delete_node(root->left, deletedData);
    else
    {
        //1 CHILD
        if(root->left == NULL){
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if(root->right == NULL) {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        //2 CHILDS NODE
        else{
            cursor = root->right;
            struct node* parent = NULL;

            while(cursor->left != NULL){
                parent = cursor;
                cursor = cursor->left;
            }

            strcpy(root->data,cursor->data);
            if(parent != NULL){
                parent->left = delete_node(parent->left, parent->left->data);
            } else {
                root->right = delete_node(root->right, root->right->data);
            }
        }
    }

    return root;
}

void search_node(struct node* root, char data[30])
{
    struct node* cursor = root;

    while(strcasecmp(cursor->data,data)!=0){
        if(cursor != NULL){
            if(strcasecmp(cursor->data,data)>0){
                cursor = cursor->left;
            }
            else {
                cursor = cursor->right;
            }

            if(cursor == NULL){
                printf("\nNode %s tidak ditemukan", data);
            }
        }
    }

    printf("\nNode %s ditemukan", data);
}

int main()
{
    struct node* root;
    root = newNode("Thoriq");
    root = insert(root,"Khaidir");
    root = insert(root,"Samuel");
    root = insert(root,"Glory");
    root = insert(root,"Gilang");
    root = insert(root,"Kharis");
    root = insert(root,"Udin");
    root = insert(root,"Adit");
    root = insert(root,"Nabil");
    root = insert(root,"Farhan");
    root = insert(root,"Afdhal");
    root = insert(root,"Akbar");

    printf("Isi Tree: \n");
    displayInorder(root);

//    delete_node(root, "Afdhal");
//    printf("\n");
//    displayInorder(root);
//
//    printf("\n");
//    search_node(root, "Nabil");
//
//    printf("\n");
//    search_node(root, "Rifky");

    return 0;
}

