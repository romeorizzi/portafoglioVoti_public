/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  turniPFG-2DAGs
* score: 0.0
* date:  2021-02-12 09:53:56.556677
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>


using namespace std;

int t,k,n;

void T0(set<tuple<int,int>> graph_arcs) {
    vector <int> node_grade = vector<int>(k+1, 0);

    for(tuple<int,int> arc : graph_arcs) {
        node_grade[get<0>(arc)]++;
        node_grade[get<1>(arc)]++;
    }

    int count = 0;

    for (int grade : node_grade) {
        if(grade == 0) {
            count++;
        }
    }
    cout<<count;
}

void T1(set<tuple<int,int>> graph_arcs) {

    vector <int> node_grade = vector<int>(k+1, 0);

    for(tuple<int,int> arc : graph_arcs) {
        node_grade[get<0>(arc)]++;
        node_grade[get<1>(arc)]++;
    }

    int max_grade = 0;

    for (int grade : node_grade) {
        if(grade > max_grade) {
            max_grade = grade;
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
    set<tuple<int,int>> graph_arcs;

    for(int i = 0; i < n; i++) {
        cin>>a>>b;
        for(int step = a; step <= b; step++){
            if(step != b){
                graph_arcs.insert(make_tuple(step,step+1));
            }
            else{
                graph_arcs.insert(make_tuple(step,a));
            }
            if(b - a == 1){
                break;
            }
        }
    }


    if(t == 0) {
        T0(graph_arcs);
    }
    else
    {
        T1(graph_arcs);
    }

    return 0;
}