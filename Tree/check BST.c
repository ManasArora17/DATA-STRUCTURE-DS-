#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *FNode;
};
struct Node *MakeNode(int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void BSTinsert(struct Node **T,int x){
    struct Node *p,*q=NULL;
    p=*T;
    if(*T==NULL) *T=MakeNode(x);
    else{
        while(p!=NULL){
            q=p;
            p->FNode=q;
            if(x<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(x<q->data) q->left=MakeNode(x);
        else q->right=MakeNode(x);
    }
}
int IsBST(struct Node *T){
    struct Node *L,*R;
    if(T==NULL) return TRUE;
    if(T->left==NULL){
        T->right=NULL;
        return TRUE;
    }
    else{
        L=T->left;
        R=T->right;
        if(R!=NULL){
            if(L->data>T->data) return FALSE;
        }
        if(R!=NULL){
            if(R->data<T->data) return FALSE;
        }
        return(IsBST(L) && IsBST(R));
    }
}
int main(){
    struct Node *root,*DNode;
    root=NULL;
    int n,x,key,r;
    printf("Enter the Number of item: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        BSTinsert(&root,x);
    }
    int n1=IsBST(root);
    printf("%d",n1);
}
