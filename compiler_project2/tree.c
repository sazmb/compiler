#include <stdio.h>

#include "header_files/def.h"
char* tabtypes[]=
    {
    "INTEGER",
    "STRING",
    "REAL",
    "BOOLEAN",
    "STRCONST",
    "ID",
    "NONTERMINAL"//MA IO HO CREATO ìL TIPO NONTERM O HO USATO DIRETTAMENTE GLI ALTRI?
    };
char* tabnonterms[]={
    "NPROGRAM",
 "NTYPESEC",
 "NTYPEDECL",
 "NRECTYPE",
 "NATOMDDECL",
 "NARRAYTYPE",
 "NVARSEC",
 "NVARDECL",
 "NFUNCSEC",
 "NFUNDECL",
 "NFORMALDECL",
 "NEXPR",
 "NBOOLTERM",
 "NCOMPTERM",
 "NTERM",
 "NFACTOR",
 "NCONDEXPR",
 "NFUNCCALL",
 "NREAD",
 "NWRITE",
 "NASSIGN",
 "NLHS",
 "NOPTFIELDING",
 "NINDEXING",
 "NIFSAT",
 "NELSEPART",
 "NWHILESTAT",
 "NFOREACH",
 "NRUNSEC",
    "NARRAYCONS",
    "NOPTEXPRLIST",

 "NLOGICEXPR",
 "NCOMPEXPR",
 "NMATHEXPR",
 "NNEGEXPR",
 "NBUILTINEXPR",
    "NCONSTRUCTOR",

    "T_INTEGER",
 "T_STRING",
 "T_BOOLEAN",
 "T_REAL",
 "T_INTCONST",
 "T_BOOLCONST",
 "T_STRCONST",
 "T_REALCONST",
 "T_ID",
 "T_NONTERMINAL",
 "T_EQUAL",
 "T_NOTEQUAL",
 "T_GT",
 "T_GE",
 "T_LE",
 "T_LT",
 "T_IN",
 "T_PLUS",
 "T_MINUS",
 "T_CONCAT",
 "T_MUL",
 "T_DIVIDE",
 "T_NOT",
 "T_EMPTY",
 "T_HEAD",
 "T_TAIL",
    "T_CARD",
 "T_OR",
 "T_AND",
 "T_CASTINT",
 "T_CASTREAL",
    "T_ARRAY",
    "T_RECORD",
    "T_NEG_SIGN"
};

void treeprint(Pnode root, int indent) {
    int i;
    Pnode p;
    for(i=0; i<indent; i++ ) {
        printf("   ");
    }
    printf("%s",  tabnonterms [root->symbol]);
    if (root->symbol==T_ID || root->symbol== T_STRCONST || root->symbol==NFUNCCALL || root->symbol==NFUNDECL)
        printf("(%s)", root->value.sval);
  else if (root->symbol==NLOGICEXPR ||  root->symbol==NCOMPEXPR || root->symbol==NMATHEXPR ||
      root->symbol==NNEGEXPR || root->symbol==NBUILTINEXPR || root->symbol==NCONSTRUCTOR )
        printf("(%s)", tabnonterms[root->value.ival]);

    else if (root->symbol==T_INTCONST )
        printf("(%d)", root->value.ival);
    else if (root->symbol==T_BOOLCONST)
        printf("(%s)", (root->value.ival==TRUE ? "true" : "false"));
    printf ("\n");

    for (p=root->c1; p!=NULL; p=p->b)
        treeprint(p, indent+1);
    for (p=root->c2; p!=NULL; p=p->b)
        treeprint(p, indent+1);
    for (p=root->c3; p!=NULL; p=p->b)
        treeprint(p, indent+1);
    for (p=root->c4; p!=NULL; p=p->b)
        treeprint(p, indent+1);
}