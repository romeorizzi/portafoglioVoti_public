/**
* user:  VR439483
* fname: MIRKO
* lname: MORATI
* task:  tree_transcode_disc
* score: 0.0
* date:  2019-07-30 11:10:34.905534
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int MAX_N = 1000000;
const int MAX_VAL = 10;

vector<int> stack;

template <class T>
void print_array(T *v, int len) {
  for(int i = 0; i < len; i++)
    cout <<  v[i] << " ";
  cout << endl;
}



void cod1to2(int *nodes, int *sum, int l, int p) {
    static int cur = 1;
    if (sum[p] == nodes[p]) return;
//    cout << "p: " << p << " cur: " << cur << "\t";
//    print_array(sum, l);
    while (sum[p] < nodes[p]) {
        if (cur < l && nodes[cur] > 1) {
            sum[p] += nodes[cur];
            cod1to2(nodes, sum, l, cur++);
        } else if (cur < l) {
            while (nodes[cur] == 1 && sum[p] < nodes[p]) {
//                cout << "p: " << p << " cur: " << cur << "\t";
//                print_array(sum, l);
                if (sum[p] < nodes[p]) {
                    cout << nodes[cur] << " ";                    
                    // cout << "leaf of " << nodes[p] << " -> " << nodes[cur] << "\n";
                    sum[p] += nodes[cur];
                }
                else {
                    
                    break;            
                }
                cur++;
            }
        }
    }
    cout << nodes[p] << " ";
    // cout << p << endl;
}

stringstream ss;

void cod2to1(int *nodes, int *sum, int l, int p) {
    static int cur = 0;
    static int count = 0;
    vector<int> res;
    while (cur < l - 1) {
        if (nodes[cur] == 1) {           
            stack.push_back(1);
        }
        if (nodes[cur] > 1) {
            int pops = nodes[cur] - stack[stack.size() - 1];   
            // cout << "nodes: " << nodes[cur] << " stack: " << stack[stack.size() - 1] << " pops: " << pops << endl;   
            for (int i = 1; i < pops; i++) {       
                res.push_back(1);      
                stack.pop_back();
            }
            res.push_back(nodes[cur]);
            stack.push_back(nodes[cur]);
        }
        cur++;
    }
    for (int i = 1; i < stack.size() - 1; i++) {
        if(stack[i] == 1)
        ss << "1 ";    
    }
    for(int i= 0; i < res.size(); i++)
        ss << res[i] << " ";
    ss << nodes[cur];
}

int main() {
    int t = 0;
    int nodes[MAX_N];
    int l = 0;
    cin >> t;
    for (; cin >> nodes[l]; l++);
    
    int sum[l];
    for (int i = 0; i < l; sum[i++] = 1);

    if (t == 1) {
        cout << "2 ";
        cod1to2(nodes, sum, l, 0);
    }
    else {
        cout << "1 ";
        cod2to1(nodes, sum, l, 0);
    }
    auto str = ss.str();
    for (int i = str.size(); i >= 0; i--) {
    cout << str[i];    
}

    return 0;
}

