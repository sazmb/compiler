#!/bin/bash
cat <<EOF
variables
    num1, num2 : int;
run
    num1 = 15;
    num2 = 30;
    write num1 * num2;
end
EOF
