#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 20
#define TRUE 1
#define FALSE 0
struct Node{
    char data;
    struct Node *left;
    struct Node *right;
    int level;
};
struct Node* MakeNode(char x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void CreateTree(struct Node **T){
    int choice;
    char x,extra1,extra2;
    struct Node *p;
    printf("Whether the left of %c exists?(1/0): ",(*T)->data);
    scanf("%d",&choice);
    scanf("%c",&extra1);
    if(choice==1){
        printf("Enter the data of left of %c : ",(*T)->data);
        scanf("%c",&x);
        p=MakeNode(x);
        (*T)->left=p;
        CreateTree(&p);
    }
    printf("Whether the Right of %c exists?(1/0): ",(*T)->data);
    scanf("%d",&choice);
    scanf("%c",&extra2);
    if(choice==1){
        printf("Enter the data of Right of %c : ",(*T)->data);
        scanf("%c",&x);
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
void InsertHT(struct Node *x){
    int r=x->level;
    int c=0;
    while(HT[r][c]!=0) c++;
    HT[r][c]=x->data;
}
int main(){
    struct QueueBT q;
    initailise(&q);
    struct Node *root=NULL,*x;
    char y;
    int R=0;
    printf("Enter the Data of root Node: ");
    scanf("%c",&y);
    root=MakeNode(y);
    root->level=0;
    CreateTree(&root);
    enqueue(&q,root);
    InsertHT(root);
    printf("Level Order Traversal: ");
    while(!isEmpty(&q)){
        x=dequeue(&q);
        if(x->left!=NULL){
            x->left->level=x->level+1;
            if(R<x->left->level) R=x->left->level;
            enqueue(&q,x->left);
            InsertHT(x->left);
        }
        if(x->right!=NULL){
            x->right->level=x->level+1;
            if(R<x->right->level) R=x->right->level;
            enqueue(&q,x->right);
            InsertHT(x->right);
        }
        printf("%c",x->data);
    }
    printf("\nLEFT View Traversal: ");
    for(int i=0;i<=R;i++){
        printf("%c",HT[i][0]);
    }
    printf("\nRIGHT View Traversal: ");
    for(int i=0;i<=R;i++){
        int j=0;
        while(HT[i][j]!=0) j++;
        printf("%c",HT[i][j-1]);
    }
}
