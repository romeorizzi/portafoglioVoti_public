/**
* user:  VR436720
* fname: BERTI
* lname: MARCO
* task:  poldo_sums
* score: 59.0
* date:  2020-06-18 11:13:42.294313
*/
/*
	www.valcon.it
	OII - Fase territoriale - La dieta di Poldo
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define PMAX 10000
using namespace std;

struct nodo
{
	nodo* padre;
	int indice;

	nodo(){};
};

void stampaCode(nodo * figlio, FILE* fout) {
	if (figlio->padre == nullptr)
		fprintf(fout, "%d ", figlio->indice);
	else {
		stampaCode(figlio->padre, fout);
		fprintf(fout, "%d ", figlio->indice);
	}
} 

int sommatoria(int form, int to, int palestra[PMAX]) {
	int sum = 0;
	//cout << "DEBUG: from-> " << form << " to-> " << to << "\t"; 
	for(int i = form; i < to; i++){
		//cout << "\t palestra[" << i << "]: " << palestra[i] << "\n";
		sum += palestra[i];
	}
	// cout << "sum = " << sum;
	return sum;
}
 
int pesi[PMAX];
int palestra[PMAX];
int mangiati[PMAX]; 
nodo lista[PMAX];
int main()
{

	FILE* fin =fopen("input.txt","r");
	FILE* fout=fopen("output.txt","w");
 
	int N;	
	fscanf(fin, "%d", &N);
	for(int i=0; i < N; i++){
	    fscanf(fin, "%d %d", &(pesi[i]), &(palestra[i]));
		//lista[i].palestra = palestra[i];
		lista[i].indice = i;
	}

	for (int i = 0; i < N; i++)
	{
		//cout << "palestra[" << i << "] " << palestra[i]<<"\n";
	}
	
	//cout << "\n \n \n";
	

 
	for(int i=0; i < N; i++)
	    mangiati[i]=1;

	for(int i=0  ; i < N-1; i++)
	    for(int j=i+1; j < N  ; j++){
			
			int somma = sommatoria(i, j, palestra);
			//cout << "" << pesi[j] << " >= " << pesi[i] << " + " << somma; 
		    if(pesi[j] >= (pesi[i] + somma) && mangiati[i] >= mangiati[j]) {
		        mangiati[j]=mangiati[i]+1;
				lista[j].padre = &lista[i];
				//cout << " PRESO\n";
				}
				//cout << " SCARTATO\n";
		}

	int massimo = 0;
	for(int i=1; i < N; i++)
		if(mangiati[i] > mangiati[massimo])
			massimo=i;

	fprintf(fout, "%d\n", mangiati[massimo]);
	stampaCode(&lista[massimo], fout);	

	return 0;
}