/**
* user:  VR475103
* fname: ALBERTO
* lname: GIRELLI
* task:  A_seq
* score: 48.0
* date:  2022-06-29 13:30:14.052942
*/
#include <iostream>
#define DIM 10000
using namespace std;
int problemNumber;
int length;
int soluzione();
int trovaMassimoInverso(int k);
int trovaMassimo(int k);
int somma[DIM];
int vettoreDec[DIM];
int vettoreCre[DIM];
int vettoreInverso[DIM];
int vet[DIM];
int trovaMassimo(int k);
int main()
{
    cin >> problemNumber;
    cin >> length;
    for(int i=0;i<length;i++)
        cin >> vet[i];

    for(int i=0;i<length;i++)
        vettoreInverso[i]=vet[length-i-1];


    for(int i=length;i>=0; i--)
    {
        vettoreDec[i]= trovaMassimo(i)+1;
        vettoreCre[i]= trovaMassimoInverso(i)+1;
    }


    for(int i=0;i<length;i++)
        somma[i]=vettoreCre[length-i-1]+vettoreDec[i]-1;


    int myMassimo=soluzione();
    int numMassimi=0;

    for(int i=0;i<length;i++)
        if(somma[i]==myMassimo)
            numMassimi=numMassimi+1;



    if(problemNumber==1)
        cout << myMassimo;
    else
        cout << numMassimi%1000000007;

    return 0;
}

int trovaMassimo(int k)
{
    int myMasssimo=0;
    for(int i=k;i<length;i++)
        if(vet[i]<vet[k])
            if(vettoreDec[i]>myMasssimo)
                myMasssimo=vettoreDec[i];
    return myMasssimo;
}

int trovaMassimoInverso(int k)
{
    int myMasssimo=0;
    for(int i=k;i<length;i++)
        if(vettoreInverso[i]<vettoreInverso[k])
            if(vettoreCre[i]>myMasssimo)
                myMasssimo=vettoreCre[i];
    return myMasssimo;
}

int soluzione()
{
    int myMasssimo=0;
    for(int i=0;i<length;i++)
        if(somma[i]>myMasssimo)
            myMasssimo=somma[i];
    return myMasssimo;
}
