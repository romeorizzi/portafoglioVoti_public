/**
* user:  VR452400_id529gvn
* fname: RICCARDO
* lname: MARCHESINI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 10:47:07.544832
*/
#include<iostream>
#include<string>
using namespace std;

int main(){
/*INPUT:
    m: lunghezza vettore s1
    n: lunghezza vettore s2
    p: intero positivo
    s1:
    s2:
    costo: vettore di costo lunghezza p+1
*/
int n,m,p;
cin>>m>>n>>p;

char s1[m]={0},s2[n]={0};
int costo[p+1]={0};

//leggo prima stringa
cin>>s1;
//leggo seconda stringa
cin>>s2;
//leggo array di costo
for(int pos=0;pos<=p;pos++){
    cin>>costo[pos];
}
//creo stringa result
char result[m]={"*"};
//scorro elementi stringa s2
//int s1_free[m]={1}
bool stop=false;
int idx_prec=0;
int costo_t=-1;

for(int element=0;element<n && stop==false;element++){//itero su seconda stringa

        //trovo corrispondenza nella prima stringa

        int idx=-1;
        bool find=false;
        for(int point=idx_prec;point<m && find==false;point++){
            if(s2[element]==s1[point]){ //se trovato

                find=true;
                idx=point;
                //s1[point]='0';
            }
        }
        //se non trovato idx==-1
        if(idx==-1){
            stop=true;
        }
        // se idx è un numero
        idx_prec=idx+1;
        //inserisco valore in result
        result[idx]=s2[element];
        //aggiorno costo
        costo_t=costo_t+costo[idx];

}
if(stop==true){// se non ho trovato qualche corrispondenza termina con errore
    cout<<-1<<endl;
}else{
cout<<costo_t<<endl;
}
//cout<<"stringa "<<s1<<" "<<s2<<endl;
return 0;
}
