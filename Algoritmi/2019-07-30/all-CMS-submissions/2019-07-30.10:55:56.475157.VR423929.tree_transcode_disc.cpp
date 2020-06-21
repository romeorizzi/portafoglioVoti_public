/**
* user:  VR423929
* fname: BRAGAGLIO
* lname: MORENO
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:55:56.475157
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
  Node * dad;
  int sum;
  int remSum;
  int d;
  int p;
};

vector<int> v;
vector<int> res;

int main() {
    fin=fopen("input.txt", "r");
    fout=fopen("output.txt", "w");
    Node root;
    Node *ptr=&root;

    int readValue;
    int treeType;
    
    root.sum=INT_MAX;
    root.remSum=INT_MAX;
    root.d=-1;

    fscanf(fin, "%i", &treeType);
    if(treeType==1) fprintf(fout, "2");
    else fprintf(fout, "1");

    int maxPos=0;
    while(true){
        fscanf(fin, "%i", &readValue);
        if(treeType==1){
            Node * newNode = new Node();
            newNode->dad=ptr;
            newNode->d=ptr->d+1;
            newNode->remSum=readValue;
            newNode->sum=readValue;
            ptr=newNode;
            v.push_back(ptr->d);
            while(ptr->remSum==1){
                v.push_back(ptr->d);
                ptr->dad->remSum-=ptr->sum;
                res.push_back(ptr->sum);
                ptr = ptr->dad;
            }
        }
        else{
            if(ptr->d == readValue){
                ptr->sum++;
                ptr->dad->sum += ptr->sum;
                v[ptr->p]+=ptr->sum;
                ptr=ptr->dad;
            }
            else{
                Node * newNode = new Node();
                newNode->dad=ptr;
                newNode->p=maxPos;
                v.push_back(0);
                maxPos++;
                newNode->d=readValue;
                ptr=newNode;
            }
        }
        if(ptr == &root) break;
    }
    for(int i=0; i<res.size(); i++){
        fprintf(fout, "%i", res[i]);
    }
}