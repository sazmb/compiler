#!/bin/bash
cat <<EOF
types
    arr = [int];
variables
    values : arr;
run
    values = [10, 20, 30];
    if values[1] > 15 then
        write "Greater than 15";
    end
end

EOF
