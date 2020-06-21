/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:15:45.882130
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> row;

struct range {
    vector<int>::iterator a, 
    vector<int>::iterator b
};

vector<range> load;

void op1(int p1, int p2) {
    int tmp;
    tmp = row.at(p1);
    row.at(p1) = row.at(p2);
    row.at(p2) = tmp;

    load.clear();
}

bool op2(int cmd1, int cmd2, int n) {
    int index_Min;
    int index_Max;
    int index;
    vector<int>::iterator itr1 = row.begin();
    vector<int>::iterator itr3 = row.begin();

    if (load.size() > 0) {
        for (vector<int>::iterator i ; i != load.end; i++) {
            if (itr1 > load.a && itr3 < load.b) return true;
        }
    }

    itr1 = find(row.begin(), row.end(), cmd1);
    itr3 = find(row.begin(), row.end(), cmd2);
    if (itr1 != row.end()) index_Min = distance(row.begin(), itr1);
    if (itr3 != row.end()) index_Max = distance(row.begin(), itr3);


    if (itr1 > itr3) {
        for (vector<int>::iterator i = itr3+1; i != itr1; i++ ) {
 
            if (*i > *itr3 || *i < *itr1) return false; 
        }
    } else {   

        for (vector<int>::iterator i = itr1+1; i != itr3; i++ ) {
           if (*i > *itr3 || *i < *itr1) return false; 
        }
    }
    
    if (itr1 > itr3)
        load.push_back(new range(itr3, itr1))

    load.push_back(new range(itr1, itr3))

    return true;
}

int main() {

int n, m;
cin >> n;
cin >> m;
 
int arr[n];
for (int i=0; i < n; i++) {
    int tmp;
    cin >> tmp;
    row.push_back(tmp);
    arr[i] = tmp;
}


for (int i=0; i < m; i++) {
    int op, cmd1, cmd2;
    cin >> op;
    cin >> cmd1;
    cin >> cmd2;

    if (op == 1) op1(cmd1-1, cmd2-1);
    if (op == 2) {
        if (op2(cmd1, cmd2, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

return 0;
}
