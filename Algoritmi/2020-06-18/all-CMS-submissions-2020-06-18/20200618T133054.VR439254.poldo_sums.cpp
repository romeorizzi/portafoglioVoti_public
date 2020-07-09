/**
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 13:30:54.654311
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> panino;
vector<int> gym;
vector<int> s;


bool check(int index){
    int sum = 0;
    for(int i=s[index-1]; i<=s[index]-1; i++)
        sum += gym[i];
    
    // cout << "## " << panino[s[index]] << " >= " << panino[s[index-1]] << " + " << sum << endl;
    return panino[index] >= (panino[index-1] + sum);
}

int main(){
    int N;
    int p,g;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> p;
        cin >> g;
        panino.push_back(p);
        gym.push_back(g);
    }
    
    s.push_back(0);
    for (int i = 1; i < panino.size(); i++){
        if(check(i))
            s.push_back(i);
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    
    return 0;
}