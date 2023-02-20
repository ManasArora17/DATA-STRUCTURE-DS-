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
void maxHeapify(int *arr,int i,int n){
    while(2*i<=n){
        int l=2*i;
        int r=2*i+1;
        int m=l;
        if(r<=n){
            if(arr[r]>arr[l]) m=r;
        }
        if(arr[m]>arr[i]){
            int t=arr[m];
            arr[m]=arr[i];
            arr[i]=t;
        }
        else{
            break;
        }
        i=m;
    }
}
void buidMaxHeap(int *arr,int n){
    for(int i=(n/2);i>=1;i--){
        maxHeapify(arr,i,n);
    }
}
void heapSort(int *arr,int n){
    buidMaxHeap(arr,n);
    for(int i=n;i>1;i--){
        int t=arr[1];
        arr[1]=arr[i];
        arr[i]=t;
        maxHeapify(arr,1,i-1);
    }

}
int main(){
    int arr[11]={-1,5,30,90,20,10,100,60,40,50};
    heapSort(arr,10);
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}
