#include <stdio.h>

int linearsearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n,key;
    printf("enter number of elements:\n");
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter element u wana search\n");
    scanf("%d",&key);
    int index=linearsearch(a,n,key);
    if(index==-1){
        printf("not found");
    }
    else{
        printf("found");
    }
    return 0;
}