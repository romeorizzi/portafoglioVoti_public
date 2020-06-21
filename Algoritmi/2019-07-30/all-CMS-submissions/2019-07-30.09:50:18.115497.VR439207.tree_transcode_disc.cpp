/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 09:50:18.115497
*/
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;
FILE *fin, *fout;
struct Node{
    int depth;
    Node * padre;
    int sum;
    int remaningsum;
    int pos;
};

vector<int> sumArray;

int main(void){
    fin = fopen("input0.txt", "r");
    fout = fopen("output.txt", "w");

    Node root;
    Node *ptr = &root;

    int treeType;
    int readvelue;
    root.sum = MAX_N;
    root.remaningsum= MAX_N;
    root.depth = -1;
    fscanf(fin, "%i", &treeType);
    if(treeType == 1){
        fprintf(fout, "2 ");
    }else{
        fprintf(fout, "1 ");
    }
    int maxPos = 0;
    while(true){
        // LETTURA
        fscanf(fin, "%i", &readvelue);
        if(treeType == 1){
            Node* newNode = new Node();
            newNode->padre = ptr;
            newNode ->depth = ptr->depth+1;
            newNode->remaningsum = readvelue;// valore letto
            newNode->sum = readvelue; // volore letto
            ptr = newNode;
            sumArray.push_back(ptr->depth);
            while(ptr->remaningsum == 1){
                sumArray.push_back(ptr->depth);
                ptr->padre->remaningsum -= ptr->sum;
                //result.push_back(ptr->sum);
                ptr = ptr->padre;
            }
        }else{
            if(ptr->depth == readvelue){
                ptr->sum++;
                ptr->padre->sum += ptr->sum;
                sumArray[ptr->pos]+=ptr->sum;
                ptr = ptr->padre;
            }else{
                Node *newNode = new Node();
            }
        }
        if (ptr == &root){
            break;
        }
    }
    for(int i = 0; i< sumArray.size(); i++){
        fprintf(fout, "%i", sumArray[i]);
    }
}