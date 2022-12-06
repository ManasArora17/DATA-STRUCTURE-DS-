#include<stdio.h>
/*int b;
    for(int i=0;i<a;i++){
        for(int j=0;j<a-1;j++){
            if(arr[j]>arr[j+1]){
                b=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=b;
            }
        }
    }int sort(int arr[],int a){

*/
int intersection(int *A,int n,int *B,int m){
    int i=0;
    int j=0;
    int k=0;
    int *arr3;
    arr3=malloc((m+n)*sizeof(int));
    while(i<n && j<m){
        if(A[i]<B[j]){
            i=i+1;
        }
        else{
            if(A[i]>B[j]){
                j=j+1;
            }
            else{
                arr3[k]=A[i];
                k++;
                i++;
                j++;
            }

        }
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

    intersection(arr1,n,arr2,m);
}
