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
void RightRotate(int arr[],int d, int n ){

    int temp[d];
    int i,j;
    j=0;
    for(i=n-d;i<n;i++){
         
        temp[j]=arr[i];
        j++;
    }
    for(i=n-1;i>=d;i--){

        arr[i]=arr[i-d];

    }

    for(i=0;i<d;i++){
        arr[i]=temp[i];
    }

    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }

}

int Rotate(int arr[],int n,char dir,int d){

   
    if(dir=='l'|| dir=='L'){
        LeftRotate(arr,d,n);
    }
    else{
        RightRotate(arr,d,n);
    }


}
int main(){

    int n,d;
    char dir; 
     printf("enter number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("enter array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the direction of rotation:l or r: ");
    getchar();
    scanf("%c",&dir);
    printf("enter count of rotation: ");
    scanf("%d",&d);
    d=d%n;
    Rotate(arr,n,dir,d);
}
