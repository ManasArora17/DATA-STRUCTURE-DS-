#include<stdio.h>
#include"myStackPointer.h"
int main(){
    struct stack fs;
    initialise(&fs);
    int x;
    for(int i=0;i<3;i++){
        scanf("%d",&x);
        push(&fs,x);
    }
    printf("%d",pop(&fs));
    printf("%d",pop(&fs));
}
