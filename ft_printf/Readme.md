# 🖨 ft_printf

## 📌 Descrizione
`ft_printf` è una reimplementazione della funzione `printf` della libreria standard di C. Permette di stampare vari tipi di dati su `stdout` gestendo diversi specificatori di formato.

## 🚀 Funzionalità
- ✅ Supporta i seguenti specificatori:
  - `%c` → Carattere
  - `%s` → Stringa
  - `%d` / `%i` → Intero con segno
  - `%u` → Intero senza segno
  - `%x` / `%X` → Numeri esadecimali (minuscolo/maiuscolo)
  - `%p` → Puntatore (indirizzo di memoria)
  - `%%` → Percentuale
- ✅ Gestione degli argomenti variadici con `va_list`
- ✅ Conta e restituisce il numero di caratteri stampati

## 🛠 Funzioni principali
- **`ft_printf`** → Funzione principale che analizza la stringa e richiama le funzioni di stampa appropriate.
- **`ft_condition`** → Determina quale funzione di stampa usare in base al carattere dopo `%`.
- **`ft_putchar_count`** → Stampa un carattere e aggiorna il conteggio.
- **`ft_putstr_count`** → Stampa una stringa gestendo il caso `NULL`.
- **`ft_putint_count`** → Stampa un numero intero con gestione del segno.
- **`ft_putuns_int_count`** → Stampa un numero intero senza segno.
- **`ft_puthex_low_count` / `ft_puthex_up_count`** → Stampa numeri esadecimali.
- **`ft_putptr_count`** → Stampa un puntatore in esadecimale.
- **`ft_putnbr_base_count`** → Funzione ricorsiva per convertire numeri in diverse basi.
- **`ft_strlen`** → Calcola la lunghezza di una stringa.

## 🏗 Compilazione
Per compilare la libreria, usa il `Makefile` incluso:
```bash
make
```
Per rimuovere i file oggetto:
```bash
make clean
```
Per rimuovere anche l'eseguibile:
```bash
make fclean
```
Per ricompilare da zero:
```bash
make re
```

## 📜 Esempio di utilizzo
```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! You have %d new messages.\n", "Alice", 5);
    return 0;
}
```
🔹 Output:
```
Hello, Alice! You have 5 new messages.
```

## 🏁 Conclusione
Questo progetto è stato un'ottima occasione per approfondire l'uso delle funzioni variadiche e la gestione della formattazione dell'output. Se hai suggerimenti o vuoi contribuire, sentiti libero di farlo! 🚀

