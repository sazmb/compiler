#!/bin/bash
cat <<EOF
types
    matrix = [ [int] ];
variables
    mat : matrix;
run
    mat = [ [1, 2], [3, 4] ];
    write mat[0][1];
end

EOF
