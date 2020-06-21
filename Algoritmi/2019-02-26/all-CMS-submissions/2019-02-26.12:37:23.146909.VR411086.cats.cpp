/**
* user:  VR411086
* fname: ZANOTTI
* lname: MATTIA
* task:  cats
* score: 0.0
* date:  2019-02-26 12:37:23.146909
*/
/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000

// input data
int Nm, Nf;
int M[MAXN], F[MAXN];


int** calculateMatrix(int i, int j, int** matrix){
    int a, b;
    int newI = i - 1;
    int newJ = j - 1;
    //int subMatrix[newI][newJ];

    int** subMatrix = new int*[newI];

    for(a = 1 ; a < i ; a++){
        subMatrix[a] = new int[newJ];
        for(b = 1 ; b < j ; b++)
            subMatrix[a][b] = matrix[a][b];
    }

    return subMatrix;
}

int maxValue(int i, int j, int** matrix){
    int a;
    int b;
    int tmp_result = 0;

    if(i == 1 && j == 1)
        return matrix[0][0];
    else if(i == 1){
        for(b = 0 ; b < j ; b++)
            if(matrix[0][b] > tmp_result)
                tmp_result = matrix[0][b];
        
        return tmp_result;

    } else if(j == 1){
        for(a = 0 ; a < i ; a++)
            if(matrix[a][0] > tmp_result)
                tmp_result = matrix[a][0];

        return tmp_result;
    
    } else {
        return matrix[i][j] + maxValue(i - 1, j - 1, calculateMatrix(i, j, matrix));
    }
}

int main() {
    int i, j;
    //int diff[Nm][Nf];

//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(2 == scanf("%d %d", &Nm, &Nf));
    for(i=0; i<Nm; i++)
        assert(1 == scanf("%d", &M[i]));
    for(i=0; i<Nf; i++)
        assert(1 == scanf("%d", &F[i]));

    int** diff = new int*[Nm];

    for(i = 0 ; i < Nm ; i++){
        diff[i] = new int[Nf];
        for(j = 0 ; j < Nf ; j++)
            diff[i][j] = abs(M[i] - F[j]);
    }

/*
    for(i = 0 ; i < Nm ; i++)
        for(j = 0 ; j < Nf ; j++)
            diff[i][j] = abs(M[i] - F[j]);
*/
    int result = 0;
    int tmp_result = 0;

    for(i = 0 ; i < Nm ; i++){
        for(j = 0 ; j < Nf ; j++){
            tmp_result = maxValue(Nm - i, Nf - j, diff);
            if(tmp_result > result)
                result = tmp_result;
            
            tmp_result = 0;
        }
    }

    printf("\n\n result: %d\n", result); // change 42 with actual answer
    return 0;
}
