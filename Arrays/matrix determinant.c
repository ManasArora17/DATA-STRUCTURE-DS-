#include<stdio.h>
int result(int arr[]){
    int a=(arr[0]*arr[3])-(arr[1]*arr[2]);
    return a;
}
int main(){
    int m,n;
    int **arr1;
    printf("Matrix-1:\n");
    printf("Enter the numbers of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    arr1=malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        arr1[i]=malloc(n*sizeof(int));
    }
    printf("Enter the elements: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<m;i++){
        int arr[4]={0};
        int a=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j!=0 && k!=i){
                    arr[a]=arr1[j][k];
                    a=a+1;
                }
            }
        }

        sum=sum+(result(arr)*(pow(-1,i))*arr1[0][i]);
    }
    printf("Determinant = %d",sum);
}
