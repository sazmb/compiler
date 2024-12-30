#!/bin/bash
cat <<EOF
types
    price = real;
variables
    item_price : price;
run
    item_price = 19.99;
    write item_price;
end

EOF
