# Get Next Line

## 📌 Descrizione
**Get Next Line (GNL)** è una funzione in C che permette di leggere un file riga per riga, restituendo ogni volta una nuova linea fino a raggiungere la fine del file (EOF). Il progetto utilizza una static buffer per conservare i dati tra chiamate successive e garantire un'efficiente gestione della memoria.

## 🔧 Compilazione e Utilizzo
### 📜 File del progetto
Il progetto è composto da:
- `get_next_line.c` → Implementazione della funzione principale.
- `get_next_line.h` → Header file con le dichiarazioni.
- `get_next_line_utils.c` → Contiene funzioni di supporto per la gestione delle stringhe.

### ⚙️ Compilazione
Per compilare un file che utilizza `get_next_line`, eseguire:
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl_test
```
📌 **Nota:** `BUFFER_SIZE` è una variabile che determina quanti byte vengono letti per volta.

### ▶️ Esempio di utilizzo
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## 🔍 Funzionamento della Funzione
### 📥 Input
- Un file descriptor valido.

### 📤 Output
- Restituisce una stringa contenente la linea letta (compresa di `\n` se presente).
- Restituisce `NULL` quando si raggiunge la fine del file o in caso di errore.

### 🔄 Processo Interno
1. **Verifica della static buffer** → Controlla se la buffer statica contiene già una linea completa.
2. **Lettura con `read()`** → Legge il file in blocchi di `BUFFER_SIZE` byte.
3. **Gestione della stash** → Memorizza dati tra chiamate successive e aggiorna il buffer per garantire la lettura riga per riga.
4. **Ritornare la linea** → Estrae una linea completa e aggiorna il buffer per la prossima chiamata.

## 📜 Funzioni Implementate
| Funzione | Descrizione |
|----------|------------|
| `get_next_line(int fd)` | Legge una linea dal file descriptor e la restituisce come stringa. |
| `check_stash(char *stash, size_t *bsn_pos)` | Controlla se nella stash c'è già una linea completa. |
| `upgrade_stash(char *stash)` | Aggiorna la stash eliminando la linea già restituita. |
| `join_stash(char *line, char *stash, int check, int bsn_pos)` | Aggiunge i caratteri necessari alla linea da restituire. |
| `read_text(char *stash, char *line, size_t bsn_pos, int fd)` | Legge dal file e costruisce la linea da restituire. |
| `gnl_strlen(const char *s)` | Calcola la lunghezza di una stringa. |
| `gnl_strndup(char *str, size_t size)` | Duplica una stringa fino a `size` caratteri. |
| `gnl_strjoin(char *s1, char *s2)` | Concatena due stringhe e libera la prima. |
| `gnl_free_line(char *line)` | Libera la memoria di una stringa e restituisce `NULL`. |

## ⚠️ Considerazioni
- `BUFFER_SIZE` può essere definito a piacere ma influenza le performance.
- Bisogna **liberare la memoria** dopo ogni chiamata per evitare **memory leaks**.
- Il comportamento su **file multipli** è supportato grazie alla gestione separata dei file descriptor.

## 🏆 Conclusione
`get_next_line` è un ottimo esercizio per comprendere la gestione della memoria e l'uso efficiente dei file descriptor in C. Se hai suggerimenti o domande, sentiti libero di contribuire! 🚀

