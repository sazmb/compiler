#!/bin/bash
cat <<EOF
types
    grades = [int];
variables
    g : grades;
run
    g = [70, 80, 90];
    write g[0] + g[1] + g[2];
end
EOF
