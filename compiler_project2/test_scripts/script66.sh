#!/bin/bash
cat <<EOF
variables
 array_rec: [{ intero : int, stringa : string}];
run
write "Array of record: ";
read array_rec;
write " arr of record: ";
write  array_rec;
write " array_rec[1].intero: ";
write array_rec[1].intero;
write " array_rec[0].stringa: ";
write array_rec[0].stringa;
end
EOF
