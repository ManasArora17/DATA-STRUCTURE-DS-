#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
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
    struct Node *p,*q;
    p=*T;
    if(*T==NULL){
        *T=MakeNode(x);
    }
    else{
        while(p!=NULL){
            q=p;
            if(x<p->data) p=p->left;

            else p=p->right;
        }
        if(x<q->data) q->left=MakeNode(x);
        else q->right=MakeNode(x);
    }
}
int MinBST(struct Node *T){
    while(T->left!=NULL){
        T=T->left;
    }
    return T->data;
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
int MaxBST(struct Node *T){
    while(T->right!=NULL){
        T=T->right;
    }
    return T->data;
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
void Mirror(struct Node **T){
    if((*T)->left!=NULL && (*T)->right!=NULL){
        Mirror(&((*T)->left));
        Mirror(&((*T)->right));
        struct Node *t=(*T)->left;
        (*T)->left=(*T)->right;
        (*T)->right=t;
    }
    else{
        return;
    }
}
int main(){
    struct Node *root=NULL;
    int n,x;
    printf("Enter the Number of item: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        BSTinsert(&root,x);
    }
    inorderTraversal(root);
    printf("\n");
    Mirror(&root);
    inorderTraversal(root);
}

