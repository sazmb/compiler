#!/bin/bash
cat <<EOF
variables nums : [int];
i : int;
num : int;
run
nums = [2, 4, 6, 8];
i = 0;
while i < 2 do
    foreach num in nums do
        write num * i;
    end;
    i = i + 1;
end;
end

EOF
