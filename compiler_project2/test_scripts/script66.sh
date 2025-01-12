#!/bin/bash
cat <<EOF
variables
 array_rec: [{ intero : int, stringa : string}];
run
write "\n Array of record: ";
read array_rec;
write "\n arr of record: ";
write  array_rec;
end
EOF
