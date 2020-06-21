/**
* user:  VR420921
* fname: AGRILLO
* lname: ENRICO CARLO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:52:59.764866
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
   
    int tot = abs(h1 - h2);

    cout << "tot: " << tot << endl;
    for (int i = 0; i < N; i++) {
        cout << nani[i];
    }

    cout <<""<< endl;

    for (int i = 0; i < N - tot; i++)
    {

        cout << "i: " << i << endl;

        if (nani[i] >= h1 && nani[i] <= h2)
        {
            int sum = 0;
            int j = 0;
            int x = i;
            int modulo;
            while (j <= tot)
            {
                cout << "x: " << x << endl;
                if (nani[x] % h2 >= h1 || nani[x] % h2 == 0)
                    sum++;
                modulo = nani[x] % h2;
                cout << "modulo: " << nani[x] << "%" << h2 << "=" << modulo << endl;
                cout << "sum: " << sum << endl;
                x++;
                j++;
            }
            if (sum == tot + 1) return true;
        }

    }

    return false;
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
