/**
* user:  VR445195
* fname: ALESSANDRO
* lname: BATTISTOLLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 12:06:12.329602
*/
#include <iostream>




const int MAX_N=10000;
const int paths=50000;
//int sequence[MAX_N+2]={0};

int sequence[MAX_N+2]={0};
int lunghezza[MAX_N+2][paths]={0};
int best=0;
int g=0;
int n=0;

int check(int sequenza[MAX_N+2], int index, int length,int start,bool down, int position[n]){
	int tmp=length;
	
	for(int i=index+1;i<n;i++){
			if(sequenza[index]<sequenza[i] && down!=true){
				check(sequenza,i, ++tmp,start, false, position);
				check(sequenza,i,1,i,false,position);
				tmp=length;
				}
			if(sequenza[index]>sequenza[i]){
				check(sequenza,i,++tmp, start, true,position);
				check(sequenza,i,1,i,false,position);
				tmp=length;
			}
		}
	
	lunghezza[start][position]=tmp;
	if(lunghezza[start][position]>best){
			best=lunghezza[start][position];
		}
	position[start]++;
	
	
	return 0;
	}




int main(){
	std::cin >> g;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::cin >> sequence[i];
		}
	
	int n_best=0;
	int indice=0;
    int& posizione = indice;
	int posizioni[n]={0};
	
	check(sequence,0,1,0,false,posizione);
			
	/*
	for(int j=0;j<n;j++){
		for(int i=0;lunghezza[j][i]!=0 && i<paths;i++){
			
				if(best<lunghezza[j][i]){
						best=lunghezza[j][i];
					}
		}
	}*/
	if(g==2){
		for(int j=0;j<n;j++){
		for(int i=0;lunghezza[j][i]!=0 && i<paths;i++){
			
				if(best==lunghezza[j][i]){
						n_best++;
					}
		}
	}
		
		}
	if(g==1){
		std::cout << best;
	
		}
	
	n_best=n_best%1000000007;
	
	if(g==2){
		std::cout << (n_best);
		
		}
	
	
	return 0;
}
