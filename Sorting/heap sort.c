#include<stdio.h>
void heapSort(int *arr,int n){

}
int main(){
    int *arr,n;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    heapSort(arr,n);
}
