#!/bin/bash
cat <<EOF
types
    num = int;
variables
    x : int;
functions
    square(a : int) : int
        a * a
    end
run
    x = 4;
    write square(x);
end

EOF
