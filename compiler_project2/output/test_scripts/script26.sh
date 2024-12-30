#!/bin/bash
cat <<EOF
variables
    grade : real;
run
    grade = 85.7;
    write grade;
end

EOF
