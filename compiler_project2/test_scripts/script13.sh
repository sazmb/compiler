#!/bin/bash
cat <<EOF
types
    num = int;
functions
    add(a : num, b : num) : num
        a + b
    end
run
    write add(3, 4);
end

EOF
