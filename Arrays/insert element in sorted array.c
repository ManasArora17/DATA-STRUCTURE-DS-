#include<stdio.h>
int main(){
    int a,n,p;
    int *arr;
    printf("Enter number of elements: ");
    scanf("%d",&a);
    arr = malloc((a+1) * sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element to enter: ");
    scanf("%d",&n);
    p=a;
    for(int i=0;i<a;i++){
        if(n<arr[i]){
            p=i;
            break;
        }
    }
    for(int i=a;i>=p;i--){
        arr[i]=arr[i-1];
    }
    arr[p]=n;
    for(int i=0;i<a+1;i++){
        printf("%d ",arr[i]);
    }
}
