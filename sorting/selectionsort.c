#include<Stdio.h>

void readarray(int arr[], int n){
    printf("enter array elements:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}

void printarray(int arr[], int n){
     for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
}
}

void selectionsort(int arr[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        int min_index=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
            min_index=j;
            }
        }
        if(min_index!=i){
                temp=arr[min_index];
                arr[min_index]=arr[i];
                arr[i]=temp;
        }
        printarray(arr,n);
        printf("\n");
    }
}

int main(){
    int n;
    printf("enter number of elements: \n");
    scanf("%d",&n);
    int arr[n];
    readarray(arr,n);
    printf("original array\n");
    printarray(arr,n);
     printf("sorted array\n");
    selectionsort(arr,n);
    printarray(arr,n);
   return 0;
}