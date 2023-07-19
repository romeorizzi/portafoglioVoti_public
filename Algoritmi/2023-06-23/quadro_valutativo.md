# punteggi in palio sui 3 problemi
 - connected_components: 50
 - nim2: 60
 - FBF_trasparenti:  100

# formula

punteggio_totale = numero totale di istanze risolte correttamente (su tutti i problemi proposti nell'appello)
punteggio_totale_platino = si prende la somma dei punti raccolti solo per quei problemi dove sono state risolte tutte le istanze

punti_voto_x =  floor( (33 * punteggio_totale_x) / 150 ), dove floor() arrotonda il numero per difetto (dove x=platino oppure anche no)

# esempi

 50 --> 11  con solo connected_components (ma tutte le istanze)
 60 --> 13  con solo nim2 (ma tutte le istanze)
100 --> 22  con solo FBF_trasparenti (ma tutte le istanze)
110 --> 24  connected_components + nim2
150 --> 33  (ossia 30 e lode) con connected_components + FBF_trasparenti o comunque esca punteggio totale >= 150

# fruibilità dei punti voto (anche ove < 18):

Tieni presente che:
 1. da un appello all'altro i punti voto si sommano fino al raggiungimento del 18 (regola della somma, ad accumulo)
 2. da un appello all'altro i punti voto platino si sommano fino al raggiungimento del 24 (regola della somma platino, ad accumulo)
 3. un punto voto acquisito ad un appello non verrà mai perso (regola del max)
