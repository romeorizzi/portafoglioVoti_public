/**
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  mst
* score: 0.0
* date:  2019-02-26 11:00:33.287607
*/
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 10000;
vector<pair<int,pair<int,int> > > edges;
int root[MAXN];
vector<pair<int,int> > mst;

int find_root(int x){
    if(root[x] != x){
        root[x]= find_root(root[x]);
    }

    return root[x];
}

int kruskal(int nodes){
    mst.clear();
    sort(edges.begin(),edges.end());
    int total_dist=0;
    for(int i=0;i<nodes;i++){
        root[i]=i;
    }
    for(int i=0;i<(int)edges.size();i++){
        int u=find_root(edges[i].second.first);
        int v=find_root(edges[i].second.second);
        if(u!=v){
            root[u]=root[v];
            mst.push_back(edges[i].second);
            total_dist+=edges[i].first;
        }
    }
    return total_dist;
}

int main(){
    int V, E;
    cin>>V;
    cin>>E;
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        edges.push_back(make_pair(w,make_pair(u,v)));
    }
    int weight=kruskal(V);
    cout<<weight;

    for(int i=0;i<mst.size();i++){

        cout<<mst[i].first<<" "<<mst[i].second;
        cout<<endl;
    }
}