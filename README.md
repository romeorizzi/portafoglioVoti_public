# PORTAFOGLIO DEI TUOI VOTI (corso di Fondamenti di Algoritmi, Complessità e Problem Solving - UniVR)

Questa repo mantiene il quadro, dinamicamente  aggiornato, dei voti da te maturati per il corso di "Fondamenti di Algoritmi, Complessità e Problem Solving" delle magistrali del Dipartimento di Informatica dell'Università di Verona.
Il corso &egrave; un fondamentale del passante e si compone di due moduli: Algoritmi (o parte pratica) e Complessit&agrave; (o parte teorica).

Il voto finale &egrave; unico ed espresso in trentesimi:
viene calcolato come media aritmetica arrotondata per eccesso e dove un 30 e lode vale 33. (In direzione contraria, per generare un 30 e lode come voto finale serve almeno una lode e nessuno dei due voti può essere sotto il 30.)

Non appena hai un voto positivo su entrambi i moduli,
puoi richiedere la registrazione del voto finale corrente, e chiudere il tuo percorso con noi, ma saremo altrettanto felici di vederti lavorare oltre per ottenere di pi&ugrave;, che sia a titolo personale od in termini di voto.

Quando sarà il momento, la registrazione del voto finale per l'intero insegnamento di Algoritmi e Complessità andrà richiesta inviandoci una mail come da [questo template della mail e relativa istruzioni](./template_mail_richiesta_registrazione_voto.txt).
L'utilizzo di questo template di mail assicura tu non ometta alcun dato necessario al processamento rapido e sereno della tua richiesta. Ma, in aggiunta ai dati obbligatori, sentitevi liberi di aggiungere quanto ritenete opportuno.
La mail verrà letta e gestita personalmente e fà sempre piacere scriviate anche fuori dalle righe, arrivateci insomma belli freschi come da vostre necessit&agrave; ma non fraschi (non omettete i precisi rifermineti di contesto necessari al processare la vostra richiesta).
</p>

---
## PRASSI E WORKFLOW NELLA GENERAZIONE E GESTIONE DEI VOTI:

Ricordo le politiche che stiamo seguendo ormai da diversi anni e che cercheremo di garantire nel tempo anche in futuro:

> per la parte di Complessità i voti vengono tenuti in caldo ma una consegna comporta che la nuova valutazione sovrascriva la precedente.

> per la parte di Algoritmi potrai comporre il tuo voto attingendo sia da uno o più appelli svolti in laboratorio (almeno uno ti sarà necessario) che (opzionalmente) attraverso gli homework (bonus di max 5 punti voto). Le regole per la composizione del voto per la parte di Algoritmi sono più complesse, e di fatto hanno richiesto l'organizzazione di questo repo.

### Composizione e gestione del voto per la parte di Algoritmi

Per Algoritmi avete più opzioni su come comporre il voto finale dai riscontri da voi prodotti sui vari appelli e attraverso gli homework. In buona sostanza, i punti homework (max 5) si sommano ai punti raccolti agli appelli. Se vi giocate un singolo appello (composizione voto con regola del max), scegliete quello dove avete ottenuto un voto standard di valore massimo e sommategli i punti accumulati con gli homework. Altrimenti (composizione voto tramite somma a 18), potete sommare i voti dei vari appelli cui avete partecipato ed aggiungere i punti bonus per gli homework, ma avete un tetto a 18 per la parte di Algoritmi.
Oltre ai voti standard, un appello genera anche voti argento, oro o platino (su esercizi svolti in modo completo o dove avete quantomento esibito competenze al livello di tale categoria, e via via sempre più scalati al crescere del pregio del metallo).
Esempio (solo indicativo): un esercizio da 20 punti voto standard, svolto in modo da totalizzare 18 punti voto standard, potrebbe generare i seguenti punti in portafoglioVoti: 18 punti standard, 0 punti platino perchè non raggiungeva i requisiti perchè vi valga in quella categoria, 13 punti oro (perchè raggiunge i requisiti), 16 punti argento (perchè raggiunge i requisiti). 
Sia ai vari appelli che poi al momento di comporre il vostro voto, scegliete di puntare sul metallo che meglio credete e tenete presente che i rispettivi tetti sul voto finale ottenibile per la parte di Algoritmi sono come da seguente tabella:

|     metallo   | regola/composizione | tetto se inclusi gli homework | tetto se esclusi gli homework |
| :---          |  ---   |  ---  |  ---  |
| voto standard | della somma | 18 | 20  |
| voto argento  | della somma | 20 | 22  |
| voto oro      | della somma | 22 | 24  |
| voto platino  | della somma | 24 | 26  |
| voto standard | del max | 30 | 30 e lode = 33 |

> [!NOTE]
> I punti homewors si maturano sottomettendo soluzioni agli esercizi proposti durante l'anno (se hai sottomesso in vari anni di corso, scegli il max dei punti raccolti sui vari anni). Un meccanismo premiale a moltiplicatori decrescenti nel tempo vi stimola ad affrontare un esercizio senza lasciar passare troppo tempo da quando proposto.

### sintesi del voto per l'intero corso

Tra i voti delle due prove si fa media aritmetica arrotondata per eccesso e dove un 30 e lode vale 33. Per generare un 30 e lode come voto finale serve almeno una lode e nessun voto sotto il 30.

Anche se non gestiti tramite il portafoglio voti, al voto possono inoltre concorrere progetti open source che possano essere di utilità per il corso (da concordare).

Quando ritieni giunto il momento di registrare il tuo voto attuale, ci mandi una mail come da [questo template della mail e relativa istruzioni](./template_mail_richiesta_registrazione_voto.txt).


> [!TIP]
> Il template assicura tu non ometta alcun dato necessario al processamento sereno e rapido della tua richiesta. Può infatti altrimenti capitarvi di dimenticare dei dettagli nella fretta (necessari perchè io possa verificare serenamente ogni riscontro, o anche utili a farvi riconoscere un voto maggiore).
> Per altro viene anche comodo per voi partire dal template poichè le info da precisare non sono poche. 


## ORGANIZZAZIONE DELLA REPO

__La sottocartella "Complexity"__ contiene una lista di files con i voti conseguiti in tale appello. Per ciascun appello abbiamo 2 file, quello in formato csv e quello in formato txt. Ricordo che per la parte di Complessità fa fede il voto conseguito all'ultimo appello sostenuto.
Nella mail con cui mi chiederai di verbalizzare il tuo voto farai esplicito riferimento a tale appello ed al voto in esso conseguito.

__La sottocartella "Algoritmi"__ contiene una sottocartella per ogni singolo appello di Algoritmi, con i voti conseguiti in tale appello ed altri materiali che hanno concorso alla loro produzione.
Per ciascuno di questi voti viene inoltre riportato il dettaglio di composizione (punti sui vari esercizi dell'appello) e, almeno qualora i voti standard/argento/oro/platino non vi apparissero già dalla `scoreboard` durante l'appello, le regole di mappatura da punti a voto. I punti di bonus per gli homework o per progetti di servizio al corso NON sono già inclusi nei voti appello in portafoglio in quanto non vengono consumati con l'appello. Stà quindi a tè aggiungerli nella gestione del tuo portafoglio voti e nel voto atteso precisato nella mail con cui richiedi la registrazione del voto finale.

Il folder `bonus_homework` contiene i punti homework acquisiti in anni accademici precedenti (sugli anni si fà il max) mentre per l'anno corrente è il problema-sevizio `scoreboard` a darti un quadro dinamico completo (inclusivo delle scadenze dei moltiplicatori attualmente impostati) della situazione dei punti homework raccolti e delle opportunità attuali per acquisirne altri (l'aggiunta incrementale di nuovi problemi e moltiplicatori assicura che il tuo voto homework possa solo crescere monotonamente nel corso dell'anno). Accedi a questo servizio [`rtal`](https://github.com/romeorizzi/AlgoritmiUniVR/tree/main/strumenti#-la-nostra-piattaforma-rtal) con:
```
   rtal -s wss//ta.di.univr.it/algo scoreboard
```


