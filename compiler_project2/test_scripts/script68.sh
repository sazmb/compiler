#!/bin/bash
cat <<EOF
variables x : int;
run
read x;
write "You entered: ", x;
end
EOF
