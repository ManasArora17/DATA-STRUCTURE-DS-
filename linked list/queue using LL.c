#include<stdio.h>
#include"LinkedList.h"
void Enqueue(struct Node **FRONT,struct Node **REAR,int x){
    if((*REAR)==NULL){
        InsBeg(REAR,x);
        (*FRONT)=(*REAR);
    }
    else{
        InsAft(REAR,x);
        (*REAR)=(*REAR)->Next;
    }
}
int Dequeue(struct Node **FRONT,struct Node **REAR){
    int x;
    if((*FRONT)==NULL){
        printf("Deletion is not possible");
        exit(1);
    }
    else{
        x=DelBeg(FRONT);
        if((*FRONT)==NULL) *REAR=NULL;
    }
    return x;
}
int main(){
    struct Node *FRONT,*REAR;
    FRONT = NULL;
    REAR = NULL;
    int x;
    Enqueue(&FRONT,&REAR,10);
    Enqueue(&FRONT,&REAR,20);
    Enqueue(&FRONT,&REAR,30);
    Enqueue(&FRONT,&REAR,40);
    Enqueue(&FRONT,&REAR,50);
    Traverse(&FRONT);
    printf("\n%d",Dequeue(&FRONT,&REAR));
}
