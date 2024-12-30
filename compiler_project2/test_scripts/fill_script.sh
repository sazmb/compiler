#!/bin/bash

# Lista dei file da creare
script_list=(
  "script1.sh"
  "script2.sh"
  "script3.sh"
  "script4.sh"
  "script5.sh"
  "script6.sh"
  "script7.sh"
  "script8.sh"
  "script9.sh"
  "script10.sh"
  "script11.sh"
  "script12.sh"
  "script13.sh"
  "script14.sh"
  "script15.sh"
  "script16.sh"
  "script17.sh"
  "script18.sh"
  "script19.sh"
  "script20.sh"
  "script21.sh"
  "script22.sh"
  "script23.sh"
  "script24.sh"
  "script25.sh"
  "script26.sh"
  "script27.sh"
  "script28.sh"
  "script29.sh"
  "script30.sh"
  "script31.sh"
  "script32.sh"
  "script33.sh"
  "script34.sh"
  "script35.sh"
  "script36.sh"
  "script37.sh"
  "script38.sh"
  "script39.sh"
  "script40.sh"
  "script41.sh"
  "script42.sh"
  "script43.sh"
  "script44.sh"
  "script45.sh"
  "script46.sh"
  "script47.sh"
  "script48.sh"
  "script49.sh"
  "script50.sh"

)

# Funzione per generare un programma esempio basato sulla BNF
crea_programma_bnf() {
    echo "#!/bin/bash" > "$1"
   echo "cat <<EOF">>"$1"

  echo "EOF">>"$1"

}

# Loop per creare ciascun file
for script in "${script_list[@]}"; do
    crea_programma_bnf "$script"
    echo "Creato $script"
done

echo "Tutti i 50 file sono stati creati con programmi esempio."
