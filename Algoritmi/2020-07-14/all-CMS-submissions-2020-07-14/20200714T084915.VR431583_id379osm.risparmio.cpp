/**
* user:  VR431583_id379osm
* fname: MIRKO
* lname: ALBANESE
* task:  risparmio
* score: 0.0
* date:  2020-07-14 08:49:15.956667
*/
#include <stdio.h>

#define MAXN 100000;
#define MAXM 200000
/*
struct spot {
    int pos;
    bool isOn = false;
};  
*/
int main()
{
    int N, M, type, pos, start, end, numInterval = 0;
    bool beginChk = false;

    scanf("%d %d", &N, &M); //Input N and M
    //printf("%d %d", N, M);

    int spotlight[N];
    for (int n=0; n<N; n++)
        spotlight[n] = 0; //Fill array

    for(int i=0; i<M; i++)  //For each operations
    {
        scanf("%d", &type); //Input type of operation
        if (type == 1)  //on-off
        {
            scanf("%d", &pos);
            spotlight[pos] = (spotlight[pos] + 1) % 2;  //interval 0 to 1 | on-off
        }
        else    //check contiguous spot
        {
            scanf("%d %d", &start, &end); //Input start and end of the interval
            for (int k = start; k <= end; k++)
            {
                if (spotlight[k] == 1 && beginChk == false)
                {
                    beginChk = true;
                    numInterval++;
                }
                else
                {
                    if (spotlight[k] == 1)
                    {}
                    else
                    {
                        beginChk = false;
                    }   
                } 
            }
            beginChk = false;
            numInterval = 0;      
        }
    }
    return 0;
}