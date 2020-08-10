/**
* user:  VR439318_id057zkp
* fname: GIANLUCA
* lname: PAVAN
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:29:32.814111
*/
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

#define MAXN 100000
#define MAXM 200000
std::set<string> tot;
int N,M;
int m,n,p;
int costi[MAXN];
string a,b;


void f1(string out){
    string copy = out;
    // ciclo sulla posizione nella stringa
    for(int i=0; i<out.length(); i++){
        // cout << "*** i *** " << i << endl;
        //ciclo su quanti * mettere
        for(int j=1; j<=m-out.length()+1; j++){
            // cout << "  * j *   " << j << endl;
            out.insert(i,j, '*');
            if(out.length() == m+1){
                // cout << out <<endl;
                tot.insert(out);
            }
            f1(out);
            out = copy;
        }
        
    }

}

int is_comp(char c1, char c2){
    if(c1==c2 || c1 == '*' || c2 == '*')
        return 1;
    else
        return 0;
}

int calcola_costo(string s){
    int segmenti[s.length()-1];
    for(int i=0; i<s.length(); i++)
        segmenti[i]=0;
    bool dentro = false;
    int index = 0;

    for(int i=0; i<s.length()-1; i++){
        if(s[i] == '*' && dentro ){
            // cout << "primo caso: "<< s[i] <<endl;
            segmenti[index]++;
        }
        else if(s[i] == '*' && !dentro ){
            // cout << "secondo caso: " << s[i] << endl;
            dentro = true;
            segmenti[index]++;
        }
        else if(s[i] != '*' && dentro ){
            // cout << "terzo caso"<< endl;
            dentro = false;
            index++;
        }
        else if(s[i] == '*' && !dentro ){
            // cout << "quarto caso"<< endl;
        }
    }
    int costo = 0;
    for(int i=0; i<s.length(); i++){
        costo+=costi[segmenti[i]];
        // cout << costi[segmenti[i]] << " ";
    }
        
    // cout << endl;

    return costo;
}

int main(){

    // assert( freopen("input.txt", "r", stdin) );
    
    scanf("%d%d%d\n",&m,&n,&p);
    
    getline(cin,a);
    getline(cin,b);
    
    for(int i=0; i<=p; i++)
        cin >> costi[i];

    string out = b;
    f1(out);
    
    for(auto const& s: tot){
        // cout << s <<endl;
        for(int i=0; i<m; i++){
            // cout << s[i] << endl;
            if(is_comp(s[i], a[i]) == 0){
                tot.erase(s);
                break;
            }
        }
    }
    int costo = 0;
    int min = 200000;
    for(auto const& s: tot){
        // cout << s <<endl;
        
        costo = calcola_costo(s);
        // cout << costo << endl;
        if(costo < min)
            min = costo;
    }
    if(min == 200000)
        cout << -1 << endl;
    else
        cout << min <<  endl;
    



}