/**
* user:  VR424649
* fname: ERBISTI
* lname: ANDREA
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 10:34:31.205188
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

void second_to_first(int n_figli){
    //printf("Sono a tree[%d]= %d\n",n_figli, tree[n_figli]);
    if(tree[n_figli]==1){
        //printf(" %d", tree[n_figli]);
        solution.push_back(tree[n_figli]);
        return;
    }
    int end = n_figli-tree[n_figli];
    for(int i = n_figli-1; i>=0 and i>=end; i--){
       //printf("per %d indice: %d\n", n_figli, i);
       second_to_first(i);
       i = i - (tree[i] - 1);
    }
    //printf(" %d", tree[n_figli]);
    solution.push_back(tree[n_figli]);
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
        printf("1");
        for(int i=0;i<11;i++){
            int u;
            scanf("%d ", &u);
            if(u>0)
                tree.push_back(u);
            else break;
        } 
        int n = tree.back();
        //printf("%d ", n);
        tree.resize(n_nodes);
        second_to_first(n-1);
        
        for(int i=0;i<n; i++){
            printf(" %d",solution.back());
            solution.pop_back();
        }
    }

}
