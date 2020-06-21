/**
* user:  VR439240
* fname: FATTORELLI
* lname: MARCO
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 10:26:58.514481
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;

FILE *fi, *fo;

struct Node{
    Node * padre;
    int sum;
    int remainingSum;
    int depth;
    int pos;
};

vector<int> sumArray;
vector<int> result;


int main()
{
    fi = fopen("input.txt", "r");
    fo = fopen("output.txt", "w");

    Node root;
    Node * ptr = &root;

    int readValue;
    int codifica;
    root.sum = INT_MAX;
    root.remainingSum = INT_MAX;
    root.depth = -1;

    fscanf(fi, "%i", &codifica);
    if (codifica == 1) fprintf(fo, "2 ");
    else fprintf(fo, "1 ");

    int maxPos = 0;
    while(true){

        fscanf(fi, "%i", &readValue);
        if (codifica == 1){
            Node * newNode = new Node();
            newNode->padre = ptr;
            newNode->depth = ptr->depth+1;
            newNode->remainingSum = readValue;
            newNode->sum = readValue;
            ptr = newNode;
            sumArray.push_back(ptr->depth);
            while(ptr->remainingSum == 1){
                sumArray.push_back(ptr->depth);
                ptr->padre->remainingSum-= ptr->sum;
                result.push_back(ptr->sum);
                ptr = ptr->padre;
            }
        }else{//codifica 2 doesn't work
            if(ptr->depth == readValue){
                ptr->sum++;
                ptr->padre->sum += ptr->sum;
                sumArray[ptr->pos]+=ptr->sum;
                ptr = ptr->padre;
            }else{
                Node * newNode = new Node();
                newNode->padre = ptr;
                newNode->pos = maxPos;
                sumArray.push_back(0);
                maxPos++;
                newNode->depth = readValue;
                ptr = newNode;
            }
        }
        if (ptr == &root) break;
    }
    for(int i = 0; i<result.size();i++){
        fprintf(fo, "%i ", result[i]);
    }
}
