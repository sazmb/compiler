#!/bin/bash
cat <<EOF
types
    num = int;
    str = string;
variables
    name : str;
    id : num;
run
    name = "John";
    id = 101;
    write name;
    write id;
end

EOF
