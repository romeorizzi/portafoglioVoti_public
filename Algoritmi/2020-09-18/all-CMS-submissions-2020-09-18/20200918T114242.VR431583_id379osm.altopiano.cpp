/**
* user:  VR431583_id379osm
* fname: MIRKO
* lname: ALBANESE
* task:  altopiano
* score: 1.0
* date:  2020-09-18 11:42:42.614218
*/
//Polto-altopiano

#include <stdio.h>
#include <iostream>
#include<bits/stdc++.h> 
#include <algorithm>



using namespace std;

bool comparison (int i,int j) { return (i>j); }

void finalFunc(vector<int> A, int start, int end){

    bool is_contiguous = false, found = false;
    int maxHighTemp, maxHigh = INT_MIN;

    //FOR Statement
/*
    for (int i = start; i <= end; i++)
    {
        if (!is_contiguous)
        {
            if(!found)
            {
                if (A[i] == A[i+1])
                {
                    is_contiguous = true;
                    maxHighTemp = A[i];
                    continue;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (A[i] < maxHigh)
                    continue;
                else
                {                
                    if (A[i] == A[i+1])
                    {
                        is_contiguous = true;
                        maxHighTemp = A[i];
                        continue;
                    }
                    else
                    {
                        continue;
                    } 
                }

            }
        }
        else
        {
            if (/*A[i-1] == A[i] && *//*A[i] == A[i+1] && i != end)
            {
                if (A[i] > maxHigh)
                {
                    maxHigh = A[i];
                    found = true;
                    continue;
                }
                else
                {
                    continue;
                }     
            }
            else
            {
                is_contiguous = false;
                continue;
            }    
        }  
    }
*/

//WHILE statement
/*
    int i = start;
    while (i <= end)
    {
        if (!is_contiguous)
        {
            if(!found)
            {
                if (A[i] == A[i+1])
                {
                    is_contiguous = true;
                    maxHighTemp = A[i];
                    i++;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (A[i] < maxHigh)
                    i++;
                else
                {                
                    if (A[i] == A[i+1])
                    {
                        is_contiguous = true;
                        maxHighTemp = A[i];
                        i++;
                    }
                    else
                    {
                        i++;
                    } 
                }

            }
        }
        else
        {
            if (/*A[i-1] == A[i] && *//*A[i] == A[i+1] && i != end)
            {
                //if (A[i] > maxHigh)
                //{
                    maxHigh = A[i];
                    found = true;
                    i++;
                //}
                //else
                //{
                //    i++;
                //}     
            }
            else
            {
                is_contiguous = false;
                i++;
            }    
        }  
    }
*/
/*
    cout << "DEBUG: start = " << start << " end = " << end << endl;
    for (int i = 0; i <= end; i++)
    {
        cout << A[i];
    }
 */   

    
    int count = 0;

    for (int i = start; i < end; i++)
    {
        if(A[i] == A[i+1])
        {
            count++;
            if(count == 2)
            {
                maxHigh = A[i];
                found = true;
                break;
            }
            else
            {
                continue;
            }  
        }
        else
        {
            count = 0;
        }
    }
    

    if (!found)
    {
        cout << "NESSUN_ALTOPIANO" << endl;
    }
    else
    {
        cout << "\n" << maxHigh << endl;
    }    
}

int main() {

    int N, M, B[3], temp;

    cin >> N;
    vector<int> A(N), C(N);

    cin >> M;

    for (int i = 0; i < N; i++){

        cin >> A[i];
    }

    //B[0] = type
    //          1   2
    //B[1] = index/start
    //          1   2   
    //B[2] =   var/ end

    for (int i = 0; i < M*3; i++)
    {
        if(i%3 < 2)
        {
            cin >> B[i%3];
        }
        else
        {
            cin >> B[2];
            if (B[0] == 1)
            {
                A[B[1]] += B[2];
            }
            else
            {
                C = A;
                std::sort(C.begin()+B[1], C.begin()+B[2], comparison);
                finalFunc(C, B[1], B[2]);
            }
        }
    }

    return 0;
    
}