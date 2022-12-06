#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct Node{
    int info;
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
        printf("%d ",p->info);
        p=p->Next;
    }
}

void InsBeg(struct Node **START,int x){
    struct Node *p;
    p=GetNode();
    p->info=x;
    p->Next=(*START);
    (*START)=p;
}
void InsAft(struct Node **q,int x){
    struct Node *p,*r;
    p=GetNode();
    p->info=x;
    r=(*q)->Next;
    p->Next=r;
    (*q)->Next=p;
}
void InsEnd(struct Node **START,int x){
    struct Node *q,*p;
    q=(*START);
    if(q==NULL){
        InsBeg(START,x);
    }
    else{
        while(q->Next!=NULL){
            q=q->Next;
        }
        p=GetNode();
        p->info=x;
        p->Next=NULL;
        q->Next=p;
    }
}
void Insert(struct Node **START,int x,int n){
    int a = CountNode(START);
    if(n==1) InsBeg(START,x);
    else if(n==a+1) InsEnd(START,x);
    else if(n>1 && n<=a){
        struct Node *p;
        p=*START;
        for(int i=0;i<n-1;i++){
            p=p->Next;
        }
        InsAft(&p,x);
    }
    else printf("Invalid Index");
}
void OrderedInsertion(struct Node **START,int x){
    struct Node *p,*q;
    p=*START;
    q=NULL;
    while(p!=NULL && x>p->info){
        q=p;
        p=p->Next;
    }
    if(q==NULL){
        InsBeg(START,x);
    }
    else InsAft(&q,x);
}
void PQInsertion(struct Node **START,int x){
    OrderedInsertion(START,x);
}

int DelBeg(struct Node **START){
    int x;
    struct Node *p;
    p=*START;
    x=p->info;
    *START=(*START)->Next;
    free(p);
    return x;
}
int DelEnd(struct Node **START){
    int x;
    struct Node *p,*q;
    p=*START;
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

void middleElement(struct Node **START){
    struct Node *T,*R;
    T=*START;
    R=(*START)->Next;
    while(R!=NULL && R->Next!=NULL){
        T=T->Next;
        R=R->Next;
        R=R->Next;
    }
    printf("%d",T->info);
}
/*void Cycledetection(struct Node **START);
    struct Node *T,*R;
    T= *START;
    R= *START;
    while(R!=NULL && R->Next!=NULL){
        T=T->Next;
        R=R->Next;
        R=R->Next;
        if(T==R){
            return TRUE;
        }
    return FALSE;
int countLengthOfCycle(struct Node **START);
    struct Node *T,*R;
        T=*START;
        R=*START;
        while(R!=NULL && R->Next!=NULL){
            T=T->Next;
            R=R->Next;
            R=R->Next;
            if(T==R){
                break;
            }
        }
        int c=0;
        do{
            c++;
            T=T->Next;
        }while(T!=R);
        return c;
struct Node* StartPoint(Struct Node **START);
    struct Node *T,*R,*P;
        T=*START;
        R=*START;
        P=*START;
        while(R!=NULL && R->Next!=NULL){
            T=T->Next;
            R=R->Next;
            R=R->Next;
            if(T==R){
                break;
            }
        }
        while(1){
            if(P==R){
                return P;
            }
            P=P->Next;
            R=R->Next;
        }
}
int PQdel(struct Node **START){
    int x = DelBeg(START);
}
void CountEvenOdd(struct Node **START){
    int c1=0,c2=0;
    struct Node *q;
    q=*START;
    while(q!=NULL){
        if((q->info)%2==0){
            c1++;
        }
        else c2++;
        q=q->Next;
    }
    printf("Even= %d,Odd= %d",c1,c2);
}*/
int main(){
    struct Node *START;
    START=NULL;
    OrderedInsertion(&START,5);
    OrderedInsertion(&START,10);
    OrderedInsertion(&START,15);
    OrderedInsertion(&START,20);
    OrderedInsertion(&START,25);
    Traverse(&START);
}
