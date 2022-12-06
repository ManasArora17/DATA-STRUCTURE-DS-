#include<stdio.h>
int main(){
    int m,n,p,q;
    int **arr1,**arr2,**arr3;
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
    printf("Matrix-2:\n");
    printf("Enter the numbers of rows: ");
    scanf("%d",&p);
    printf("Enter the number of columns: ");
    scanf("%d",&q);
    arr2=malloc(p*sizeof(int*));
    for(int i=0;i<p;i++){
        arr2[i]=malloc(q*sizeof(int));
    }
    printf("Enter the elements: \n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    arr3=malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        arr3[i]=malloc(q*sizeof(int));
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            arr3[i][j]=arr1[i][j]-arr2[i][j];
        }
    }
    printf("________________________\n");
    printf("Resultant Matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }
}
