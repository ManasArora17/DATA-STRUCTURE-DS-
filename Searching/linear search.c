#include<stdio.h>
int linearSearch(int *arr,int n,int s){
    for(int i=0;i<n;i++){
        if(arr[i]==s) return i;
    }
}
int main(){
    int *arr,n,s;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&s);
    int r=linearSearch(arr,n,s);
    printf("indexing-%d",r);
}
