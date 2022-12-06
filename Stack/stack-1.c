#include<stdio.h>
#include<stdlib.h>
#define size 100
#define TURE 1
#define FALSE 0
#include"mystack.h"
int main(){
    initialize();
    for(int i=0;i<5;i++){
        push(100);
    }
    printf("%d",pop());

}
