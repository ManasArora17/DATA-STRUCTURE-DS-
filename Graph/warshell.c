#include<stdio.h>
#include<climits>
int WeightMatrix[10][10];
int D[10][10];
int main(){
    int V,E,Weight;
    printf("How many vertices are there in the Graph?: ");
    scanf("%d",&V);
    printf("How many edges are there in the the Graph?: ");
    scanf("%d",&E);

    for(int i=1;i<=E;i++){
        int a,b;
        printf("Enter the end points of edge %d and weight: ",i+1);
        scanf("%d %d %d",&a,&b,&Weight);
        WeightMatrix[a][b]=Weight;
    }
    printf("\nWeight Matrix\n");
    for(int i=1;i<=V;i++){
        printf("%d. ",i);
        for(int j=1;j<=V;j++){
            printf("%d ",WeightMatrix[i][j]);
        }printf("\n");
    }
    for(int i=1;i<=V;i++){
        for(int j=1;i<=V,j++){
            if(WeightMatrix[i][j]==0){
                if(i!=j) D[i][j]=(INT_MAX)/2                                                                                                                ;
                else D[i][j]=W[i][j];
            }
        }
    }
}

