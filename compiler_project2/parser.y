%{
#include "header_files/def.h"
#define YYSTYPE Pnode
extern char *yytext;
extern Value lexval;
extern int line;
extern FILE *yyin;
extern int yylineno;
extern int yydebug;
yydebug=1;
char *currentRule;
Pnode root=NULL;
%}
//%debug
%token DEF INT STRING BOOL REAL ID INTCONST REALCONST STRCONST BOOLCONST TYPES ASSIGN ERROR VARIABLES FUNCTIONS
%token IF THEN ELSE END RUN
%token READ_TOKEN WRITE WHILE FOREACH IN DO
%token AND OR ADD SUB CONCAT EQUAL NEQUAL GT GE LE LT PLUS MINUS MUL DIVIDE NOT MINUSSIGN CAST_INT CAST_REAL
%token EMPTY_TOKEN HEAD_TOKEN TAIL_TOKEN

%left AND OR
%nonassoc EQUAL NEQUAL GT GE LE LT IN
%left PLUS MINUS CONCAT
%left MUL DIVIDE
%right NOT MINUSSIGN

%%

program : type_section var_section func_section run_section {  currentRule="program";

                                                             root=$$= nontermnode(NPROGRAM);
                                                            $$->c1=$1;
                                                            $$->c2=$2;
                                                            $$->c3=$3;
                                                            $$->c4=$4;}
         ;
type_section : TYPES type_decl_list { currentRule="type_section_1";
                                      $$= nontermnode(NTYPESEC);
                                      $$->c1=$2;}
             | {currentRule="type_section_2";
                $$=NULL;}
             ;
type_decl_list: type_decl type_decl_list{currentRule="type_decl_list_1";$$=$1;
                                         $$->b=$2;
                                         }
               | type_decl{currentRule="type_decl_list_2"; $$=$1;}
               ;
type_decl: id_list ASSIGN type ';' { currentRule="type_decl_1";
                                    $$=nontermnode(NTYPEDECL);
                                     $$->c1=$1;
                                     $$->c2=$3;}
           ;
id_list: ID{$$= idnode();} ',' id_list{ currentRule="id_list_1";
                                        $$=$2;
                                        $$->b=$4;}
       |ID{currentRule="id_list_2";$$=idnode();}
       ;
type: atomic_type { currentRule="type_1";
                    $$=$1;}
     | record_type { currentRule="type_2";
                                       $$=$1;}
     | array_type { currentRule="type_3";
                                      $$=$1;}
     ;
atomic_type  : INT {currentRule="atomic_type_1";$$ = keynode(T_INTEGER);}
              | REAL {currentRule="atomic_type_2";$$ = keynode(T_REAL);}
              | STRING {currentRule="atomic_type_3";$$ = keynode(T_STRING);}
              | BOOL{currentRule="atomic_type_4";$$ = keynode(T_BOOLEAN);}
              | ID{currentRule="atomic_type_5";$$ = idnode();}
              ;
record_type: '{' atomic_decl_list '}' {currentRule="record_type_1";$$=nontermnode(NRECTYPE);
                                       $$->c1=$2;}
           ;
atomic_decl_list: atomic_decl ',' atomic_decl_list {currentRule="atomic_decl_list_1"; $$=$1;
                                                     $$->b=$3;}
                | atomic_decl {currentRule="atomic_decl_list_2"; $$=$1;}
                ;
atomic_decl: ID{$$= idnode();} ':' atomic_type{currentRule="atomic_decl_1";$$=nontermnode(NATOMDECL);
                                               $$->c1=$2;
                                               $$->c2= $4;}
           ;
array_type: '[' array_elem_type ']' {currentRule="array_type_1";$$=nontermnode(NARRAYTYPE);
                                     $$->c1=$2;}
          ;
array_elem_type: atomic_type {currentRule="array_elem_type_1"; $$=$1;}
               | record_type {currentRule="array_elem_type_2"; $$=$1;}
               ;
var_section: VARIABLES var_decl_list { currentRule="var_section_1";$$= nontermnode(NVARSEC);
                                       $$->c1=$2;}
            | {currentRule="var_section_2";$$=NULL;}
            ;
var_decl_list: var_decl var_decl_list{currentRule="var_decl_list_1";$$=$1;
                                      $$->b=$2;
                                         }
               | var_decl{currentRule="var_decl_list_2"; $$=$1;}
               ;
var_decl: id_list ':' type ';' { currentRule="var_decl_1";$$=nontermnode(NVARDECL);
                                 $$->c1=$1;
                                 $$->c2=$3;}
func_section: FUNCTIONS fun_decl_list { currentRule="func_section_1";$$= nontermnode(NFUNCSEC);
                                        $$->c1=$2;}
            | {currentRule="func_section_2";$$=NULL;}
            ;
fun_decl_list: fun_decl fun_decl_list{currentRule="fun_decl_list_1";$$=$1;
                                      $$->b=$2;
                                         }
               | fun_decl{currentRule="fun_decl_list_2"; $$=$1;}
               ;
fun_decl: ID{$$=idnode();} '(' opt_formal_decl_list ')' ':' type expr END { currentRule="fun_decl_1";$$=nontermnode(NFUNDECL);
                                                                            $$->value.sval=$2->value.sval;
                                                                            $$->c1=$4;
                                                                            $$->c2=$7;
                                                                            $$->c3=$8;}
        ;
opt_formal_decl_list: formal_decl_list {currentRule="opt_formal_decl_list";$$=$1;}
                    | {currentRule="opt_formal_decl_list_2";$$=NULL;}
                    ;
formal_decl_list: formal_decl ',' formal_decl_list {currentRule="formal_decl_list_1";$$=$1;
                                                    $$->b=$3;
                                                    }
                | formal_decl{ currentRule="formal_decl_list_2";$$=$1;}
                ;
formal_decl: ID{$$=idnode();} ':' type {currentRule="formal_decl_1";$$=nontermnode(NFORMALDECL);
                                       $$->c1=$2;
                                       $$->c2=$4;}
           ;
expr: expr bool_op bool_term {currentRule="expr_1";
                              $$=nontermnode(NLOGICEXPR);
                              $$->c1=$1;
                              $$->c2=$3;
                              $$->value.ival=$2->symbol;}
    |bool_term {currentRule="expr_2";
                $$=$1;}
    ;
bool_op: OR {currentRule="bool_op_1";$$=keynode(T_OR);}
       | AND{currentRule="bool_op_2";$$=keynode(T_AND);}
       ;
bool_term: comp_term comp_op comp_term{currentRule="bool_term_1";$$=nontermnode(NCOMPEXPR);
                                        $$->c1=$1;
                                        $$->c2=$3;
                                        $$->value.ival=$2->symbol;}

         | comp_term{currentRule="bool_term_2";
                     $$=$1;}
         ;
comp_op:EQUAL  {currentRule="comp_op_1";$$=keynode(T_EQUAL);}
       |NEQUAL {currentRule="comp_op_2";$$=keynode(T_NOTEQUAL);}
       |GT {currentRule="comp_op_3";$$=keynode(T_GT);}
       |GE {currentRule="comp_op_4";$$=keynode(T_GE);}
       |LE {currentRule="comp_op_5";$$=keynode(T_LE);}
       |LT {currentRule="comp_op_6";$$=keynode(T_LT);}
       |IN {currentRule="comp_op_7";$$=keynode(T_IN);}
       ;
comp_term: comp_term add_op term {currentRule="comp_term_1";$$=nontermnode(NMATHEXPR);
                                  $$->c1=$1;
                                  $$->c2=$3;
                                  $$->value.ival=$2->symbol;}
          | term {currentRule="comp_term_2";
                 $$=$1;}
          ;
add_op: PLUS {currentRule="add_op_1";$$=keynode(T_PLUS);}
      | MINUS {currentRule="add_op_2";$$=keynode(T_MINUS);}
      | CONCAT {currentRule="add_op_3";$$=keynode(T_CONCAT);}
      ;
term: term mul_op factor {currentRule="term_1";$$=nontermnode(NMATHEXPR);
                          $$->c1=$1;
                          $$->c2=$3;
                          $$->value.ival=$2->symbol;}
     |factor {currentRule="term_2";
              $$=$1;}
     ;
mul_op: MUL {currentRule="mul_op_1";$$=keynode(T_MUL);}
      | DIVIDE{currentRule="mul_op_2";$$=keynode(T_DIVIDE);}
      ;
factor: unary_op factor %prec NOT {currentRule="factor_1";$$=nontermnode(NNEGEXPR);
                        $$->c1=$2;
                        $$->value.ival=$1->symbol;
                        }
       | '(' expr ')' {currentRule="factor_2";
                                 $$=$2;}
       | '|' expr '|' {currentRule="factor_3";$$=nontermnode(NBUILTINEXPR);
                       $$->c1=$2;
                       $$->value.ival=T_CARD;}
       | lhs  {currentRule="factor_4";
              $$=$1;}
       | built_in '(' expr ')' {currentRule="factor_5";
                                 $$=nontermnode(NBUILTINEXPR);
                                 $$->c1=$3;
                                 $$->value.ival=$1->symbol;}
       | atomic_constant {currentRule="factor_6";
                          $$=$1;}
       | record_constructor {currentRule="factor_7";
                             $$=$1;}
       | array_constructor {currentRule="factor_8";
                           $$=$1;}
       | cond_expr {currentRule="factor_9";
                   $$=$1;}
       | func_call {currentRule="factor_10";
                    $$=$1;}
       ;
unary_op: MINUSSIGN {currentRule="unary_op_1";$$=keynode(T_NEG_SIGN);}
        | NOT {currentRule="unary_op_2";$$=keynode(T_NOT);}
        ;
built_in: INT {currentRule="built_in_1";$$=keynode(T_CASTINT);}
        | REAL {currentRule="built_in_2";$$=keynode(T_CASTREAL);}
        | EMPTY_TOKEN {currentRule="built_in_3";$$=keynode(T_EMPTY);}
        | HEAD_TOKEN {currentRule="built_in_4";$$=keynode(T_HEAD);}
        | TAIL_TOKEN {currentRule="built_in_5";$$=keynode(T_TAIL);}
        ;
atomic_constant: BOOLCONST {currentRule="atomic_constant_1";$$=boolconstnode();}
               | INTCONST {currentRule="atomic_constant_2";$$=intconstnode();}
               | REALCONST {currentRule="atomic_constant_3";$$=realconstnode();}
               | STRCONST {currentRule="atomic_constant_4";$$=strconstnode();}
               ;
record_constructor: '{' expr_list '}' {currentRule="record_constructor_1";$$=nontermnode(NCONSTRUCTOR);
$$->value.ival=T_RECORD;
$$->c1=$2;}
                                       ;
expr_list: expr ',' expr_list { currentRule="expr_list_1";$$=$1;
                                $$->b=$3;}
          | expr {currentRule="expr_list_2";$$=$1;}
          ;
cond_expr: IF expr THEN expr ELSE expr END {currentRule="cond_expr_1";$$=nontermnode(NCONDEXPR);
                                            $$->c1=$2;
                                            $$->c2=$4;
                                            $$->c3=$6;}
          ;
func_call: ID {$$=idnode();} '(' opt_expr_list ')' {currentRule="func_call_1";$$=nontermnode(NFUNCCALL);
                                                   $$->value.sval=$2->value.sval;
                                                   $$->c1=$4;}
         ;
opt_expr_list: expr_list {currentRule="opt_expr_list_1";$$=$1;
                          }
             | { currentRule="opt_expr_list_2";$$=NULL;}
             ;
array_constructor: '[' opt_expr_list ']' {currentRule="array_constructor_1";$$=nontermnode(NCONSTRUCTOR);
                                          $$->c1=$2;
                                          $$->value.ival=T_ARRAY;}
                 ;
run_section: RUN stat_list END {currentRule="run_section_1";$$=nontermnode(NRUNSEC);
$$->c1=$2;}
            | { currentRule="opt_expr_list_2";$$=NULL;}
           ;
stat_list: stat ';' stat_list    {currentRule="stat_list_1";$$=$1;
                                 $$->b=$3;}
         | stat ';' {currentRule="stat_list_2";$$=$1;}
         ;
stat: read_stat {currentRule="stat_1";$$=$1;}
    | write_stat {currentRule="stat_2";$$=$1;}
    | assign_stat {currentRule="stat_3";$$=$1;}
    | if_stat {currentRule="stat_4";$$=$1;}
    | while_stat {currentRule="stat_5";$$=$1;}
    | foreach_stat {currentRule="stat_6";$$=$1;}
    ;
read_stat: READ_TOKEN ID {currentRule="read_stat_1";$$=nontermnode(NREAD); //////////giust0???
                    $$->c1=idnode();}
         ;
write_stat: WRITE expr {currentRule="write_stat_1";$$= nontermnode(NWRITE);
                        $$->c1= $2;}
          ;
assign_stat: lhs ASSIGN expr {currentRule="assign_stat_1";$$=nontermnode(NASSIGN);
                            $$->c1=$1;
                            $$->c2=$3;}
           ;
lhs: ID{$$=idnode();} opt_fielding {currentRule="lhs_1";
                                    $$= nontermnode(NLHS);
                                    $$->c1=$2;
                                    $$->c2=$3;}
   | indexing {currentRule="lhs_2";$$= nontermnode(NLHS);
               $$->c1=$1;}
   ;
opt_fielding: '.' ID {currentRule="opt_fielding_1";
                      $$=idnode();}
            | {currentRule="opt_fielding_2";$$=NULL;}
            ;
indexing: ID {$$=idnode();} '[' expr ']' opt_fielding {currentRule="indexing_1";$$= nontermnode(NINDEXING);
                                                     $$->c1=$2;
                                                     $$->c2=$4;
                                                     $$->c3=$6;
                                                     }
        ;
if_stat: IF expr THEN stat_list else_part END {currentRule="if_stat_1";$$= nontermnode (NIFSTAT);
                                               $$->c1=$2;
                                               $$->c2=$4;
                                               $$->c3 =$5;}
       ;
else_part: ELSE stat_list {currentRule="else_part_1";$$=$2;
                         }
         | {$$=NULL;}
         ;
while_stat: WHILE expr DO stat_list END {currentRule="while_stat_1";$$=nontermnode(NWHILESTAT);
                                         $$->c1=$2;
                                         $$->c2=$4;}
           ;
foreach_stat: FOREACH ID {$$=idnode();} IN ID {$$=idnode();} DO stat_list END { currentRule="foreach_stat_1";$$=nontermnode(NFOREACH);
                                                                              $$->c1=$3;
                                                                              $$->c2= $6;
                                                                              $$->c3=$8;
                                                                              }
             ;

%%
Pnode nontermnode(int nonterm)
{
 Pnode p = newnode(nonterm);
 p->line=line;
 return(p);
}
Pnode idnode()
{
 Pnode p = newnode(T_ID);
 p->value.sval = lexval.sval;
 return(p);
}
Pnode keynode(Typenode keyword)
{
 return(newnode(keyword));
}
Pnode intconstnode()
{
 Pnode p = newnode(T_INTCONST);
 p->value.ival = lexval.ival;
 return(p);
}
Pnode strconstnode()
{
 Pnode p = newnode(T_STRCONST);
 p->value.sval = lexval.sval;
 return(p);
}
Pnode boolconstnode()
{
 Pnode p = newnode(T_BOOLCONST);
 p->value.bval = lexval.bval;
 return(p);
}
Pnode realconstnode()
{
 Pnode p = newnode(T_REALCONST);
 p->value.rval = lexval.rval;
 return(p);
}
Pnode newnode(Typenode tnode)
{
 Pnode p = malloc(sizeof(Node));
 p->symbol = tnode;
 p->line= line;
 p->c1 = p->c2 = p->c3 = p->c4 = p->b = NULL;
 return(p);
}
Pnode generate_abstree(FILE *input)
{
 int result;
 yyin = input;
 result = yyparse();
 return root;
}
void yyerror()
{
 fprintf(stderr, "Line %d: syntax error on symbol \"%s\" on BNF rule \"%s\"\n", line, yytext, currentRule);
 exit(2);
}