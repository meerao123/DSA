#include <stdio.h>
void BubbleSort(int arr[],int n){

int i,j,temp;
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]<arr[j+1]){

            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;

        }
    }
}
printf("sorted array: ");
for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
}
int main(){
    int a[]={2,9,5,10,11,-9};
    BubbleSort(a,6);
    return 0;
}