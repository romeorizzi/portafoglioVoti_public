/**
* user:  VR436780
* fname: CAUCCHIOLO
* lname: ANDREA
* task:  tree_transcode_disc
* score: 50.0
* date:  2019-07-30 08:34:51.493044
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <limits>
#include <queue>

using namespace std;

struct Node{
    Node * padre;
    int n;
    int remainingSum;
};

int main()
{
    Node root;
    root.remainingSum = 0;
    int type;
    Node * ptr = &root;
    scanf("%i", &type);
    vector<int> res;
    vector<int> input(1000000);
    int tmp;
    do{
        scanf("%i", &tmp);
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
            input.push_back(tmp);
        }

    }while (ptr != &root);

    if (type == 2){

    }

    printf("%i ", 3-type);
    for (int i = 0; i<res.size();i++){
        printf("%i ", res[i]);
    }
    return 0;
}
