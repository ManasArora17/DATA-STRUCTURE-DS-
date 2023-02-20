#include<iostream>
#include<vector>
using namespace std;
int main(){
    int V,E;
    cout<<"How many vertices are there in the Graph?: ";
    cin>>V;
    cout<<"How many edges are there in the the Graph?: ";
    cin>>E;
    vector<int>adjlist[V];
    int inDeg[V+1]={0};
    int outDeg[V+1]={0};
    for(int i=0;i<E;i++){
        int a,b;
        cout<<"Enter the end points of edge"<<i+1<<": ";
        cin>>a>>b;
        adjlist[a].push_back(b);
        outDeg[a]++;
        inDeg[b]++;
    }
    cout<<"InDegree:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": "<<inDeg[i]<<endl;
    }cout<<endl;
    cout<<"OutDegree:"<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<": "<<outDeg[i]<<endl;
    }cout<<endl;
    return 0;
}

