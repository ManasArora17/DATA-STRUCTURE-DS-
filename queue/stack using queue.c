#include<stdio.h>
#include"Queue.h"
void push(struct Queue *q,int x){
    struct Queue q2;
    initialise(&q2);
    enqueue(&q2,x);
    while(!isEmpty(q)){
        enqueue(&q2,dequeue(q));
    }
    while(!isEmpty(&q2)){
        enqueue(q,dequeue(q));
    }
}
int pop(struct Queue *q){
    return dequeue(q);
}
int main(){
    struct Queue q1;
    initialise(&q1);
    push(&q1,10);

}
