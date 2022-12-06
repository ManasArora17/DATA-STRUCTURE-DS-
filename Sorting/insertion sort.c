#include<stdio.h>
int insertionSort(int *arr,int n){
    for(int i=1;i<n;i++){
        int x=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>x){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1] = x;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int *arr,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr = malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insertionSort(arr,n);
}
