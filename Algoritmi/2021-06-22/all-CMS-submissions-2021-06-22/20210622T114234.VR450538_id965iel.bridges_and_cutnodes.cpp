/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  bridges_and_cutnodes
* score: 30.0
* date:  2021-06-22 11:42:34.543011
*/
#include <iostream>
#include <vector>

using namespace std;

int round_iter = 0;

int * visited_nodes(int g, vector<vector<int>> archs, int visited[]) {

    if(archs.size() == 1){
        if(visited[archs[0][0]] == 1){
            visited[archs[0][1]] = 1;
            return visited;
        }
        else if(visited[archs[0][1]] == 1){
            visited[archs[0][0]] = 1;
            return visited;
        }
        
    }
    else{
        if(visited[archs[0][0]] == 1){
            round_iter = 0;
            visited[archs[0][1]] = 1;
            archs.erase(archs.begin());
            return visited_nodes(g,archs,visited);
        }
        else if(visited[archs[0][1]] == 1){
            round_iter = 0;
            visited[archs[0][0]] = 1;
            archs.erase(archs.begin());
            return visited_nodes(g,archs,visited);
        }
        else{
            if(round_iter >= archs.size() + 1){
                return visited;
            }
            vector<int> tail = archs[0];
            archs.erase(archs.begin());
            archs.push_back(tail);
            round_iter++;
            return visited_nodes(g,archs,visited);            
        }        
    }
}

bool is_connected(int g, vector<vector<int>> archs, int node_removed = -1) {
    int visited[g] = {0};
    visited[archs[0][0]] = 1;

    visited_nodes(g, archs, visited);

    for (int i = 0; i < g; i++) {
        if(visited[i] == 0 && i != node_removed){
            return false;
        }
    }    
    return true;
}


int main(void){

    int t,g,e;

    scanf("%d%d%d", &t, &g,&e);
    vector<vector<int>> archs;

    int n1,n2;

    for(int i = 0; i < e; i++) {
        scanf("%d%d", &n1, &n2);
        vector<int> arch;
        arch.push_back(n1);
        arch.push_back(n2);
        archs.push_back(arch);
    }

    if(t == 1) {

        for(int arch_index = 0; arch_index < e; arch_index++){
            vector<vector<int>> temp = archs;
            temp.erase(temp.begin() + arch_index);
            if(is_connected(g,temp)) {
                cout<<"0"<<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }
    }
    else if(t == 2){
        for(int node_index = 0; node_index<g; node_index++){
            vector<vector<int>> temp;
            for(int i = 0; i<e; i++){
                if(archs[i][0] == node_index || archs[i][1] == node_index){
                    continue;
                }
                temp.push_back(archs[i]);
            }
            if(is_connected(g,temp, node_index)) {
                cout<<"0"<<endl;
            }
            else{
                cout<<"1"<<endl;
            }
        }
    }

}
