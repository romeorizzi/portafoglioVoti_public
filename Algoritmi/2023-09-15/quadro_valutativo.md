# punteggi in palio sui 3 problemi
 - binary_heap: 54
 - poldo_mania: 66
 - monotone_01_matrix:  93

# formula

punteggio_totale = numero totale di istanze risolte correttamente (su tutti i problemi proposti nell'appello)
punteggio_totale_platino = si prende la somma dei punti raccolti solo per quei problemi dove sono state risolte tutte le istanze

## Durante esame:
   punti_voto_x =  floor( (33 * punteggio_totale_x) / 150 ), dove floor() arrotonda il numero per difetto (dove x=platino oppure anche no)

Esempi

 48 --> 16 (48*33/99=1584/99=16) 
 54 --> 18 (54*33/99=1782/99=18)  (binary_heap, con tutte le istanze)
 61 --> 20 (61*33/99=2013/99=20)  


## A esame concluso, abbiamo incrementato questi voti nei seguenti:

 48 --> 22 
 54 --> 25
 61 --> 26  

# fruibilità dei punti voto (anche ove < 18):

Tieni presente che:
 1. da un appello all'altro i punti voto si sommano fino al raggiungimento del 18 (regola della somma, ad accumulo)
 2. da un appello all'altro i punti voto platino si sommano fino al raggiungimento del 24 (regola della somma platino, ad accumulo)
 3. un punto voto acquisito ad un appello non verrà mai perso (regola del max)
