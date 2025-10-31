#include <stdio.h>

void readarray(int a[],int n){
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void printarray(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int binarysearch(int a[],int left, int right, int key){

    if(left>right){
        return -1;
    }
    else{
        int mid=(left+right)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            return binarysearch(a,mid+1,right,key);
        }
        else{
            return binarysearch(a,left,mid-1,key);
        }
    }
}

int main(){
    int n;
    printf("enter number of elements\n");
    scanf("%d",&n);
    int arr[n];
    readarray(arr,n);
    printf("input array\n");
    printarray(arr,n);
    int key;
    printf("enter element u wanna search\n");
    scanf("%d",&key);
    int res=binarysearch(arr,0,n-1,key);
    if(res==-1){
        printf("not found");

    }
    else{
        printf("found");
    }
    return 0;
}