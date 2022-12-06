#include<stdio.h>
#include"LinkedList.h"
void Copy(struct Node **START){
    struct Node *p,*q;
    q=NULL;
    p=*START;
    while(p!=NULL){
        InsEnd(&q,p->info);
        p=p->Next;
    }
    Traverse(&q);
}
int main(){
    struct Node *START;
    START  = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    Copy(&START);
}
