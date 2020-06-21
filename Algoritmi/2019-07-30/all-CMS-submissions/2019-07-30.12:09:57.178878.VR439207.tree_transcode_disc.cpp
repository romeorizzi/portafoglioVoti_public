/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 12:09:57.178878
*/
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits.h>
using namespace std;

//const int MAX_N = 1000000;
//const int MAX_VAL = 10;
FILE *fin, *fout;
struct Node{
    int depth;
    Node * padre;
    int sum;
    int remaningsum;
    int pos;
};
vector<int> sumArray;
vector<int> result;
int main(void){
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    Node root;
    Node *ptr = &root;

    int treeType;
    int readvelue;
    root.sum = INT_MAX;
    root.remaningsum= INT_MAX;
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
            newNode->depth = ptr->depth+1;
            newNode->remaningsum = readvelue;// valore letto
            newNode->sum = readvelue; // volore letto
            ptr = newNode;
            sumArray.push_back(ptr->depth);
            while(ptr->remaningsum == 1){
                sumArray.push_back(ptr->depth);
                ptr->padre->remaningsum -= ptr->sum;
                result.push_back(ptr->sum);
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
                newNode ->padre = ptr;
                newNode ->pos= maxPos;
                sumArray.push_back(0);
                maxPos++;
                newNode->depth = readvelue;
                ptr = newNode;
            }
        }
        if (ptr == &root){
            break;
        }
    }
    for(int i = 0; i< result.size(); i++){
        fprintf(fout, "%i ", result[i]);
    }
}