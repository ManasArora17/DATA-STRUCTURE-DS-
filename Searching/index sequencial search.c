#include<stdio.h>
int indexSearch(int *arr,int n,int k){
    int *index,a=n/4;
    index = malloc((n/2)*sizeof(int));
    for(int i=0;i<=a;i++){
        index[i] = i*4;
    }
    if((n-1)%4!=0){
        a++;
        index[a] = n-1;
    }
    printf("Index array:- ");
    for(int i=0;i<=a;i++){
        printf("%d ",index[i]);
    }
    printf("\n");
    int high;
    for(int i=0;i<=a;i++){
        if(k==arr[index[i]]){
            return index[i];
        }
        else if(k<arr[index[i]]){
            high=i;
            break;
        }
    }
    for(int i=index[high-1]+1;i<index[high];i++){
        if(k==arr[i]){
            return i;
        }
    }
}
int main(){
    int *arr,n,k;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&k);
    int result = indexSearch(arr,n,k);
    printf("Index - %d",result);
    return 0;
}
