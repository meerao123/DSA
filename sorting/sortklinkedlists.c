//Merge K sorted lists into a single sorted list using a heap.
// Use a min-heap to keep track of the smallest element from each list.
// Repeatedly extract the smallest element and insert the next element from the corresponding list 
// into the heap until all lists are merged.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * createnode(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

struct heapnode{
    struct node * node;
    int listindex;
};

void swap(struct heapnode *a, struct heapnode *b){
    struct heapnode temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(struct heapnode heap[], int n,int i){
    int smallest= i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left].node->data < heap[smallest].node->data){
        smallest=left;
    }
    if(right<n && heap[right].node->data<heap[smallest].node->data){
        smallest=right;
    }
    if(smallest!=i){
        swap(&heap[smallest],&heap[i]);
        heapify(heap,n,smallest);
    }
}

void buildheap(struct heapnode heap[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(heap,n,i);
    }
}

struct node * mergeklist(struct node * arr[], int k){
    struct heapnode *heap=(struct heapnode *)malloc(sizeof(struct heapnode)*k);
    int heapsize=0;
    for(int i=0;i<k;i++){
        if(arr[i]!=NULL){
            heap[heapsize].node=arr[i];
            heap[heapsize].listindex=i;
            heapsize++;
        }
    }
    buildheap(heap,heapsize);
    struct node dummy;
    struct node *tail=&dummy;
    dummy.next=NULL;

    while(heapsize>0){
        struct heapnode root=heap[0];
        tail->next=root.node;
        tail=tail->next;
        if(root.node->next!=NULL){
            heap[0].node=root.node->next;
        }
        else{
            heap[0]=heap[heapsize-1];
            heapsize--;
        }
        heapify(heap,heapsize,0);
    }
    return dummy.next;
}

void printlist(struct node * node){
    while(node!=NULL){
        printf("%d -->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}

int main(){
    int k,n,value;
    printf("Enter number of linked lists\n");
    scanf("%d",&k);
    struct node *arr[k];
    for(int i=0;i<k;i++){
        struct node * head=NULL ;
        struct node * tail=NULL;
        printf("enter number of elements in %d list",i+1);
        scanf("%d",&n);
        printf("enter elements in sorted order\n");
        for(int j=0;j<n;j++){
            scanf("%d",&value);
            struct node * newnode=createnode(value);
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }
            else{
                tail->next=newnode;
                tail=tail->next;
            }
        }
        arr[i]=head;
    }
    struct node * result = mergeklist(arr,k);
    printlist(result);
    return 0;

}