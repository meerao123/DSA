#include <stdio.h>

void merge(int arr[],int left, int mid, int right){

    int n1=mid-left+1;
    int n2=right-mid;
    int l[n1];
    int r[n2];

    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        r[j]=arr[mid+1+j];
    }

    int i=0, j=0,k=left;
    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

void printArray(int arr[], int n){
      for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void readArray(int arr[],int n){
    printf("enter array elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

int main(){
    int n;
    printf("enter number of elements :\n");
    scanf("%d",&n);
    int arr[n];
    readArray(arr,n);
    printf("input array:\n");
    printArray(arr,n);
    printf("sorted array:\n");
    mergesort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}