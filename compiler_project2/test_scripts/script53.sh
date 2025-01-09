#!/bin/bash
cat <<EOF
variables
v : [int];
count : int;
run
v = [1, 2, 3, 4, 5];
count = 0;
while count<=5 do
    write "ODD number: ";
    write v[count];
    count = count + 2;
end;
end

EOF
