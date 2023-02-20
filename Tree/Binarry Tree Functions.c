#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define TRUE 1
#define FALSE 0
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node* MakeNode(int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
int Max(int a,int b){
    if(a>b) return a;
    else return b;
}
int CountNode(struct Node *T){
    if(T==NULL) return 0;
    else return 1+CountNode(T->left)+CountNode(T->right);
}
int CountLeaf(struct Node *T){
    if(T==NULL) return 0;
    else if(T->left==NULL && T->right==NULL) return 1;
    else return CountLeaf(T->left)+CountLeaf(T->right);
}
int CountN2(struct Node *T){
    if(T==NULL) return 0;
    else if(T->left==NULL && T->right==NULL) return 0;
    else if(T->left!=NULL && T->right!=NULL)return 1+CountN2(T->left)+CountN2(T->right);
    else return CountN2(T->left)+CountN2(T->right);
}
int CountN1(struct Node *T){
    if(T==NULL) return 0;
    else if(T->left==NULL && T->right==NULL) return 0;
    else if(T->left!=NULL && T->right!=NULL)return CountN1(T->left)+CountN1(T->right);
    else return 1+CountN1(T->left)+CountN1(T->right);
}
int Height(struct Node *T){
    if(T==NULL) return 0;
    else if(T->left==NULL && T->right==NULL) return 0;
    else return Max(Height(T->left),Height(T->right))+1;
}
int sumOfNodes(struct Node *T){
    if(T==NULL) return 0;
    else return T->data + sumOfNodes(T->left)+sumOfNodes(T->right);
}
void CreateTree(struct Node **T){
    int x,choice;
    struct Node *p;
    printf("Whether the left of %d exists?(1/0): ",(*T)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the data of left of %d : ",(*T)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*T)->left=p;
        CreateTree(&p);
    }
    printf("Whether the Right of %d exists?(1/0): ",(*T)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the data of Right of %d : ",(*T)->data);
        scanf("%d",&x);
        p=MakeNode(x);
        (*T)->right=p;
        CreateTree(&p);
    }
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
int StrictlyBT(struct Node *T){
    if(CountN1(T)==0) return 1;
    else return 0;
}
int IsComplete(struct Node *root,int i,int numberNodes){
  if (root == NULL)
    return TRUE;
  if (i>=numberNodes)
    return FALSE;
  return (IsComplete(root->left,2*i+1,numberNodes) && IsComplete(root->right,2*i+2,numberNodes));
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
    int x;
    printf("Enter the Data of root Node: ");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(&root);
    inorderTraversal(root);
    printf("\n");
    Mirror(&root);
    inorderTraversal(root);
    return 0;
}
