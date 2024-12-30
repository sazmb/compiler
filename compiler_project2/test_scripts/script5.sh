#!/bin/bash
cat <<EOF
types
    rect = { length : int, width : int };
variables
    my_rect : rect;
run
    my_rect = { 5, 10 };
    write my_rect.length * my_rect.width;
end

EOF
