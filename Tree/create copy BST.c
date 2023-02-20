#include<stdio.h>
#include<stdlib.h>
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
void inorderTraversal(struct Node *T){
    if(T!=NULL){
        inorderTraversal(T->left);
        printf("%d ",T->data);
        inorderTraversal(T->right);
    }
}
struct Node* CopyBST(struct Node *T){
    if(T==NULL) return NULL;
    else{
        struct Node *p = MakeNode(T->data);
        p->left=CopyBST(T->left);
        p->right=CopyBST(T->right);
        return p;
    }
}
int main(){
    struct Node *root=NULL;
    int x;
    printf("Enter the Data of root Node: ");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(&root);
    struct Node *New_root=CopyBST(root);
    inorderTraversal(root);
    printf("\n");
    inorderTraversal(New_root);
    return 0;
}
