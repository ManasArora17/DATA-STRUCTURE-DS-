#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr,n,m;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the numbers: ");
    arr = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(arr+i));
    }
}
