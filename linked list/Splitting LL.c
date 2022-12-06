#include<stdio.h>
#include"LinkedList.h"
void Split(struct Node **START){
    struct Node *START2,*p;
    p=(*START);
    START2=NULL;
    int n = CountNode(START)/2;
    for(int i=0;i<n-1;i++){
        p=p->Next;
    }
    START2 = p->Next;
    p->Next = NULL;
    Traverse(START);
    printf("\n");
    Traverse(&START2);
}
int main(){
    struct Node *START;
    START=NULL;
    InsEnd(&START,10);
    InsEnd(&START,20);
    InsEnd(&START,30);
    InsEnd(&START,40);
    InsEnd(&START,50);
    InsEnd(&START,60);
    Traverse(&START);
    printf("\n");
    Split(&START);

}
