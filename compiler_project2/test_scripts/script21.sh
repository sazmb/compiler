#!/bin/bash
cat <<EOF
variables
    a : int;
    b : int;
run
    a = 7;
    b = 14;
    if a < b then
        write "A is smaller";
    end;
end

EOF
