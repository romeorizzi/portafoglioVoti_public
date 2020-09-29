/**
* user:  VR451060_id716xls
* fname: NICHOLAS
* lname: CARON
* task:  risparmio
* score: 23.0
* date:  2020-07-14 11:44:18.301812
*/
#include <iostream>
#include <vector>

using namespace std;

int count(vector<bool>& ls, int q, int p) {
    bool range = ls[q];
    int count = range;
    
    for(++q; q <= p; ++q) {
        if(ls[q]!=ls[q-1]) {
            range = !range;
            count += range;
        }
        
    }
    
    return count;
}



int main() {
	
	
    int luci, operations;
    cin >> luci >> operations;
    vector<bool> ls(luci, false);

    for(int k = 0; k<operations; ++k) {
        int op;
        cin >> op;
        
        if(op == 1) {
            int where;
            cin >> where;
            ls[where] = !ls[where];
        }
        
        else {
            int q, p;
            cin >> q >> p;
            cout << count(ls, q, p) << endl;
        }
    }
    
    
    return 0;
}
