#!/bin/bash
cat <<EOF
functions factorial (n : int) : int
    if n <= 1 then 1 else n * factorial(n - 1) end
end
run
write factorial(4);
end

EOF
