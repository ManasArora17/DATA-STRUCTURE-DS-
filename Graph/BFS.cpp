#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?";
    cin>>V;
    cout<<"How many edges are there in the the Graph?";
    cin>>E;
    vector<int>adjlist[V];
    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<int>visited(V);
    queue<int>Q;
    Q.push(0);
    visited[0]=1;
    cout<<"BSF: ";
    while(!(Q.empty())){
        int x=Q.front();
        Q.pop();
        for(int j=0;j<adjlist[x].size();j++){
            if(visited[adjlist[x][j]]==0){
                Q.push(adjlist[x][j]);
                visited[adjlist[x][j]]=1;
            }
        }
        cout<<x<<" ";
    }
    return 0;
}

