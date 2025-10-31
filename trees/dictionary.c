#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char word[50];
    char meaning[100];
    struct node*left,*right;
};

struct node * create_node(const char *word, const char *meaning){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    strcpy(newnode->word,word);
    strcpy(newnode->meaning,meaning);
    newnode->left=NULL;
    newnode->right=NULL;
}

struct node * insert_node(const char *word, const char *meaning, struct node *root){
    if(root==NULL){
        return create_node(word,meaning);
    }
    else{
        if(strcmp(word,root->word)<0){
            root->left=insert_node(word,meaning,root->left);
        }
        else if(strcmp(word,root->word)>0){
            root->right=insert_node(word,meaning,root->right);
        }
        else{
            printf("word exists\n");
        }
    }
    return root;
}
void search_node(const char *word,struct node *root){
    if(root==NULL){
        printf("word not found\n");
        return;
    }
    else{
        if(strcmp(word,root->word)==0){
            printf("found\n%s : %s",root->word,root->meaning);
        }
        else if(strcmp(word,root->word)<0){
            search_node(word,root->left);
        }
        else{
            search_node(word,root->right);
        }
    }
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
          printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    char word[50];
    char meaning[100];
    int choice;
    while(1){
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert Word\n2. Search Word\n3. Display Dictionary\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
         switch (choice) {
            case 1:
                printf("Enter Word: ");
                fgets(word,50,stdin);
                word[strcspn(word,"\n")]='\0';
                printf("Enter Meaning: ");
                fgets(meaning,100,stdin);
                meaning[strcspn(meaning,"\n")]='\0';
                root = insert_node( word, meaning,root);
                break;
            case 2:
                printf("Enter Word to Search: ");
                fgets(word,50,stdin);
                word[strcspn(word,"\n")]='\0';
                search_node(word,root);
                break;
            case 3:
                printf("\n--- Dictionary Words ---\n");
                inorder(root);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } 
    
    return 0;
}

    