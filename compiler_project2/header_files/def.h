//
// Created by samue on 25/07/2024.
//

#ifndef DEF_H
#define DEF_H
#include <stdlib.h>
# include <stdio.h>


/*typedef enum
{
 NPROGRAM,
 NTYPESEC,
 NTYPEDECL,
 NRECTYPE,
 NATOMDDECL,
 NARRAYTYPE,
 NVARSEC,
 NVARDECL,
 NFUNCSEC,
 NFUNDECL,
 NFORMALDECL,
 NEXPR,
 NBOOLTERM,
 NCOMPTERM,
 NTERM,
 NFACTOR,
 NCONDEXPR,
 NFUNCCALL,
 NREAD,
 NWRITE,
 NASSIGN,
 NLHS,
 NOPTFIELDING,
 NINDEXING,
 NIFSAT,
 NELSEPART,
 NWHILESTAT,
 NFOREACH,
} Nonterminal;
*/
typedef enum
{
 NPROGRAM,
 NTYPESEC,
 NTYPEDECL,
 NRECTYPE,
 NATOMDECL,
 NARRAYTYPE,
 NVARSEC,
 NVARDECL,
 NFUNCSEC,
 NFUNDECL,
 NFORMALDECL,
 NEXPR,
 NBOOLTERM,
 NCOMPTERM,
 NTERM,
 NFACTOR,
 NCONDEXPR,
 NFUNCCALL,
 NREAD,
 NWRITE,
 NASSIGN,
 NLHS,
 NOPTFIELDING,
 NINDEXING,
 NIFSTAT,
 NELSEPART,
 NWHILESTAT,
 NFOREACH,
 NRUNSEC,
 NARRAYCONS,
 NOPTEXPRLIST,

 NLOGICEXPR,
 NCOMPEXPR,
 NMATHEXPR,
 NNEGEXPR,
 NBUILTINEXPR,
 NCONSTRUCTOR,


 T_INTEGER,
 T_STRING,
 T_BOOLEAN,
 T_REAL,
 T_INTCONST,
 T_BOOLCONST,
 T_STRCONST,
 T_REALCONST,
 T_ID,
 T_NONTERMINAL,
 T_EQUAL,
 T_NOTEQUAL,
 T_GT,
 T_GE,
 T_LE,
 T_LT,
 T_IN,
 T_PLUS,
 T_MINUS,
 T_CONCAT,
 T_MUL,
 T_DIVIDE,
 T_NOT,
 T_EMPTY,
 T_HEAD,
 T_TAIL,
 T_CARD,
 T_OR,
 T_AND,
 T_CASTINT,
 T_CASTREAL,
 T_ARRAY,
 T_RECORD,
 T_NEG_SIGN
} Typenode;




typedef union
{
 int ival;
 char *sval;
 float rval;
 enum {FALSE, TRUE} bval;
}Value;

typedef struct snode
{
 //Typenode type;//------------------------------------------------------ma se questo è un type node come si creano i non terminali(se guardi sopra i
 //-------------------------------------------------------------------- type node sono solo quelli terminali
 Typenode symbol;
 Value value;
 int line;
 struct snode *c1, *c2, *c3, *c4, *b;
} Node;
typedef Node *Pnode;


char *newstring(char*);
float stringToFloat(const char *str, int *error);
int yylex();
Pnode nontermnode(int nontermnode),
 idnode(),
 keynode(Typenode),
 intconstnode(),
 strconstnode(),
 boolconstnode(),
 realconstnode(),
 newnode(Typenode);
void treeprint(Pnode, int),
 yyerror(),
tracciaVar();
Pnode generate_abstree(FILE *input);
char* concatena_stringa(char* buffer, char* aggiunta);

#endif //DEF_H
