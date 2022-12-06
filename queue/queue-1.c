#include<stdio.h>
#include"circular queue.h"
#define QUEUESIZE 10
#define TRUE 1
#define FALSE 0
int main(){
    struct Queue qf;
    initialise(&qf);
    printf("Enter 1 to Enqueue.\n");
    printf("Enter 2 to Dequeue.\n");
    printf("Enter 3 to exit Queue.\n");
    while(1){
        int n;
        printf("Enter Option: ");
        scanf("%d",&n);
        if(n==1){
            int x;
            printf("Enter the value: ");
            scanf("%d",x);
            enqueue(&qf,x);

        }
        else if(n==2){
            printf("Dequeue value: %d\n",dequeue(&qf));
        }
        else if(n==3){
            break;
        }
        else{
            printf("Invalid option.\n");
        }
    }
    return 0;
}
