#include<stdio.h>
int main(){
    int arr[10][10][10],i,j,k;
    printf("Enter the indexes to verify: ");
    scanf("%d %d %d",&i,&j,&k);
    int baseaddress=&arr[0][0][0];
    printf("Base address = %u\n",&arr[0][0][0]);
    printf("Actual address = %u\n",&arr[i][j][k]);
    printf("using formula = %u",&arr[0][0][0] + ((10*10)*i+10*j+k));

}

