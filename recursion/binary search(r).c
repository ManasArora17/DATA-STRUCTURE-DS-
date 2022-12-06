#include<stdio.h>
int binarySearch(int *arr,int low,int high,int key){
    if(low<high){
        int mid;
        mid=(low+high)/2;
        if(arr[mid] == key){
            return mid;
        }
        else{
            if(key<arr[mid]){
                binarySearch(arr,low,mid-1,key);
            }
            else{
                binarySearch(arr,mid+1,high,key);
            }
        }
    }
}
int main(){
    int *arr,low=0,high,mid,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the element: ");
    high = n-1;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("Enter the key: ");
    scanf("%d",&key);
    int result=binarySearch(arr,low,high,key);
    printf("Index of entered element:- %d",result);
}
