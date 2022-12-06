#include<stdio.h>
int sort(int arr[],int a){
    int b,t=1,c=0;
        for(int i=0;i<a-1 && t==1;i++){
            t=0;
            for(int j=0;j<a-i-1;j++){
                if(arr[j]>arr[j+1]){
                    b=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=b;
                    t=1;
                }
            }
        }
    for(int i=0;i<a;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int *arr,n;
    printf("Enter the number of element:");
    scanf("%d",&n);
    printf("Enter the elements: ");
    arr=malloc((n)*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
}
