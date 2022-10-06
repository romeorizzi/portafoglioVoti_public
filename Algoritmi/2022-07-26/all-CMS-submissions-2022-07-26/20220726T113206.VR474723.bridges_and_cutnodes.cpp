/**
* user:  VR474723
* fname: MARCELLO
* lname: DE VINCENZI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 11:32:06.117520
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
const int MAX=10000;
int mem[MAX][MAX];


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
        cutnodes(edges,tmp);
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
    if(edges[first][second]==1)
        return true;
    else{
        for(int i=0;i<n;i++)
            if(edges[first][i]==1 && seen.count(i)==0){
                set<int> tmp (seen);
                if(mem[first][second]==0){
                    int t=reachable(i,second,tmp,edges)+1;
                    mem[first][second]=t;
                    mem[second][first]=t;
                }
                reach = reach || mem[first][second]-1;
            }
        return reach;
    }
}