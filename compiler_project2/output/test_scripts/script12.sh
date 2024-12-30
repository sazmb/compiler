#!/bin/bash
cat <<EOF
types
    arr = [int];
variables
    a : arr;
run
    a = [5, 10, 15];
    write a[1];
end

EOF
