#!/bin/bash
cat <<EOF
variables
 nums : [int];
 i : int;
 rec: { intero : int , stringa : string };
 array_rec: [{ intero : int, stringa : string}];
run
nums = [];
i = 0;
write "\n Array: ";
read nums;
write "\n record: ";
read rec;
write "\n Array of record: ";
read array_rec;

write "\n Array: ";
write  nums;
write "\n record: ";
write  rec;
write "\n arr of record: ";
write  array_rec;
end

EOF
