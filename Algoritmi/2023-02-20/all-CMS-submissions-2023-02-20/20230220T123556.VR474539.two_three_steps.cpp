/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:35:56.508424
*/
#include <iostream>
#include <vector>

int N;
std::vector<int> GGG;

int sol(int i)
{
    if (i + 2 < N && i + 3 < N)
    {
        // int a = GGG[i + 2];
        // int b = GGG[i + 3];

        // std::cout << a << b << "\n";
        return GGG[i] + std::max(sol(i + 2), sol(i + 3));
    }
    if (i + 2 < N)
        return GGG[i] + sol(i + 2);
    if (i + 3 < N)
        return GGG[i] + sol(i + 3);
    else
        return GGG[i];
    
}

int main()
{
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        GGG.push_back(-1);
        std::cin >> GGG[i];
    }

    // for (int i = 0; i < N; i++)
    //     std::cout << GGG[i] << " ";

    std::cout << sol(0) << std::endl;

    return 0;
}