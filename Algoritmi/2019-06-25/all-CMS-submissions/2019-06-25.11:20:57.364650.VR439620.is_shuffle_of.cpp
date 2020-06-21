/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  is_shuffle_of
* score: 0.0
* date:  2019-06-25 11:20:57.364650
*/
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int M[1000];
    int N[1000];
    int S[2000];
    int m,n,t;
    input >> m >> n >> t;
    for(int i = 0;i < m; i++)
    {
        input >> M[i];
    }
    for(int i = 0;i < n; i++)
    {
        input >> N[i];
    }
    int pm = 0,pn = 0;
    bool correct = true;
    int val;
    for(int i = 0;i < m+n; i++)
    {
        input >> val;
        if(pm < m && val == M[pm])
        {
            S[i] = 0;
            pm++;
        }
        else if(pn < n && val == N[pn])
        {
            S[i] = 1;
            pn++;
        }
        else
            correct = false;
    }
    output << correct << endl;
    if (t == 1 && correct == true)
    {
        for(int i = 0;i < m+n; i++)
            output << S[i] << " ";  
        output << endl;
    }
    return 0;
}
