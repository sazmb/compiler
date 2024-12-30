#!/bin/bash
cat <<EOF
variables
    text : string;
run
    text = "Hello World";
    write text;
end

EOF
