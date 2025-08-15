#include<stdio.h>
#define MAX 100
int mainstack[MAX]; int top=-1;
int tempstack[MAX]; int temptop=-1;
int pushmain(int value){

    if(top<=MAX-1){
        mainstack[++top]=value;
    }
    else return -1;
}
int popmain(){

    if(top!=-1){
        return(mainstack[top--]);
    }
    else return -1;

}
int peekmain(){

    if(top!=-1){
        return(mainstack[top]);
    }
    else return -1;

}
int pushtemp(int value){

    if(temptop<=MAX-1){
        tempstack[++temptop]=value;
    }
    else return -1;
}
int poptemp(){

    if(temptop!=-1){
        return tempstack[temptop--];
    }
    else return -1;
}

int peektemp(){
    if(temptop!=-1){
        return tempstack[temptop];
    }
    else return -1;
}

void sortstack(){

    while(top>=0){
        int temp=popmain();
        while(temptop>=0 && peektemp()>temp){
            pushmain(poptemp());
        }
        pushtemp(temp);
    }

    //pushing sorted elements from temp stack to main stack
    while(temptop>=0){
        pushmain(poptemp());
    }
    //printing the elements
    for(int i=top;i>=0;i--){
        printf("%d\t",mainstack[i]);
    }
}

int main(){

    int val, n;
    printf("Enter no. of elements in stack: \n");
    scanf("%d",&n);
    printf("enter elements: ");
    for(int i=0;i<n;i++){

        scanf("%d",&val);
        pushmain(val);
    }
    printf("elements in main stack before sorting: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",mainstack[i]);
    }
    printf("elements after sorting\n");
    sortstack();
    return 0;

}