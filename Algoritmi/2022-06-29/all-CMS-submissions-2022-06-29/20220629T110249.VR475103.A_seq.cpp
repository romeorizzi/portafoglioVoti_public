/**
* user:  VR475103
* fname: ALBERTO
* lname: GIRELLI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:02:49.198706
*/
#include <iostream>
#include <math.h>
#define MAX_DIM 1000
using namespace std;
int DIM;
int cresc(int i,int j);
int decresc(int i,int j);
int sequence[MAX_DIM];
int matrix[MAX_DIM][MAX_DIM]={-1};

int main()
{


    int problemNumber =0;
    cin >> problemNumber;
    cin >> DIM;
    if(DIM<=0)
    {
        cout << 0;
        return 0;
    }
    for(int i=0;i<DIM;i++)
    {
        cin >> sequence[i];
    }

      for(int i=0;i<DIM ;i++)
        for(int j=0;j<DIM;j++)
            matrix[i][j]=-1;

    for(int i=1;i<DIM;i++)
        cresc(0,i);

    for(int i=1;i<DIM;i++)
        decresc(0,i);

   /* for(int i=0;i<DIM ;i++)
    {
        for(int j=0;j<DIM;j++)
        {
         cout << matrix[i][j];
         cout <<"\t";
        }

        cout << "\n\n";
    }
*/
    int myMax=0;
    for(int i=0;i<DIM-1;i++)
    {
        for(int j=i+1;j<DIM;j++)
        {
             for(int k=j+1;k<DIM;k++)
                if(matrix[i][j] +  matrix[k][j]> myMax)
                    myMax=matrix[i][j] +  matrix[k][j];
        }

    }
    myMax=max(myMax,1);
    int howManyMax=0;

    for(int i=0;i<DIM;i++)
    {
        for(int j=i+1;j<DIM;j++)
        {
             for(int k=j+1;k<DIM;k++)
                if(max(matrix[i][j] +  matrix[k][j],1)== myMax)
                    howManyMax++;
        }

    }
    if(problemNumber==1)
        cout<< myMax;
    else
        cout << min(howManyMax,DIM)%1000000007;
    return 0;
}

int cresc(int i,int j)
{

    if(matrix[i][j]!=-1)
        return matrix[i][j];
    int delta;

    delta=sequence[i]<sequence[j] ? 1:0;


    if(j-i==1)
        matrix[i][j]=delta;
    else
        matrix[i][j]= max(delta,cresc(i,i+1)+cresc(i+1,j));
    return matrix[i][j];
}



int decresc(int i,int j)
{
    //cout << "Analizzo " << j <<" : " << i << "\n";
    if(matrix[j][i]!=-1)
        return matrix[j][i];
    int delta;

    delta=sequence[i]>sequence[j] ? 1:0;


     if(j-i==1)
        matrix[j][i]=delta;
    else
        matrix[j][i]= max(delta,decresc(i,i+1)+decresc(i+1,j));
    return matrix[j][i];
}
