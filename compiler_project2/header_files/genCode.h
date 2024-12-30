//
// Created by samue on 11/09/2024.
//

#ifndef GENCODE_H
#define GENCODE_H
#include "def.h"
#include "symbolTable.h"
typedef enum {
    ADDI,
 ADDR,
 APOP,
 CARD,
 CIDX,
 CODE,
 CONC,
 DIVI,
 DIVR,
 EMPT,
 EQUA,
 FUNC,
 GEQI,
 GEQR,
 GEQS,
 GTHI,
 GTHR,
 GTHS,
 HALT,
 HEAD,
 INDL,
 IXAD,
 JUMP,
 LEQI,
 LEQR,
 LEQS,
 LOAD,
 LOCI,
 LOCR,
 LOCS,
 LODA,
 LTHI,
 LTHR,
 LTHS,
 MEMB,
 MULI,
 MULR,
 NEGB,
 NEGI,
 NEGR,
 NEQU,
 NEWO,
 PACK,
 PUSH,
 READ,
 RETN,
 SKIP,
 SKPF,
 STOR,
 SUBI,
 SUBR,
 TAIL,
 TOIN,
 TORE,
 VARS,
 WRIT

    }Operator;

typedef struct sstat
{
    int address;
    Operator op;
    Value arg1;
    Value arg2;
    Value arg3;
    struct sstat *next; } Stat;
typedef Stat *Pstat;
typedef struct scode{
    Stat *head;
    int size ;
    Stat *tail;} Code;
typedef Code *Pcode;

Code genCode(Pnode root);
void relocate(Code code, int offset);
Code appcode(Code code1, Code code2);
Code endcode();
Code concode(int num_args, Code code1, ...);
Stat *newstat(Operator op);
Code makecode(Operator op);
Code makecode1(Operator op, int arg);
Code makecode2(Operator op, int arg1, int arg2);
Code startGenCode(Pnode root);
void printCode(Code *code, FILE* outputfile);
void printCode_v(Code *code, FILE* outputfile1, FILE* outputfile2);
#endif