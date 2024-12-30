%{
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include "header_files/parser.h"
#include "header_files/def.h"
    int line = 1;
    Value lexval;
    int error;
%}
%option noyywrap
spacing ([ \t])+
letter [A-Za-z]
digit [0-9]
alfanum {digit}|{letter}
intconst {digit}+
strconst \"([^\"])*\"
boolconst false|true
realconst {intconst}\.{intconst}
id {letter}{alfanum}*(_{alfanum}+)*
comment \/\/.*\n
sugar [(){},;\.\[\]:]
EOF ^D
%%
{spacing} {};
{comment} {};
\n {line++;}
def {return(DEF);}
int {return(INT);}
real {return(REAL);}
string {return(STRING);}
bool {return(BOOL);}
types {return(TYPES);}
variables {return(VARIABLES);}
functions {return(FUNCTIONS);}
end {return(END);}

{intconst} {lexval.ival = atoi(yytext); return(INTCONST);}
{realconst} {lexval.rval = stringToFloat(yytext, &error); return(REALCONST);}
{strconst} {lexval.sval = newstring(yytext); return(STRCONST);}
{boolconst} {lexval.bval = (yytext[0] == 'f' ? FALSE : TRUE); return(BOOLCONST);}

{sugar} {return(yytext[0]);}

and {return (AND);}
or {return(OR);}

"++" {return(CONCAT);}
"+" {return(PLUS);}
"-" {return(MINUS);}

"*" {return(MUL);}
"/" {return(DIVIDE);}

"<=" {return(LE);}
"<" {return(LT);}
"==" {return(EQUAL);}
"!=" {return(NEQUAL);}
">" {return(GT);}
">=" {return(GE);}
in {return(IN);}
= {return(ASSIGN);}

empty {return(EMPTY_TOKEN);}
head {return(HEAD_TOKEN);}
tail {return(TAIL_TOKEN);}

if {return(IF);}
then {return(THEN);}
else {return(ELSE);}

run {return(RUN);}
read {return(READ_TOKEN);}
write {return(WRITE);}

while {return(WHILE);}
do {return(DO);}

foreach {return(FOREACH);}
{id} {lexval.sval = newstring(yytext); return(ID);}
. {return(ERROR);}
%%
char *newstring(char *s)
{
  char *p;

  p = malloc(strlen(s)+1);
  strcpy(p, s);
  return(p);
}
float stringToFloat(const char *str, int *error) {
    char *endptr;
    errno = 0; // To distinguish success/failure after the call
    float result = strtof(str, &endptr);

    // Check for various possible errors
    if (errno == ERANGE) {
        if (result == 0.0f) {
            *error = 1; // Underflow
            return 0.0f;
        }
        else if (result == HUGE_VALF || result == -HUGE_VALF) {
            *error = 2; // Overflow
            return result;
        }
    }

    if (endptr == str) {
        // No digits were found
        *error = 3;
        return 0.0f;
    }

    // If we reach here, the conversion was successful
    *error = 0;
    return result;
}