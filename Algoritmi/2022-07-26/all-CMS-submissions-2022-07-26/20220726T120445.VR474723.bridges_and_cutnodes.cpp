/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esamebridges_and_cutnodes
* score: 15.0
* date:  2022-07-26 12:04:45.516342
*/
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

int t,n,m;
void bridges(int **,queue<int>);
bool connected(int**);
bool reachable(int,int,set<int>,int **);
void cutnodes(int **);
int **remove_node(int,int**);
const int MAX=10000;
int mem[MAX][MAX];
set <int> skip;


int main(){
    int result;
    cin >> t;
    cin >> n;
    cin >> m;
    queue<int> nodes;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
        edges[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            edges[i][j]=0;
            for(int i=0;i<m;i++){
                int a,b;
                cin >> a;
                cin >> b;
                nodes.push(a);
                nodes.push(b);
                edges[a][b]=1;
                edges[b][a]=1;
            }
    queue <int> tmp (nodes);
    if(t==1)
        bridges(edges,tmp);
    if(t==2)
        cutnodes(edges);
}

void bridges(int **edges,queue <int> nodes){
    int first,second;
    while(!nodes.empty()){
        first=nodes.front();
        nodes.pop();
        second=nodes.front();
        nodes.pop();
        edges[first][second]=0;
        edges[second][first]=0;
        if(connected(edges))
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
        edges[first][second]=1;
        edges[second][first]=1;
        
    }
}

bool connected(int **edges){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            if(j==i);
            else{
                set<int> seen;
                if(skip.count(i)==1 || skip.count(j)==1);
                else
                    if(!reachable(i,j,seen,edges)){
                        return false;
                    }
            }
    }
    return true;
}   

bool reachable(int first,int second,set <int> seen,int **edges){
    seen.insert(first);
    bool reach=false;
    for(set<int>::iterator it=skip.begin();it!=skip.end();++it)
        seen.insert(*it);
    if(edges[first][second]==1)
        return true;
    else{
        for(int i=0;i<n;i++){
            if(edges[first][i]==1 && seen.count(i)==0){
                set<int> tmp (seen);
                reach = reach || reachable(i,second,tmp,edges);
            }
        }
        return reach;
    }
}

void cutnodes(int **edges){
     int **mod_edges;
    for(int i=0;i<n;i++){
        skip.clear();
        mod_edges=remove_node(i,edges);
        if(connected(mod_edges))
            cout << "0" << "\n";
        else
            cout << "1" << "\n";
    }
}

int  **remove_node(int node,int **edges){
    skip.insert(node);
    int **result=new int*[n];
    for(int i=0;i<n;i++)
        result[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            result[i][j]=edges[i][j];
    for(int i=0;i<n;i++)
        if(edges[node][i]==1){
            result[i][node]=0;
            result[node][i]=0;
        }
    return result;
}