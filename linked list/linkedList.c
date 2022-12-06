#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *Next;
};
struct node *START;
struct Node *GetNode(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    return p;
};
insaft(struct Node **q,int x){
    struct Node *p,*r;
    p=GetNode();
    p->info=x;
    r=(*q)->Next;
    p->Next=r;
    (*q)->Next=p;
}
InsBeg(int x){
    struct Node *p;
    p=GetNode();
    p->info=x;
    p->Next=START;
    START=p;
}
Traverse(){
    struct Node *p;
    p=START;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->Next;
    }
}
void InsEnd(int x){
    struct Node *q,*p;
    q=START;
    while(q->Next!=NULL){
        q=q->Next;

    }
    p=GetNode();
    p->info=x;
    p->Next=NULL;
    q->Next=p;
}
int CountNode(){
    int c=0;
    struct Node *q;
    q=START;
    while(q!=NULL){
        c++;
        q=q->Next;
    }
    return c;
}
void CountEvenOdd(){
    int c1=0,c2=0;
    struct Node *q;
    q=START;
    while(q!=NULL){
        if((q->info)%2==0){
            c1++;
        }
        else c2++;
        q=q->Next;
    }
    printf("Even= %d,Odd= %d",c1,c2);
}
int main(){
    START=NULL;
    InsBeg(4);
    InsBeg(5);
    InsBeg(6);
    InsBeg(7);
    InsBeg(8);
    printf("%d\n",CountNode());
    CountEvenOdd();
}
