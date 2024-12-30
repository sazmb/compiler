#!/bin/bash
cat <<EOF
variables
    result : int;
run
    result = 5 * 4;
    write result;
end
EOF
