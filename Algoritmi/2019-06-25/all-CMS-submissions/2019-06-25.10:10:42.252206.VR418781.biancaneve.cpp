/**
* user:  VR418781
* fname: BRENTEGANI
* lname: MATTEO
* task:  biancaneve
* score: 10.0
* date:  2019-06-25 10:10:42.252206
*/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> row;

void op1(int p1, int p2) {
    int tmp;
    tmp = row.at(p1);
    row.at(p1) = row.at(p2);
    row.at(p2) = tmp;
}

bool op2(int cmd1, int cmd2, int n) {
    int index_Min;
    int index_Max;
    int index;
    vector<int>::iterator itr1 = row.begin();
    vector<int>::iterator itr2 = row.begin();
    vector<int>::iterator itr3 = row.begin();

    itr1 = find(row.begin(), row.end(), cmd1);
    itr3 = find(row.begin(), row.end(), cmd2);
    if (itr1 != row.end()) index_Min = distance(row.begin(), itr1);
    if (itr3 != row.end()) index_Max = distance(row.begin(), itr3);

    int arr[abs(index_Max-index_Min)];

    for(int i =0; i < abs(index_Max-index_Min); i++) {
        arr[i] = row.at(i);
    } 


    if (cmd2+1 <= n) {

        if (index_Min > index_Max) {

            itr2 = find(itr3, itr1, cmd2+1);

            if (itr2 != itr1) index = distance(row.begin(), itr2);
            if(index_Min > index && index > index_Max) return false;
                    
        }
        if (index_Min < index_Max) {
    
            itr2 = find(itr1, itr3, cmd2+1);

            if (itr2 != itr3) index = distance(row.begin(), itr2);

            if(index_Min < index && index < index_Max) return false; 
        
        }
    }

    if (cmd1-1 >= 1) {


        if (index_Min > index_Max) {
            itr2 = find(itr3, itr1, cmd1-1);

            if (itr2 != itr1) index = distance(row.begin(), itr2);
            if(index_Min > index && index > index_Max) return false;
        }        
        if (index_Min < index_Max) {
            
            itr2 = find(itr1, itr3, cmd1-1);

            if (itr2 != itr3) index = distance(row.begin(), itr2);
            if(index_Min < index && index < index_Max) return false;
        }       
    }
  
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
