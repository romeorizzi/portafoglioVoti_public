/**
* user:  VR425328
* fname: MOUHAMED
* lname: FALL
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 10:55:48.727959
*/
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <string>

using namespace std;

const int MAX_N = 500;
const int INT_MAX = 10;

FILE *fi, *fo;

Struct Node{
    Node * padre;
    int sum;
    int resto;
    int depth;
    int pos;
};
vector <int> sumArray;

int main() {
fi = fopen("input.txt","r");
fo = fopen("output.txt","W");

Node root;
Node * ptr = &root;

int readValue;
int TreeType;
root.sum = INT_MAX;
root.resto = INT_MAX;
root.depth = -1;

fscanf(fi, "%i", &readValue);
if(TreeType ==  1)
fprintf(fo,"2 ");
else fprintf(fo,"1 ");

int maxPos = 0;

while(true){
    fscanf(fi, "%i", &readValue);
    if(TreeType == 1){
    Node * newNode = new Node();
    newNode->padre = ptr;
    newNode->depth = ptr->depth+1;
    newNode->resto = readValue;
    newNode ->sum = readValue;
    ptr = newNode;
    sumArray.push_back(ptr->depth);
    while(ptr->resto == 1){
    sumArray.push_back(ptr->depth);
    ptr->padre->resto-= ptr->sum;
    ptr = ptr->padre;

    }

    }
    else{
        if(ptr->depth == readValue){
            ptr->sum++;
            ptr->padre->sum += ptr->sum;
            sumArray[ptr->pos]+= ptr->sum;
            ptr = ptr->padre;

        }else{
            Node * newNode = new Node();
            newNode->padre = ptr;
            newNode-> pos = maxPos;
            sumArray.push_back(0);
            maxPos++;
            newNode->depth = readValue;
            ptr = newNode;
        }
    }
    if(ptr == &root) break;
}
for(int i=0; i<sumArray.size();i++){
    fprintf(fo,"%i ",sumArray[i]);
}



    return 0;
}
