#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* MakeNode(int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int Search(int *Inorder,int n,int m,int data){
    for(int i=n;i<m;i++){
        if(Inorder[i]==data) return i;
    }
}
struct Node* BuildTree(int *Inorder,int *Postorder,int n,int m,int* size){
    if(n>m) return NULL;
    int currNode=Postorder[(*size)--];
    struct Node* root = MakeNode(currNode);
    if(n==m) return root;
    int j=Search(Inorder,n,m,root->data);
    root->right=BuildTree(Inorder,Postorder,j+1,m,size);
    root->left=BuildTree(Inorder,Postorder,n,j-1,size);
    return root;
}

void PreorderTraversal(struct Node *T){
    if(T!=NULL){
        printf("%d ",T->data);
        PreorderTraversal(T->left);
        PreorderTraversal(T->right);
    }
}
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
void postorderTraversal(struct Node *T){
    if(T!=NULL){
        postorderTraversal(T->left);
        postorderTraversal(T->right);
        printf("%d ",T->data);
    }
}
int Max(int a,int b){
    if(a>b) return a;
    else return b;
}
int Height(struct Node *T){
    if(T==NULL) return 0;
    else if(T->left==NULL && T->right==NULL) return 0;
    else return Max(Height(T->left),Height(T->right))+1;
}
int main(){
    int Inorder[10]={8,6,9,4,7,2,5,1,3};
    int Postorder[10]={8,9,6,7,4,5,2,3,1};
    int n=sizeof(Postorder)/sizeof(int);
    int m=n-1;
    struct Node* root = BuildTree(Inorder,Postorder,0,n-1,&m);
    printf("PostOrder Traversal: ");
    postorderTraversal(root);
    printf("\nPreOrder Traversal: ");
    PreorderTraversal(root);
    printf("\nInOrder Traversal: ");
    inorderTraversal(root);
    printf("\n%d",Height(root));
}
