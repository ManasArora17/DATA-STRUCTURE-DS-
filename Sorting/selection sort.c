#include<stdio.h>
void selectionSort(int *arr,int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if(min!= i){
            int a=arr[i];
            arr[i]=arr[min];
            arr[min]=a;
        }
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
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
