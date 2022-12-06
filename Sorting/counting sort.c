#include<stdio.h>
int main(){
    int *arr1,n,*arr2;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    arr1=malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr1[i]);
    }
    int max=arr1[0];
    for(int i=0;i<n;i++){
        if(max<arr1[i]){
            max=arr1[i];
        }
    }
    arr2=malloc((max+1)*sizeof(int));
    for(int i=0;i<max+1;i++){
        arr2[i]=0;
    }
    for(int i=0;i<n;i++){
        arr2[arr1[i]]++;
    }
    for(int i=0;i<=max;i++){
        for(int j=0;j<arr2[i];j++){
            printf("%d ",i);
        }
    }
}
