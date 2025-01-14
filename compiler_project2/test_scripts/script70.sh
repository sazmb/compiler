#!/bin/bash
cat <<EOF
types
 Numeri = [int];
variables
 numeri_da_ordinare: Numeri;
functions
 inserisci(n: int, numeri: Numeri): Numeri // inserimento di un numero in un arrary ordinato
 if empty(numeri) then
 [n]
 else
 if n <= head(numeri) then
 [n] ++ numeri
 else
 [head(numeri)] ++ inserisci(n, tail(numeri))
 end
 end
 end
 ordina(numeri: Numeri): Numeri // ordinamento di un array per inserzione
 if empty(numeri) then
 []
 else
 inserisci(head(numeri), ordina(tail(numeri)))
 end
 end
run
 write "Inserisci una sequenza di numeri da ordinare:\n";
 read numeri_da_ordinare;
 write "Sequenza di numeri ordinata:\n";
 write ordina(numeri_da_ordinare);
 end
EOF
