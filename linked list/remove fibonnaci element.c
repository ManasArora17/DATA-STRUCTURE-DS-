#include<stdio.h>
#include"CircularLinkedList.h"
int MaxElement(struct Node **CSTART){
    struct Node *p;
    int max = (*CSTART)->info;
    p=(*CSTART)->Next;
    while(p!=(*CSTART)){
        if(max<p->info){
            max=p->info;
        }
        p=p->Next;
    }
    return max;
}
int fib(int n){
    int a=0,b=1,c;
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        for(int i=0;i<n-2;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
}
void RemoveFibonnaciElement(struct Node **CSTART){
    int *DAT;
    struct Node *p,*q;
    int m = MaxElement(CSTART);
    DAT = calloc((m+1),sizeof(int));
    int i=1;
    while(fib(i)<=m){
        DAT[fib(i)]++;
        i++;
    }
    for(int i=0;i<m+1;i++){
        printf("%d ",DAT[i]);
    }
    //Traverse(CSTART);

}
int main(){
    struct Node *CSTART;
    CSTART=NULL;
    InsEnd(&CSTART,1);
    InsEnd(&CSTART,2);
    InsEnd(&CSTART,3);
    InsEnd(&CSTART,4);
    InsEnd(&CSTART,5);
    RemoveFibonnaciElement(&CSTART);
}

//0 1 1 2 3
