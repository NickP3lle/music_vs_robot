## Little overview:

### Ptr
La classe ptr<T> definita in ptr.h è un puntatore nella heap che si dealloca da
solo.
Per leggere il valore memorizzato dentro il puntatore si utilizza get(); per
modificarne il valore si utilizza get_mut(). Per liberare la memoria
precocemente si può utilizzare free, isPtr() e isNone() controllano se il
puntatore è nullptr.
Lo scopo principale per questa classe è il seguente: indica l'oggetto o
l'assenza dell'oggetto.

### Deque
ptr<T> è una dependency di deque<T>.
deque<T> supporta le funzioni push_back e pop_front per inserire ed estrarre i
dati. Ho anche implementato operator[] per controllarne i valori nei test.
Reputo utile un utilizzo del tipo 

	if (deque.len() > 0)
		deque[0].(...)

perchè ti permette di modificare il primo oggetto senza estrarlo. Quindi ho
implementato anche len che ritorna il numero di elementi della deque.
Il metodo iter permette di convertire la deque a iteratore. Non ne fa la copia,
per cui le modifiche effettuate nell'iteratore sono effettuate anche nella
deque!

### IndependentFn
in questo file ci sono delle funzioni molto utilizzate in diversi file, ma di
piccole dimensioni.
Abbiamo randomInt e Test

### Iterator
si tratta di una classe ad hoc per fare da interfaccia a deque: potevo
implementare begin() e end(), ma ho preferito srivere iterator. Di fatto
iterator permette di chiamare for_each e copy_if in un modo più immediato e ad
alto livello.
NB map chiama for_each se la lambda function ritorna un valore non lo salva;
NB filter crea un nuovo iteratore che contiene i puntatori agli oggetti che
rispettano la condizione;
collect ritorna un contenitore con gli oggetti nell'iteratore
