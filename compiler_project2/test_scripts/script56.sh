#!/bin/bash
cat <<EOF
variables names : [string];
name : string;
run
names = ["Alice", "Bob", "Charlie"];
foreach name in names do
    if name != "Bob" then
        write "Hello, ";
        write name;
    end;
end;
end

EOF
