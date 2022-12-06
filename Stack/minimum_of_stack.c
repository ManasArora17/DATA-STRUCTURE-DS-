#include<stdio.h>
#include"myStackPointer.h"
int main(){
    int n,y;
    struct stack fs;
    struct stack ss;
    initialise(&fs);
    initialise(&ss);
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int i=0;
    while(i<n){
        int x;
        scanf("%d",&x);
        push(&fs,x);
        i++;
    }
    int min = stacktop(&fs);

    while(!isempty(&fs)){
        y = stacktop(&fs);
        if(y<min){
            min = y;
        }
        else{
            pop(&fs);
            push(&ss,y);
        }
    }

    while(!isempty(&ss)){
        pop(&ss);
        push(&fs,y);
    }
    printf("%d",min);
}
