#include<stdio.h>
#include<stdlib.h>
int jumpSearch(int *arr,int n,int step,int key){
    int j=0;
    for(int i=0;i<n;i=i+step){
        if(key<arr[i]){
            j=i;
            break;
        }
        else if(key==arr[i]){
            return j;
        }
    }
    int t=0;
    for(int p=j-step;p<j;p++){
        if(arr[p]==key){
            return p;
            t=1;
        }
    }
    if(t==0){
        printf("Element is not present.");
    }
}
int main(){
    int *arr,n,s,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the search key: ");
    scanf("%d",&k);
    printf("Enter the steps: ");
    scanf("%d",&s);
    printf("index- %d",jumpSearch(arr,n,s,k));
}
