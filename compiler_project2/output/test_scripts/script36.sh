#!/bin/bash
cat <<EOF
types
    pos = { x : int, y : int };
variables
    point : pos;
run
    point = { 10, 15 };
    write point.x;
end
EOF
