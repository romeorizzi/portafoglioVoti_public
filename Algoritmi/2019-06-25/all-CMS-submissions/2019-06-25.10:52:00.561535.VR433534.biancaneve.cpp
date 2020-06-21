/**
* user:  VR433534
* fname: BRENTAROLLI
* lname: ELIA
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:52:00.561535
*/
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <string>
#define MAXN 200000
#define MAXM 200000

struct Command{
    int command;
    int start;
    int end;
};


using namespace std;
int main(int argv, char* argc){
    int n,m;
    int Parray[MAXN];
    Command commands[MAXM];
    assert(scanf("%d %d",&n,&m)==2);
    int *posArray= new int[n]();
    for(int i=0;i<n;i++){
        assert(scanf("%d",&Parray[i])==1);
        posArray[Parray[i]-1]=i;
    }
    int appo;
    int *subarray=new int[n]();
    string answer;
    for(int i=0;i<m;i++){
        assert(scanf("%d %d %d",&commands[i].command, &commands[i].start,&commands[i].end)==3);
    }

    for(int i=0;i<m;i++){
        if(commands[i].command==1){
            appo=posArray[Parray[commands[i].start-1]-1];
            posArray[Parray[commands[i].start-1]-1]=posArray[Parray[commands[i].end-1]-1];
            posArray[Parray[commands[i].end-1]-1]=appo;

            appo=Parray[commands[i].start-1];
            Parray[commands[i].start-1]=Parray[commands[i].end-1];
            Parray[commands[i].end-1]=appo;
        }
        else{
            for(int j=commands[i].start-1;j<commands[i].end;j++){
                subarray[j]=posArray[j];
            }
            sort(subarray+commands[i].start-1,subarray+commands[i].end-1);
            bool end=false;
            for(int j=commands[i].start-1;j<commands[i].end && (!end);j++){
                if(subarray[j]-subarray[j-1]>1){
                    answer="NO\n";
                    end=true;
                }
                else answer="YES\n";
            }
            cout<<answer;

        }
    }
}
