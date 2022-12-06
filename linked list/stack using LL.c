#include<stdio.h>
#include"LinkedList.h"
#define TURE 1
#define FALSE 0
void push(struct Node **TOP,int x){
    InsBeg(TOP,x);
}
int pop(struct Node **TOP){
    int x;
    x=DelBeg(TOP);
    return x;
}
int isEmpty(struct Node **TOP){
    if((*TOP)==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct Node *TOP;
    TOP = NULL;
    int x;
    push(&TOP,100);
    push(&TOP,200);
    push(&TOP,300);
    push(&TOP,400);
    Traverse(&TOP);
    pop(&TOP);
    printf("\n%d",isEmpty(&TOP));
}
