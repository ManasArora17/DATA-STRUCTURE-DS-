#include<stdio.h>
#include"LinkedList.h"
void CountEvenOdd(struct Node **START){
    int c1=0,c2=0;
    struct Node *q;
    q=(*START);
    while(q!=NULL){
        if((q->info)%2==0){
            c1++;
        }
        else c2++;
        q=q->Next;
    }
    printf("Even = %d \nOdd = %d",c1,c2);
}
int main(){
    struct Node *START;
    START = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    InsEnd(&START,6);
    InsEnd(&START,7);
    CountEvenOdd(&START);
}
