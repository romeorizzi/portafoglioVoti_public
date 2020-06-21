/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:20:56.968994
*/
#include <bits/stdc++.h>

using namespace std;

int N = 0; //nani
int M = 0; //richieste
vector<int> disp_nani;

void switch_pos(int p1, int p2)
{
 
    int tmp;
    tmp = disp_nani[p1-1];
    disp_nani[p1-1] = disp_nani[p2-1];
    disp_nani[p2-1] = tmp;

}

bool check(int h1, int h2)
{
    int min, max, index;
    vector<int>::iterator itr1 = disp_nani.begin();
    vector<int>::iterator itr2 = disp_nani.begin();

    itr1 = find(disp_nani.begin(), disp_nani.end(), h1);
    itr2 = find(disp_nani.begin(), disp_nani.end(), h2);

    if (itr1 != disp_nani.end()) min = distance(disp_nani.begin(), itr1);
    if (itr2 != disp_nani.end()) max = distance(disp_nani.begin(), itr2);

    if (itr1 > itr2) 
    {
        for (vector<int>::iterator i = itr2+1; i != itr1; i++) {
            if(*i > *itr2 || *i < *itr1) return false;
        }
    }
    else {
        for (vector<int>::iterator i = itr1+1; i != itr2; i++) {
            if(*i > *itr1 || *i < *itr2) return false;
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
    disp_nani.push_back(tmp);
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
