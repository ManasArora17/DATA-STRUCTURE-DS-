#include<iostream>
#include<vector>
using namespace std;
int Imatrix[100][100];
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?";
    cin>>V;
    cout<<"How many edges are there in the the Graph?";
    cin>>E;

    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        Imatrix[a][i]=1;
        Imatrix[b][i]=1;
    }
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": ";
        for(int j=0;j<E;j++){
            cout<<Imatrix[i][j]<<",";
        }cout<<endl;
    }
}

