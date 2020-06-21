/**
* user:  VR433534
* fname: BRENTAROLLI
* lname: ELIA
* task:  tree_transcode_disc
* score: 60.0
* date:  2019-07-30 10:40:57.419216
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>


using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

int x[MAX_N], input_type;
int len=0, index=0;

int recursive_transcode(){
    int value;
    if(scanf("%d",&value)){
        len++;
        if(value == 1){
            x[index]=1;
            return 1;
        }
        else{
            int val=value-1;
            while(val){
                //printf("%d ",val);
                val-=recursive_transcode();
                index++;
            }
            x[index]=value;
            return value;
        }
    }
    return 0;
}


struct Tree_node{
    Tree_node* father;
    int value;
    vector<Tree_node*> sons;
    int vect_len;
    int counter;
};


void rec_ltr_dfs(Tree_node* root){
    printf("%d ",root->value);
    for(int i= root->vect_len-1; i>=0; i--){
        if(root->sons[i]->value == 1)
            printf("1 ");
        else rec_ltr_dfs(root->sons[i]);
    }
}


int main() {
    
    scanf("%d",&input_type);

    if(input_type == 1){
        recursive_transcode();
        printf("2 ");
        for(int i=0;i<len-1;i++){
            printf("%d ",x[i]);
        }
        printf("%d\n",x[len-1]);
    }
    else{
        int value;
        int sum=0;
        vector<int> stack;
        while(cin >> value){
            stack.push_back(value);
            len++;
        }
        printf("1 ");
        Tree_node* father=(Tree_node*) malloc(sizeof(Tree_node));
        father-> value=stack[len-1];
        father->father = NULL;
        father->counter = stack[len-1]-1;
        Tree_node* root=father;
        for(int i=len-2;i>=0;i--){
            Tree_node* node=(Tree_node*) malloc(sizeof(Tree_node));
            node->value=stack[i];
            //printf("adding %d to %d\n",node->value,father->value);
            father->sons.push_back(node);
            node->father=father;
            father->vect_len++;
            father->counter-=node->value;
           // printf("counter %d\n",father->counter);
            if(father->counter==0 && father->father!=NULL){
                while(father->counter == 0 && father != root)
                    father=father->father;
            }
            if(node->value>1){
                father=node;
                node->counter=node->value-1;
            }
        }
        rec_ltr_dfs(root);

    }
    return 0;
}

