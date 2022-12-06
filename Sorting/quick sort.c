#include<stdio.h>
int partition(int *arr,int low,int high){
    int i = low-1;
    int pivot = arr[high];
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            int a = arr[i];
            arr[i] = arr[j];
            arr[j] = a;
        }
    }
    int b = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = b;
    return i+1;
}
void quickSort(int *arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int main(){
    int n,*arr;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    arr=malloc((n+1)*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0,high=n-1;
    quickSort(arr,low,high);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

