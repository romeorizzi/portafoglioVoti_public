/**
* user:  VR450936
* fname: MARTINI
* lname: FRANCESCO
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 10:49:07.248228
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
using namespace std;

string N;

int min;


int main() {

    cin >> N;
    if (N[N.size - 1] == '0')
        cout << 0;
    else
        cout << 1 << ' ' << N[N.size - 1];
  
    return 0;


}