#include<stdio.h>
#include<stdlib.h>
#define size 100
#define TURE 1
#define FALSE 0
#include"mystack.h"
int main(){
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    initialise();
    while(x!=0){
        int rem =x%2;
        push(rem);
        x=x/2;
    }
    while(!isempty()){
        int a= pop();
        printf("%d",a);
    }
}

