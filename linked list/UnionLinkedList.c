#include<stdio.h>
#include"LinkedList.h"
void UnionLL(struct Node **START1,struct Node **START2){
    struct Node *p,*q,*START;
    START=NULL;
    p=*START1;
    q=*START2;
    while(p!=NULL && q!=NULL){
        if(p->info<q->info){
            InsEnd(&START,p->info);
            p=p->Next;
        }
        else{
            if(p->info==q->info){
                InsEnd(&START,p->info);
                q=q->Next;
                p=p->Next;
            }
            else{
                InsEnd(&START,q->info);
                q=q->Next;
            }
        }
    }
    while(p!=NULL){
        InsEnd(&START,p->info);
        p=p->Next;
    }
    while(q!=NULL){
        InsEnd(&START,q->info);
        q=q->Next;
    }
    Traverse(&START);
}
int main(){
    struct Node *START1,*START2;
    START1=NULL;
    START2=NULL;
    int arr1[5] = {20,40,30,10,5};
    int arr2[6] = {35,34,12,20,30,23};
    for(int i=0;i<5;i++){
        OrderedInsertion(&START1,arr1[i]);
    }
    for(int i=0;i<6;i++){
        OrderedInsertion(&START2,arr2[i]);
    }
    UnionLL(&START1,&START2);
}
