#!/bin/bash
cat <<EOF
variables arr : [int];
i : int;
run
arr = [5, 10, 15];
i = 0;
while i < 3 do
    arr[i] = arr[i] + 1;
    write arr[i];
    i = i + 1;
end;
end

EOF
