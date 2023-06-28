/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:54:35.100436
*/
#include <iostream>
#include <vector>
#include <fstream>

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
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> N;
    for (int i = 0; i < N; i++)
    {
        GGG.push_back(-1);
        input >> GGG[i];
    }

    // for (int i = 0; i < N; i++)
    //     std::cout << GGG[i] << " ";

    output << sol(0);

    return 0;
}