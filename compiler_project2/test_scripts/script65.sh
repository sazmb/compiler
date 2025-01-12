#!/bin/bash
cat <<EOF
variables
rec: { intero : int, stringa : string};
run
write "\n record: ";
read rec;
write " record: ";
write  rec;
end
EOF
