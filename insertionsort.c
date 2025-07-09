#include <stdio.h>
void InsertionSort(int arr[],int n){

int i,j,key;
for(i=1;i<n;i++){

    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]<key){

        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;

}
for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
}

int main(){

    int a[]={2,20,3,5,10};
    InsertionSort(a,5);
    return 0;
}