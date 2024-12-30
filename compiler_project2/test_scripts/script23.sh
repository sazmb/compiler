#!/bin/bash
cat <<EOF
types
    num = int;
variables
    n : num;
run
    n = 10;
    if n > 5 then
        write "Greater than 5";
    end
end

EOF
