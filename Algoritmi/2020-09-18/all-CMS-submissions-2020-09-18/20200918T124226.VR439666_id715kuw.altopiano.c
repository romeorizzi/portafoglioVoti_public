/**
* user:  VR439666_id715kuw
* fname: ENRICO
* lname: GUERRA
* task:  altopiano
* score: 0.0
* date:  2020-09-18 12:42:26.937315
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count=0;

int main(void){
int N, M;
    printf("Inserisci N ed M:\n");
    scanf("%i %i", &N, &M);
    
    int altezze[N];
    char altezzeS[100000];
    char delim[] = " ";
    
    printf("Inserisci altezze:\n");
    scanf("%s", altezzeS);
    
    char *ptr=strtok(altezzeS, delim);
    int i=0;
    while(ptr != NULL){
        altezze[i]=atoi(ptr);
		ptr = strtok(NULL, delim);
	}

    int ops[M][3];
    int j=0;
    char arrayS[3];
    while(j<M){
        printf("Inserisci riga:\n");
        scanf("%s",arrayS);
        char *ptr=strtok(arrayS, delim);
        while(ptr != NULL){
            int l=0;
            ops[j][l]=atoi(ptr);
            printf("Carattere inserito.\n");
		    ptr = strtok(NULL, delim);
            l++;
        }
        j++;
	}

    int temp;
    int temp2;
    for(int a=0;a<M;a++)
        if(ops[a][0]==1){
            temp=ops[a][1];
            altezze[temp]+=ops[a][2];
         }
         else{
            count=-10000;
            for(int z=ops[a][1];z<ops[a][2]-1;z++)
                if(altezze[z]==altezze[z+1] && altezze[z]==altezze[z+2]){
                    if(altezze[z]>=count)
                        count=altezze[z];
                }

            if(count==-10000)
                printf("NESSUN_ALTOPIANO");
            else
                printf(count);
         }
     }

return 0;
}
