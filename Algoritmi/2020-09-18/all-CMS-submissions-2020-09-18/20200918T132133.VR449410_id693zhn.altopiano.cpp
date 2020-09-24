/**
* user:  VR449410_id693zhn
* fname: ANDREA
* lname: MULTINEDDU
* task:  altopiano
* score: 0.0
* date:  2020-09-18 13:21:33.442805
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;


const int min = numeric_limits<int>::min();


int potenza2_prossima(int N) { //restituisce la potenza di 2 successiva o N se N = 2 ^ n
    int esp = -1;
    int n = N;
    
    while(n != 0)
	{
        n /= 2;
		esp++;
    }
    if(N ^ (1 << esp) != 0)
		esp++;
    
	return 1 << esp;
}

vector<int> albero(vector<int>& percorso, int altezze)
{
    vector<int> tree;
    queue<int> q;
    int n = potenza2_prossima(altezze);
	
	
    for(int i = n - 1; i >= 0; i--)
	{
        int h = percorso[i]
		if (i < altezze)
			h = min;
        
        q.push(h);
        tree.push_back(h);
    }
    
    while(q.size() != 1)
	{
        int l = q.front();
        q.pop();
        
        int r = q.front();
        q.pop();
        
        int h = max(l, r);
        q.push(h);
        
        tree.push_back(h);
    }
    
    reverse(tree.begin(), tree.end());
    return tree;
}

int massimo(vector<int>& tree, int id, int l, int r, int a, int b)
{
    if (r <= a || l >= b)
        return min;

    if (l >= a && r <= b)
        return tree[id - 1];

    int meta = (l + r) / 2;

    return max(massimo(tree, 2 * id, l, meta, a, b), massimo(tree, 2 * id + 1, meta, r, a, b));
}

void aggiorna(vector<int>& tree, int id, int l, int r, int x, int y) {
    if(r <= x || l > x)
        return;

    if(r > l + 1) {
        int meta = (l + r) / 2;

        aggiorna(tree, 2 * id, l, meta, x, y);
        aggiorna(tree, 2 * id + 1, meta, r, x, y);

        tree[id-1] = max(tree[2 * id - 1], tree[2 * id]);
    }
    else
        tree[id - 1] = y;
}



int main() {
    int altezze, operazioni;
    cin >> altezze >> operazioni;
    
    vector<int> cammino(altezze);
    for(int i = 0; i < altezze; i++) {
        cin >> cammino[i];
    }
    
    vector<int> altopiano(altezze, min);
    for(int i = 1; i < altezze - 1; i++) {
        if(cammino[i - 1] == cammino[i] && cammino[i] == cammino[i + 1])
            altopiano[i] = cammino[i];
            
            
    vector<int> tree = albero(altopiano, altezze);
    for(int i=0; i<operazioni; ++i)
	{
    	int op, x, y;
        cin >> op >> x >> y;
        
        if(op == 1)
		{
            cammino[x] += y;
            if(x - 2 >= 0)
			{
                if(cammino[x-2]==cammino[x-1] && cammino[x-1]==cammino[x])
				    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x-1, cammino[x-1]);
                else
                    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x-1, min);
            }
            
			if(x - 1 >= 0 && x + 1 < altezze)
			{
                if(cammino[x - 1] == cammino[x] && cammino[x]==cammino[x + 1])
                    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x, cammino[x]);
                else
                    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x, min);
            }
            
            if(x + 2 < altezze)
                if(cammino[x] == cammino[x + 1] && cammino[x + 1] == cammino[x + 2])
                    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x + 1, cammino[x + 1]);
                else
                    aggiorna(tree, 1, 0, potenza2_prossima(altezze), x + 1, min);
            }
        }
        else {
            if(cammino[x] == cammino[x + 1])
				x++;
            
            if(cammino[y] == cammino[y - 1])
				y--;
            
			int maximum = massimo(tree, 1, 0, potenza2_prossima(altezze), x, y + 1); 
            if(maximum == min)
                cout << "NESSUN_ALTOPIANO" << endl;
            else
                cout << maximum << endl;
        }
    }
    return 0;
}
