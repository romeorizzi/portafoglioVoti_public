/**
* user:  VR409637
* fname: GERMINIANI
* lname: SAMUELE
* task:  cats
* score: 100.0
* date:  2019-02-26 09:18:44.328427
*/
#include <bits/stdc++.h>

#define MAXN 1010

int scoreMatrix[MAXN][MAXN];
int mLove[MAXN];
int fLove[MAXN];
int m_count=0;
int f_count=0;
int dp[MAXN][MAXN];


int max3(int e1,int e2,int e3){
	if(e1>e2){
		return e1>e3 ? e1 : e3;
	}
	if(e2>e3){
		return e2;
	}else{
		return e3;
	}

}
int main(){
	using namespace std;
	assert(freopen("input.txt","r",stdin));
#ifdef EVAL
	assert(freopen("output.txt","w",stdout));
#endif




	cin>> m_count;
	cin>> f_count;

	for(int i=0;i<m_count;i++){
		cin>>mLove[i];
	}
	for(int i=0;i<f_count;i++){
		cin>>fLove[i];
	}

	//load score matrix
	for(int i=0;i<m_count;i++){
		for(int j=0;j<f_count;j++){
			scoreMatrix[i][j]=abs(mLove[i]-fLove[j]);
		}
	}


	/*
	for(int i=0;i<m_count;i++){
		for(int j=0;j<f_count;j++){
			std::cout<<scoreMatrix[i][j]<<" ";
		}
			std::cout<<"\n";
	}
			std::cout<<"\n";
			*/


	for(int i=1;i<=m_count;i++){
		for(int j=1;j<=f_count;j++){
			dp[i][j]= max3(dp[i-1][j-1]+scoreMatrix[i-1][j-1],dp[i-1][j],dp[i][j-1]);
		}
	}

	/*
	for(int i=0;i<=m_count;i++){
		for(int j=0;j<=f_count;j++){
			std::cout<<dp[i][j]<<" ";
		}
			std::cout<<"\n";
	}
			std::cout<<"\n";
			*/

	cout<<dp[m_count][f_count]<<"\n";



	return 0;

}
