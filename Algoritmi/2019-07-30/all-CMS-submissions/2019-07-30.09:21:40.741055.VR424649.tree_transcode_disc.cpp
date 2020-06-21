/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 09:21:40.741055
*/
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
vector <int> tree;
vector <int> solution;
int t,n_nodes;;

void first_to_second(int i){
    if(i==n_nodes)
        return;
    int end = i+tree[i];
    for(int j = i+1; j<end and j<n_nodes; j++){
        first_to_second(j);
        j += tree[j]-1;
    }
    printf(" %d", tree[i]);
    //solution.push_back(tree[i]);
    return;
}

void second_to_first(int j){
    return;
}

int main(){
#ifdef EVAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d", &t);
    
    if(t==1){
        printf("2");
        scanf("%d ", &n_nodes);
        tree.resize(n_nodes);;
        tree[0] = n_nodes;      
        for(int i=1;i<n_nodes;i++){
            scanf("%d ", &tree[i]);
            //printf("%d ", tree[i]);
        } 
        first_to_second(0);
    }

    if(t==2){   
        for(int i=1;i<n_nodes;i++){
            int u;
            scanf("%d ", &u);
            if(u>0)
                tree.push_back(u);
        } 
        second_to_first(0);
    }

}
