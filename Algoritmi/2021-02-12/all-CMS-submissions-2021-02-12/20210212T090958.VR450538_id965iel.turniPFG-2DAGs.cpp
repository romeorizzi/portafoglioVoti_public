/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  turniPFG-2DAGs
* score: 0.0
* date:  2021-02-12 09:09:58.766178
*/
#include <iostream>
#include <vector>

using namespace std;


int max_grade;
vector<int> node_grade;
int t,k,n;

void T0() {

}

void T1() {
    for(int node : node_grade) {
        if(node > max_grade) {
            max_grade = node;
        }
    }
    cout<<max_grade;
}

int main() {

    //fetching input data from stdin
    cin>>t;
    cin>>k;
    cin>>n;

    int a,b;

    node_grade = vector<int>(k+1, 0);

    max_grade = 0;

    for(int i = 0; i < n; i++) {
        cin>>a>>b;
        for(int step = a; step <= b; step++){
            node_grade[step]++;
        }
    }

    if(t == 0) {
        T0();
    }
    else
    {
        T1();
    }

    return 0;
}