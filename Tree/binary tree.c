#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void PreorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%c ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}

void inorderTraversal(struct Node *T){
    if(T!=NULL){
        PreorderTraversal(T->left);
        printf("%c ",T->data);
        PreorderTraversal(T->right);
    }
}
void postorderTraversal(struct Node *T){
    if(T!=NULL){
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
        printf("%c ",T->data);
    }
}
int MaxHD(struct Node **T){
    int L=1,R=1;
    while((*T)->left!=NULL){
        (*T)=(*T)->left;
        L++;
    }
    while((*T)->right!=NULL){
        (*T)=(*T)->left;
        R++;
    }
    if(R>=L) return R;
    else return L;
}
int main(){
    struct Node *root=NULL;
    root=MakeNode('A');
    root->left=MakeNode('B');
    root->right=MakeNode('C');
    root->right->left=MakeNode('E');
    root->right->right=MakeNode('F');
    root->right->left->left=MakeNode('G');
    root->right->left->left->right=MakeNode('H');
    int n=MaxHD(&root);
    printf("%d\n",n);
    PreorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    return 0;
}
