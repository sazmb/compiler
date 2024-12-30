#!/bin/bash
cat <<EOF
types
    check = bool;
variables
    is_valid : check;
run
    is_valid = false;
    write is_valid;
end
EOF
