#!/bin/bash
cat <<EOF
types
    temp = real;
variables
    temperature : temp;
run
    temperature = 36.5;
    write temperature;
end

EOF
