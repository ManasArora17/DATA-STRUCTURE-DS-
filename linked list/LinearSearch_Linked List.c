#include<stdio.h>
#include"LinkedList.h"
void LinearSearch(struct Node **START,int key){
    struct Node *p;
    p=*START;
    int t=0,c=0;
    while(p!=NULL){
        c++;
        if(p->info==key){
            t=1;
            printf("%d is present at %d Node.",key,c);
            break;
        }
        p=p->Next;
    }
    if(t==0) printf("Element is not present.");
}
int main(){
    struct Node *START;
    START  = NULL;
    InsEnd(&START,1);
    InsEnd(&START,2);
    InsEnd(&START,3);
    InsEnd(&START,4);
    InsEnd(&START,5);
    LinearSearch(&START,3);
}
