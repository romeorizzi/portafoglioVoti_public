/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 12:25:05.441712
*/
#include <vector>
#include <tuple>
#include <iostream>
#include <cassert>
#include <cstdio>
#include <algorithm>


using namespace std;
const int MAX_N = 1000000;
int nf = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];

struct tree{
    int nfigli;
    int ndiscendenti;
    int livello;
    std::vector<struct tree> figli;
};

std::tuple<struct tree, int> input_1(int i, int livello)
{
    struct tree node;
    node.nfigli = in_tree[i];
    node.livello=livello;

    for(int j=0; j<node.figli; j++){
        std::tuple<struct tree, int> temp = input_1(i+1, livello+1);
        struct tree childtree = std::get<0>(temp);
        node.figli.push_back(childtree);
        i=std::get<1>(temp);
    }

    return std::tuple<tree, int>(node,i);
}


std::tuple<struct tree, int> input_2(int i, int livello)
{
    struct tree node;
    node.ndiscendenti=in_tree[i];
    node.livello = livello;
    int sommaDis=1;

    while(sommaDis < node.ndiscendenti){
        std::tuple<struct tree, int> temp = input_2(i+1, livello+1);

        struct tree childtree = std::get<0>(temp);
        node.figli.push_back(childtree);
        i= std::get<1>(temp);
        sommaDis += childtree.ndiscendenti;
    }
    return std::tuple<tree, int>(node,i);
}

std::tuple<struct tree, int> input_3(int i)
{
    struct tree node;
    node.livello = in.tree[i];
    i++;

    while(in_tree[i] != node.livello){
        std::tuple<struct tree, int> temp = input_3(i);

        struct tree childtree = std::get<0>(temp);
        node.figli.push_back(childtree);
        i= std::get<1>(temp) + 1;
    }
    return std::tuple<tree, int>(node,i);
}

void evapora(struct tree* evennode){
    std::vector<struct tree> nipoti;
    for(auto it = evennode->figli.begin(); it!=evennode->figli.end(); ++it){
        struct tree oddnode = *it;
        for(auto it = oddnode.figli.begin(); it!=oddnode.figli.end(); ++it){
            struct tree nephew = (*it);
            evapora(&nephew);
            nipoti.push_back(nephew);
        }
    }
    evennode->figli.clear();
    evennode->ndiscendenti=1;
    evennode->nfigli = nipoti.size();

   for(auto it = nipoti.begin(); it!=nipoti.end(); ++it){
       evennode->figli.push_back(*it);
       evennode->ndiscendenti += (*it).ndiscendenti;
   }
}

void print_1(struct tree* node){
    cout << (node->nfigli) << " ";
    for(auto it = node->figli.begin(); it!= node->figli.end(); ++it){
        print_1(&(*it));
    }
}

void print_2(struct tree* node){
    cout << (node->ndiscendenti) << " ";
    for(auto it = node->figli.begin(); it!= node->figli.end(); ++it){
        print_2(&(*it));
    }
}

void print_3(struct tree* node, int divider){
    cout << (node->livello / divider) << " ";
    for(auto it = node->figli.begin(); it!= node->figli.end(); ++it){
        print_3(&(*it), divider);
    }
    cout << (node->livello /divider) << " ";
    
}







int main(){
    cin >> input_type;
    int val;
    while(cin>>val)
    in_tree[n++] = val;

    if(input_type==3){
        struct tree node = std::get<0>(input_3(0));
        evapora(&node);
        cout << "3 ";
        print_3(&node, 2);
    } else{
        assert(false);
    }

    return 0;

}






