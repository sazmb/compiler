#!/bin/bash
cat <<EOF
types
    ages = [int];
variables
    a : ages;
run
    a = [22, 30, 25];
    write a[1];
end
EOF
