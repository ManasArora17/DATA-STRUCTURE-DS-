#include<iostream>
#include<vector>
using namespace std;
int adjmatrix[10][10];
int product[10][10];
int temp[10][10];
int M[10][10];
int T[10][10];
void matrixMultiple(int matrix1[][10],int matrix2[][10],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++){
                sum=sum+matrix1[i][k]*matrix2[k][j];
            }
            temp[i][j]=sum;
        }
    }
}
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?: ";
    cin>>V;
    cout<<"How many edges are there in the the Graph?: ";
    cin>>E;

    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjmatrix[a][b]=1;
    }
    printf("\nAdjacency Matrix\n");
    for(int i=0;i<V;i++){
        printf("%d. ",i);
        for(int j=0;j<V;j++){
            printf("%d ",adjmatrix[i][j]);
        }printf("\n");
    }
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            product[i][j]=adjmatrix[i][j];
            M[i][j]=adjmatrix[i][j];
        }
    }


    for(int i=0;i<V-1;i++){
        matrixMultiple(product,adjmatrix,V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                product[i][j]=temp[i][j];
            }
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                M[i][j]+=product[i][j];
            }
        }
    }

    printf("\n");
    printf("Product's sum of Adjacency Matrix V times: (V is vertices)\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",M[i][j]);
        }printf("\n");
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(M[i][j]!=0) T[i][j]=1;
            else T[i][j]=0;
        }
    }

    printf("\n");
    printf("Transitive closure matrix: \n");
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("%d ",T[i][j]);
        }printf("\n");
    }
}
