#include<stdio.h>
#include"PolynomailLinkedList.h"
void Multiplication(struct Node **poly1,struct Node **poly2){
    struct Node *p,*q,*r,*poly3;
    poly3 = NULL;
    p=(*poly1);
    q=(*poly2);
    while(q!=NULL){
        while(p!=NULL){
            OrderedInsertion(&poly3,p->Coefficent*q->Coefficent,p->Exponent+q->Exponent);
            p=p->Next;
        }
        q=q->Next;
    }

    r = poly3;
    while(r->Next!=NULL){
        if(r->Exponent == r->Next->Exponent){
            r->Coefficent = r->Coefficent + r->Next->Coefficent;
            DelAft(&r);
        }
        else{
            r=r->Next;
        }
    }
    Traverse(&poly3);
}
int main(){
    struct Node *START1,*START2;
    START1 = NULL;
    InsEnd(&START1,3,2);
    InsEnd(&START1,4,1);
    START2 = NULL;
    InsEnd(&START2,1,2);
    InsEnd(&START2,2,1);
    Traverse(&START1);
    printf("\n");
    Traverse(&START2);
    printf("\n");
    Multiplication(&START1,&START2);
}
