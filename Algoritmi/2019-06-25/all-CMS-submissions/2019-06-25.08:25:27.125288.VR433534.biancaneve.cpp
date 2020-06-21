/**
* user:  VR433534
* fname: BRENTAROLLI
* lname: ELIA
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:25:27.125288
*/
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <string>

#define MAXN 200000
#define MAXM 200000


using namespace std;
int main(int argv, char* argc){
    int n,m;
    int Parray[MAXN];
    assert(scanf("%d %d\n",&n,&m)==2);
    int *posArray= new int[n]();
    for(int i=0;i<n;i++){
        assert(scanf("%d",&Parray[i])==1);
        posArray[Parray[i]-1]=i+1;
    }
    int command, start, end, appo;
    int *subarray=new int[n]();
    string answer;
    for(int i=0;i<m;i++){
        assert(scanf("%d %d %d\n",&command, &start,&end)==1);
        if(command==1){
            appo=posArray[Parray[start-1]];
            posArray[Parray[start-1]]=posArray[Parray[end-1]];
            posArray[Parray[end-1]]=appo;

            appo=Parray[start-1];
            Parray[start-1]=Parray[end-1];
            Parray[end-1]=appo;
        }
        else{
            for(int i=start-1;i<end;i++){
                subarray[i]=posArray[i];
            }
            sort(subarray+start-1,subarray+end-1);
            for(int i=0;i<n;i++)
                cout<<subarray[i]<<" ";
            cout<<endl;
            bool end=false;
            for(int i=start;i<end && (!end);i++){
                if(subarray[i]-subarray[i-1]==1){
                    answer="NO";
                    end=true;
                }
                else answer="YES";
            }
            cout<<answer<<endl;
        }
    }
}
