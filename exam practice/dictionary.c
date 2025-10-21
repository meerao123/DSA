#include <Stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

struct term{
    char word[MAX];
    char meaning[MAX];
    struct term *left,*right;
};

struct term* create(char word[], char meaning[]){
    struct term * new=(struct term*)malloc(sizeof(struct term));
    strcpy(new->word,word);
    strcpy(new->meaning,meaning);
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct term * insert(struct term *new, struct term * root){
    if(root==NULL){
        return new;
    }
    else if(strcmp(new->word,root->word)<0){
        root->left=insert(new,root->left);
    }
    else if(strcmp(new->word,root->word)>0){
        root->right=insert(new,root->right);
    }
    else{
        printf("duplicate not allowed\n");
    }

}

struct term * search(struct term * root, char word[]){
    if(root==NULL|| strcmp(word,root->word)==0){
        return root;
    }
    else if(strcmp(root->word,word)>0){
        search(root->right,word);
    }
    else{
        search(root->left,word);
    }
}

void inorder(struct term *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%s: %s\n",root->word,root->meaning);
        inorder(root->right);
    }
}
int main() {
    struct term *root = NULL;
    int choice;
    char word[MAX], meaning[MAX];
    struct term *temp;

    while (1) {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert Word\n");
        printf("2. Search Word\n");
        printf("3. Display Dictionary (Inorder)\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice){
            case 1: printf("enter the word\n");
            scanf("%s",word);
            getchar();
            printf("Enter meaning\n");
            fgets(meaning,MAX,stdin);
            temp=create(word,meaning);
            root=insert(temp,root);
            break;

            case 2:
            printf("enter word u want to search:\n");
            scanf("%s",word);
            getchar();
            temp=search(root,word);
            if(temp){
                printf("%s: %s",temp->word,temp->meaning);
            }
            else{
                printf("Word not found\n");
            }
            break;

            case 3:
            printf("\nDictionary (sorted):\n");
            inorder(root);
            break;
            case 4:
            return 0;
                
            }
        }
    }
