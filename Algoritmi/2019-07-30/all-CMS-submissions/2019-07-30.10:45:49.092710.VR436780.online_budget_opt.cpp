/**
* user:  VR436780
* fname: CAUCCHIOLO
* lname: ANDREA
* task:  online_budget_opt
* score: 0.0
* date:  2019-07-30 10:45:49.092710
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
        scanf("%i", &q[i]);
        order[i].first = i;
        order[i].second = q[i];
    }
    for (int i = 0; i<n; i++){
        cout << "sec: " << order[i].second << ", frst: " << order[i].first << endl;
    }
    sort(order, order+n, compare);

    for (int i = 0; i<n; i++){
        cout << "sec: " << order[i].second << ", frst: " << order[i].first << endl;
    }

    int pos = 0;
    int ptr = 0;
    long int res = 0;
    vector<int> choices;
    while (pos < n){
        if (order[ptr].first >= pos){
            res += q[pos]*x[pos];
            pos = order[ptr].first;
            choices.push_back(x[pos]);
            ptr++;
        }else{
            pos++;
            choices.push_back(0);
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
