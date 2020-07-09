/**
* user:  VR439254
* fname: TOAIARI
* lname: ANDREA
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:59:52.260407
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
    
    cout << "## " << panino[s[index]] << " >= " << panino[s[index-1]] << " + " << sum << endl;
    return panino[s[index]] >= (panino[s[index-1]] + sum);
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

    // printf("Panino\n");
    // for(int i=0; i<N; i++){
    //     cout << panino[i] << " ";
    // }
    
    // printf("\nGym\n");
    // for(int i=0; i<N; i++){
    //     cout << gym[i] << " ";
    // }
    
    for (int i = 0; i < panino.size(); i++){
        if(check(i))
            s.push_back(i);
    }
    
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    

    // cout << endl;
    // for(int i=0; i<s.size(); i++){
    //     printf("%s ", check(i) ? "true" : "false"); 
    //     cout << endl;
    // }
    return 0;
}