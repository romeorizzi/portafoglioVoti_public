/**
* user:  VR450538_id965iel
* fname: ANDREA
* lname: AVOGARO
* task:  turniPFG-2DAGs
* score: 30.0
* date:  2021-02-12 12:42:55.404125
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

int people_used = 0;
int external = 0;


void solve(int k,set<tuple<int,int>> days_interval){
    for(int day = 0; day < k; day++){

        bool found = false;

        tuple<int,int> max_interval_day = make_tuple(0,0);

        for(tuple<int,int> days : days_interval){

            if(get<0>(days) <= day){
                if(get<1>(max_interval_day) - day < get<1>(days) - day && get<1>(days) > day){
                    max_interval_day = days;
                    found = true;
                }
            }
        }

        if(!found){
            external++;
            continue;
        }
        else{
            people_used++;
            day = get<1>(max_interval_day);
            days_interval.erase(max_interval_day);
        }
    }
}


int main() {

    int t,n,k;

    //fetching input data from stdin
    cin>>t;
    cin>>k;
    cin>>n;
    int a,b;
    set<tuple<int,int>> days_interval;

    for(int i = 0; i < n; i++) {

        cin>>a>>b;
        days_interval.insert(make_tuple(a,b));
    }

    solve(k, days_interval);

    if(t == 0) {
        cout<<external;
    }
    else
    {
        cout<<people_used;
    }

    return 0;
}