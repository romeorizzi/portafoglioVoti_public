/**
* user:  VR439346
* fname: MASOTTO
* lname: GIOVANNI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:32:40.367885
*/
/**
 *  Template per soluzione in c++ per il problema tree_transcode_disc
 *
 *  Romeo Rizzi, 2019-07-28
 *
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>

using namespace std;

FILE *fin, *fout;

struct Node{
    Node * father;
    int sum;
    int remainingSum;
    int depth;
    int pos;
};

vector <int> vecS;
vector <int> res;
int a = 0;
int b = -1;
int main(){
    fin = fopen("input0.txt", "r");
    fout = fopen("output.txt", "w");

    Node root;
    Node * p = &root;

    int val = -1;
    int codifica = -1;
    int maxPos = 0;
    root.sum = INT_MAX;
    root.remainingSum = INT_MAX;
    root.depth = -1;

    fscanf(fin,"%i", &codifica);
    if(codifica == 1) fprintf(fout,"2 ");
    else fprintf(fout,"1 ");


    while(true){
        fscanf(fin,"%i",&val);
        if(codifica ==1){
        Node * newnode =  new Node();
        newnode->father=p;
        newnode->sum = val;
        newnode->remainingSum = val;
        newnode->depth = p->depth;
        p = newnode;
        vecS.push_back(p->depth);
        while(p->remainingSum ==1){
                vecS.push_back(p->depth);
                p->father->remainingSum-=p->sum;
                res.push_back(p->sum);
                p = p->father;
                a++;
            }
        }else{
            if(p->depth == val){
                p->sum++;
                p->father->sum += p->sum;
                vecS[p->pos]+=p->sum;
                p=p->father;
                if (a = b){
                    p->depth = val;
                }
            }else{
                Node * newnode = new Node();
                newnode->father = p;
                b++;
                vecS.push_back(0);
                newnode->pos = maxPos;
                newnode->depth = val;
                maxPos++;
                p = newnode;
            }
        }
        if(p ==&root) break;
    }
    for(int i = 0; i < res.size();i++){
    fprintf(fout, "%i ",res[i]);
    }
    return 0;
}
