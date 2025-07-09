#include <stdio.h>
void SelectionSort(int arr[], int n){

int i,j,max,temp;
for(i=0;i<n-1;i++){

    max=i;
    for(j=i+1;j<n;j++){

         if(arr[j]>arr[max]){
            max=j;
         }
         
         }
        if(max!=i){
            temp=arr[i];
            arr[i]=arr[max];
            arr[max]=temp;
    }

}
printf("sorted array: ");
for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
}

}

int main(){
int a[]={3,10,5,4,11};
SelectionSort(a,5);
}