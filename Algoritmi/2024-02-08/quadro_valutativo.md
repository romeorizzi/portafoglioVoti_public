# punti_esercizio e voti_platino in palio sui problemi

- odd_cycle_reach: max_punti_esercizio=72, voto_platino = 19 (se raggiungi max_punti)
- piastrelle: max_punti_esercizio=80+48=128, voto_platino = 21 (se raggiungi 80 punti). NOTA: per i 48 aggiuntivi serve la fast-matrix multiplication. Di base vuole essere un esercizio semplice di ricorsione con memoizzazione o PD.
- lists_alignment: max_punti_esercizio=80, voto_platino = 21 (se raggiungi max_punti)

Ricordiamo che i voti_appello si sommano fino al 18. I voto_platino si sommano anche su appelli diversi fino al raggiungimento del 24 (ma sono più difficili da ottenere, sul singolo appello la somma dei voti_platino assegnati non potrà mai superare il voto_appello). I 


# Formula punti_esercizi -> voto_appello:

- tot_punti_esercizi = somma dei punti_esercizio presa sui diversi esercizi dell'appello

- punti_esercizio = somma dei punti acquisiti sulle singole istanze dell'esercizio correttamente risolte allo scopo

- voto_appello = ceil( (0.6625 \* tot_punti_esercizi)^(0.75) )

dove:
- ceil() arrotonda il numero per eccesso - ^ indica l'elevamento a potenza

Se la formula è arcana, a fine di questa pagina Markdown trovi la tabella esplicita di conversione.


# fruibilità dei punti voto (anche ove < 18):

Tieni presente che:

1.  da un appello all'altro i voti_appello si sommano fino al raggiungimento del 18 (regola della somma, ad accumulo)
2.  i voti_platino degli esercizi si sommano tutti (anche su appelli diversi) fino al raggiungimento del 24 (regola della somma platino, ad accumulo)
3.  nè i voti_platino nè i voti_appello acquisiti ad un appello vengono mai persi (regola del max)

In buona sostanza: nessun voto scade, puoi riprovare l'esame quante volte vuoi e vorremo renderlo un momento piacevole ed utile.


# registrazione voto

Una volta acquisito il tuo voto anche per la parte di Complessità (con cui facciamo infine media aritmetica, arrotondata per eccesso, dove 30L vale 33, e per ottenere 30L serve almeno un 30L ed entrambi i voti almeno 30), puoi richiedere la registrazione del tuo voto scrivendomi una mail dove avrai cura di specificare:
- matricola (nel formato VR??????)
- nome e cognome
- voto di cui si richiede la registrazione
- come ottenuto (voto e appello per la parte di Complessità, voto e sua composizione per la parte di Algoritmi) con riferimenti a quanto in portafoglio voti (voti utilizzati e data relativi appelli) 


## Tabella soglie punti_appello necessari al raggiungimento dei possibili voto_appello:

voto => punti necessari
1 => 1
2 => 3
3 => 6
4 => 9
5 => 12
6 => 16
7 => 20
8 => 24
9 => 28
10 => 32
11 => 36
12 => 41
13 => 46
14 => 50
15 => 55
16 => 60
17 => 65
18 => 71
19 => 76
20 => 81
21 => 87
22 => 93
23 => 98
24 => 104
25 => 110
26 => 116
27 => 122
28 => 128
29 => 134
30 => 140
30L => 159
