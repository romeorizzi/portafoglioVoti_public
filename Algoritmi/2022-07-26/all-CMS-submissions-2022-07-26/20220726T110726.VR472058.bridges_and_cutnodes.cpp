/**
* user:  VR472058
* fname: ALESSANDRO
* lname: FURIA
* task:  esamebridges_and_cutnodes
* score: 31.0
* date:  2022-07-26 11:07:26.058317
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#define N 10000
using namespace std;

int graph[N][N] = {0};
int t, n, m;

int solution_task_1[N];
int solution_task_2[N];

int appo[N][N];

int appo_vertex[N]={0};

int edges[N][2];

int solution[N] = {0};

bool isConnected_without_edge(int v1, int v2){
    for(int i=0; i<n; i++){
        if(appo[v1][i] == 1){
            for(int k=0; k<n; k++){
                if(appo[v2][k] == 1){
                    for(int j=0; j<n; j++){
                        int tm = appo[i][j] + appo[k][j];
                        if(tm == 2)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void restoreAppo(){
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            appo[a][b] = graph[a][b];
        }
    }
}

void subtask_1(){
    
    for(int e=0; e<m; e++){
        appo[edges[e][0]][edges[e][1]] = 0;
        appo[edges[e][1]][edges[e][0]] = 0;
        if(!isConnected_without_edge(edges[e][0], edges[e][1]))
          solution[e] = 1;
        restoreAppo();
    }

    for(int i=0; i<m; i++){
        cout << solution[i] << "\n";
    }
}


void visit(int v){
    appo_vertex[v] = 1;
    for(int i=0; i<n-1; i++){
        if(appo[v][i]==1 && appo_vertex[i] != 1){
            visit(i);
        }
    }
}

void subtask_2(){
    for(int v=0; v<n; v++){
        

        for(int r=0; r<n; r++){
            for(int c=v; c<n; c++){
                int colonna=c+1;
                appo[r][c] = appo[r][colonna];
            }   
        }

        
        for(int r=v; r<n; r++){
            for(int c=0; c<n; c++){
                int riga=r+1;
                appo[r][c] = appo[riga][c];
            }   
        }

        visit(0);
        
        int sum=0;
        for(int i=0; i<n-1; i++){
            sum += appo_vertex[i];
        }

        if(sum != n-1){
            solution[v] = 1;
        }

        for(int i=0; i<n; i++){
            appo_vertex[i] = 0;
        }

        restoreAppo();
    }

    for(int i=0; i<n; i++){
        cout << solution[i] << "\n";
    }
}

int main(void){
    cin >> t;
    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1;
        cin >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
        appo[v1][v2] = 1;
        appo[v2][v1] = 1;
        edges[i][0] = v1;
        edges[i][1] = v2;
    }


    if(t==1) subtask_1();
    if(t==2) subtask_2();
    
    return 0;
}