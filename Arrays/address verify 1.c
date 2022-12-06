#include<stdio.h>
int main(){
    int *arr,n,a;
    printf("Enter the size: ");
    scanf("%d",&n);
    arr = calloc(n,sizeof(int));
    printf("Enter the index to verify: ");
    scanf("%d",&a);
    int baseaddress=&arr[0];
    printf("Actual address = %d\n",&arr[a]);
    int b=baseaddress + a*sizeof(int);
    printf("using formula - %d",b);

}
