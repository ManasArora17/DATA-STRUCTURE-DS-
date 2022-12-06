#include<stdio.h>
#include"LinkedList.h"
void concat(struct Node **START1,struct Node **START2){
    struct Node *p;
    p = *START1;
    while(p->Next!=NULL){
        p=p->Next;
    }
    p->Next = *START2;
}
int main(){
    struct Node *START1,*START2;
    START1  = NULL;
    InsEnd(&START1,1);
    InsEnd(&START1,2);
    InsEnd(&START1,3);
    InsEnd(&START1,4);
    InsEnd(&START1,5);
    START2  = NULL;
    InsEnd(&START2,6);
    InsEnd(&START2,7);
    InsEnd(&START2,8);
    InsEnd(&START2,9);
    InsEnd(&START2,10);
    concat(&START1,&START2);
    Traverse(&START1);
}
