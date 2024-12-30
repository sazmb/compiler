#!/bin/bash
cat <<EOF
types
    num = int;
variables
    a, b, c : num;
run
    a = 2;
    b = 3;
    c = a + b;
    write c;
end

EOF
