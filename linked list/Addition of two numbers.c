#include<stdio.h>
#include"LinkedList.h"
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
int Addition(struct Node **START1,struct Node **START2){
    struct Node *p,*q,*START3;
    START3=NULL;
    ReverseInplace(START1);
    ReverseInplace(START2);
    p=*START1;
    q=*START2;
    int carry = 0,total,sum;
    while(p!=NULL & q!=NULL){
        total = p->info + q->info + carry;
        sum = total%10;
        carry = total/10;
        p=p->Next;
        q=q->Next;
        InsBeg(&START3,sum);
    }
    while(p!=NULL){
        total = p->info + carry;
        sum = total%10;
        carry = total/10;
        p=p->Next;
        InsBeg(&START3,sum);
    }
    while(q!=NULL){
        total = q->info + carry;
        sum = total%10;
        carry = total/10;
        q=q->Next;
        InsBeg(&START3,sum);
    }
    if(carry>0){
        InsBeg(&START3,sum);
    }
    Traverse(&START3);
}
int main(){
    struct Node *START1,*START2;
    START1  = NULL;
    InsEnd(&START1,1);
    InsEnd(&START1,2);
    InsEnd(&START1,3);
    InsEnd(&START1,3);
    START2 = NULL;
    InsEnd(&START2,1);
    InsEnd(&START2,8);
    InsEnd(&START2,3);
    Addition(&START1,&START2);
}
