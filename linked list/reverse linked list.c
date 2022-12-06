#include<stdio.h>
#include"LinkedList.h"
#include"mystackPointer.h"
void ReverseInplace(struct Node **START){
    struct Node *C,*P,*N;
    C = *START;
    P = NULL;
    N = C->Next;
    while(C!=NULL){
        C->Next = P;
        P = C;
        C = N;
        if(N!=NULL) N = N->Next;
    }
    *START = P;
}
void ReverseUsingStack(struct Node **START){
    struct Node *p,*START2;
    START2=NULL;
    struct stack s;
    initialise(&s);
    p=*START;

    while(p!=NULL){
        push(&s,p->info);
        p=p->Next;
    }
    while(!isempty(&s)){
        InsEnd(&START2,pop(&s));
    }
    Traverse(&START2);
}
void Reverse(struct Node **START){
    struct Node *p,*q;
    p=*START;
    q=NULL;
    while(p!=NULL){
        InsBeg(&q,p->info);
        p=p->Next;
    }
    Traverse(&q);
}
int main(){
    struct Node *START;
    START = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    Traverse(&START);
    printf("\n");
    Reverse(&START);
}

