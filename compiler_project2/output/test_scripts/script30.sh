#!/bin/bash
cat <<EOF
variables
    x : int;
run
    x = 12;
    write x;
end
EOF
