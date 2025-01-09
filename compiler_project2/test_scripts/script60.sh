#!/bin/bash
cat <<EOF
variables
x : int;
run
x = 10;
while x > 0 and x - 2 != 7 do
    write "Counting down: ";
     write x;
    x = x - 2;
end;
end

EOF
