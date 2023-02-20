#include<stdio.h>
#include<stdlib.h>
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
    if(*T==NULL){
        *T=MakeNode(x);
    }
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
struct Node* MinBST(struct Node *T){
    while(T->left!=NULL){
        T=T->left;
    }
    return T;
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
struct Node *MaxBST(struct Node *T){
    while(T->right!=NULL){
        T=T->right;
    }
    return T;
}
struct Node* BSTSearch(struct Node *T,int x){
    while(T!=NULL){
        if(T->data==x){
            return T;
        }
        else{
            if(x<T->data) T=T->left;
            else T=T->right;
        }
    }
    return NULL;
}
struct Node *BSTSuccessor(struct Node *T,int key){
    struct Node *q,*p;
    p=BSTSearch(T,key);
    if(p->right!=NULL) q=MinBST(p->right);
    else{
        q=p->FNode;
        while(q!=NULL && q->right==p){
            p=q;
            q=q->FNode;
        }
    }
    return q;
}
struct Node *BSTPredessor(struct Node *T,int key){
    struct Node *q,*p;
    p=BSTSearch(T,key);
    if(p->right!=NULL) q=MaxBST(p->left);
    else{
        q=p->FNode;
        while(q!=NULL && q->left==p){
            p=q;
            q=q->FNode;
        }
    }
    return q;
}
int main(){
    struct Node *root=NULL;
    int n,x,key;
    printf("Enter the Number of item: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        BSTinsert(&root,x);
    }
    printf("Enter the key: ");
    scanf("%d",&key);
    struct Node *r1=BSTSuccessor(root,key);
    struct Node *r2=BSTPredessor(root,key);
    printf("Successor Node: %d\n",r1->data);
    printf("predessor Node: %d",r2->data);
}
