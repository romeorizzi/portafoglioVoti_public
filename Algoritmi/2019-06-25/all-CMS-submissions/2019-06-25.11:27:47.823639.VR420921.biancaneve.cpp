/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  biancaneve
* score: 10.0
* date:  2019-06-25 11:27:47.823639
*/
#include <bits/stdc++.h>

using namespace std;

int N = 0; //nani
int M = 0; //richieste
vector<int> nani;

void switch_pos(int p1, int p2)
{
 
    int tmp;
    tmp = nani[p1-1];
    nani[p1-1] = nani[p2-1];
    nani[p2-1] = tmp;

}

bool check(int h1, int h2)
{
    int min, max, index;
    vector<int>::iterator itr1 = nani.begin();
    vector<int>::iterator itr2 = nani.begin();

    itr1 = find(nani.begin(), nani.end(), h1);
    itr2 = find(nani.begin(), nani.end(), h2);

    if (itr1 != nani.end()) 
    {
        min = distance(nani.begin(), itr1);
    }
    if (itr2 != nani.end())
    {
        max = distance(nani.begin(), itr2);
    }

    if (itr1 > itr2) 
    {
        for (vector<int>::iterator i = itr2+1; i != itr1; i++) {
            if(*i > *itr2 || *i < *itr1)
                return false;
        }
    }
    else {
        for (vector<int>::iterator i = itr1+1; i != itr2; i++) {
            if(*i > *itr2 || *i < *itr1)
                return false;
        }
    }

    return true;

}

int main() {

//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

cin >> N; //leggo il numero di nani

cin >> M; //leggo # di istruzioni


for (int i = 0; i < N; i++) //leggo la disp. dei nani
{
    int tmp;
    cin >> tmp;
    nani.push_back(tmp);
}

for (int i = 0; i < M; i++) //leggo le istr
{
    int istr, par1, par2;
    cin >> istr;
    cin >> par1;
    cin >> par2;
    
    if (istr == 1)
    {
        switch_pos(par1, par2);
    }

    if (istr == 2)
    {
        if (check(par1, par2)) 
        {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    
}


return 0;

}
