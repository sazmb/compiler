#!/bin/bash

# Lista dei file da creare
script_list=(

  "script61.sh"
   "script62.sh"
   "script63.sh"
   "script64.sh"
   "script65.sh"
   "script66.sh"
   "script67.sh"
   "script68.sh"
   "script69.sh"
   "script70.sh"

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
