#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* create_node(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert node in level order (like a complete binary tree)
struct node* insert_node(struct node* root, int value) {
    struct node* newnode = create_node(value);

    if (root == NULL) {
        return newnode;
    }

    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newnode;
            return root;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newnode;
            return root;
        } else {
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Level order traversal
void levelorder(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert_node(root, value);
    }

    printf("Level Order Traversal: ");
    levelorder(root);
    printf("\n");

    return 0;
}
