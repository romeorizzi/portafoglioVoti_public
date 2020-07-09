/**
* user:  VR419485
* fname: QUINCI
* lname: OLIVIO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:29:46.671300
*/

#include <algorithm>
#include <array>
#include <iostream>     // std::cout
#include <fstream>

int main()
{
   std::fstream in("input.txt");
  std::ofstream out("output.txt");
  int N;
in >> N;
int p[N];
int g[N];
int valoremax[N];


for(int i = 0; i < N; i++)
in >> p[i] >> g[i];
valoremax[0]=0;
for(int ss = 0; ss < N; ss++)
{valoremax[ss]=0;
    for(int mm = 0; mm < ss-1; mm++)
    valoremax[ss]= g[mm]+valoremax[ss];}



 {for (int i = 0; i < N; i++) {
 for (int j = 0; j <= M - oggetti[i].peso ; j++)
    {
}
}
