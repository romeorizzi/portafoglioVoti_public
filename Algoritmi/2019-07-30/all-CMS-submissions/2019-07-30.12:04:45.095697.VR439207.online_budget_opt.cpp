/**
* user:  VR439207
* fname: TROTTI
* lname: FRANCESCO
* task:  online_budget_opt
* score: 50.0
* date:  2019-07-30 12:04:45.095697
*/
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <istream>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
using namespace std;

int *x;
int *q;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}
pair <int, int> * order;
int main(void){
    int n, b0, t;
    scanf("%i %i %i", &n, &b0, &t);
    x = new int[n+1];
    q = new int[n];
    int temp = 0;
    order = new pair<int, int>[n];
    x[0]= b0;
    for (int i =1; i<n+1; i++){
        scanf("%i", &temp);
        x[i] = x[i-1] + temp;
    }
    for (int i =0; i<n; i++){
        scanf("%li", &q[i]);
        order[i].first = i;
        order[i].second = q[i];
    }

    sort(order, order+n, compare);

    int pos = 0;
    int ptr = 0;
    long int res = 0;
    int pen = 0;
    vector<int> choice;
    while(pos <n){
        if (order[ptr].first >=pos){
            res += ((long int)q[order[ptr].first])*(x[order[ptr].first]-pen);

            for (int i=pos; i<order[ptr].first; i++){
                choice.push_back(0);
            }
            choice.push_back(x[order[ptr].first]-pen);
            pen = x[order[ptr].first];
            pos = order[ptr].first+1;
            ptr++;
        }else{
            ptr++;
        }
    }
    if(t == 1){
        printf("%li", res);
    }else{
        for(int i=0; i<n;i++){
            printf("%i", choice[i]);
        }
    }
    return 0;
}