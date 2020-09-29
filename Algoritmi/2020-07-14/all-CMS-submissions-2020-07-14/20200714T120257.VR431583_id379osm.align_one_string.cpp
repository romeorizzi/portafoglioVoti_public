/**
* user:  VR431583_id379osm
* fname: MIRKO
* lname: ALBANESE
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 12:02:57.792601
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

#define MAX 1000

bool is_comp(char a[], char b[], int len)
{
    bool isOk;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == b[i] || a[i] == '*' || b[i] == '*')
        {
            isOk == true;
        }
        else if ((a[i] != b[i]) && a[i] != '*' && b[i] != '*')
            return false;     
    }

    return isOk;
}

int main()
{
    using namespace std;
    
    int m, n, p, diffLength;
    string a, b, temp;
    int cost[MAX];
    
    scanf("%d %d %d", &m, &n, &p);

    cin >> a;
    cin >> b;

    for (int i = 0; i <= p; i++)
    {
        scanf("%d", &cost[i]);
    }
/*
    for (int i = 0; i <= p; i++)
    {
        printf("%d", cost[i]);
    }
 */

    diffLength = m - n;
    printf("%d", cost[diffLength]);
    
   return 0; 
}