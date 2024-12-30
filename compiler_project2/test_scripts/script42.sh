#!/bin/bash
cat <<EOF
variables
    x : int;
run
    x = 10;
    write x;
end
EOF
