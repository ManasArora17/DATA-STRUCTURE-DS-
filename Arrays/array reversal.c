#include<stdio.h>
int main(){
    int n,*arr;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    arr=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0,j=n-1;i<j;i++,j--){
        int a=arr[i];
        arr[i]=arr[j];
        arr[j]=a;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
