#!/bin/bash
cat <<EOF
types
    coords = { lat : real, lon : real };
variables
    location : coords;
run
    location = { 40.7128, 74.0060 };
    write location.lat;
end
EOF
