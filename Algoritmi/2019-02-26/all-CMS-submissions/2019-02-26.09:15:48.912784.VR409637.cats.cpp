/**
* user:  VR409637
* fname: GERMINIANI
* lname: SAMUELE
* task:  cats
* score: 20.0
* date:  2019-02-26 09:15:48.912784
*/
#include <bits/stdc++.h>

#define MAXN 1000

long long int scoreMatrix[MAXN][MAXN];
long long int mLove[MAXN];
long long int fLove[MAXN];
long long int m_count=0;
long long int f_count=0;
long long int dp[MAXN][MAXN];


long long int max3(long long int e1,long long int e2,long long int e3){
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

	for(long long int i=0;i<m_count;i++){
		cin>>mLove[i];
	}
	for(long long int i=0;i<f_count;i++){
		cin>>fLove[i];
	}

	//load score matrix
	for(long long int i=0;i<m_count;i++){
		for(long long int j=0;j<f_count;j++){
			scoreMatrix[i][j]=abs(mLove[i]-fLove[j]);
		}
	}


	/*
	for(long long int i=0;i<m_count;i++){
		for(long long int j=0;j<f_count;j++){
			std::cout<<scoreMatrix[i][j]<<" ";
		}
			std::cout<<"\n";
	}
			std::cout<<"\n";
			*/


	for(long long int i=1;i<=m_count;i++){
		for(long long int j=1;j<=f_count;j++){
			dp[i][j]= max3(dp[i-1][j-1]+scoreMatrix[i-1][j-1],dp[i-1][j],dp[i][j-1]);
		}
	}

	/*
	for(long long int i=0;i<=m_count;i++){
		for(long long int j=0;j<=f_count;j++){
			std::cout<<dp[i][j]<<" ";
		}
			std::cout<<"\n";
	}
			std::cout<<"\n";
			*/

	cout<<dp[m_count][f_count]<<"\n";



	return 0;

}
