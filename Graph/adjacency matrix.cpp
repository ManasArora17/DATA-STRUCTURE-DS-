#include<iostream>
#include<vector>
using namespace std;
int adjmatrix[100][100];
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?";
    cin>>V;
    cout<<"How many edges are there in the the Graph?";
    cin>>E;

    for(int i=0;i<V;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjmatrix[a][b]=1;
        adjmatrix[b][a]=1;
    }
    cout<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": ";
        for(int j=0;j<V;j++){
            cout<<adjmatrix[i][j]<<",";
        }cout<<endl;
    }
}
