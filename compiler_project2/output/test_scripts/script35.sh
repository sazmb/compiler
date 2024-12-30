#!/bin/bash
cat <<EOF
types
    money = real;
variables
    balance : money;
run
    balance = 100.5;
    write balance;
end
EOF
