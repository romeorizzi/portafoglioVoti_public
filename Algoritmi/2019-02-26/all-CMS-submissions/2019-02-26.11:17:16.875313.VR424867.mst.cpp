/**
* user:  VR424867
* fname: CONSOLARO
* lname: GIANPIETRO
* task:  mst
* score: 0.0
* date:  2019-02-26 11:17:16.875313
*/
int mst(int N, int M, int* A, int* B, int* P, int* C, int* D) {
	int V=N;
	int E=M;
    int root[10000];
    vector<pair<int,pair<int,int> > > edges;
	for(int i=0;i<E;i++){
        edges.push_back(make_pair(P[i],make_pair(A[i],B[i])));
    }
    sort(edges.begin(),edges.end());

    int total_dist=0;
    for(int i=0;i<N;i++){
        root[i]=i;
    }
    for(int i=0;i<(int)edges.size();i++){
        int u=find_root(edges[i].second.first);
        int v=find_root(edges[i].second.second);
        if(u!=v){
            root[u]=root[v];
            mst.push_back(edges[i].second);
            C[i]=edges.second.first;
            D[i]=edges.second.second;
            total_dist+=edges[i].first;
        }
    }
    return total_dist;
}

