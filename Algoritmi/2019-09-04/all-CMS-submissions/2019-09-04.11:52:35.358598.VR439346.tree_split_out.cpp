/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:52:35.358598
*/
#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>



using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];


struct tree{
    int n_figli;
    int n_discendenti;
    int livello;
    std::vector<struct tree> figli;
};

std::tuple<struct tree, int> input_3(int i){
    struct tree node;
    node.livello = in_tree[i];
    i++;
    while(in_tree[i] != node.livello){
        tuple<struct tree,int> temp = input_3(i);
        struct tree childtree = get<0>(temp);
        node.figli.push_back(childtree);
        i= get<1>(temp)+1;
    }
    return tuple<tree, int>(node,i);
}

void evapora(struct tree* evennode){

    std::vector<struct tree> nipoti;
    for(auto it = evennode->figli.begin();it !=evennode->figli.end();++it){
        
        struct tree odd_node = *it;
        for(auto it = odd_node.figli.begin(); it!=odd_node.figli.end();++it){
            struct tree nephw = (*it);
            evapora(&nephw);
            nipoti.push_back(nephw);
        }

    }
    evennode->figli.clear();
    evennode->figli.assign(nipoti.begin(),nipoti.end());
}

void print_3(struct tree* node, int divider){
    cout << node->livello /divider << " ";
    for(auto it = node->figli.begin(); it !=node->figli.end(); ++it){
    print_3(&(*it),divider);

    }
    cout << (node->livello/divider) << " ";
}

int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
   if(input_type == 3){
       struct tree node = get<0>(input_3(0));
       evapora(&node);
       cout << "3";
       print_3(&node, 2);
   }
    
    return 0;
}