#include <stdio.h>
int main(){

int s1[]={1,2,3,4};
int s2[]={3,4,5};
int s3[10];
int i,j,k=0;
int n1=sizeof(s1)/sizeof(s1[0]);
int n2=sizeof(s2)/sizeof(s2[0]);
for(i=0;i<n1;i++){
    for(j=0;j<n2;j++){
        if(s1[i]==s2[j]){
            s3[k]=s1[i];
            k++;
        }
    }
}
printf("intersection is: ");
for(i=0;i<k;i++){
    printf("%d\t",s3[i]);
}
return 0;
}