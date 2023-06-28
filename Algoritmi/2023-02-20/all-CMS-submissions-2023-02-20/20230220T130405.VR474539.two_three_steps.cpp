/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 13:04:05.811433
*/
#include <iostream>
#include <vector>
#include <fstream>

int N;
std::vector<int> GGG;
std::vector<int> memo;

int sol(int i)
{
    if (memo[i] != -1)
        return memo[i];
    if (i + 2 < N && i + 3 < N)
    {
        if (memo[i] != -1)
            return memo[i];
        return GGG[i] + std::max(sol(i + 2), sol(i + 3));
    }
    if (i + 2 < N)
    {
        if (memo[i] == -1)
            memo[i] = GGG[i] + sol(i + 2);
        return memo[i];
    }
    if (i + 3 < N)
    {
        if (memo[i] == -1)
            memo[i] = GGG[i] + sol(i + 3);
        return memo[i];
    }
    else
        return GGG[i];
    
}

int main()
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> N;
    for (int i = 0; i < N; i++)
    {
        GGG.push_back(-1);
        input >> GGG[i];

        memo.push_back(-1);
    }

    // for (int i = 0; i < N; i++)
    //     std::cout << GGG[i] << " ";

    output << sol(0);

    return 0;
}