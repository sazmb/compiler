#!/bin/bash
cat <<EOF
types
    arr = [int];
variables
    numbers : arr;
run
     numbers = [1, 2, 3, 4];
        write numbers[2];
end
EOF
