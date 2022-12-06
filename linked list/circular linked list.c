#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *Next;
};
struct Node *GetNode(){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    return p;
};
void Traverse(struct Node **CSTART){
    struct Node *p;
    p=(*CSTART)->Next;
    while(p!=(*CSTART)){
        printf("%d ",p->info);
        p=p->Next;
    }
    printf("%d ",p->info);
}
void InsBeg(struct Node **CSTART,int x){
    struct Node *p;
    p=GetNode();
    p->info=x;
    if((*CSTART)!=NULL){
         p->Next=((*CSTART)->Next);
         (*CSTART)->Next=p;
    }
    else{
        (*CSTART)=p;
        (*CSTART)->Next=p;
    }
}
void InsAft(struct Node **q,int x){
    struct Node *p;
    if(p==NULL){
        printf("Void Insertion");
        exit(1);
    }
    else{
        p=GetNode();
        p->info=x;
        p->Next=(*q)->Next;
        (*q)->Next=p;
    }
}
void InsEnd(struct Node **CSTART,int x){
    struct Node *p;
    p=GetNode();
    p->info=x;
    if((*CSTART)!=NULL){
        p->Next=(*CSTART)->Next;
        (*CSTART)->Next=p;
        (*CSTART)=p;
    }
    else{
        (*CSTART) = p;
        (*CSTART)->Next = p;
    }
}
int DelBeg(struct Node **CSTART){
    struct Node *p;
    int x;
    p=(*CSTART)->Next;
    (*CSTART)->Next=p->Next;
    if((*CSTART)->Next == (*CSTART)){
        CSTART = NULL;
    }
    x=p->info;
    free(p);
    return x;
}
int DelEnd(struct Node **CSTART){
    int x;
    struct Node *p,*q;
    q=*CSTART;
    p=(*CSTART)->Next;
    if((*CSTART)=NULL){
        printf("Void Deletion");
        exit(1);
    }
    else{
        while(p->Next!=*CSTART){
            p=p->Next;
        }
        q->Next=(*CSTART)->Next;
        *CSTART = p;
        x=q->info;
        free(p);
        return x;
    }
}
int DelAft(struct Node **q){
    int x;
    struct Node *p;
    p=(*q)->Next;
    (*q)->Next=p->Next;
    x=p->info;
    free(p);
    return x;
}
int main(){
    struct Node *CSTART;
    CSTART=NULL;
    InsBeg(&CSTART,10);
    InsBeg(&CSTART,20);
    InsBeg(&CSTART,30);
    DelEnd(&CSTART);
    Traverse(&CSTART);
}


