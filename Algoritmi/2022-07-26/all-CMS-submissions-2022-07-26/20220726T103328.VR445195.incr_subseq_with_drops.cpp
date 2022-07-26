/**
* user:  VR445195
* fname: ALESSANDRO
* lname: BATTISTOLLI
* task:  esameincr_subseq_with_drops
* score: 40.0
* date:  2022-07-26 10:33:28.817251
*/
#include <iostream>


const int MAX_N=100;
int sequence[MAX_N+2]={0};
int highest=-1;
int longest_sequence=0;
int actual_sequence=0;
int index_sequence=0;
int all_lengths[40000]={0};
int n_max=0;
int g=0;
int n=0;
int k=0;



void long_road(int crolli_ammessi, int index, int length, int high){
	
	int temp=0;
	int temp2=0;
	
	
	
	
	for(int j=index;j<n+1;j++){
			
			if(sequence[j]>high){
					temp=j;
					long_road(crolli_ammessi,temp+1,length,high);
					
					length++;
					if(length>longest_sequence){
							longest_sequence=length;
						}
					high=sequence[j];
				}
			else{
					if(crolli_ammessi>0){
							length++;
							if(length>longest_sequence){
								longest_sequence=length;
							}
							temp=crolli_ammessi-1;
							temp2=j+1;
							long_road(temp,temp2, length,sequence[j]);
							length--;
						}
				}
			
			}
	if(length==longest_sequence){
		all_lengths[index_sequence]=length;
		index_sequence++;
			}
		
			
	return;
		}

void long_road_g1_kplus(int crolli_ammessi, int index, int length, int high){
	
	int temp=0;
	int temp2=0;
	
	
	
	
	for(int j=index;j<n+1;j++){
			
			if(sequence[j]>high){
					if((n-index)>(longest_sequence-length)){
						temp=j;
						long_road(crolli_ammessi,temp+1,length,high);
					}
					length++;
					if(length>longest_sequence){
							longest_sequence=length;
						}
					high=sequence[j];
				}
			else{
					if(crolli_ammessi>0){
							length++;
							if(length>longest_sequence){
								longest_sequence=length;
							}
							if((n-index)>(longest_sequence-length)){
								temp=crolli_ammessi-1;
								temp2=j+1;
								long_road(temp,temp2, length,sequence[j]);
								length--;
							}
						}
				}
			
			}
	if(length==longest_sequence){
		all_lengths[index_sequence]=length;
		index_sequence++;
			}
		
			
	return;
		}



void long_road_zero_k(int index, int length, int high){
	
	int temp=0;
	
	
	
	
	for(int j=index;j<n+1;j++){
			
			if(sequence[j]>high){
					temp=j;
					long_road_zero_k(temp+1,length,high);
					
					length++;
					if(length>longest_sequence){
							longest_sequence=length;
						}
					high=sequence[j];
				}
			}
	if(length==longest_sequence){
		all_lengths[index_sequence]=length;
		index_sequence++;
			}
		
			
	return;
		}
	
	
int main(){
	std::cin >> g;
	std::cin >> n;
	std::cin >> k;
	for(int i=1;i<n+1;i++){
		std::cin >> sequence[i];
		}
	sequence[n+1]=-1;
	sequence[0]=-1;
	
	if(k==0){
		long_road_zero_k(1,0,-1);
		}else{
			
				long_road(k,1,0,-1);
		}
	
	
	
	
	if(g==1){
		std::cout <<  longest_sequence;
	}	
	if(g==2){
		for(int i=0;i<index_sequence;i++){
			if(all_lengths[i]==longest_sequence){
					n_max++;
				}
			}
		
		std::cout << n_max;
	}
	return 0;
}
