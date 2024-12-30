#!/bin/bash
cat <<EOF
types
    status = bool;
variables
    flag : status;
run
    flag = false;
    write flag;
end

EOF
