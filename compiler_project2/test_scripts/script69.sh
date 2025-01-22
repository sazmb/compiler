#!/bin/bash
cat <<EOF
variables
i : int;
functions fibonacci (x : int) : int
 if x==1 or x==0 then
        x
      else
        fibonacci(x-1) + fibonacci(x-2)
        end
end
run
read i;
write fibonacci(i);
end

EOF
