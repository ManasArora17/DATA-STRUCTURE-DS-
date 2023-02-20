#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int V,E;
    queue<int>q;
    cout<<"How many vertices are there in the Graph?: ";
    cin>>V;
    cout<<"How many edges are there in the the Graph?: ";
    cin>>E;
    vector<int>adjlist[V];
    int inDeg[V]={0};
    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        inDeg[b]++;
    }
    for(int i=0;i<V;i++){
        if(inDeg[i]==0) q.push(i);
    }

    while(!(q.empty())){
        int x=q.front();
        q.pop();
        for(int i=0;i<adjlist[x].size();i++){
            int a=adjlist[x][i];
            inDeg[a]--;
            if(inDeg[a]==0) q.push(a);
        }
        cout<<x<<" ";
    }
}

