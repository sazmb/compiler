#!/bin/bash
cat <<EOF
types
    pair = { first : int, second : int };
variables
    p : pair;
run
    p = { 5, 8 };
    write p.first + p.second;
end

EOF
