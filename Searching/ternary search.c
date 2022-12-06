#include<stdio.h>
int ternarySearch(int *arr,int n,int k){
    int high = n-1,low=0;
    while(low<high){
        int mid1 =  low + (high/3);
        int mid2 =  high - (high/3);
        if(k==arr[mid1]){
            return mid1;
        }
        else if(k==arr[mid2]){
            return mid2;
        }
        else if(k<arr[mid1]){
            low=1;
            high=mid1-1;
        }
        else if(k>arr[mid2]){
            low=mid2+1;
        }
        else{
            low=mid1+1;
            high=mid2-1;
        }
    }
}
int main(){
    int *arr,n,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&k);
    int result = ternarySearch(arr,n,k);
    printf("Index - %d",result);
}
