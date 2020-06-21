/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 12:00:58.765541
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
#include <limits.h>
#include <iostream>
#include <string>
using namespace std;

FILE *fin, *fout;


struct Node{
  Node * padre;
  int sum;
  int remaningsum;
  int depth;
  int pos;
};

vector<int> sumArray;
vector<int> result;

int main() {
    fin=fopen("input.txt", "r");
    fout=fopen("output.txt", "w");
    Node root;
    Node *ptr=&root;

    int treeType;
    int readValue;
    root.sum=INT_MAX;
    root.remaningsum=INT_MAX;
    root.depth=-1;

    fscanf(fin, "%i", &treeType);
    if(treeType==1) fprintf(fout, "2");
    else fprintf(fout, "1");

    int maxPos=0;
    while(true){
        fscanf(fin, "%i", &readValue);
        if(treeType==1){
            Node* newNode = new Node();
            newNode->padre=ptr;
            newNode->depth=ptr->depth+1;
            newNode->remaningsum=readValue;
            newNode->sum=readValue;
            ptr=newNode;
            sumArray.push_back(ptr->depth);
            while(ptr->remaningsum==1){
                sumArray.push_back(ptr->depth);
                ptr->padre->remaningsum-=ptr->sum;
                result.push_back(ptr->sum);
                ptr = ptr->padre;
            }
        }else{
            if(ptr->depth == readValue){
                ptr->sum++;
                ptr->padre->sum += ptr->sum;
                sumArray[ptr->pos]+=ptr->sum;
                ptr=ptr->padre;
            }
            else{
                Node *newNode = new Node();
                newNode ->padre=ptr;
                newNode ->pos=maxPos;
                sumArray.push_back(0);
                maxPos++;
                newNode->depth=readValue;
                ptr=newNode;
            }
        }
        if(ptr == &root){
           break;
        }
    }
    for(int i=0; i<result.size(); i++){
        fprintf(fout, "%i", result[i]);
    }

    return 0;
}