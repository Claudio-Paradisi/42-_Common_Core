# 🚀 pipex

## 📌 Descrizione
**pipex** è un progetto di 42 che replica il comportamento della pipeline Unix `|` in C, consentendo di collegare il flusso di output di un comando all'input di un altro.

---

## 🛠️ Funzionamento
Il programma viene eseguito con il seguente formato:

```bash
./pipex file1 cmd1 cmd2 file2
```

📝 Questo comando esegue:
1. **Legge** da `file1`
2. **Esegue** `cmd1` prendendo `file1` come input
3. **Passa** l'output di `cmd1` come input a `cmd2`
4. **Scrive** il risultato in `file2`

Esempio di utilizzo:
```bash
./pipex input.txt "cat -e" "grep foo" output.txt
```
Sarà equivalente a eseguire:
```bash
< input.txt cat -e | grep foo > output.txt
```

---

## 🏗️ Implementazione

🔹 **Uso di pipe() e fork()**: Pipex crea una pipe per collegare i due processi figli, poi usa `fork()` per eseguire i comandi in due processi separati.

🔹 **Esecuzione dei comandi**: I comandi vengono trovati nel `PATH` e eseguiti con `execve()`.

🔹 **Gestione degli errori**: Se un file non esiste o un comando non è valido, viene gestito con messaggi di errore.

---

## 📂 File principali
- `pipex.c` → Contiene la logica principale del programma
- `utils` → Cartella con funzioni di supporto
- `src` → Cartella con funzioni essenziali per l'esecuzione del programma (esecuzione dei comandi, gesione errori, ecc-)
- `get_next_line` → Cartella contenente i file della omonima funzione
- `here_doc` → Cartella contenente le funzioni necessarie per il **bonus** here_doc
- `Makefile` → Compila il progetto generando l'eseguibile `pipex`

---

## 🔧 Compilazione e utilizzo

Per compilare il programma, eseguire:
```bash
make
```
Per eseguirlo:
```bash
./pipex file1 cmd1 cmd2 file2
```
Per rimuovere i file oggetto e l'eseguibile:
```bash
make fclean
```

---

## 🎯 Bonus
Il progetto include anche i **bonus** con supporto per:
✅ Più comandi in pipeline (`cmd1 | cmd2 | cmd3 | ...`)
✅ Supporto per `<<` (here_doc) per gestire input multi-linea

---

## 🏆 Conclusione
**pipex** è un ottimo esercizio per imparare a gestire processi e pipe in C, avvicinandosi al funzionamento interno della shell! 🖥️🔥

