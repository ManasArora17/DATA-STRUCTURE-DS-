#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int partition(int a[],int low,int high){
    int i,t;
    srand(time(0));
    int random= rand()%(high+1)+low;
    t=a[low];
    a[low]=a[random];
    a[random]=t;
    i=low;
    int j=high+1;
    int pivot=a[low];
    do{
        do{
            i++;
        }while(a[i]<pivot);

        do{
            j--;

        }while(a[j]>pivot);

        if(i<j){
           t=a[j];
           a[j]=a[i];
           a[i]=t;
        }
    }while(i<j);
    t=a[j];
    a[j]=a[low];
    a[low]=t;
    return j;
}
 void quicksort(int a[],int low,int high){
     if(low<high){
        int j;
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
     }
 }
int main(){
    int n,*arr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc((n+1)*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int low=0,high=n-1;
    arr[n]= INT_MAX;
    quicksort(arr,low,high);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
