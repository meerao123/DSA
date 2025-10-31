#include <stdio.h>
#define MAX 100

int tree[MAX];

// Initialize all tree positions to -1 (empty)
void init(){
    for(int i=0;i<MAX;i++){
        tree[i] = -1;
    }
}

// Insert data at a given index
void insert(int value, int index){
    if(tree[index] != -1){
        printf("Already occupied at index %d\n", index);
    }
    else{
        tree[index] = value;
    }
}

int main(){
    int n, data, index;

    init(); // You forgot this in your version (needed before inserting!)

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter data and index for each node:\n");
    for (int i = 0; i < n; i++){
        scanf("%d %d", &data, &index);
        insert(data, index);
    }

    // Print the tree array
    printf("\nTree array representation:\n");
    for (int i = 0; i < n; i++){
        if (tree[i] != -1)
            printf("Index %d -> %d\n", i, tree[i]);
    }

    // Example: print left and right children of root (index 0)
    int left = 2 * 0 + 1;
    int right = 2 * 0 + 2;
    printf("\nLeft child index: %d\n", left);
    printf("Right child index: %d\n", right);

    // If those positions exist in the tree, print their values too
    if (tree[left] != -1)
        printf("Left child value: %d\n", tree[left]);
    if (tree[right] != -1)
        printf("Right child value: %d\n", tree[right]);

    return 0;
}
