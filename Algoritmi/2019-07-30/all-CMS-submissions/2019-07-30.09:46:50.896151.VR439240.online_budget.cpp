/**
* user:  VR439240
* fname: FATTORELLI
* lname: MARCO
* task:  online_budget
* score: 0.0
* date:  2019-07-30 09:46:50.896151
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
    fi = fopen("input1.txt", "r");
    fo = fopen("output.txt", "w");

    Node root;
    Node * ptr = &root;

    int readValue;
    int treeType;
    root.sum = INT_MAX;
    root.remainingSum = INT_MAX;
    root.depth = -1;

    fscanf(fi, "%i", &treeType);
    if (treeType == 1) fprintf(fo, "2 ");
    else fprintf(fo, "1 ");

    int maxPos = 0;
    while(true){

        fscanf(fi, "%i", &readValue);
        if (treeType == 1){
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
        }else{
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
    }
    for(int i = 0; i<result.size();i++){
        fprintf(fo, "%i ", result[i]);
    }
}
