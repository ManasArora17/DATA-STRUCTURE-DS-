#include<stdio.h>
#include"LinkedList.h"
int countNode(struct Node **START){
    int c=0;
    struct Node *q;
    q=(*START);
    while(q!=NULL){
        c++;
        q=q->Next;
    }
    return c;
}
int main(){
    struct Node *START;
    START  = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    printf("Number of Nodes: %d",countNode(&START));
}
