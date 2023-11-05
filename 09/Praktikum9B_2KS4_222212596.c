#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Node
{
	char data[30];
	struct Node *left;
	struct Node *right;
	int height;
};

int height(struct Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(char new_data[30])
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->data,new_data);
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1; // new node is initially added at leaf
	return(new_node);
}

struct Node* rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Lakukan rotasi
	x->right = y;
	y->left = T2;

	// Update height
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return root baru
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Lakukan rotasi
	y->left = x;
	x->right = T2;

	// Update height
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return root baru
	return y;
}

struct Node* insert(struct Node* node, char new_data[30])
{
	// 1. Lakukan BST insert biasa
	if (node == NULL)
		return(newNode(new_data));

	if (strcasecmp(new_data, node->data)<0)
		node->left = insert(node->left, new_data);
	else if (strcasecmp(new_data, node->data)>0)
		node->right = insert(node->right, new_data);
	else
		return node; // asumsi tidak boleh ada nilai yang sama dalam BST

	// 2. Update height dari node
	node->height = 1 + max(height(node->left), height(node->right));

	// 3. Hitung balance factor untuk menentukan apakah node unbalanced
	int balance = getBalanceFactor(node);

	// Jika tidak balanced, return hasil rotation
	// Kasus 1: Left Left
	if (balance > 1 && strcasecmp(new_data,node->left->data)<0)
		return rightRotate(node);

	// Kasus 2: Right Right
	if (balance < -1 && strcasecmp(new_data,node->right->data)>0)
		return leftRotate(node);

	// Kasus 3: Right Left
	if (balance < -1 && strcasecmp(new_data,node->right->data)<0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	// Kasus 4: Left Right
	if (balance > 1 && strcasecmp(new_data,node->left->data)>0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// return node jika balanced
	return node;
}

struct Node * minValueNode(struct Node* node) //cari node minimum di suatu subtree
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


struct Node* deleteNode(struct Node* root, char deleted_data[30])
{
    // 1. Lakukan BST delete biasa
    if (root == NULL)
        return root;

    if (strcasecmp(deleted_data,root->data)<0)
        root->left = deleteNode(root->left, deleted_data);

    else if(strcasecmp(deleted_data,root->data)>0)
        root->right = deleteNode(root->right, deleted_data);

    else
    { //jika ditemukan node yang akan dihapus
        // 1 CHILD atau NO CHILD
       struct Node* cursor;
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        //2 CHILDS
        else
        {
            // cari minimum di subtree kanan
            cursor = minValueNode(root->right);

            strcpy(root->data,cursor->data);

            // Delete data yang telah dipindahkan sebagai root
            root->right = deleteNode(root->right, cursor->data);
        }
    }

    // Jika setelah dilakukan delete, tree kosong maka return root
    if (root == NULL)
      return root;

    // 2. Update height dari node
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Hitung balance factor untuk menentukan apakah root unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
	// Kasus 1: Left Left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // return root jika balanced
    return root;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("|| %s ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void printLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("|| %s ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node *root)
{
    for (int i = 1; i <= height(root); i++) {
        printLevel(root, i);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, "Kharis");
    root = insert(root, "Dimas");
    root = insert(root, "Gilang");
    root = insert(root, "Farhan");
    root = insert(root, "Alfons");
    root = insert(root, "Fadila");
    root = insert(root, "Pipi");
    root = insert(root, "Glory");
    root = insert(root, "Dita");

    /* AVL Tree
           Farhan
         /       \
      Dimas       Kharis
     /    \      /      \
Alfons  Fadila  Gilang  Pipi
        /          \
      Dita        Glory
    */

    printf("Preorder traversal dari AVL tree adalah \n");
    preOrder(root);

    root = deleteNode(root, "Alfons");

    /*AVL Tree setelah delete Alfons
           Farhan
         /      \
      Dita       Kharis
     /    \      /     \
 Dimas  Fadila  Gilang  Pipi
                   \
                  Glory
    */

    printf("\nPreorder traversal dari AVL tree (setelah delete) adalah \n");
    preOrder(root);

    printf("\nLevel traversal dari AVL tree adalah \n");
    levelOrder(root);

    return 0;
}
