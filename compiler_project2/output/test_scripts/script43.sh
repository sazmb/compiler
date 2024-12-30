#!/bin/bash
cat <<EOF
variables
    x, y : int;
run
    x = 100;
    y = 200;
    if x < y then
        write "x is less than y";
    end;
end
EOF
