#!/bin/bash
cat <<EOF
types
    person = { name : string, age : int };
variables
    p : person;
run
    p = { "Bob", 25 };
    write p.name;
end
EOF
