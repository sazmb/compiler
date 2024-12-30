#!/bin/bash
cat <<EOF
types
    info = { name : string, age : int };
variables
    person : info;
run
    person = { "Alice", 30 };
    write person.name;
    write person.age;
end

EOF
