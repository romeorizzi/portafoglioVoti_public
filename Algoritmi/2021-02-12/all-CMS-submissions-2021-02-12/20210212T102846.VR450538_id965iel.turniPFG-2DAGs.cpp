/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  turniPFG-2DAGs
* score: 0.0
* date:  2021-02-12 10:28:46.798811
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <set>


using namespace std;

int k;

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

    int t,n;

    //fetching input data from stdin
    cin>>t;
    cin>>k;
    cin>>n;

    bool found = false;

    int a,b;
    set<tuple<int,int>> graph_arcs;

    for(int i = 0; i < n; i++) {
        cin>>a>>b;
        if(a == 0 && b > k - 1 && t == 1){
            found = true;
        }
        if(b > k - 1){
            b = k - 1;
        }
        if(a > k - 1){
            continue;
        }
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
        if(found){
            cout<<1;
            return 0;
        }
        T1(graph_arcs);
    }

    return 0;
}