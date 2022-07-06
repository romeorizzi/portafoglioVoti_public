/**
* user:  VR445195
* fname: ALESSANDRO
* lname: BATTISTOLLI
* task:  A_seq
* score: 13.0
* date:  2022-06-29 11:22:19.541557
*/
#include <iostream>




const int MAX_N=10000;
const int paths=50000;
//int sequence[MAX_N+2]={0};

int sequence[MAX_N+2]={0};
int lunghezza[MAX_N+2][paths]={0};



int check(int sequenza[MAX_N+2], int index, int length,int start,bool down, int& position,int size){
	int tmp=length;
	
	for(int i=index+1;i<size;i++){
			if(sequenza[index]<sequenza[i] && down!=true){
				lunghezza[start][position] = tmp+1;
				check(sequenza,i, ++tmp,start, false, ++position,size);
				tmp=length;
				}
			if(sequenza[index]>sequenza[i]){
				lunghezza[start][position] = tmp+1;
				check(sequenza,i,++tmp, start, true,++position,size);
				tmp=length;
			}
		}
	
	
	
	
	return 0;
	}




int main(){
	int g=0;
	int n=8;
	std::cin >> g;
	std::cin >> n;
	for(int i=0;i<n;i++){
		std::cin >> sequence[i];
		}
	
	int best=0;
	int n_best=1;
	int indice=0;
    int& posizione = indice;
	
	for(int i=0;i<n;i++){
			posizione=0;
			check(sequence,i,1,i,false,posizione,n);
			
		}
	for(int j=0;j<n;j++){
		for(int i=0;lunghezza[j][i]!=0 && i<paths;i++){
			
				if(best==lunghezza[j][i]){
						n_best++;
					}
				if(best<lunghezza[j][i]){
						best=lunghezza[j][i];
					}
		}
	}
	if(g==1){
		std::cout << best;
		return 0;
		}
		
	n_best=n_best%1000000007;
	
	if(g==2){
		std::cout << (n_best);
		return 0;
		}
	
	
	return 0;
}
