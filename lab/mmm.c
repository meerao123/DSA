#include <stdio.h>
void Mean(int arr[],int n){

    int i,sum=0;
    for(i=0;i<n;i++){
        sum=sum+arr[i];
    }
    printf("mean is: %d\n",sum/n);

}
void Median(int *arr, int n){

    int i,j,temp;
    for(i=0;i<n;i++){

        for(j=0;j<n;j++){

            if (arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }

    }

    if(n%2==0){
        printf("median is %d\n",arr[n/2-1]+arr[n/2]/2);
    }
    else{
        printf("median is %d",arr[n/2]);
    }

}

void Mode(int arr[],int n){

    int mode=arr[0];
    int maxcount=0;
    int i,j;
    for(i=0;i<n;i++){

        int count=0;
        for(j=0;j<n;j++){

            if(arr[i]==arr[j]){
                count++;
            }
        }
    if(count>maxcount){
        maxcount=count;
        mode=arr[i];
    }
    }
printf("mode is %d\n",mode);
}
int main(){

    int a[]={1,2,4,5,2,1,6,4};
    Mode(a,8);
    Mean(a,8);
    Median(a,8);

}