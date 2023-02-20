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
int IdenticalTree(struct Node *T1,struct Node *T2){
    if(T1==NULL && T2==NULL) return 1;
    else if(T1!=NULL && T2!=NULL){
        return(T1->data==T2->data && IdenticalTree(T1->right,T2->right) && IdenticalTree(T1->left,T2->left));
    }
    else return 0;
}
int main(){
    struct Node *root1=NULL;
    struct Node *root2=NULL;
    int x1,x2;
    printf("Enter the Data of root1 Node: ");
    scanf("%d",&x1);
    root1=MakeNode(x1);
    CreateTree(&root1);
    printf("\n");
    printf("Enter the Data of root2 Node: ");
    scanf("%d",&x2);
    root2=MakeNode(x2);
    CreateTree(&root2);
    printf("\n");
    int n=IdenticalTree(root1,root2);
    if(n==1) printf("YES");
    else printf("NO");
    return 0;
}
