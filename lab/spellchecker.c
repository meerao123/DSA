#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define WORD_LEN 50

typedef struct Node {
    char word[WORD_LEN];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

unsigned int hash(char *word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash << 2) ^ tolower(*word++);
    }
    return hash % TABLE_SIZE;
}

void insert(char *word) {
    unsigned int index = hash(word);
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}


int search(char *word) {
    unsigned int index = hash(word);
    Node *temp = hashTable[index];
    while (temp) {
        if (strcasecmp(temp->word, word) == 0)
            return 1;
        temp = temp->next;
    }
    return 0;
}


void suggest(char *word) {
    printf("Did you mean:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *temp = hashTable[i];
        while (temp) {
            int diff = 0;
            if (strlen(temp->word) == strlen(word)) {
                for (int j = 0; j < strlen(word); j++)
                    if (tolower(temp->word[j]) != tolower(word[j])) diff++;
                if (diff == 1) printf("- %s\n", temp->word);
            }
            temp = temp->next;
        }
    }
}

int main() {
    int n;
    char word[WORD_LEN];

    printf("Enter number of words in dictionary: ");
    scanf("%d", &n);
    printf("Enter dictionary words:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        insert(word);
    }

    printf("Enter a word to check: ");
    scanf("%s", word);

    if (search(word))
        printf("'%s' is a VALID word.\n", word);
    else {
        printf("'%s' is NOT in dictionary.\n", word);
        suggest(word);
    }
    return 0;
}
