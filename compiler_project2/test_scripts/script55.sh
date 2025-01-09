#!/bin/bash
cat <<EOF
variables nums : [int];
num : int;
run
nums = [1, 2, 3, 4, 5];
foreach num in nums do
    write num * num;
    write " ";
end;
end

EOF
