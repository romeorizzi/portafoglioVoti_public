/**
* user:  VR457796_id572ecb
* fname: FRANCESCO
* lname: CECCONELLO
* task:  hanoi_with_toddler
* score: 0.0
* date:  2021-06-22 10:09:14.157221
*/
#include <iostream>
using namespace std;
ofstream fcout("output.txt");

void hanoi(int num_disks,char inizio, char fine,char ausiliario)
{ 
	if(n==1)
	{
		fcout<<"daddy "<<"muove il disco "<<num_disks<<" dal piolo "<<inzio<<" al piolo "<<fine<<endl;
		return;
	}
	
	hanoi(num_disks-1,inizio,fine,ausiliario);
	fcout<<"toddler "<<"muove il disco "<<num_disks<<" dal piolo "<<inzio<<" al piolo "<<fine<<endl;
	hanoi(num_disks-1,inizio,fine,ausiliario);
}

int main()
{ 
	int t;
    cin >> t;
    int disks;
	cin >> disks;
	hanoi(disks,'A','C','B');
	if(t==0){
		cout << cont << endl;
	}
	return 0;
}
