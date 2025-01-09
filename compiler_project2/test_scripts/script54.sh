#!/bin/bash
cat <<EOF
variables
a : int;
b : int;
run
a = 1;
b = 1;
while a < 5 do
    while b < 5 do
        write "a: ";
        write a;
        write" b: ";
        write b;
        b = b + 1;
    end;
    b = 1;  // Reset b
    a = a + 1;
end;
end

EOF
