#include<stdio.h>
int jumpSearch(){

}
int main(){
    int *arr,n,s,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the search key: ");
    scanf("%d",&k);

    printf("Enter the steps: ");
    scanf("%d",&s);
    int j=0;
    for(int i=0;i<n;i=i+s){
        if(k<arr[i]){
            j=i;
            break;
        }
        else if(k==arr[i]){
            return j;
        }
    }
    int t=0;
    for(int p=j-s;p<j;p++){
        if(arr[p]==k){
            printf("Index- %d",p);
            t=1;
        }
    }
    if(t==0){
        printf("Element is not present.");
    }
}
