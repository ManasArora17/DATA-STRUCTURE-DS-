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
struct Node* BuildTree(int *Inorder,int *Preorder,int n,int m){
    static int i=0;
    if(n>m) return NULL;
    int currNode=Preorder[i++];
    struct Node* root = MakeNode(currNode);
    if(n==m) return root;
    int j=Search(Inorder,n,m,root->data);
    root->left=BuildTree(Inorder,Preorder,n,j-1);
    root->right=BuildTree(Inorder,Preorder,j+1,m);
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

int main(){
    int Inorder[10]={10,15,20,23,25,30,35,39,42};
    int Preorder[10]={30,20,10,15,25,23,39,35,42};
    struct Node* root = BuildTree(Inorder,Preorder,0,9);
    printf("PostOrder Traversal: ");
    postorderTraversal(root);
    printf("\nPreOrder Traversal: ");
    PreorderTraversal(root);
    printf("\nInOrder Traversal: ");
    inorderTraversal(root);

}
