#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    int item[STACKSIZE];
    int TOP;
};

void initialise(struct stack *s){
    s->TOP=-1;
}

int isempty(struct stack *s){
    if (s->TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void push(struct stack *s,char x){
    if(s->TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s->TOP=s->TOP+1;
    s->item[s->TOP]=x;
}

int pop(struct stack *s){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    int x=s->item[s->TOP];
    s->TOP=s->TOP-1;
    return x;
}
int stacktop(struct stack *s){
    int x=s->item[s->TOP];
    return x;
}

