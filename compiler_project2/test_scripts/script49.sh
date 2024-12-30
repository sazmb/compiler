#!/bin/bash
cat <<EOF
types
    real_arr = [real];
variables
    prices : real_arr;
run
    prices = [10.99, 20.99, 30.99];
    write prices[2];
end
EOF
