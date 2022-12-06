#include<stdio.h>
int main(){
    int a,t=0;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&a);
    arr = malloc((a+1) * sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int n,p;
    printf("Enter the Element to Delete: ");
    scanf("%d",&n);
    for(int i=0;i<a;i++){
        if(n==arr[i]){
            p=i;
            t=1;
            break;
        }
    }
    if(t==1){
        for(int i=p;i<a;i++){
            arr[i]=arr[i+1];
        }

        for(int i=0;i<a-1;i++){
            printf("%d ",arr[i]);
        }
    }
    else{
        printf("Element is not present in array");
    }
}

