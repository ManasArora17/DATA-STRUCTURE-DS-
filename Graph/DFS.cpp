#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int DFS_visit(int i,vector<int>&visited,vector<int>adjlist[],int ele){
    cout<<i<<" ";
    visited[i]=1;
    for(int j=0;j<adjlist[i].size();j++){
        if(visited[adjlist[i][j]]==0){
            ele++;
            ele=DFS_visit(adjlist[i][j],visited,adjlist,ele);
        }
    }
    return ele;
}
void DFS(vector<int>adjlist[],int V){
    int c=0;
    vector<int>visited(V,0);
    vector<int>elements;
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            c=c+1;
            int ele=1;
            ele=DFS_visit(i,visited,adjlist,ele);
            elements.push_back(ele);
        }
    }
    cout<<endl<<"No. of connected components: "<<c<<endl;
    for(int i=0;i<c;i++){
        cout<<i+1<<":"<<elements[i]<<endl;
    }
}
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?: ";
    cin>>V;
    cout<<"How many edges are there in the the Graph?: ";
    cin>>E;
    vector<int>adjlist[V];
    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjlist[a].push_back(b);
    }
    DFS(adjlist,V);
    return 0;
}


