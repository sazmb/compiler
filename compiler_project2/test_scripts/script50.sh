#!/bin/bash
cat <<EOF
variables
    a : int;
run
    a = 9;
    write a * a;
end
EOF
