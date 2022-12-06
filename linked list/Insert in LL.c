#include<stdio.h>
#include"LinkedList.h"
void insert(struct Node **START,int x,int n){
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
int main(){
    struct Node *START;
    START = NULL;
    InsEnd(&START,10);
    InsEnd(&START,20);
    InsEnd(&START,40);
    InsEnd(&START,50);
    InsEnd(&START,60);
    Traverse(&START);
    insert(&START,30,2);
    printf("\n");
    Traverse(&START);
}
