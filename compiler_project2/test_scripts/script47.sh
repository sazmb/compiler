#!/bin/bash
cat <<EOF
variables
    num : int;
run
    num = 7;
    write num * num;
end
EOF
