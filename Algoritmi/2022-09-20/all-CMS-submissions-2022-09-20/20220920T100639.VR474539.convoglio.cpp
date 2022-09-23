/**
* user:  VR474539
* fname: LEONARDO
* lname: FRACCAROLI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 10:06:39.527976
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    vector<int> messages, ships;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int message, ship;
        cin >> message >> ship;
        messages.push_back(message);
        ships.push_back(ship);
    }

    cout << "-1" << endl;
}