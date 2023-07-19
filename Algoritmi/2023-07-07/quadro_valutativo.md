# punti (=numero istanze) in palio sui 3 problemi
 - mutually_unreachable: 50
 - quanti_poldo: 100
 - ricerca_binaria: 84


# formula che si intendeva usare

punteggio_totale = numero totale di istanze risolte correttamente (su tutti i problemi proposti nell'appello)
punteggio_totale_platino = si prende la somma dei punti raccolti solo per quei problemi dove sono state risolte tutte le istanze

punti_voto_x =  floor( (33 * punteggio_totale_x) / 137 ), dove floor() arrotonda il numero per difetto (dove x=platino oppure anche no)

# variazioni introdotte (causa mancanza feedback dovuta al brakedown della rete di ateneo)

1. abbiamo scalato per 14/11 il voto ottenuto come somma dei punti voto sui tre esercizi.
2. contro la nostra impostazione di fondo, siamo andati a spendere valutazioni soggettive sui codici sottomessi per vedere di recuperare dei punti (anche su codici che non risolvevano alcuna istanza). Questi punti aggiuntivi non hanno comportato alcun scavalcamento nell'ordine totale in termini dei punti conseguiti (principalmente hanno quantomeno consentito di assegnare un punteggio minimo, e le altre differenze sono state davvero minime).
3. siamo stati meno restrittivi della regola originariamente intesa (voleva essere quella del precedente appello) nella generazione dei punti platino.

# fruibilità dei punti voto (anche ove < 18)

Tieni presente che:
 1. da un appello all'altro i punti voto si sommano fino al raggiungimento del 18 (regola della somma, ad accumulo)
 2. da un appello all'altro i punti voto platino si sommano fino al raggiungimento del 24 (regola della somma platino, ad accumulo)
 3. un punto voto acquisito ad un appello non verrà mai perso (regola del max)
