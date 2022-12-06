#include<stdio.h>
#include"CircularLinkedList.h"
void Concatenate(struct Node **CSTART1, struct Node **CSTART2){
    struct Node *p,*q;
    p= (*CSTART1)->Next;
    q= (*CSTART2)->Next;
    (*CSTART1)->Next=q;
    (*CSTART2)->Next=p;
    Traverse(CSTART1);
}
int main(){
    struct Node *CSTART1,*CSTART2;
    CSTART1=NULL;
    InsBeg(&CSTART1,10);
    InsBeg(&CSTART1,20);
    InsBeg(&CSTART1,30);
    CSTART2=NULL;
    InsBeg(&CSTART2,40);
    InsBeg(&CSTART2,50);
    InsBeg(&CSTART2,60);
    Concatenate(&CSTART1,&CSTART2);
}

