#!/bin/bash
cat <<EOF
variables
index : int;
run
index = 5;
while index >= 0 do
    write "Index: ";
    write index;
    index = index - 1;
end;
end

EOF
