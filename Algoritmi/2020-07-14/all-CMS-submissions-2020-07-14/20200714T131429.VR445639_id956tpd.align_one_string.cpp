/**
* user:  VR445639_id956tpd
* fname: ROSA
* lname: RUSSO
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 13:14:29.691605
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
using namespace std;


bool is_comp(int b1, int a1){ // predicato di compatibilità
    // Se sono uguali is_comp da true
    if ((b1 == a1)){
        return true;
    }

    // Se sono arrivata qui è perché b1 != a1, quindi controllo se sono in sigma
    bool c1_in_sigma = (b1 >= 'A' && b1 <= 'Z') || (b1 >= 'a' && b1 <= 'z');
    bool c2_in_sigma = (a1 >= 'A' && a1 <= 'Z') || (a1 >= 'a' && a1 <= 'z');

    if (c1_in_sigma && c2_in_sigma) { // c1, c2 appartengono a sigma, ma sono diversi
        return false;
    }
    return true;
}

string rep(string bp, int i){ // aggiungo "i" caratteri '*' nella stringa b' 
    for (int j = 0; j < i; j++)
        bp.push_back('*');
    return bp;
}

bool comp_stringhe(string a, string bp, int m){

    char car_b, car_a; // car_b : i-esimo carattere della stringa b

    for (int i = 0; i < bp.length(); i++){
        car_b = bp[i];
        car_a = a[i];
        if (is_comp(car_b, car_a) == false){
            return false;
        }
    }

    return true;
}

/* Questa funzione restituisce tutte le possibili combinazioni
 * di inserimenti che risultino in delta inserimenti.
 * Restituisce un array di array. Ogni array interno
 * contiene n interi.
 * I primi n-1 interi sono le varie sostituzioni, l'n-esimo è il costo
 */
list<list<int>> combinations(vector<int> cost, int delta) {
    // Caso base
    if (delta == 0) {
        list<list<int>> vec(1, list<int>(1));
        list<int> front = vec.front();
        front.push_back(0);

        return vec;
    }

    list<list<int>> combinazioni;

    for (int i = 1; i < cost.size(); i++) {
	if (delta - i >= 0) {
		list<list<int>> next_combinations = combinations(cost, delta - i);
		int current_cost = cost[i];
	       
		list<list<int>>::iterator it;
		for (it = next_combinations.begin(); it != next_combinations.end(); ++it) {
		    // Prendo la combinazione j-esima
		    list<int> inner_combination = *it;

		    // Gli aggiungo il numero di sostituzioni scelti in questa chiamata
		    inner_combination.push_front(i);

		    // Modifico il costo aggiungendogli anche il costo della prima sostituzione
		    int* back = &inner_combination.back();
			*back = *back + current_cost;

		    // Lo aggiungo al vettore di combinazioni
		    combinazioni.push_back(inner_combination);
		}
	}
    }
    return combinazioni;
}

list<list<int>> sorted_combinations(vector<int> cost, int delta) {
    list<list<int>> combinazioni = combinations(cost, delta);

    list<list<int>> combinazioni_ordinate;

    list<list<int>>::iterator it;
    for (it = combinazioni.begin(); it != combinazioni.end(); it++) {
        list<int> combinazione = *it;
        int costo = combinazione.back();

        if (combinazioni_ordinate.size() == 0) {
            combinazioni_ordinate.push_back(combinazione);
        } else {
            bool inserito = false;

			list<list<int>>::iterator it2lavendetta;
            for (it2lavendetta = combinazioni_ordinate.begin(); it2lavendetta != combinazioni_ordinate.end(); it2lavendetta++) {
				list<int> element = *it2lavendetta;
                if (costo < element.back()){
                    combinazioni_ordinate.insert(it2lavendetta, combinazione);
                    inserito = true;
					break;
                }
            }
            if (!inserito) {
                combinazioni_ordinate.push_back(combinazione);
            }
        }
    }

    return combinazioni_ordinate;
}

bool tenta_combinazione(string bp, string a, int m, list<int> combinazione) {
	// caso base
	if (combinazione.size() == 1) { // combinazione contiene il costo come ultimo elemento
		return comp_stringhe(a, bp, m);
	}

	char buf[m];
	string bp_copy;
	for (int i = 0; i < bp.length() + 1; i++) {
		strcpy(buf, bp.c_str());
		string bp_copy(buf);
		// bp_copy = bp;
		int number = combinazione.front();
	   	combinazione.pop_front();
		for (int j = 0; j < number; j++) {
			bp_copy = bp_copy.insert(i, "*");
		}

		if (tenta_combinazione(bp_copy, a, m, combinazione)){
			return true;
		}
		combinazione.push_front(number);
	}
	return false;

}

int inserimento_ast(string bp, string a, int m, vector<int> cost){
    int costo, delta;

    if (bp.length() < m){
        delta = m - bp.length(); // massimo numero di *
    }

    list<list<int>> combinazioni = sorted_combinations(cost, delta);

	list<list<int>>::iterator it;
	for (it=combinazioni.begin(); it != combinazioni.end(); it++) {
		list<int> combinazione = *it;

		if (tenta_combinazione(bp, a, m, combinazione)){
			return combinazione.back();
		}
	}
//    se tutte comp_strunghe false return -1; // Partendo da b, non è stato possibile ottenere un b'
                       //t.c. ogni carattere di b' sia compatibile con il rispettivo carattere in a
    return -1;
}

int main(){
    
    int m, n, p;

    cin >> m; // len(a)
    cin >> n; // len(b)
    assert(n <= m);
    cin >> p; // cost[p+1]

    assert(m >= 1);
    assert(m <= 1000);
    assert(n >= 1);
    assert(n <= 1000);
    assert(p >= 1);
    assert(p <= 1000);

    vector<int> cost(0); // cost {0, 0, ... , 0}

    string a, b, bp; // bp equivale a b'
    cin >> a;
    int a_len = a.length();
    assert(a_len = m);
    cin >> b;
    int b_len = b.length();
    assert(b_len = n);
    
    int x;
    for(int i = 0; i < p; i++){ // acquisizione vettore cost
        cin >> x;
        assert(x >= 0);
        cost.push_back(x);
    }
    // Costruzione stringa b' e verifica compatibilità tra b' ed a
    // Se esiste, restituire il costo minimo, altrimenti -1
    bp = b;
    int costo = inserimento_ast(bp, a, m, cost);
	cout << costo << endl;
    return 0;
}
