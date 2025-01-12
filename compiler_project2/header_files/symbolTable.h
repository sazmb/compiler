#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "parser.h"
#include "def.h"
# include <stdio.h>
# include <stdlib.h>

typedef enum{
    TYPE_CLASS,
    VAR_CLASS,
    FUNCT_CLASS,
    PARAM_CLASS
    } Tclass;



typedef enum{
    D_BOOL,
    D_INT,
    D_REAL,
    D_STRING,
    D_RECORD,
    D_ARRAY,
    D_EMPTY} Tdomain;



typedef struct sparam{
char *name;
Tdomain domain;
    int offset;
    int dim;
    int next_offset;
struct sparam *next;} *Param;

typedef struct sdomain{
    Tdomain domain;
    Tdomain child;
    Param fields;} *Ttype;



typedef struct sTable{
    char *name;
    Tclass tclass;
    int oid;
    Ttype type;
    int dimension;
    struct sTable *formals;
    struct sTable *next;} Table;

typedef Table *Ptable;

Ptable lookup (char *name);
void insert (char  *name, Tclass tclass,  Ttype type, int oid);
Ttype select_type(Pnode node, int complexdomain);
Ttype checkTree(Pnode root);
Ptable generate_symboltable(Pnode root);
void printTable(Ptable t);
Param search_param(Ttype type, char *param_name );
int evaluate_dim(Ttype type);
void set_current_env(Ptable t);
void reset_env();
void pause_current_env();
void restart_current_env();
Ptable lookup_oid(int oid);
char *evaluate_format(Ttype type);
#endif