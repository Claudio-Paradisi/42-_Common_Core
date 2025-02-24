# Libft

## 📌 Descrizione

Libft è una libreria di funzioni scritte in **C** che ricreano molte delle funzioni standard della libreria C (*stdlib.h*, *string.h*, *ctype.h*, etc.), insieme ad alcune funzioni extra per la gestione delle liste concatenate. Questo progetto è il primo passo per costruire una base solida di funzioni riutilizzabili nei progetti futuri.

## 📁 Struttura del Progetto

Il progetto è suddiviso in diverse sezioni:

- **Funzioni della libc** → Ricreazione di funzioni standard della libreria C.
- **Funzioni aggiuntive** → Funzioni utili per la manipolazione di stringhe, memoria e numeri.
- **Funzioni bonus** → Strutture dati e operazioni su liste concatenate.

## 🔧 Compilazione e Utilizzo

Per compilare la libreria ed ottenere il file `libft.a`, eseguire:

```sh
make
```

Per pulire i file oggetto generati:

```sh
make clean
```

Per rimuovere anche la libreria compilata:

```sh
make fclean
```

Per ricompilare da zero:

```sh
make re
```

Una volta compilata, puoi includere `libft.h` nel tuo progetto e linkare la libreria:

```c
#include "libft.h"
```

E compilarlo con:

```sh
gcc -Wall -Wextra -Werror -L. -lft my_program.c -o my_program
```

---

## 📌 Funzioni Implementate

### 🏛 Funzioni della LibC

Queste funzioni replicano quelle della standard library C.

| Funzione     | Descrizione                                                        |
| ------------ | ------------------------------------------------------------------ |
| `ft_memset`  | Riempie un'area di memoria con un valore specifico.                |
| `ft_bzero`   | Azzera un'area di memoria.                                         |
| `ft_memcpy`  | Copia un'area di memoria in un'altra.                              |
| `ft_memmove` | Copia un'area di memoria gestendo sovrapposizioni.                 |
| `ft_memchr`  | Cerca un carattere in un'area di memoria.                          |
| `ft_memcmp`  | Confronta due aree di memoria.                                     |
| `ft_strlen`  | Calcola la lunghezza di una stringa.                               |
| `ft_strlcpy` | Copia una stringa in modo sicuro.                                  |
| `ft_strlcat` | Concatena due stringhe in modo sicuro.                             |
| `ft_strchr`  | Cerca un carattere in una stringa.                                 |
| `ft_strrchr` | Cerca un carattere in una stringa, partendo dalla fine.            |
| `ft_strncmp` | Confronta due stringhe fino a un massimo di `n` caratteri.         |
| `ft_strnstr` | Cerca una sottostringa in una stringa, con un limite di caratteri. |
| `ft_atoi`    | Converte una stringa in un intero.                                 |
| `ft_isalpha` | Verifica se un carattere è alfabetico.                             |
| `ft_isdigit` | Verifica se un carattere è numerico.                               |
| `ft_isalnum` | Verifica se un carattere è alfanumerico.                           |
| `ft_isascii` | Verifica se un carattere appartiene alla tabella ASCII.            |
| `ft_isprint` | Verifica se un carattere è stampabile.                             |
| `ft_toupper` | Converte un carattere in maiuscolo.                                |
| `ft_tolower` | Converte un carattere in minuscolo.                                |
| `ft_calloc`  | Alloca memoria azzerata per un array.                              |
| `ft_strdup`  | Duplica una stringa.                                               |

### 🛠 Funzioni Aggiuntive

Queste funzioni offrono utilità aggiuntive rispetto alla standard library.

| Funzione        | Descrizione                                                                       |
| --------------- | --------------------------------------------------------------------------------- |
| `ft_substr`     | Estrae una sottostringa da una stringa.                                           |
| `ft_strjoin`    | Concatena due stringhe in una nuova stringa.                                      |
| `ft_strtrim`    | Rimuove i caratteri specificati dall'inizio e dalla fine di una stringa.          |
| `ft_split`      | Divide una stringa in un array di sottostringhe, usando un delimitatore.          |
| `ft_itoa`       | Converte un intero in una stringa.                                                |
| `ft_strmapi`    | Applica una funzione a ogni carattere di una stringa.                             |
| `ft_striteri`   | Applica una funzione a ogni carattere di una stringa, modificandola direttamente. |
| `ft_putchar_fd` | Scrive un carattere su un file descriptor.                                        |
| `ft_putstr_fd`  | Scrive una stringa su un file descriptor.                                         |
| `ft_putendl_fd` | Scrive una stringa seguita da un newline su un file descriptor.                   |
| `ft_putnbr_fd`  | Scrive un numero su un file descriptor.                                           |

### 🔗 Funzioni Bonus (Liste Concatenate)

Queste funzioni gestiscono una lista concatenata semplice.

| Funzione          | Descrizione                                               |
| ----------------- | --------------------------------------------------------- |
| `ft_lstnew`       | Crea un nuovo nodo della lista.                           |
| `ft_lstadd_front` | Aggiunge un nodo all'inizio della lista.                  |
| `ft_lstadd_back`  | Aggiunge un nodo alla fine della lista.                   |
| `ft_lstsize`      | Restituisce la dimensione della lista.                    |
| `ft_lstlast`      | Restituisce l'ultimo nodo della lista.                    |
| `ft_lstdelone`    | Elimina un nodo della lista.                              |
| `ft_lstclear`     | Elimina tutti i nodi della lista.                         |
| `ft_lstiter`      | Applica una funzione a ogni nodo della lista.             |
| `ft_lstmap`       | Crea una nuova lista applicando una funzione a ogni nodo. |

---

## 🏆 Conclusione

Libft è un progetto essenziale per comprendere il funzionamento della standard library di C e per creare una base solida di funzioni riutilizzabili nei progetti futuri.

Se hai suggerimenti o vuoi contribuire, sentiti libero di aprire una *pull request* o segnalare un *issue*! 🚀

