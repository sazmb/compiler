#!/bin/bash
cat <<EOF
variables
    x, y : int;
run
    x = 3;
    y = 4;
    if x + y == 7 then
        write "Sum is 7";
    end;
end
EOF
