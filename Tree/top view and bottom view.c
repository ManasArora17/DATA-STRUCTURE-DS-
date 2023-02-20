#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 20
#define TRUE 1
#define FALSE 0
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int hd;
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
    int choice;
    int x;
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

struct QueueBT{
    struct Node *item[QUEUESIZE];
    int front;
    int rear;
};
void initailise(struct QueueBT *q){
    q->front=0;
    q->rear=-1;
}
int isEmpty(struct QueueBT *q){
    if(q->rear-q->front+1==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
void enqueue(struct QueueBT *q,struct Node *x){
    if(q->rear==QUEUESIZE-1){
        printf("Queue overflow");
        exit(1);
    }
    q->rear=q->rear+1;
    q->item[q->rear]=x;
}
struct Node* dequeue(struct QueueBT *q){
    if (isEmpty(q)){
        printf("Queue underflow");
        exit(1);
    }
    struct Node *x = q->item[q->front];
    q->front=q->front+1;
    return x;
}
int HT[10][10];
int MaxHD(struct Node **T){
    int L=0,R=0;
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
void InsertHT(struct Node *x,int R){
    int r=(x->hd)+R;
    int c=0;
    while(HT[r][c]!=0) c++;
    HT[r][c]=x->data;
}
int main(){
    struct QueueBT q;
    initailise(&q);
    struct Node *root=NULL,*x,*Hroot;
    int y;
    int R;
    printf("Enter the Data of root Node: ");
    scanf("%d",&y);
    root=MakeNode(y);
    root->hd=0;
    Hroot=root;
    CreateTree(&root);
    enqueue(&q,root);
    R=MaxHD(&root);
    InsertHT(Hroot,R);
    printf("Level Order Traversal: ");
    while(!isEmpty(&q)){
        x=dequeue(&q);
        if(x->left!=NULL){
            (x->left)->hd = (x->hd)-1;
            enqueue(&q,x->left);
            InsertHT(x->left,R);
        }
        if(x->right!=NULL){
            (x->right)->hd=(x->hd)+1;
            enqueue(&q,x->right);
            InsertHT(x->right,R);
        }
        printf("%d ",x->data);

    }
    printf("\n");
    printf("\nVERTICAl View Traversal: ");
    for(int i=0;i<=(2*R);i++){
        int j=0;
        while(HT[i][j]!=0){
            printf("%d ",HT[i][j]);
            j++;
        }
    }
    printf("\n");
    printf("\nTOP View Traversal: ");
    for(int i=0;i<=(2*R);i++){
        printf("%d ",HT[i][0]);
    }
    printf("\n");
    printf("\nBOTTOM View Traversal: ");
    for(int i=0;i<=2*R;i++){
        int j=0;
        while(HT[i][j]!=0) j++;
        printf("%d ",HT[i][j-1]);
    }
    printf("\n");
    printf("\nHash Table\n");
    for(int i=0;i<=(2*R);i++){
        for(int j=0;j<=(2*R);j++) printf("%d ",HT[i][j]);
        printf("\n");
    }
}
