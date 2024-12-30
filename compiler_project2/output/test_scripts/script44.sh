#!/bin/bash
cat <<EOF
variables
    grade : real;
run
    grade = 90.5;
    write grade;
end
EOF
