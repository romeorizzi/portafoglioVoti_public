/**
* user:  VR451823EXAM
* fname: CINQUETTI
* lname: ETTORE
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 12:35:02.223462
*/
#include<fstream>
#include<iostream>
#include<assert.h>
#include<vector>

#include<algorithm>		// std::fill

using namespace std;

vector<int> panini;
vector<int> gym;
vector<int> msq;
vector<int> sequenza;

int l_array;

//int matrix_costo_gym[100000][100000] = {0};

int calcola_costo_gym(int index_uno, int index_due) {

	assert(index_uno <= index_due);
	assert(index_uno >= 0);
	assert(index_uno < l_array);

	/*if(matrix_costo_gym[index_uno][index_due] != 0)
		return matrix_costo_gym[index_uno][index_due];*/

	//matrix_costo_gym[index_uno][index_due] = panini[index_uno] + calcola_costo_gym(index_uno + 1, index_due);

	int somma = panini [index_uno]; 

	while(index_uno < index_due){
		somma += gym[index_uno];
		index_uno++;
	}

	return somma;

}


int max_num_dato_indice(int index_first, int l_array) {

	assert(index_first >= 0);
	assert(index_first < l_array);

	if(msq[index_first] != 0)
		return msq[index_first];

	int answer = 1;

	for(int i = l_array - 1; i > index_first; i--) {
		if (panini[i] > calcola_costo_gym(index_first, i))
			if(answer < 1 + max_num_dato_indice(i, l_array)){
				answer = 1 + max_num_dato_indice(i, l_array);
				if (i != index_first) sequenza[index_first] = i;
			}
	}

	msq[index_first] = answer;

	return msq[index_first];


}

int main (void) {

	ifstream fileIn;
	fileIn.open("input.txt");
	ofstream fileOut;
	fileOut.open("output.txt");

	if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());

    cin >> l_array;
    //printf("\n%d", l_array);

    panini.resize(l_array);
    gym.resize(l_array);
    msq.resize(l_array);
    sequenza.resize(l_array);

    fill(msq.begin(), msq.end(), 0);

    for(int i = 0; i < l_array; i++){
    	cin >> panini[i]; //printf("\n%d", panini[i]);
    	cin >> gym[i]; //printf(" %d", gym[i]);
    }

    //printf("\nStarting...\n");

    for(int i = 0; i < l_array; i++){
    	max_num_dato_indice(i, l_array);
    }
	    
    cout << *max_element(msq.begin(), msq.end()) << endl;

	int first = distance(msq.begin(), max_element(msq.begin(), msq.end()));

	while(first < l_array){
    	cout << sequenza[first]; first = sequenza[first];
    }
}