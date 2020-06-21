/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 12:01:53.150845
*/
/**
 *  Template per soluzione in c++ per il problema tree_split_out
 *
 *  Romeo Rizzi, per l'appello di algoritmi 2019-09-04
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

const int MAX_N = 1000000;

int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];

struct tree
{
    int nFigli;
    int nDiscendenti;
    int livello;
    vector<struct tree> figli;
};

tuple<struct tree,int> Sol_3_val(int i)
{
    struct tree node;
    node.livello = in_tree[i];
    i++;

    while(in_tree[i] != node.livello)
    {
        tuple<struct tree,int> temp = Sol_3_val(i);
        struct tree child = get<0>(temp);
        node.figli.push_back(childtree);
        i = get<1>(temp) +1;
    }
    return tuple<tree,int>(node,i);
}

void evapora(struct tree * t)
{
    vector<struct free> nipoti;
    for(aiuto it = t->figli.begin();it != t->figli.end();++it)
    {
        struct tree oddnode = *it;
        for(aiuto it = oddnode->figli.begin();it != oddnode->figli.end();++it)
        {
            struct tree n = (*it);
            evapora(&n);
            nipoti.push_back(n);
        }
        
    }
    t->figli.clear();
    t->nDiscendenti = 1;
    t->nFigli = nipoti.size();
    for(auto it = nipoti.begin(); it != nipoti.end();++it)
    {
        t->figli.push_back(*it);
        t->nDiscendenti += (*it).nDiscendenti;
    }
}

void printSol(struct tree * node)
{
    cout << (node->nFigli) << " ";
    for(auto it = node->figli.begin();it!=node->figli.end();++it)
    {
        printSol(&(*it));
    }
}


void print2(struct tree * node)
{
    cout << (node->nDiscendenti) << " ";
    for(auto it = node->figli.begin();it!=node->figli.end();++it)
    {
        print2(&(*it));
    }
}

void print3(struct tree * node, int d)
{
    cout << (node->livello / divider) << " ";
    for(auto it = node->figli.begin();it!=node->figli.end();++it)
    {
        print3(&(*it),divider);
    }
    cout << (node->livello / divider) << " ";
}


int main() {
    // leggere l'input_type:
    cin >> input_type;

    // leggere la sequenza che codifica l'albero in input (in formato input_type):
    int val;
    while (cin >> val)
      in_tree[n++] = val;

    // in questo template di soluzione mi limito a ricopiare l'input in output (non sarà mai la soluzione corretta tranne che per alberi di un solo nodo):
    //if(in_tree[0] == 1) cout << input_type << ' ';
    if(input_type == 3)
    {
        struct tree node = get<0>(Sol_3_val(0));
        evapora(&node);
        cout << 3;
        print3(&node,2)
    }
    else
        assert(false);
    return 0;
}

