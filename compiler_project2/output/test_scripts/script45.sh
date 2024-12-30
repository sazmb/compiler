#!/bin/bash
cat <<EOF
types
    check = bool;
variables
    status : check;
run
    status = true;
    write status;
end
EOF
