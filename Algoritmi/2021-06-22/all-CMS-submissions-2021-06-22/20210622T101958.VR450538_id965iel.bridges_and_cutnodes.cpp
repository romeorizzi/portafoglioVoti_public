/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 10:19:58.729393
*/
#include <iostream>
#include <vector>

using namespace std;


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
            visited[archs[0][1]] = 1;
            archs.erase(archs.begin());
            return visited_nodes(g,archs,visited);
        }
        else if(visited[archs[0][1]] == 1){
            visited[archs[0][0]] = 1;
            archs.erase(archs.begin());
            return visited_nodes(g,archs,visited);
        }
        else{
            archs.erase(archs.begin());
            return visited_nodes(g,archs,visited);            
        }        
    }
}

bool is_connected(int g, vector<vector<int>> archs) {
    int visited[g] = {0};
    visited[archs[0][0]] = 1;

    visited_nodes(g, archs, visited);

    for (int node : visited) {
        if(node == 0){
            return false;
        }
    }    
    return true;
}


int main(void){

    int t = 1;
    int g = 10;
    int e = 13;

    scanf("%d%d%d", &t, &g,&e);
    vector<vector<int>> archs;


    for(int i = 0; i < e; i++) {
        int n1,n2;
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
            ;
        }
    }

}
