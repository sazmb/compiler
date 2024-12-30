#!/bin/bash
cat <<EOF
variables
    result : int;
run
    result = 8 * 3;
    write result;
end

EOF
