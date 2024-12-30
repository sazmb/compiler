#!/bin/bash
cat <<EOF
types
    num = int;
variables
    x : int;
functions
    double(n : int) : int
        n + n
    end
run
    write double(5);
end
EOF
