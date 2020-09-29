/**
* user:  VR439664_id915qvl
* fname: NEREO
* lname: SORIO
* task:  risparmio
* score: 5.0
* date:  2020-07-14 12:53:16.628162
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

int count_interval(int A, int B, int array[], int partenza)
{

    int medium =(B - A) / 2 ;

    if (medium == 0)
    {
        if (A == partenza)
        {
            
            if (array[partenza] == 1 || array[B]==1)
            {
                 //std::cout << "+1 da partenza" << std::endl;
                //std::cout << "sei arrivato qua!, partenza=" << partenza << " array[partenza]=" << array[partenza] << std::endl;
                return 1;
            }
            
        }
        else
        {
            if ((array[A - 1] != array[A]) && array[A] == 1)
            {
                //std::cout << "array[A-1]" << array[A-1] << " array[partenza]=" <<array[partenza] << std::endl;
                //std::cout << "+1 da mediano, A-1=" << A-1 << "A=" <<A << std::endl;
                return 1;
            }
            else
            {
                 //std::cout << "+0 " << std::endl;
                return 0;
            }
        }
    }
    else
    {   
        if((B - A) % 2 == 0)
            return count_interval(A, B - medium, array, partenza) + count_interval(A + medium+1, B, array, partenza);
        else
        {
            return count_interval(A, B - medium-1, array, partenza) + count_interval(A + medium+1, B, array, partenza);
        }
        
    }
    return 0;

    //std::cout << "intervallo: " << count;
}

int main()
{

    int N, M;
    std::cin >> N; //numero punti luce
    std::cin >> M; //numero operazioni

    int operazione;

    int luci[N];

    //std::vector<int> luci(N);
    for (int i = 0; i < N; i++)
        luci[i] = 0;
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
           /* for (int i = 0; i < N; i++)
            {
                std::cout << luci[i] << " ";
            }
*/
            int result = count_interval(da, a, luci, da);
                
            std::cout << result << std::endl;
        }
    }
    return 0;
}
