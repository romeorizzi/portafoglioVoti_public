/**
* user:  VR436780
* fname: CAUCCHIOLO
* lname: ANDREA
* task:  tree_transcode_disc
* score: 100.0
* date:  2019-07-30 10:09:30.606611
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <deque>
#include <vector>

using namespace std;

vector<int> res;

struct Node{
    Node * padre;
    vector <Node*> figli;
    int n;
    int remainingSum;
};

void DFS(Node * n ){
    res.push_back(n->n);
    for (int i = n->figli.size()-1; i>=0;i--){
        DFS(n->figli[i]);
    }
}

deque <Node *> freeTrees;

int main()
{
    Node root;
    root.remainingSum = 0;
    int type;
    Node * ptr = &root;
    scanf("%i", &type);
    int tmp;
    int val;
    int i = 0;
    do{
        //val = cin >> tmp;
        val = scanf("%i", &tmp);
        //cout << "val" << val << endl;
        if (val <= 0) break;
        if (type == 1){
            Node * newNode = new Node;
            newNode->padre = ptr;
            newNode->n = tmp;
            newNode->remainingSum = tmp;
            ptr = newNode;
            while (ptr->remainingSum == 1){
                res.push_back(ptr->n);
                ptr->padre->remainingSum -= ptr->n;
                ptr = ptr->padre;
            }
        }else{
            ptr = 0;
            Node * newNode = new Node;
            newNode->n = tmp;
            newNode->remainingSum = tmp;
            //cout << "added " << newNode -> n << endl;
            while (newNode->remainingSum > 1){
                Node * k = freeTrees.back();
                freeTrees.pop_back();
                newNode->figli.push_back(k);
                k->padre = newNode;
                newNode->remainingSum -= k->n;
                //cout << "absorbed node " << k->n << endl;
            }
            freeTrees.push_back(newNode);
        }

    }while (ptr != &root);

    if(type == 2){
        DFS(freeTrees.back());
    }


    printf("%i ", 3-type);
    for (int i = 0; i<res.size();i++){
        printf("%i ", res[i]);
    }
    return 0;
}
