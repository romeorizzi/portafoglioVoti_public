/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:51:00.305428
*/
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <vector>
#include <cassert>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include <cstdio>

#include <limits.h>

#include <deque>

using namespace std;

//const int MAX_N = 1000000;
//const int MAX_VAL = 10;
deque <Node *> freetrees;
vector<int> res;
FILE *fin, *fout;
struct Node{
    Node * padre;
    vector <Node *> figli;
    int n;
    int remaningsum;
};


void DFS(Node *n){
    res.push_back(n->n);
    for(int i = n->figli.size()-1; i>=0; i--){
        DFS(n->figli[i]);
    }
}


int main(void){

    Node root;
    Node *ptr = &root;
    int type;
    root.remaningsum = 0;
    int temp;
    int val;
    int i =0;
    scanf("%i", &type);

    do{
        val = scanf("%i", &readvelue);
        if(type == 1){
            Node* newNode = new Node();
            newNode->padre = ptr;
            newNode->n = temp;
            newNode->remaningsum = readvelue;// valore letto
            newNode->sum = readvelue; // volore letto
            ptr = newNode;
            while(ptr->remaningsum == 1){
                res.push_back(ptr->n);
                ptr->padre->remaningsum -= ptr->n;
                ptr = ptr->padre;
            }
        }else{
            ptr = 0;                
            Node *newNode = new Node();
            newNode ->n = readvelue;
            newNode ->remaningsum= readvelue;
            while(newNode->remaningsum>1){
                Node * j =freetrees.back();
                freetrees.pop_back();
                newNode->figli.push_back(j);
                k->padre= newNode;
                newNode->remaningsum -= j->n;
            }
            freetrees.push_back(newNode);
        }
    } while(ptr != root);


    if (type == 2){
        DFS(freetrees.back());
    }
    printf("%i ", 3-type);
    for(int i = 0; i< res.size(); i++){
        printf("%i ", res[i]);
    }
}