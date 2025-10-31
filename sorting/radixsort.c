#include <stdio.h>

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

int getmax(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
void countingsort(int a[],int n,int pos){
    int b[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        ++count[(a[i]/pos)%10];
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(int i=0;i<n;i++){
        a[i]=b[i];
    }
}

void radix_sort(int a[],int n){
    int max=getmax(a,n);
    for(int pos=1; max/pos>0; pos=pos*10){
        countingsort(a,n,pos);
    }
}



int main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    int a[n];
    readArray(a,n);
    printf("inpur array\n");
    printArray(a,n);
    radix_sort(a,n);
    printf("sorted array\n");
    printArray(a,n);
    return 0;

}