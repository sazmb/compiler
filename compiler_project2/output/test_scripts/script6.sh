#!/bin/bash
cat <<EOF
variables
    flag : bool;
run
    flag = true;
    if flag then
        write "chess!";
    else write "Unsuccess";
        end;
end

EOF
