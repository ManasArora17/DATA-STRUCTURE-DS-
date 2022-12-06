#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *Prev;
    struct Node *Next;
};
struct Node *GetNode(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    return p;
};
void Traverse(struct Node **DSTART){
    struct Node *p;
    p=(*DSTART);
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->Next;
    }
}
int CountNode(struct Node **DSTART){
    int c=0;
    struct Node *q;
    q=(*DSTART);
    while(q!=NULL){
        c++;
        q=q->Next;
    }
    return c;
}
void InsBeg(struct Node **DSTART,int x){
    struct Node *p;
    p=GetNode();
    p->info=x;
    p->Prev=NULL;
    p->Next=(*DSTART);
    if((*DSTART)!=NULL){
        (*DSTART)->Prev = p;
    }
    (*DSTART)=p;
}
void InsEnd(struct Node **DSTART,int x){
    struct Node *q,*p;
    p=(*DSTART);
    if(p==NULL){
        InsBeg(DSTART,x);
    }
    else{
        while(p->Next!=NULL){
            p=p->Next;
        }
        q=GetNode();
        q->info=x;
        q->Next=NULL;
        p->Next=q;
        q->Prev=p;
    }
}
void InsAft(struct Node **p,int x){
    struct Node *r,*q;
    q=GetNode();
    q->info=x;
    r=(*p)->Next;
    (*p)->Next=q;
    q->Prev=(*p);
    q->Prev=(*p);
    q->Next=r;
    if(r!=NULL){
        r->Prev = q;
    }
}
void InsPrev(struct Node **p,int x){
    struct Node *r,*q;
    q=GetNode();
    q->info = x;
    r = (*p)->Prev;
    (*p)->Prev = q;
    q->Next = (*p);
    q->Prev = r;
}
void OrderedInsertion(struct Node **DSTART,int x){
    struct Node *p,*q;
    p=*DSTART;
    q=NULL;
    while(p!=NULL && x>p->info){
        q=p;
        p=p->Next;
    }
    if(q==NULL){
        InsBeg(DSTART,x);
    }
    else InsAft(&q,x);
}
int DelBeg(struct Node **DSTART){
    int x;
    struct Node *p;
    p=*DSTART;
    x=p->info;
    *DSTART=(*DSTART)->Next;
    free(p);
    return x;
}
int DelEnd(struct Node **DSTART){
    int x;
    struct Node *p,*q;
    p=*DSTART;
    q=NULL;
    while(p->Next!=NULL){
        q=p;
        p=p->Next;
    }
    q->Next=NULL;
    x=p->info;
    free(p);
    return x;
}
int DelAft(struct Node **p){
    int x;
    struct Node *q,*r;
    q=(*p)->Next;
    r=q->Next;
    (*p)->Next=r;
    x=q->info;
    free(p);
    return x;
}
int main(){
    struct Node *DSTART,*p;
    DSTART = NULL;
    InsEnd(&DSTART,10);
    InsEnd(&DSTART,20);
    InsEnd(&DSTART,30);
    InsEnd(&DSTART,40);
    InsEnd(&DSTART,50);
    InsEnd(&DSTART,60);
    p=DSTART;
    for(int i=0;i<2;i++){
        p=p->Next;
    }
    InsPrev(&p,35);
    Traverse(&DSTART);
}



