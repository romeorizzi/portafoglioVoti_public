/**
* user:  VR436944
* fname: GHIGNONI
* lname: EROS
* task:  tree_transcode_disc
* score: 90.0
* date:  2019-07-30 11:15:54.582438
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> tree;
int *result;

int one_to_two(int index, int start){   // ritorna l'ultima posizione scritta

    if (tree[index] == 1){  //sono una foglia
        result[start] = tree[index];
        return start;
    }

    int conta_figli = 1;
    while(conta_figli < tree[index]){

        start = one_to_two(index + conta_figli, start) + 1;
        conta_figli += tree[index+conta_figli];     
    }

    result[start] = tree[index];
    return start;
}

void two_to_one(int index, int start){  

    if (tree[index] == 1){
        result[start] = 1;
        return;
    }

    int root = tree[index];

    result[start] = root;
    
    int conta_figli = tree[index] - 1;
    stack<pair<int,int> > figli;
    int j = index - 1;
    
    while(conta_figli > 0 && j >=0 ){
        figli.push({tree[j], j});

        conta_figli -= tree[j];
          j -= tree[j];
    }
    int s_figlio = start + 1;

    while(!figli.empty()){

        int son = figli.top().first;
        two_to_one(figli.top().second, s_figlio);
        figli.pop();
        s_figlio += son;
    }

}


int main(){

    int i;
    int mode;
    int value;
    cin >> mode;

    while(cin>>value)
        tree.push_back(value);

    result = new int[tree.size()];

    if (mode == 1){
        cout << 2 << " ";
        one_to_two(0, 0);
    } else {
        
        cout << 1 << " ";
        two_to_one(tree.size()-1, 0);
    }

    for (i=0; i<tree.size(); i++)
        cout << result[i] << " ";

    return 0;
}