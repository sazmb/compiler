#!/bin/bash
cat <<EOF
variables name : string;
run
write "Enter your name:";
read name;
write "Hello, ";
write name;
write "!";
end

EOF
