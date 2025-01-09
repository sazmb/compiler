#!/bin/bash
cat <<EOF
variables nums : [int];
i : int;
num : int;
run
nums = [];
i = 0;
while i < 5 do
    read num;
    nums = nums ++ [num];
    i = i + 1;
end;
write "Array: ";
write  nums;
end

EOF
