#include<stdio.h>
int arr1[100];
void merge(int *arr,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            arr1[k] = arr[i];
            i++;k++;
        }
        else{
            arr1[k] = arr[j];
            j++;k++;
        }
    }
    while(i<=mid){
        arr1[k]=arr[i];
        i++;k++;
    }
    while(j<=high){
        arr1[k]=arr[j];
        j++;k++;
    }

    for(int i=low;i<=high;i++){
        arr[i]=arr1[i];
    }


}
void mergeSort(int *arr,int low,int high){
    if(low<high){
        int mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int *arr,n,low,high,mid;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    arr = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
    low=0;
    high=n-1;
    mergeSort(arr,low,high);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
