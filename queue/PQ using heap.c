#include<stdio.h>
int n;
void pqinsert(int a[], int data){
    a[n]= data;
    int x=n;
    int y=(n-1)/2;
    while(x>0 && a[x]<a[y]){
        int temp=a[x];
        a[x]=a[y];
        a[y]= temp;
        x=y;
        y=(x-1)/2;
    }
    n=n+1;
}
void minheapify(int a[], int i){
    while(2*i+1<=n-1){
        int l= 2*i+1;
        int r= 2*i+1;
        int min=l;
        if(r<=n-1){
            if(a[r]<a[l]){
                min=r;
            }
        }
        if(a[min]<a[i]){
            int temp=a[min];
            a[min]= a[i];
            a[i]= temp;
        }
        else{
            break;
        }
        i=min;
    }
}

int pqdelete(int a[]){
    int x=a[0];
    a[0]= a[n-1];
    n=n-1;
    minheapify(a,0);
    return x;
}
int main(){
    int a[10];
    pqinsert(a,10);
    pqinsert(a,15);
    pqinsert(a,20);
    pqinsert(a,25);
    printf("%d ",pqdelete(a));
    printf("%d ",pqdelete(a));
}
