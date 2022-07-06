/**
* user:  VR445195
* fname: ALESSANDRO
* lname: BATTISTOLLI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 12:55:17.144459
*/
#include <iostream>


int g,n,k;
int position=0;

void combinations(int n,int k, int comb,int position, int value){
	int tmp=position;
	int tmp2 = value;
	if(position==n){ // questo è lo 0 iniziale
		combinations(n,k,comb,--tmp,value);
		}
		
		
	if(tmp!=1){
		if((value==0)){
			combinations(n,k,comb,--tmp, tmp2);
			tmp=position;
			}
		if(value>0){
			combinations(n,k,comb,--tmp,--tmp2);
			tmp=position;
			tmp2=value;
			}
		if((value+k)<position-1){
			combinations(n,k,comb,--tmp,tmp2 +k);
			tmp=position;
			tmp2=value;	
			}
		
		}
	else{ //questo è lo 0 finale
		comb++;
		return;
		}	
	return;
	}


int main(){
	int value=0;
	std::cin >> g;
	std::cin >> n;
	std::cin >> k;
	position=n;
	int combinazioni=0;
	int& refComb=combinazioni;
	if(g==1){
		combinations(n,k,refComb,position,value);
		}
	std::cout << refComb;
	}
