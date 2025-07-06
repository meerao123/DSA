#include <stdio.h>
void LeftRotate(int arr[], int d,int n){
    
    int temp[d];
    int i;

    for(i=0;i<d;i++){
        
        temp[i]=arr[i];
    }

    for(i=d;i<n;i++){

        arr[i-d]=arr[i];
    }
    int j=0;
    for(i=n-d;i<n;i++){
        arr[i]=temp[j];
        j++;
    }

    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}

int main(){
 
int arr[]={1,2,3,4,5,6,7};
LeftRotate(arr,3,7);
return 0;

}