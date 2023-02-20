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
struct Node* BSTSearch(struct Node **T,int x){
    while((*T)!=NULL){
        if((*T)->data==x){
            return (*T);
        }
        else{
            if(x<(*T)->data) (*T)=(*T)->left;
            else (*T)=(*T)->right;
        }
    }
    return NULL;
}
struct Node *BSTSuccessor(struct Node *T){
    struct Node *q,*p;
    p=T;
    if(p->right!=NULL) return MinBST(p->right);
    else{
        q=p->FNode;
        while(q!=NULL && q->right==p){
            p=q;
            q=q->FNode;
        }
    }
    return q;
}
int IsLeft(struct Node *p){
    if(p->FNode->left==p) return TRUE;
    else return FALSE;
}
int IsRight(struct Node *p){
    if(p->FNode->right==p) return TRUE;
    else return FALSE;
}
int BSTDelete(struct Node *p){
    struct Node *q,*r;
    int x,y;
    if(p->left==NULL && p->right==NULL){
        q=p->FNode;
        if(IsLeft(p)) q->left=NULL;
        else q->right=NULL;

        int x=p->data;
        free(p);
        return x;
    }
    else if(p->left==NULL || p->right==NULL){
            q=p->FNode;
        if(p->left==NULL){
            r=p->right;
        }
        else{
            r=p->left;
        }
        if(IsLeft(p)){
            q->left=r;
        }
        else{
            q->right=r;
        }
        r->FNode=q;
        x=p->data;
        free(p);
        return x;
    }
    else{
        q=BSTSuccessor(p);
        y=BSTDelete(q);
        x=p->data;
        p->data=y;
        return x;
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
    printf("Enter the Key: ");
    scanf("%d",&key);
    DNode = BSTSearch(&root,key);
    inorderTraversal(root);
    BSTDelete(DNode);
    printf("\n");
    inorderTraversal(root);
}


