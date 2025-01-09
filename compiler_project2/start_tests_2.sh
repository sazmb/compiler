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
    "./test_scripts/script51.sh"
    "./test_scripts/script52.sh"
    "./test_scripts/script53.sh"
    "./test_scripts/script54.sh"
    "./test_scripts/script55.sh"
    "./test_scripts/script56.sh"
    "./test_scripts/script57.sh"
    "./test_scripts/script58.sh"
    "./test_scripts/script59.sh"
    "./test_scripts/script60.sh"
    "./test_scripts/script61.sh"
    "./test_scripts/script62.sh"
    "./test_scripts/script63.sh"
    "./test_scripts/script64.sh"
    "./test_scripts/script65.sh"
    "./test_scripts/script66.sh"
    "./test_scripts/script67.sh"
    "./test_scripts/script68.sh"
    "./test_scripts/script69.sh"
    "./test_scripts/script70.sh"


)

# Lista dei file di output per salvare i risultati
output_files=(
    "pcode_test/pcode_01.txt"
    "pcode_test/pcode_02.txt"
    "pcode_test/pcode_03.txt"
    "pcode_test/pcode_04.txt"
    "pcode_test/pcode_05.txt"
    "pcode_test/pcode_06.txt"
    "pcode_test/pcode_07.txt"
    "pcode_test/pcode_08.txt"
    "pcode_test/pcode_09.txt"
    "pcode_test/pcode_10.txt"
    "pcode_test/pcode_11.txt"
    "pcode_test/pcode_12.txt"
    "pcode_test/pcode_13.txt"
    "pcode_test/pcode_14.txt"
    "pcode_test/pcode_15.txt"
    "pcode_test/pcode_16.txt"
    "pcode_test/pcode_17.txt"
    "pcode_test/pcode_18.txt"
    "pcode_test/pcode_19.txt"
    "pcode_test/pcode_20.txt"
    "pcode_test/pcode_21.txt"
    "pcode_test/pcode_22.txt"
    "pcode_test/pcode_23.txt"
    "pcode_test/pcode_24.txt"
    "pcode_test/pcode_25.txt"
    "pcode_test/pcode_26.txt"
    "pcode_test/pcode_27.txt"
    "pcode_test/pcode_28.txt"
    "pcode_test/pcode_29.txt"
    "pcode_test/pcode_30.txt"
    "pcode_test/pcode_31.txt"
    "pcode_test/pcode_32.txt"
    "pcode_test/pcode_33.txt"
    "pcode_test/pcode_34.txt"
    "pcode_test/pcode_35.txt"
    "pcode_test/pcode_36.txt"
    "pcode_test/pcode_37.txt"
    "pcode_test/pcode_38.txt"
    "pcode_test/pcode_39.txt"
    "pcode_test/pcode_40.txt"
    "pcode_test/pcode_41.txt"
    "pcode_test/pcode_42.txt"
    "pcode_test/pcode_43.txt"
    "pcode_test/pcode_44.txt"
    "pcode_test/pcode_45.txt"
    "pcode_test/pcode_46.txt"
    "pcode_test/pcode_47.txt"
    "pcode_test/pcode_48.txt"
    "pcode_test/pcode_49.txt"
    "pcode_test/pcode_50.txt"
    "pcode_test/pcode_51.txt"
    "pcode_test/pcode_52.txt"
    "pcode_test/pcode_53.txt"
    "pcode_test/pcode_54.txt"
    "pcode_test/pcode_55.txt"
    "pcode_test/pcode_56.txt"
    "pcode_test/pcode_57.txt"
    "pcode_test/pcode_58.txt"
    "pcode_test/pcode_59.txt"
    "pcode_test/pcode_60.txt"
    "pcode_test/pcode_61.txt"
    "pcode_test/pcode_62.txt"
    "pcode_test/pcode_63.txt"
    "pcode_test/pcode_64.txt"
    "pcode_test/pcode_65.txt"
    "pcode_test/pcode_66.txt"
    "pcode_test/pcode_67.txt"
    "pcode_test/pcode_68.txt"
    "pcode_test/pcode_69.txt"
    "pcode_test/pcode_70.txt"
"pcode_test/pcode_61.txt"
"pcode_test/pcode_62.txt"
"pcode_test/pcode_63.txt"
"pcode_test/pcode_64.txt"
"pcode_test/pcode_65.txt"
"pcode_test/pcode_66.txt"
"pcode_test/pcode_67.txt"
"pcode_test/pcode_68.txt"
"pcode_test/pcode_69.txt"
"pcode_test/pcode_70.txt"


)
 # Vettore dei valori di uscita attesi (esempio: success=0, failure=1, custom=42, etc.)
  expected_exit_codes=(0 0 0 0 0
                       0 0 0 0 2
                       0 0 0 0 0
                       0 0 0 0 0
                       0 0 0 0 0
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
  PRINT_SUCCESS=false

  # Controlla se i parametri per l'intervallo sono stati passati
  if [[ "$1" == "-ver" ]]; then
      PRINT_SUCCESS=true
      shift  # Rimuovi -ver dai parametri per non interferire con gli altri
  fi

  # Verifica se sono stati passati gli estremi del ciclo (due numeri interi)
  if [[ $# -ge 2 ]]; then
      START_INDEX=$1
      END_INDEX=$2
      shift 2  # Rimuove gli estremi passati dalla lista dei parametri
  else
        START_INDEX=0
        END_INDEX=$((${#script_list[@]} - 1))
    fi

  # Loop per eseguire ciascuno script Bash e successivamente il programma C
  for ((index=$START_INDEX; index<=$END_INDEX; index++)); do
      script="${script_list[$index]}"
      output_file="${output_files[$index]}"

    # Verifica se lo script esiste ed è eseguibile
    if [[ -x "$script" ]]; then
        # Esegui lo script e passa l'output al programma C, salvando il risultato
        bash "$script" | "$C_PROGRAM" -o "$output_file" -

        # Verifica l'exit status
        exit_status=$?
        if [[ $exit_status -eq ${expected_exit_codes[$index]} ]]; then
            if $PRINT_SUCCESS; then
                echo "SUCCESS: Risultato salvato in $output_file"
            fi
        else
            echo "ERROR: Exit status errato ($exit_status) per $script"
        fi
    else
        echo "Errore: Lo script $script non è eseguibile o non esiste."
    fi

    echo "------------------------"
done

echo "Tutti gli script sono stati eseguiti."


