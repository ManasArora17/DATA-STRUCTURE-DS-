#include<stdio.h>
#include"ploynomialLinkedList.h"
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
int main(){
    struct Node *START1,*START2;
    START1 = NULL;
    InsEnd(&START1,1,5);
    InsEnd(&START1,3,4);
    InsEnd(&START1,4,3);
    InsEnd(&START1,2,2);
    InsEnd(&START1,6,1);
    Traverse(&START1);
    printf("\n");
    START2 = NULL;
    InsEnd(&START2,1,5);
    InsEnd(&START2,3,4);
    InsEnd(&START2,4,3);
    InsEnd(&START2,2,2);
    InsEnd(&START2,6,1);
    Traverse(&START2);
    printf("\n");
    PolynomailAddition(&START1,&START2);
}
