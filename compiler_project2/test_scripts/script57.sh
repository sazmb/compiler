#!/bin/bash
cat <<EOF
variables matrix : [int];
row : int;
value : int;
run
matrix = [1, 2];
foreach row in matrix do
    foreach value in matrix do
        write value * 2;
        write " ";
    end;
end;
foreach value in matrix do
        write 3 * 2;
        write " ";
    end;
end

EOF
