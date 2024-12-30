#!/bin/bash
cat <<EOF
types
    flag = bool;
variables
    check : bool;
functions
    is_true(val : bool) : bool
        val == true
    end
run
    write is_true(true);
end

EOF
