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
void initialise(struct Queue *q){
    q->Front=0;
    q->Rear=-1;
}

int isEmpty(struct Queue *q){
    if(q->Rear-q->Front+1==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void enqueue(struct Queue *q,int x){
    if(q->Rear==QUEUESIZE-1){
        printf("Queue overflow");
        exit(1);
    }
    q->Rear=q->Rear+1;
    q->item[q->Rear]=x;
}

int dequeue(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue underflow");
        exit(1);
    }
    int x=q->item[q->Front];
    q->Front=q->Front+1;
    return x;
}
