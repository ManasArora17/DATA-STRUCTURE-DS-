#include<stdio.h>
#include"ploynomialLinkedList.h"
int polynomailSubtraction(struct Node **poly1,struct Node **poly2){
    struct Node *p;
    p=(*poly2);
    while(p!=NULL){
        p->Coefficent = -(p->Coefficent);
        p=p->Next;
    }
    PolynomailAddition(poly1,poly2);
}
int main(){
    struct Node *START1,*START2;
    START1 = NULL;
    InsEnd(&START1,2,5);
    InsEnd(&START1,4,4);
    InsEnd(&START1,5,3);
    InsEnd(&START1,10,2);
    InsEnd(&START1,8,1);
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
    polynomailSubtraction(&START1,&START2);
}

