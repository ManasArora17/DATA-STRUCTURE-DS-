#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 10
#define TRUE 1
#define FALSE 0
struct Queue{
    int item[QUEUESIZE];
    int Front;
    int Rear;
};
struct Queue cq;
void initialise(struct Queue *cq){
    cq->Front=QUEUESIZE-1;
    cq->Rear=QUEUESIZE-1;
}

int isEmpty(struct Queue *cq){
    if(cq->Rear == cq->Front){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void enqueue(struct Queue *cq,int x){
    if((cq->Rear+1)%QUEUESIZE==cq->Front){
        printf("Queue overflow");
        exit(1);
    }
    cq->Rear=(cq->Rear+1)%QUEUESIZE;
    cq->item[cq->Rear]=x;
}

int dequeue(struct Queue *cq){
    if (isEmpty(cq)){
        printf("Queue underflow");
        exit(1);
    }
    cq->Front=(cq->Front+1)%QUEUESIZE;
    int x=cq->item[cq->Front];
    return x;
}

