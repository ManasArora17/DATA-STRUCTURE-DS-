#include<stdio.h>
#include<stdlib.h>
int matrix[10];
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
    int value1,value2;
    printf("Enter the value of i: ");
    scanf("%d",&value1);
    printf("Enter the value of j: ");
    scanf("%d",&value2);
    if (value1==value2){
        printf("location: %d ",3*value1);
    }
    else if(value1>value2){
        printf("location: %d",(3*value1)-1);
    }
    else{
        printf("location: %d",(3*value1)+1);
    }

}
