#include<stdio.h>
int main(){
    int arr[10][10],i,j;
    printf("Enter the indexes to verify: ");
    scanf("%d %d",&i,&j);
    printf("Base address = %u\n",&arr[0][0]);
    printf("Actual address = %u\n",&arr[i][j]);
    printf("using formula = %u",&arr[0][0]+(i*(10)+j));
}
