//The CSE dept is organizing a tech fest with so many exciting events.
//  By participating in an event,you can claim for activity points as stipulated by KTU.
//  Each event i gives you A[i] activity points where A is an array.If you are not allowed to
//  participate in more than k events, what’s the max number of points that you can earn?
#include<stdio.h>
void descendingorder(int a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    printf("enter total number of events\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the ktu points \n");
    for (int i=0;i<n;i++){
        printf("for event %d ",i+1);
        scanf("%d",&arr[i]);
    }
    int k,max=0;
    printf("enter max events u can participate in\n");
    scanf("%d",&k);
    descendingorder(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("max ktu points: ");
    for(int i=0;i<k;i++){
        max+=arr[i];
    }
    printf("%d",max);
    return 0;
}