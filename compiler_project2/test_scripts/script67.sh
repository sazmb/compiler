#!/bin/bash
cat <<EOF
functions max (a : int, b : int) : int
    if a > b then a else b end
end
run
write max(15, 10);
end

EOF
