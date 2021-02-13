/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  turniPFG-2DAGs
* score: 20.0
* date:  2021-02-12 08:45:40.414050
*/
#include <iostream>
#include <algorithm>

const auto MAX_N = 100000;

using namespace std;

struct Interval
{
  int A;
  int B;
};

int main()
{
  int T, K, N;
  Interval I[MAX_N];

  cin >> T >> K >> N;
  for (auto i = 0; i < N; ++i)
    cin >> I[i].A >> I[i].B;

  if (T == 0)
  {
    auto sorter = [](Interval& x, Interval& y){
      if (x.A < y.A)
        return true;
      else if (x.B < y.B)
        return true;
      return false;
    };
    sort(begin(I), begin(I) + N, sorter);

    // intervals are now sorted in ascending order
    int R = 0;
    int last = 0;
    for (auto i = 0; i < N; ++i)
    {
      R += max(I[i].A - last, 0);
      last = I[i].B;
    }
    R += ((K - 1) - last);
    cout << R;
  }
  else
  {
    cout << 1;
  }
}
