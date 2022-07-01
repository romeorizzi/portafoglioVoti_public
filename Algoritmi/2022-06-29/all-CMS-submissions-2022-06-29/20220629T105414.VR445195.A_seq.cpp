/**
* user:  VR445195
* fname: ALESSANDRO
* lname: BATTISTOLLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:54:14.735145
*/
#include <iostream>




const int MAX_N=10000;
const int paths=10000;
//int sequence[MAX_N+2]={0};

int sequence[MAX_N+2]={0};
int n_sequence_length[MAX_N+2]={0};
int lunghezza[MAX_N+2][paths]={0};
int n;



int check(int sequenza[MAX_N+2], int index, int length,int start,bool down, int& position){
	int tmp=length;
	
	for(int i=index+1;i<n+1;i++){
			
			if(sequenza[index]<sequenza[i] && down!=true){
				lunghezza[start][position] = tmp+1;
				check(sequenza,i, ++tmp,start, false, ++position);
				tmp=length;
				}
			if(sequenza[index]>sequenza[i]){
				lunghezza[start][position] = tmp+1;
				check(sequenza,i,++tmp, start, true,++position);
				tmp=length;
			}
		}
	
	
	
	
	return 0;
	}




int main(){
	int g=0;
	int n=0;
	std::cin >> g;
	std::cin >> n;
	sequence[0]=-1;
	for(int i=1;i<n+1;i++){
		std::cin >> sequence[i];
		}
	sequence[n+1]=-1;
	
	int best=0;
	int n_best=1;
	int indice=0;
    int& posizione = indice;
	
	for(int i=1;i<n+1;i++){
			posizione=0;
			check(sequence,i,1,i,false,posizione);
			
		}
	for(int j=1;j<n+1;j++){
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
		}
	if(g==2){
		std::cout << n_best%1000000007;
		}
	
	
	return 0;
}
