/**
* user:  VR436780
* fname: CAUCCHIOLO
* lname: ANDREA
* task:  online_budget_opt
* score: 100.0
* date:  2019-07-30 11:13:56.642932
*/
#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int * x;
int * q;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

pair<int, int> * order;
int main(){
    int n, b0, t;
    scanf("%i %i %i", &n, &b0, &t);
    x = new int[n+1];
    q = new int[n];
    int tmp = 0;
    order = new pair<int, int>[n];
    x[0] = b0;
    for (int i = 1; i<n+1; i++){
        scanf("%i", &tmp);
        x[i] = x[i-1]+tmp;
    }
    for (int i = 0; i<n; i++){
        scanf("%li", &q[i]);
        order[i].first = i;
        order[i].second = q[i];
    }
    /*
    for (int i = 0; i<n; i++){
        cout << "sec: " << order[i].second << ", frst: " << order[i].first << endl;
    }*/
    sort(order, order+n, compare);

    /*for (int i = 0; i<n; i++){
        cout << "sec: " << order[i].second << ", frst: " << order[i].first << endl;
    }
    for (int i = 0; i<n; i++){
        cout << "x:" << x[i] << endl;
    }*/

    int pos = 0;
    int ptr = 0;
    long int res = 0;
    int penalty = 0;
    vector<int> choices;
    while (pos < n){
        if (order[ptr].first >= pos){
            res += ((long int)q[order[ptr].first])*(x[order[ptr].first]-penalty);

            for (int i = pos; i<order[ptr].first;i++){
                choices.push_back(0);
            }
            choices.push_back(x[order[ptr].first]-penalty);
            penalty = x[order[ptr].first];
            pos = order[ptr].first+1;
            ptr++;
        }else{
            ptr++;
        }
    }
    if (t == 1) printf("%li", res);
    else{
        for(int i = 0; i<n;i++){
            printf("%i ", choices[i]);
        }
    }

    return 0;

}
