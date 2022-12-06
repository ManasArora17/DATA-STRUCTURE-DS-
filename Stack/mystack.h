#include <stdio.h>
#include <string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    int item[STACKSIZE];
    int TOP;
};
struct stack s;
void initialise(){
    s.TOP=-1;
}

int isempty(){
    if (s.TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void push(int x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}

int pop(){
    if (isempty()){
        printf("stack underflow");
        exit(1);
    }
    int x=s.item[s.TOP];
    s.TOP=s.TOP-1;

    return x;
}
int stacktop(){
    int x=s.item[s.TOP];
    return x;
}

