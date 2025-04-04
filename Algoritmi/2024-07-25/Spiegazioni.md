# Spiegazioni:

## Come richiedere la registrazione di un voto composto dal mio portafoglio voti

Quando volete chiudere la vostra posizione mi inviate una mail dove specificate la vostra matricola, il voto che vi attendete io vi registri, la sua composizione dai dati degli appelli ricompresi in portafoglio-voti riportando i riferimenti agli appelli coinvolti e i vostri conteggi. Ricordo che il voto deve essere ottenuto come la media arrotondata per eccesso del voto per il modulo di Complessità e del voto per il modulo di Algoritmi (dove 30L-->33 e per ottenere 3OL serve almeno una lode ed entrambi i voti devono essere almeno 30).
Per il voto di Complessità dovete riportare l'ultimo voto acquisito ad un appello per quel modulo.
Per il voto di Algoritmi un voto_appello non scade mai (regola del max) anche se in appelli successivi prendete meno (attenzione: la situazione però viene resettata se copiate, abbiamo modi per accorgercene in fase di analisi delle sottomissioni se non al momento).
Inoltre, fino al 18 risulta possibile sommare i voti di più appelli (da riportare tutti nella mail quando ci si avvalga di questa regola).
Sempre per il modulo di Algoritmi risulta inoltre possibile sommare voti_platino come presi da più appelli fino al raggiungimento del 24.
Ricordiamo che il voto_platino di un appello è il voto che si otterrebbe in quell'appello conteggiando solo i punti raccolti su esercizi risolti a punteggio pieno.    

## Prepararsi al prossimo appello:

Il modo migliore è provando a risolvere esercizi di precedenti appelli.
Per gli appelli fino a febbraio 2023 usa la VM algo-simula-prove allo URL:
   https://rizzi.olinfo.it/algo-simula-prove

Per gli appelli successivi usa i seguenti server TALight:
   rtal -s wss://ta.di.univr.it/algo list

   rtal -s wss://ta.di.univr.it/algo2024 list

Al secondo trovi per altro il tuo bonus homeworks svolti da aggiungere al voto maturato con gli appelli d'esame:

   rtal -s wss://ta.di.univr.it/algo2024 connect scoreboard

E, se non sei arrivato a saturazione (max 5 punti voto), puoi migliorare il vostro bonus sottomettendo soluzioni a problemi d'esame proposti nel corso del corrente anno accademico (il moltiplicatore è ora meno generoso che durante l'erogazione del corso ma con più lavoro riesci ancora a non uscirne penalizzato).


Puoi visionare e partire da una tua sottomissione durante l'appello, se hai partecipato e sottomesso.
Trovi le tue sottomissioni nel folder your_submissions.cyphered
Per poter decifrare il file .zip di tua pertinenza devi usare la password personale che ti viene comunicata chiamando

> rtal -s wss://ta.di.univr.it/algo2024 connect password 


Quando mi scrivete la mail per richiedere la registrazione del voto ricordatevi di conteggiare anche il bonus nel voto atteso (con esplicita menzione nella composizione analitica che a mè spetta di verificare in ogni suo elemento).