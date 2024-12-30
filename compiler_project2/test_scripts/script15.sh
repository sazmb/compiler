#!/bin/bash
cat <<EOF
types
    coords = { x : int, y : int };
variables
    point : coords;
run
    point = { 3, 4 };
    write point.x + point.y;
end

EOF
