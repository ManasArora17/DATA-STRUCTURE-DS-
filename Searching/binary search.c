#include<stdio.h>
#include<stdlib.h>
int binarySearch(int *arr,int n,int s){
    int mid,l=0,h=n;
    while(l<=h){
        mid=(l+h)/2;
        if(arr[mid]==s){
            return mid;
        }
        else if(arr[mid]>s){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
}
int main(){
    int *arr,n,s;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&s);
    int r=binarySearch(arr,n,s);
    printf("indexing-%d",r);
}
