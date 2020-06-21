/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 09:35:00.895896
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

    for (int i = 0; i < N; i++)
    {

        if (disp_nani[i] >= h1-1 && disp_nani[i] <= h2-1)
        {
            
        }

    }



}

int main() {

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

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

    for (int i = 0; i < N; i++) //stampo
    {
        cout << disp_nani[i];
    }
    cout << "" << endl;

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
