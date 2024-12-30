#!/bin/bash
cat <<EOF
types
    marks = [real];
variables
    score : marks;
run
    score = [75.5, 88.2, 92.0];
    write score[2];
end

EOF
