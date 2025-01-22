#!/bin/bash
cat <<EOF
types
    age = int;

variables
    person_age : age;
    num : int;
run
    person_age = 25;
    write "indovina l'età";
    read num;
    if person_age !=num then
    write " non hai indovinato";
    else
    write "hai indovinato";
    end;
end

EOF
