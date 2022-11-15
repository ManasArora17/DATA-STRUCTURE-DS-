#include<stdio.h>
int main(){
    int *arr,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
