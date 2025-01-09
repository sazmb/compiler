#!/bin/bash
cat <<EOF
variables
x : int;
run
x = 0;
while x < 10 do
    write x;
    x = x + 1;
end;
end

EOF
