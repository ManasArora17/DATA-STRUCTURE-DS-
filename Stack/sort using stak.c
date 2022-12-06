#include<stdio.h>
#include"myStackPointer.h"
int main(){
    int x,n;
    struct stack input;
    struct stack temp;
    initialise(&input);
    initialise(&temp);
    printf("Enter the number of element: ");
    scanf("%d",&n);
    printf("Enter the element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        push(&input,x);
    }
    int a;
    while(!isempty(&input)){
        if(isempty(&temp)){
            a = pop(&input);
            push(&temp,x);
        }
        else{
            a = pop(&input);
            while(a<stacktop(&temp)  && !isempty(&temp)){
                push(&input,pop(&temp));
            }
            push(&temp,a);
        }
    }
    while(!isempty(&temp)){
        push(&input,pop(&temp));
    }
    for(int i=0;i<n;i++){
        printf("%d ",pop(&input));
    }
}
