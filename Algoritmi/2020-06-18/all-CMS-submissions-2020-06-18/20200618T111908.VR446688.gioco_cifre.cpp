/**
* user:  VR446688
* fname: LUTTERI
* lname: NICOLO
* task:  gioco_cifre
* score: 0.0
* date:  2020-06-18 11:19:08.976012
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
    if (numero > 0 && numero <= 9)
    {
        return numero;
    }
    if (numero % 10 == 0)
    {
        return -1;
    }

    string s = to_string(numero);

    int cifra = s[s.size() - 1] - '0';

    if (cifra > 0 && cifra <= 9)
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
    //freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &numero);

    int v;

    for (int i = 0; i < 100; i++)
    {
        numero = i;
        v = calcola();
        cout << v << endl;
    }
    
    if (v == -1)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << "1 " + to_string(v) << endl;
    }
}
