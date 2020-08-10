/**
* user:  VR431583_id379osm
* fname: MIRKO
* lname: ALBANESE
* task:  risparmio
* score: 23.0
* date:  2020-07-14 13:05:40.008168
*/
#include <stdio.h>
#include <vector>

#define MAXN 100000;

int main()
{
    int N, M, type, pos, start, end, numIntervals = 0;
    bool beginChk = false;

    scanf("%d %d", &N, &M); //Input N and M
    //printf("%d %d", N, M);

    //int spotlight[N];

    std::vector<int> spotlight(N);
/*
    for (int n=0; n<N; n++)
        spotlight[n] = 0; //Fill array
*/

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
                    numIntervals++;
                }
                else
                {
                    if (spotlight[k] != 1)
                         beginChk = false;
                }
            }
            printf("%d\n", numIntervals);
            beginChk = false;
            numIntervals = 0;      
        }
    }
    return 0;
}