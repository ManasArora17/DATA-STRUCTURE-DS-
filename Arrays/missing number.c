#include<stdio.h>
int main(){
    int n,*arr;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=malloc((n+1)*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int *arr1;
    arr1=malloc((max+1)*sizeof(int));
    for(int i=0;i<max+1;i++){
        arr1[i]=0;
    }
    for(int i=0;i<n;i++){
        arr1[arr[i]]=arr1[arr[i]]+1;
    }
    for(int i=1;i<max+1;i++){
        if(arr1[i]==0){
            printf("missing number-%d\n",i);
        }
    }
}




