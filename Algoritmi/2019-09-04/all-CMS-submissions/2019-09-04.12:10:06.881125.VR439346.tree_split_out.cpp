/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  Prob1_tree_split_out
* score: 20.0
* date:  2019-09-04 12:10:06.881125
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

std::tuple<struct tree, int> codifica3(int i){
    struct tree nodo;
    nodo.livello = in_tree[i];
    i++;
    while(in_tree[i] != nodo.livello){
        std::tuple<struct tree,int> temp = codifica3(i);
        struct tree childtree = std::get<0>(temp);
        nodo.figli.push_back(childtree);
        i= std::get<1>(temp)+1;
    }
    return std::tuple<tree, int>(nodo,i);
}

void evaporazione(struct tree* evennode){
    std::vector<struct tree> nipoti;
    for(auto iterator = evennode->figli.begin();iterator != evennode->figli.end(); ++iterator){
        struct tree odd_node = *iterator;
        for(auto iterator = odd_node.figli.begin(); iterator != odd_node.figli.end();++iterator){
            struct tree nephw = (*iterator);
            evaporazione(&nephw);
            nipoti.push_back(nephw);
        }
    }
    evennode->figli.clear();
    evennode->figli.assign(nipoti.begin(),nipoti.end());
}

void print_3(struct tree* nodo, int divisore){
    cout << (nodo->livello / divisore) << " ";
    for(auto iterator = nodo->figli.begin(); iterator !=nodo->figli.end(); ++iterator){
    print_3(&(*iterator),divisore);
    }
    cout << (nodo->livello/divisore) << " ";
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
       struct tree nodo = get<0>(codifica3(0));
       evaporazione(&nodo);
       cout << "3 ";
       print_3(&nodo, 2);
   }
    return 0;
}