/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  risparmio
* score: 23.0
* date:  2020-07-14 12:55:39.820932
*/

#include <iostream>
#include <vector>

void switch_luce(int pos, int array[])
{
    if (array[pos] == 1)
        array[pos] = 0;
    else
    {
        array[pos] = 1;
    }

}

int count_interval(int A, int B, int array[])
{
    int count = 0;
    if(array[A]==1)
        count++;
       // std::cout << "intervall: " << count;

    for(int i=A+1 ; i <= B ; i++){
         //std::cout << "da: " << i <<std::endl;
        if((array[i] != array[i-1]) && array[i]==1 ){
            count++;
            i++;
        }
        if(array[i]==1)
            i++;
            
        //std::cout << "intervallo: " << count;

    }

    return count;
}

int main()
{

    int N, M;
    std::cin >> N; //numero punti luce
    std::cin >> M; //numero operazioni

    int operazione;

    int luci[N];

    //std::vector<int> luci(N);
    for(int i=0;i<N;i++)
        luci[i]=0;
    for (int i = 0; i < M; i++)
    {

        std::cin >> operazione;
        //switcho luce
        if (operazione == 1)
        {
            int pos;

            std::cin >> pos;
            switch_luce(pos, luci);
        }

        //conto intervalli
        else
        {
            int da, a;
            std::cin >> da >> a;
          /*  for(int i=0; i< N;i++){
                std::cout << luci[i] << " ";
            }
           */ 
            int result = count_interval(da, a, luci);
            std::cout << result << std::endl;
        }
    }
    return 0;
}
