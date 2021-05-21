# Esercitazione di Programmazione 2
## 17/05/2021

## Analisi del problema

Il testo richiede la progettazione e l'implementazione di una o più opportune strutture dati astratte (ADT) che consentano di:

+ inserire elementi nella struttura dati;
+ cercare elementi nella struttura dati;
+ cancellare elementi nella struttura dati.


Tra i requisiti, si nota che:

+ la ricerca e la cancellazione avvengono in base a dei valori passati come parametri alle rispettive funzioni;
+ i dati da inserire sono forniti in un file di testo;
+ la stampa della struttura dati deve essere ordinata in maniere crescente o descrescente, a seconda del valore di un parametro fornito alla funzione stampa.

## Considerazioni progettuali

1. La richiesta di stampare in ordine crescente o descrescente suggerisce l'utilizzo di una struttura dati che sia "percorribile" in entrambi i versi;
2. Il fatto che la struttura dati venga popolata a partire da un file di testo suggerisce che è opportuno utilizzare un'implementazione dinamica, che consenta quindi di variare il numero di elementi nella struttura stessa;
3. L'ordinamento potrebbe essere introdotto già in fase di inserimento, in modo che l'elenco sia sempre ordinato in un verso, e la possibilità di percorrere la struttura in entrambi i versi evita l'implementazione di un algoritmo di ordinamento separato;
4. La necessità di comparare gli elementi suggerisce l'overload degli operatori di comparazione;

Si decide, pertanto, di utilizzare una **Lista Doppiamente Linkata** con un riferimento alla testa e un riferimento alla coda.

##Classi utilizzate

+ `Player`: classe che modella il giocatore.
	- Overload della redirezione dell'input. Utilizzando la redirezione e la funzione `std::getline` si gestisce correttamente la separazione tra i campi, che avviene con il carattere ';' invece del classico spazio.
	- Overload degli operatori di comparazione logica, utilizzando il punteggio come parametro di confronto.
+ `NodeDL<T>`: classe template vista a lezione che rappresenta un nodo della lista con predecessore e successore.
+ `ListDL<T>`: classe template vista a lezione che rappresenta una lista doppiamente linkata, con puntatori a testa e coda della lista. L'unica modifica apportata è il modificatore di accesso per gli attributi, che da `private` diventa `protected`.
+ `PlayerList`: sottoclasse della classe `ListDL<T>`, specificando `Player` come tipo di dato da utilizzare.
	- Qui vengono implementati i metodi di ricerca e cancellazione specificamente richiesti dal testo. 

Trattandosi di liste doppiamente linkate, le operazioni di inserimento, ricerca e cancellazione avvengono in tempo `O(n)`.

