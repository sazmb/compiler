#!/bin/bash
cat <<EOF
types
    real_list = [real];
variables
    values : real_list;
run
    values = [1.1, 2.2, 3.3];
    write values[0] + values[1];
end

EOF
