#!/bin/bash
cat <<EOF
variables
    x : int;
    y : int;
run
    x = 10;
    y = 20;
    write x + y;
end

EOF
