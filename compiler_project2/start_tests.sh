#!/bin/bash

# Percorso del programma C già compilato
C_PROGRAM="./bup"  # Sostituisci con il percorso del tuo programma C

# Lista degli script bash da eseguire ciclicamente
script_list=(
    "./test_scripts/script1.sh"
    "./test_scripts/script2.sh"
    "./test_scripts/script3.sh"
    "./test_scripts/script4.sh"
    "./test_scripts/script5.sh"
    "./test_scripts/script6.sh"
    "./test_scripts/script7.sh"
    "./test_scripts/script8.sh"
    "./test_scripts/script9.sh"
    "./test_scripts/script10.sh"
    "./test_scripts/script11.sh"
    "./test_scripts/script12.sh"
    "./test_scripts/script13.sh"
    "./test_scripts/script14.sh"
    "./test_scripts/script15.sh"
    "./test_scripts/script16.sh"
    "./test_scripts/script17.sh"
    "./test_scripts/script18.sh"
    "./test_scripts/script19.sh"
    "./test_scripts/script20.sh"
    "./test_scripts/script21.sh"
    "./test_scripts/script22.sh"
    "./test_scripts/script23.sh"
    "./test_scripts/script24.sh"
    "./test_scripts/script25.sh"
    "./test_scripts/script26.sh"
    "./test_scripts/script27.sh"
    "./test_scripts/script28.sh"
    "./test_scripts/script29.sh"
    "./test_scripts/script30.sh"
    "./test_scripts/script31.sh"
    "./test_scripts/script32.sh"
    "./test_scripts/script33.sh"
    "./test_scripts/script34.sh"
    "./test_scripts/script35.sh"
    "./test_scripts/script36.sh"
    "./test_scripts/script37.sh"
    "./test_scripts/script38.sh"
    "./test_scripts/script39.sh"
    "./test_scripts/script40.sh"
    "./test_scripts/script41.sh"
    "./test_scripts/script42.sh"
    "./test_scripts/script43.sh"
    "./test_scripts/script44.sh"
    "./test_scripts/script45.sh"
    "./test_scripts/script46.sh"
    "./test_scripts/script47.sh"
    "./test_scripts/script48.sh"
    "./test_scripts/script49.sh"
    "./test_scripts/script50.sh"


    # Aggiungi altri script se necessario
)
  # Vettore dei valori di uscita attesi (esempio: success=0, failure=1, custom=42, etc.)
  expected_exit_codes=(0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0 )
  # Contatore per indicare l'indice corrente del vettore di valori attesi
    index=0

# Controlla se il programma C esiste
if [[ ! -x "$C_PROGRAM" ]]; then
    echo "Errore: Il programma C non è eseguibile o non esiste."
    exit 1
fi

# Loop per eseguire ciascuno script Bash e successivamente il programma C
for script in "${script_list[@]}"; do
    # Verifica se lo script esiste ed è eseguibile
    if [[ -x "$script" ]]; then
        echo "Eseguendo lo script $script"
            # Ottieni l'exit status dell'ultima esecuzione del programma C
            if [ "$1" == "-all" ]; then
             script_output=$(bash "$script")
             fi

            C_PROGRAM_OPTIONS="/mnt/c/Users/samue/Desktop/compiler_project2/output/code.txt"  # Esempio di opzione per specificare l'output
            C_PROGRAM_OPTION_2=" -"  # Esempio di opzione per specificare l'output
            "$script" | "$C_PROGRAM" -o "$C_PROGRAM_OPTIONS" - # Esegui il programma C
            exit_status=$?
            # Verifica se l'exit status corrisponde a quello atteso
            if [[ $exit_status -eq ${expected_exit_codes[$index]} ]]; then
                echo "SUCCESS: Exit status corretto ($exit_status)"
            else
              echo "ERROR: Exit status errato! Atteso: ${expected_exit_codes[$index]}, Ricevuto: $exit_status"
            fi

            # Incrementa l'indice per passare al prossimo valore atteso (opzionale, se necessario)
            ((index++))


        echo "------------------------"
    else
        echo "Errore: Lo script $script non è eseguibile o non esiste."
    fi
done

echo "Tutti gli script sono stati eseguiti."
