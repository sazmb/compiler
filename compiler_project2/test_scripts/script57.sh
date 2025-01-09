#!/bin/bash
cat <<EOF
variables matrix : [int];
row : int;
value : int;
run
matrix = [1, 2];
foreach row in matrix do
    foreach value in matrix do
        write matrix[0] * 2;
    end;
end;
foreach value in matrix do
        write matrix[2] * 2;
    end;
end

EOF
