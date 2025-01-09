#!/bin/bash
cat <<EOF
variables count, sum, num : int;
average : real;
run
sum = 0;
count = 0;
while count < 5 do
    read num;
    sum = sum + num;
    count = count + 1;
end;
average = sum / count;
write "Average: ";
write average;
end

EOF
