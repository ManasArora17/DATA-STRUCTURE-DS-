#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int H;
};
int Max(int a,int b){
    if(a>b) return a;
    else return b;
}
struct Node* MakeNode(int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->H=0;
    return p;
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
void PreorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%d ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}
struct Node* LeftRotation(struct Node *x){
    struct Node *y,*z;
    y=x->right;
    z=y->left;
    y->left=x;
    x->right=z;
    return y;
}
struct Node* RightRotation(struct Node *x){
    struct Node *y,*z;
    y=x->left;
    z=y->right;
    y->right=x;
    x->left=z;
    return y;
}
struct Node* LL(struct Node *x){
    struct Node *y;
    y=RightRotation(x);
    return y;
}
struct Node* RR(struct Node *x){
    struct Node *y;
    y=LeftRotation(x);
    return y;
}
struct Node* LR(struct Node *x){
    struct Node *y,*z,*T;
    y=x->left;
    z=LeftRotation(y);
    x->left=z;
    T=RightRotation(x);
    return T;
}
struct Node* RL(struct Node *x){
    struct Node *y,*z,*T;
    y=x->right;
    z=RightRotation(y);
    x->right=z;
    T=LeftRotation(x);
    return T;
}
int Height(struct Node *T){
    int hl,hr;
    if(T==NULL) return 0;
    if(T->left==NULL) hl=0;
    else hl=1+T->left->H;
    if(T->right==NULL) hr=0;
    else hr=1+T->right->H;
    return Max(hl,hr);
}
int BalanceFactor(struct Node *T){
    int hl,hr;
    if(T==NULL) return 0;
    if(T->left==NULL) hl=0;
    else hl=1+T->left->H;
    if(T->right==NULL) hr=0;
    else hr=1+T->right->H;
    return hl-hr;
}
struct Node* AVLInsert(struct Node *T, int x){
    if(T==NULL) T=MakeNode(x);
    else{
        if(x<T->data){
            T->left=AVLInsert(T->left,x);
            if(BalanceFactor(T)==2){
                if(x<(T->left->data)) T=LL(T);
                else T=LR(T);
            }
        }
        else{
            T->right=AVLInsert(T->right,x);
            if(BalanceFactor(T)==-2){
                if(x>(T->right->data)) T=RR(T);
                else T=RL(T);
            }
        }
    }
    T->H=Height(T);
    return T;
}
int main(){
    struct Node* root=NULL;
    root=AVLInsert(root,10);
    root=AVLInsert(root,20);
    root=AVLInsert(root,30);
    root=AVLInsert(root,40);
    root=AVLInsert(root,50);
    root=AVLInsert(root,25);

    inorderTraversal(root);
    printf("\n");
    PreorderTraversal(root);
}

