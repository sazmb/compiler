#!/bin/bash
cat <<EOF
types
    record = { a : int, b : int };
variables
    rec : record;
run
    rec = { 1, 2 };
    write rec.a + rec.b;
end

EOF
