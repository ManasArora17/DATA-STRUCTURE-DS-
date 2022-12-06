#include<stdio.h>
#include<stdlib.h>
struct Node{
    int Coefficent;
    int Exponent;
    struct Node *Next;
};
struct Node *GetNode(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    return p;
};
void Traverse(struct Node **START){
    struct Node *p;
    p=*START;
    while(p!=NULL){
        if(p->Next==NULL) printf("%dX^%d",p->Coefficent,p->Exponent);
        else printf("%dX^%d + ",p->Coefficent,p->Exponent);
        p=p->Next;
    }
}
void InsBeg(struct Node **START,int x,int y){
    struct Node *p;
    p=GetNode();
    p->Coefficent=x;
    p->Exponent=y;
    p->Next=(*START);
    (*START)=p;
}
void InsEnd(struct Node **START,int x,int y){
    struct Node *q,*p;
    q=(*START);
    if(q==NULL){
        InsBeg(START,x,y);
    }
    else{
        while(q->Next!=NULL){
            q=q->Next;
        }
        p=GetNode();
        p->Coefficent=x;
        p->Exponent=y;
        p->Next=NULL;
        q->Next=p;
    }
}
void InsAft(struct Node **q,int x,int y){
    struct Node *p,*r;
    p=GetNode();
    p->Coefficent=x;
    p->Exponent=y;
    r=(*q)->Next;
    p->Next=r;
    (*q)->Next=p;
}
void OrderedInsertion(struct Node **START,int x,int y){
    struct Node *p,*q;
    p=*START;
    q=NULL;
    while(p!=NULL && y>p->Exponent){
        q=p;
        p=p->Next;
    }
    if(q==NULL){
        InsBeg(START,x,y);
    }
    else InsAft(&q,x,y);
}
void DelAft(struct Node **p){
    struct Node *q,*r;
    q=(*p)->Next;
    r=q->Next;
    (*p)->Next=r;
    free(p);
}
void PolynomailAddition(struct Node **poly1,struct Node **poly2){
    struct Node *poly3,*p,*q;
    p = *poly1;
    q = *poly2;
    poly3=NULL;
    while(p!=NULL && q!=NULL){
        if(p->Exponent == q->Exponent){
            InsEnd(&poly3,p->Coefficent+q->Coefficent,p->Exponent);
            p=p->Next;
            q=q->Next;
        }
        else{
            if(p->Exponent>q->Exponent){
                InsEnd(&poly3,p->Coefficent+q->Coefficent,p->Exponent);
                p=p->Next;
            }
            else{
                InsEnd(&poly3,p->Coefficent+q->Coefficent,p->Exponent);
                q=q->Next;
            }
        }
    }
    while(p!=NULL){
        InsEnd(&poly3,p->Coefficent+q->Coefficent,p->Exponent);
        p=p->Next;
    }
    while(q!=NULL){
        InsEnd(&poly3,p->Coefficent+q->Coefficent,p->Exponent);
        q=q->Next;
    }
    Traverse(&poly3);
}

