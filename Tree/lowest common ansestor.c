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
int Max(int a,int b,int c){
    if(a>=b && a>=c) return a;
    else if(b>=a && b>=c) return b;
    else return c;
}
int Max_(int a,int b){
    if(a>b) return a;
    else return b;
}
int Height(struct Node *T){
    if(T==NULL) return 1;
    else if(T->left==NULL && T->right==NULL) return 0;
    else return Max_(Height(T->left),Height(T->right))+1;
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
struct Node* LCA(struct Node *T,int x,int y){
    struct Node *L,*R;
    if(T==NULL) return NULL;
    else{
        if(T->data==x || T->data==y) return T;
        else{
            L=LCA(T->left,x,y);
            R=LCA(T->right,x,y);
            if(L==NULL) return R;
            else if(R==NULL) return L;
            else return T;
        }
    }
}
int main(){
    struct Node *root;
    root=NULL;
    int x;
    printf("Enter the Data of root Node: ");
    scanf("%d",&x);
    root=MakeNode(x);
    CreateTree(&root);
    struct Node *p=LCA(root,12,10);
    printf("Lowest common ancestor of BST: %d",p->data);
}

