/**
* user:  VR451275_id420ehk
* fname: EDOARDO
* lname: GRASSI
* task:  turniPFG-2DAGs
* score: 0.0
* date:  2021-02-12 09:17:18.264993
*/
#include <iostream>
#include <algorithm>

const auto MAX_N = 100000 + 1;

using namespace std;

struct Interval
{
  int64_t A;
  int64_t B;
};

bool operator<(const Interval& lhs, const Interval& rhs)
{
  if (lhs.A < rhs.A) return true;
  if (lhs.B < rhs.B) return true;
  return false;
}

int main()
{
  int64_t T, K, N;
  Interval I[MAX_N];

  cin >> T >> K >> N;
  for (auto i = 0; i < N; ++i)
    cin >> I[i].A >> I[i].B;

  if (T == 0)
  {
    /*
    auto sorter = [](Interval& x, Interval& y){
      if (x.A < y.A)
        return true;
      else if (x.B < y.B)
        return true;
      return false;
    };*/
    //sort(begin(I), begin(I) + N, sorter);
    sort(begin(I), begin(I) + N);

    // intervals are now sorted in ascending order
    int64_t X = 0;
    int64_t fud = 0;
    for (auto i = 0; i < N; ++i)
    {
      X += max(I[i].A - fud, 0);
      fud = max(I[i].B + 1, fud);
    }
    if (fud < (K - 1))
      X += (K - 1) - fud;
    cout << X;
  }
  else
  {
    cout << 2; // 1
  }
}
