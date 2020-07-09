/**
* user:  VR424289
* fname: BRUNONE
* lname: STEFANO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:13:32.608675
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

static FILE *file;

int main(){
    
    int n;
    int pan;
    int gym;



    #ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif

    fscanf(file, "%d", &n);


    int s[n] = {};
    int panL[n] = {};
    int gymL[n] = {};
    int gymSum[n] = {};
    int res[n] = {};
    int resS[n] = {};
    int lastS;
    int nS;
    int lenght=0;
    int lenghtS=0;
    

    fscanf(file, "%d" , &pan);
    fscanf(file, "%d" , &gym);

    gymSum[0]=gym;
    panL[0]=pan;

    for(int i=1;i<n;i++){
        lenghtS=0;
        fscanf(file, "%d" , &pan);
        fscanf(file, "%d" , &gym);
        //cout << pan<<endl;
        //cout << gym<<endl;
        gymSum[i]=gym+gymSum[i-1];
            //cout << gymSum[i]<<endl;

        panL[i]=pan;
        if(i==1){
            s[0]=0;
            s[1]=1;
            lastS=0;
            nS=1;
        }

        //cout << s[nS-1]<<endl;
        int nP=s[nS-1];
        nS=nP;
         //cout << nP<<endl;
        //for(nS=nP;nS<n-1;nS++)
            //cout << nS<<endl;

        //for per trovare tutti gli s piu` grandi di s-1
        for(nS;nS<i;nS++){
            
            //cout << nS << endl;
            //cout << gymSum[nS]-gymSum[lastS]<<endl;
            //cout << nS<<endl;
            if(panL[nS]>=panL[s[lastS]]+(gymSum[Ns-1]-gymSum[lastS])){
                lenghtS=0;
                lastS=nS;
                resS[i]=nS;
                lenghtS++;
                cout << nS << endl;
                if(lenghtS>lenght){
                    
                    
                    //res=resS;
                    for(int r=0;r<lenghtS;r++)
                        s[r]=resS[r];
                    lenght=lenghtS;
                   
                     /* for(int r=0;r<lenght;r++){
                        cout << s[r] << endl;
                    }
                    cout << "\n \n" << endl;  */
                }
    
                
                //cout << nS<<endl;
            }
            /*for(int i=0;i<4;i++){
                    fprintf(file, "%d ", res[i]);
                }*/
        }
    }

    #ifdef EVAL
    file = fopen("output.txt", "w");
	#else
    file = stdout;
	#endif
    for(int i=0;i<lenght;i++){
        fprintf(file, "%d ", s[i]);
    }
    

    return 0;
}