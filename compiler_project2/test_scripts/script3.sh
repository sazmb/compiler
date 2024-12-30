#!/bin/bash
cat <<EOF
types
    age = int;
variables
    person_age : age;
run
    person_age = 25;
    write person_age;
end

EOF
