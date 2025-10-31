#include <stdio.h>

void readArray(int arr[],int n){
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[],int n){
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partitition(int a[],int lb, int ub){

    int pivot=a[lb];
    int start=lb;
    int end=ub;

    while(start<end){
        while(a[start]<=pivot&& start<=ub){
            start ++;
        }
        while(a[end]>pivot && end>=lb){
            end --;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}

void quicksort(int a[], int lb, int ub){

    if(lb<ub){
        int loc=partitition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}

int main(){
    int n;
    printf("Enter number of values: \n");
    scanf("%d",&n);
    int arr[n];
    readArray(arr,n);
    printf("original array\n");
    printArray(arr,n);
    quicksort(arr,0,n-1);
    printf("sorted array\n");
    printArray(arr,n);
    return 0;
}
