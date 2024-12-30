#!/bin/bash
cat <<EOF
types
    points = { x : int, y : int };
variables
    p : points;
run
    p = { 5, 8 };
    write p.x + p.y;
end
EOF
