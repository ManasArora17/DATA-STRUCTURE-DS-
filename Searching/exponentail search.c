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
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int exponentailSearch(int *arr,int n,int key){
    if(arr[0]==key){
        return 0;
    }
    int i=1;
    while(i<n && arr[i]<=key){
        i=i*2;
    }
    return binarySearch(arr,i/2,min(i,n-1),key);
}
int main(){
    int *arr,n,key;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the elements: ");
    arr=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&key);
    int result=exponentailSearch(arr,n,key);
    printf("Index: %d",result);
}
