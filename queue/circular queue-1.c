#include<stdio.h>
#include"circular queue.h"
int main(){
    struct Queue qf;
    initialise(&qf);
    enqueue(&qf,1);
    printf("%d",dequeue(&qf));
    return 0;
}

