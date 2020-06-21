/**
* user:  VR439620
* fname: MOLINARI
* lname: DAVIDE
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:07:18.839908
*/
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

int sequenzaNani[200000];
int posizioniNani[200000];

struct query
{
    long int tipo,par1,par2;  
};

void SpostaNani(long int p1,long  int p2)
{
    posizioniNani[sequenzaNani[p2]] = p1;
    posizioniNani[sequenzaNani[p1]] = p2;
}
bool ControllaAltezze(long int h1,long int h2, int N)
{
    int maxH = max(h1,h2);
    int minH = min(h1,h2);
    int start = min(posizioniNani[h1],posizioniNani[h2]);
    int fine = max(posizioniNani[h1],posizioniNani[h2]);
    for(int h = 1;h <= N;h++)
    {
        if(posizioniNani[h] >= start && posizioniNani[h] <= fine && (h < minH || h > maxH ))
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fstream in;
    int M,N,tipo,par1,par2;
    bool ok;
    query richieste[200000];
    in.open("att/input0.txt",ios::in);
    //in.open("input.txt",ios::in);
    in >> N >> M;
    for (int i = 0; i < N; i++)
    {
        in >> sequenzaNani[i];
        posizioniNani[sequenzaNani[i]] = i;
    }
    
    for (int i = 0; i < M; i++)
    {
        in >> richieste[i].tipo >> richieste[i].par1 >> richieste[i].par2;
    }
    for (int i = 0; i < M; i++)
    {
        if (richieste[i].tipo == 1)
            SpostaNani(richieste[i].par1-1,richieste[i].par2-1);
        else{
            ok = ControllaAltezze(richieste[i].par1,richieste[i].par2,N);
            if(ok == true)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
