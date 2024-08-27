# dai punti esercizio e voti (normali e platino)

- questa volta la formula per passare dai punti al voto è stata semplicemente quella di sommare sui tre esercizi il voto ottenuto dai punti raccolti su quell'esercizio tramite la funzione:

```python
     def points2voto(points):
         return floor( (25 * ( points + 1) ) / 88 )
```

- per i voti platino, su ciascun esercizio su cui si raggiungesse il punteggio soglia di 80 si assommava il valore:

```python
     def points2voto(points):
   voto_platino += math.ceil( 2 * points2voto(final_points_problem) / 3 )
```


Ricordiamo che nell'ottenere il voto esame i voti_appello si sommano fino al 18. I voto_platino si sommano anche su appelli diversi fino al raggiungimento del 24 (ma sono più difficili da ottenere, sul singolo appello la somma dei voti_platino assegnati non potrà mai superare il voto_appello). 

Ricordiamo che i punti guadagnati con gli homework vanno a sommarsi al voto esame composto come detto sopra. 


# fruibilità dei punti voto (anche ove < 18):

Tieni presente che:

1.  da un appello all'altro i voti_appello si sommano fino al raggiungimento del 18 (regola della somma, ad accumulo)
2.  i voti_platino degli esercizi si sommano tutti (anche su appelli diversi) fino al raggiungimento del 24 (regola della somma platino, ad accumulo)
3.  nè i voti_platino nè i voti_appello acquisiti ad un appello vengono mai persi (regola del max)

In buona sostanza: nessun voto scade, puoi riprovare l'esame quante volte vuoi e vorremo renderlo un momento piacevole ed utile.


