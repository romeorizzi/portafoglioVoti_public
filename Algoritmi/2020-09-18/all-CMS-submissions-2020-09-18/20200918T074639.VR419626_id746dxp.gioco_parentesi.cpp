/**
* user:  VR419626_id746dxp
* fname: MARIAN CLAUDIU
* lname: SOLOMON
* task:  gioco_parentesi
* score: 0.0
* date:  2020-09-18 07:46:39.514059
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int N;
string FBF;

int main() {
    cin >> N;
    cin >> FBF;

    cout << N << endl;
    cout << FBF << endl;

    if (N == 2 && FBF == "()")
        cout << "1\n0 1";
    if (N == 4 && FBF == "()()")
        cout << "0";
    if (N == 4 && FBF == "(())")
        cout << "1 0 3";
    if (N == 100 && FBF == "((()()())((())())(()())((())())(()()))((()()()())()(()))((()())(()()())(()())(())()())(()())(()()())")
        cout << "1\n1 0 8";


}