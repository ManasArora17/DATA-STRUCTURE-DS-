#include<stdio.h>
#include<stdlib.h>
struct Node{
    int x;
    int y;
    int data;
    struct Node *Next;
};
struct Node* MakeNode(int n,int m,int x){
    struct Node *p;
    p=(struct Node*)malloc(sizeof(struct Node));
    p->x=n;
    p->y=m;
    p->data=x;
    p->Next=NULL;
    return p;
}
void InsBeg(struct Node **START,int n,int m,int x){
    struct Node *p;
    p=MakeNode(n,m,x);
    p->Next=(*START);
    (*START)=p;
}
void Traverse(struct Node **START){
    struct Node *p;
    p=*START;
    while(p!=NULL){
        printf("(%d,%d)->%d   ",p->x,p->y,p->data);
        p=p->Next;
    }
}
void InsEnd(struct Node **START,int n,int m,int x){
    struct Node *q,*p;
    q=(*START);
    if(q==NULL){
        InsBeg(START,n,m,x);

    }
    else{
        while(q->Next!=NULL){
            q=q->Next;
        }
        p=MakeNode(n,m,x);
        q->Next=p;

    }
}
int main(){
    int r,c;
    int **arr1;
    printf("Matrix-1:\n");
    printf("Enter the numbers of rows: ");
    scanf("%d",&r);
    printf("Enter the number of columns: ");
    scanf("%d",&c);
    arr1=malloc(r*sizeof(int*));
    for(int i=0;i<c;i++){
        arr1[i]=malloc(c*sizeof(int));
    }
    printf("Enter the elements: \n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    struct Node *START=NULL;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr1[i][j]!=0){
                InsEnd(&START,i,j,arr1[i][j]);

            }
        }
    }
    printf("Linked List Representation:\n");
    Traverse(&START);


}

