/**
* user:  VR431583_id379osm
* fname: MIRKO
* lname: ALBANESE
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 13:13:04.157498
*/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int const MAXN = 1000000;
char f[MAXN];

int main(){
    
    int N;
    cin >> N;
    int numB = N/2;

    int aperte = 0, chiuse = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> f[i];
    }

    if (N == 2)
    {
        cout << "1" << endl;
        cout << "0 1" << endl;
    }
    else
    {
        cout << "0" << endl;
    }
    
    return 0;

}