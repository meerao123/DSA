#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create_node(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert_node(struct node *root, int value) {
    if (root == NULL)
        return create_node(value);

    struct node *queue[100];
    int front = 0, rear = -1;
    queue[++rear] = root;

    while (front <= rear) {
        struct node *temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = create_node(value);
            return root;
        } else
            queue[++rear] = temp->left;

        if (temp->right == NULL) {
            temp->right = create_node(value);
            return root;
        } else
            queue[++rear] = temp->right;
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int height(struct node *root) {
    if (root == NULL)
        return -1;
    int hl = height(root->left);
    int hr = height(root->right);
    return 1 + (hl > hr ? hl : hr);
}

int count_nodes(struct node *root) {
    if (root == NULL)
        return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int count_leaf(struct node *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

void delete_tree(struct node *root) {
    if (root == NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    printf("Deleting %d\n", root->data);
    free(root);
}

int search(struct node *root, int value) {
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    return search(root->left, value) || search(root->right, value);
}

int main() {
    struct node *root = NULL; // ✅ initialize
    int choice, value, key, found;

    while (1) {
        printf("\n\n--- Binary Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search a Node\n");
        printf("6. Find Height of Tree\n");
        printf("7. Count Total Nodes\n");
        printf("8. Count Leaf Nodes\n");
        printf("9. Delete Entire Tree\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert_node(root, value);
                printf("Node inserted.\n");
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &key);
                found = search(root, key);
                if (found) printf("Node found.\n");
                else printf("Node not found.\n");
                break;
            case 6:
                printf("Height of tree: %d\n", height(root));
                break;
            case 7:
                printf("Total nodes: %d\n", count_nodes(root));
                break;
            case 8:
                printf("Leaf nodes: %d\n", count_leaf(root));
                break;
            case 9:
                delete_tree(root);
                root = NULL;
                printf("Tree deleted.\n");
                break;
            case 10:
                delete_tree(root);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
