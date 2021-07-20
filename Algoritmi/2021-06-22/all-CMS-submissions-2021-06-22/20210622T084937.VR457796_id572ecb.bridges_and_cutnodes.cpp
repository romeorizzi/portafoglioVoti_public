/**
* user:  VR457796_id572ecb
* fname: FRANCESCO
* lname: CECCONELLO
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 08:49:37.123323
*/
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;
ofstream fcout("output.txt");

//tower of HANOI function implementation
void TOH(int n,char Sour, char Aux,char Des)
{ 
	if(n==1)
	{
		fcout<<"daddy "<<"muove il disco "<<n<<" dal piolo "<<Sour<<" al piolo "<<Des<<endl;
		return;
	}
	
	TOH(n-1,Sour,Des,Aux);
	fcout<<"toddler "<<"muove il disco "<<n<<" dal piolo "<<Sour<<" al piolo "<<Des<<endl;
	TOH(n-1,Aux,Sour,Des);
}

//main program
int main()
{ 
	int t;
    cin >> t;
    int disks;
	cin >> disks;
	//calling the TOH 
	TOH(disks,'A','B','C');
	
	return 0;
}