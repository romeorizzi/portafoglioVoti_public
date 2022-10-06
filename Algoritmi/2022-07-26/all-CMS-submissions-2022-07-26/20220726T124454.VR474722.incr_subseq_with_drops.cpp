/**
* user:  VR474722
* fname: LUIGI
* lname: HU
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 12:44:54.231959
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
       int g, n, k;
       cin >> g;
       cin >> n;
       cin >> k;

       int s[n];
       int i, count, temp, max;
       for(i = 0; i < n; i++)
              cin >> s[i];

       for(i = 0, count = 1, temp = k, max = 1; i < n - 1; i++){
              if(s[i] > s[i+1]){
                     temp--;
                     if(temp == -1){
                            if(count > max)
                                   max = count;
                            count = 1;
                            i = i - k;
                            temp = k;
                     }else
                            count++;
              }else if(s[i] < s[i+1]){
                     count++;
              }
       }
       if(i == n-1 && max < count){
              max = count;
       }
       cout << max;
       return 0;
}