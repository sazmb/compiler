#!/bin/bash
cat <<EOF
types
    person = { name : string, age : int };
variables
    friend : person;
run
    friend = { "Sam", 29 };
    write friend.name;
end
EOF
