#include<stdio.h>
int sort(int arr[],int a){
    int b;
    for(int i=0;i<a;i++){
        for(int j=0;j<a-1;j++){
            if(arr[j]>arr[j+1]){
                b=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=b;
            }
        }
    }
}
int unionArray(int *A,int n,int *B,int m){
    int i=0;
    int j=0;
    int k=0;
    int *arr3;
    arr3=malloc((m+n)*sizeof(int));
    while(i<n && j<m){
        if(A[i]<B[j]){
            arr3[k]=A[i];
            k=k+1;
            i=i+1;
        }
        else{
            if(A[i]>B[j]){
                arr3[k]=B[j];
                k=k+1;
                j=j+1;
            }
            else{
                i++;
                j++;
            }
        }
    }

    while(i<n){
        arr3[k]=A[i];
        i=i+1;
        k=k+1;
    }
    while(j<m){
        arr3[k]=B[j];
        j=j+1;
        k=k+1;
    }
    printf("\n");
    for(int p=0;p<k;p++){
        printf("%d ",arr3[p]);
    }
}
int main(){
    int n,m,*arr1,*arr2;
    printf("Enter the number of element of Array-1: ");
    scanf("%d",&n);
    arr1=malloc((n+1)*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the number of element of Array-2: ");
    scanf("%d",&m);
    arr2=malloc((m+1)*sizeof(int));
    printf("Enter the elements: ");
    for(int j=0;j<m;j++){
        scanf("%d",&arr2[j]);
    }
    sort(arr1,n);
    sort(arr2,m);
    unionArray(arr1,n,arr2,m);
}

