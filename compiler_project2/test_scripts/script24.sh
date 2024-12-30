#!/bin/bash
cat <<EOF
types
    matrix = [ [real] ];
variables
    m : matrix;
run
    m = [ [1.2, 2.3], [3.4, 4.5] ];
    write m[1][1];
end

EOF
