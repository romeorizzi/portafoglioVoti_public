/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  Prob1_tree_split_out
* score: 0.0
* date:  2019-09-04 11:40:30.547848
*/
#include <vector>
#include <tuple>
#include <iostream>

using namespace std;
const int MAX_N = 1000000;
int n = 0, input_type;
int in_tree[MAX_N], out_tree[MAX_N];

struct tree{
    int nfigli;
    int ndiscendenti;
    int livello;
    std::vector<struct tree> figli;
};

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
        for(auto it = oddnode->figli.begin(); it!=oddnode->figli.end(); ++it){
            struct tree nephew = (*it);
            evapora(&nephew);
            nipoti.push_back(nephew);
        }
    }
    evennode->figli.clear();
    evennode->figli.assign(nipoti.begin(), nipoti.end());
}

void print_3(struct tree* node, int divider){
    cout << (node->livello / divider) << " ";
    for(auto it = node->figli.begin() it!= node->figli.end(); ++it){
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
        assert(false)
    }

    return 0;

}










// ifstream fin;
// ofstream fout;

// vector<int> vec1, vec2;

// int writeType_2(int deep){
//     int child; fin >> child;
//     int count = 0;
//     fout << deep << " ";
//     while(count<child){
//         count += writeType_2(deep+1);
//     }
//     fout<<deep<<" ";
//     return child;
// }

// int calcVec1(int index1, int index2){
//     vec1.push_back(1);
//     int deep; deep = vec2[index2];
//     while(vec2[index2 + 2*vec1[index1] - 1] > deep){
//         vec1[index1] += calcVec1(index1 + vec1[index1],index2+2*vec1[index1]-1);
//     }
//     return vec1[index1];
// }

// void writeType_1(){
//     vec2.push_back(0);
//     int temp;
//     fin >> temp;
//     do{
//         fin >> temp;
//         vec2.push_back(temp);
//     }while(temp>0);
//     calcVec1(0,0);
//     for(int i=0; i<vec1.size(); i++){
//         fout << vec1[i] << " ";
//     }
// }




// int main(){
// fin.open("input.txt");
// fout.open("output.txt");
// assert(fin);
// assert(fout);
// int type; fin >> type;
// fout << 3-type << " ";
// if(type==1){
//     writeType_2(0);
// }
// else{
//     writeType_1();
// }
// fout<<endl;

// return 0;
// }