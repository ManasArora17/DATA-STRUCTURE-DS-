#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data;
    int freq;
    struct Node *next;
};
struct Node* MakeNode(char a,int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=a;
    p->freq=x;
    p->next=NULL;
    return p;
};
void  InsertAfter(struct Node **q,char a,int x){
    struct Node *p,*r;
    p=MakeNode(a,x);
    r=(*q)->next;
    p->next=r;
    (*q)->next=p;
}
void InsertBeg(struct Node **START,char a,int x){
    struct Node *q;
    q=MakeNode(a,x);
    q->next=(*START);
    (*START)=q;
}
void Insert(struct Node **START,char a,int x){
    struct Node *p=(*START),*q=NULL;
    if(p==NULL){
        (*START)=MakeNode(a,x);
    }
    else{
        while(p!=NULL && x>p->freq){
            q=p;
            p=p->next;
        }
        if(q!=NULL) InsertAfter(&q,a,x);
        else InsertBeg(START,a,x);
    }
}
struct Node* Delete_front(struct Node **START){
    struct Node *p;
    p=(*START);
    (*START)=(*START)->next;
    p->next=NULL;
    return p;
}
int main(){
    char para[1000];
    int hash[26]={0};
    gets(para);
    int n=strlen(para);
    for(int i=0;i<n;i++){
        hash[para[i]-'a']++;
    }
    struct Node *START=NULL;
    for(int i=0;i<26;i++){
        if(hash[i]!=0) Insert(&START,'a'+i,hash[i]);
    }
}
