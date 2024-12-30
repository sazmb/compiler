#!/bin/bash
cat <<EOF
variables
    a, b : int;
run
    a = 10;
    b = 20;
    write a + b;
end
EOF
