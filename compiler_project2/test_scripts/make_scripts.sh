#!/bin/bash

# Ciclo per creare 50 file .sh
for i in {1..50}; do
    filename="script$i.sh"

    # Creazione del file e aggiunta di uno shebang per Bash
    echo "#!/bin/bash" > "$filename"

    # Aggiungi un comando di esempio dentro ogni script
    echo "echo \"Esecuzione dello script $filename\"" >> "$filename"

    # Rendi il file eseguibile
    chmod +x "$filename"

    echo "Creato $filename"
done

echo "Tutti i 50 file .sh sono stati creati."
