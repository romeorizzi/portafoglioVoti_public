/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  gioco_cifre
* score: 40.0
* date:  2020-06-18 10:55:23.733304
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <string>

using namespace std;

#define EVAL
#define DIMMAX 100000

int numero;

int calcola()
{
    string s = to_string(numero);

    if (s == "10")
    {
        return -1;
    }

    int cifra = s[s.size() - 1] - '0';

    if (cifra > 0 && cifra < 9)
    {
        return cifra;
    }
    else
    {
        return -1;
    }
}

int main()
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &numero);

    int v = calcola();

    if (v == -1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "1 " + to_string(v) << endl;
    }
}
