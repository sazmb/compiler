#include <stdio.h>
#include <string.h>
#include "header_files/genCode.h"
#include <stdarg.h>
#include <stddef.h>
const char *opCodeStrings[] = {
    "ADDI",
 "ADDR",
 "APOP",
 "CARD",
 "CIDX",
 "CODE",
 "CONC",
 "DIVI",
 "DIVR",
 "EMPT",
 "EQUA",
 "FUNC",
 "GEQI",
 "GEQR",
 "GEQS",
 "GTHI",
 "GTHR",
 "GTHS",
 "HALT",
 "HEAD",
 "INDL",
 "IXAD",
 "JUMP",
 "LEQI",
 "LEQR",
 "LEQS",
 "LOAD",
 "LOCI",
 "LOCR",
 "LOCS",
 "LODA",
 "LTHI",
 "LTHR",
 "LTHS",
 "MEMB",
 "MULI",
 "MULR",
 "NEGB",
 "NEGI",
 "NEGR",
 "NEQU",
 "NEWO",
 "PACK",
 "PUSH",
 "READ",
 "RETN",
 "SKIP",
 "SKPF",
 "STOR",
 "SUBI",
 "SUBR",
 "TAIL",
 "TOIN",
 "TORE",
 "VARS",
 "WRIT"

};


Tdomain current_domain=D_EMPTY;
int vars = 0;
int foreach_vars = 0;
int environment;
int foreach_lvl = 0;
//start region function to manipulate code
void generation_error(char *msg) {
    fprintf(stderr, "Errore:  %s -- at line\n", msg);
    // Termina il programma con uno stato di uscita non zero (indica errore)
    exit(4);
}

void relocate(Code code, int offset) {
    Stat *pt = code.head;

    for (int i = 1; i <= code.size; i++) {
        pt->address += offset;
        pt = pt->next;
    }
}

Code appcode(Code code1, Code code2) {
    Code rescode;
    relocate(code2, code1.size);
    rescode.head = code1.head;
    rescode.tail = code2.tail;
    code1.tail->next = code2.head;
    rescode.size = code1.size + code2.size;
    return rescode;
}

Code endcode() {
    static Code code = {NULL, 0, NULL};
    return code;
}

Code concode(int num_args, Code code1, ...) {
    Code rescode = code1;
    va_list args; // Dichiarazione della lista di argomenti variabili

    // Inizializzazione della lista di argomenti
    va_start(args, code1);

    // Loop attraverso tutti gli argomenti variabili
    for (int i = 1; i < num_args; i++) {
        Code nextcode = va_arg(args, Code); // Ottieni il prossimo Code
        rescode = appcode(rescode, nextcode); // Concatenazione dei codici
    }

    // Fine dell'elaborazione degli argomenti variabili
    va_end(args);

    return rescode;
}

Stat *newstat(Operator op) {
    Stat *pstat;

    pstat = (Stat *) malloc(sizeof(Stat));
    pstat->address = 0;
    pstat->op = op;
    pstat->next = NULL;
    return pstat;
}

Code makecode(Operator op) {
    Code code;

    code.head = code.tail = newstat(op);
    code.size = 1;
    return code;
}

Code makecode1(Operator op, int arg) {
    Code code;

    code = makecode(op);
    code.head->arg1.ival = arg;
    return code;
}

Code makecode2(Operator op, int arg1, int arg2) {
    Code code;
    code = makecode(op);
    code.head->arg1.ival = arg1;
    code.head->arg2.ival = arg2;
    return code;
}

Code makecode3(Operator op, int arg1, int arg2, int arg3) {
    Code code;
    code = makecode(op);
    code.head->arg1.ival = arg1;
    code.head->arg2.ival = arg2;
    code.head->arg3.ival = arg3;
    return code;
}

//end region


Code choose_comp_op(Pnode root, int operator, int type) {
    Code new_code = endcode();
    switch (operator) {
        case T_GE:
            if (type == D_INT)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GEQI));
            else if (type == D_REAL)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GEQR));
            if (type == D_STRING)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GEQS));
            break;
        case T_GT:
            if (type == D_INT)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GTHI));
            else if (type == D_REAL)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GTHR));
            if (type == D_STRING)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(GTHS));
            break;
        case T_LE:
            if (type == D_INT)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LEQI));
            else if (type == D_REAL)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LEQR));
            if (type == D_STRING)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LEQS));
            break;
        case T_LT:
            if (type == D_INT)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LTHI));
            else if (type == D_REAL)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LTHR));
            if (type == D_STRING)
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(LTHS));
            break;
    }
    return new_code;
}

Code choose_math_op(Pnode root, int operator, int type) {
    Code new_code = endcode();
    switch (operator) {
        case T_PLUS:
            if ((current_domain==D_INT &&  type==D_REAL) || (current_domain!=D_REAL &&  type==D_INT))
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(ADDI));
            else
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(ADDR));
            break;
        case T_MINUS:
            if ((current_domain==D_INT &&  type==D_REAL) || (current_domain!=D_REAL &&  type==D_INT))
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(SUBI));
             else
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(SUBR));
            break;
        case T_DIVIDE:
            if ((current_domain==D_INT &&  type==D_REAL) || (current_domain!=D_REAL &&  type==D_INT))
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(DIVI));
            else
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(DIVR));
            break;
        case T_MUL:
            if ((current_domain==D_INT &&  type==D_REAL) || (current_domain!=D_REAL &&  type==D_INT))
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(MULI));
            else
                new_code = concode(3, genCode(root->c1), genCode(root->c2), makecode(MULR));
            break;
    }
    return new_code;
}

Code gen_var_section(Pnode root) {
    //vado a prendere il primo id della prima decl
    Ptable t1 = lookup(root->c1->c1->value.sval);
    Code result_code;
    // la dim è uguale per tutti gli id all'interno della prima decl (cerco nalla stable solo quella del primo id)
    int dim = t1->dimension;
    //per ogni id all'interno della decl vado a creare la istruzione di newo
    if (t1->type->domain == D_ARRAY)
        result_code = makecode2(NEWO, dim, 0);
    else
        result_code = makecode2(NEWO, dim, 1);
    vars++;
    for(Pnode n = root->c1->c1->b; n != NULL; n = n->b){
        if (t1->type->domain == D_ARRAY)
            result_code = appcode(result_code, makecode2(NEWO, dim, 0));
        else
            result_code = appcode(result_code, makecode2(NEWO, dim, 1));
    vars++;
}
    for (Pnode n = root->c1->b; n != NULL; n = n->b) {
        Ptable t = lookup(n->c1->value.sval);
        dim = t->dimension;
        if (t->type->domain == D_ARRAY)
            result_code = appcode(result_code, makecode2(NEWO, dim, 0));
        else
            result_code = appcode(result_code, makecode2(NEWO, dim, 1));
        vars++;
        for(Pnode p = n->c1->b; p!= NULL; p = p->b){
            if (t1->type->domain == D_ARRAY)
                result_code = appcode(result_code, makecode2(NEWO, dim, 0));
            else
                result_code = appcode(result_code, makecode2(NEWO, dim, 1));
            vars++;
        }
    }


    //result_code=appcode(result_code, endcode());

    return result_code;
}

Code gen_foreach_vars() {
    Ptable t2 = lookup("FOREACH");
    Code result_code = makecode2(NEWO, 4, 1);
    vars++;
    for (Ptable t3 = t2->formals->next; t3 != NULL; t3 = t3->next) {
        result_code = appcode(result_code, makecode2(NEWO, 4, 1));
        vars++;
    }
    return result_code;
}

Code gen_func_code(Pnode root) {
    Ptable t = lookup(root->value.sval);
    environment = 1;
    set_current_env(t->formals);
    Code new_code = concode(3, makecode1(FUNC, t->oid), genCode(root->c3), makecode(RETN));
    reset_env();
    environment = 0;
    return new_code;
}

Code gen_read_stat(Pnode root) {
    Ptable t = lookup(root->c1->value.sval);
    char *format = evaluate_format(t->type);
    //manca di generare la stringa riassuntiva da passare come secondo arg aka format
    Code new_code = makecode1(READ, t->oid);
    new_code.head->arg2.sval = format;
    return new_code;
}

Code gen_write_stat(Pnode root) {
    Ttype t = checkTree(root->c1);
    char *format = evaluate_format(t);
    //manca di generare la stringa riassuntiva da passare come secondo arg aka format
    Code new_code = appcode(genCode(root->c1), makecode(WRIT));
    new_code.tail->arg1.sval = format;
    return new_code;
}

Code gen_lhs(Pnode root, int isaddr) {
    Code new_code = endcode();
    Tdomain domain=D_EMPTY;
    if (isaddr){
        //caso id semplice
        if (root->c1->symbol == T_ID) {
            Ptable t = lookup(root->c1->value.sval);
            domain=t->type->domain;
            new_code = makecode2(LODA, environment, t->oid);
            //caso record semplice
            if (root->c2 != NULL) {
                Param p = (search_param(t->type, root->c2->value.sval));
                domain=p->domain;
                new_code = concode(3,
                                   new_code,
                                   makecode1(LOCI, p->offset),
                                   makecode1(IXAD, 1));
            }
        } else {
            //caso array semplice
            root=root->c1;
            Ptable t = lookup(root->c1->value.sval);
            domain=t->type->domain;
            new_code = makecode2(LODA, environment, t->oid);
            if (root->c3 == NULL)
                new_code = concode(4,
                                   new_code,
                                   genCode(root->c2),
                                   makecode(CIDX),
                                   makecode1(IXAD, t->dimension));
            //caso array di record
            else {
                Param p = (search_param(t->type, root->c3->value.sval));
                domain=p->domain;
                new_code = concode(5,
                                   new_code,
                                   genCode(root->c2),
                                   makecode(CIDX), makecode1(IXAD, t->dimension),
                                   makecode1(LOCI, p->offset),
                                   makecode1(IXAD, 1));
            }
        }
    }
    else {
        if (root->c1->symbol == T_ID) {
            Ptable t = lookup(root->c1->value.sval);
            new_code = makecode2(LOAD, environment, t->oid);
            domain=t->type->domain;
            if (root->c2 != NULL) {

                new_code = makecode2(LODA, environment, t->oid);
                Param p = (search_param(t->type, root->c2->value.sval));
                new_code = appcode(new_code, makecode2(INDL, p->offset, p->dim));
                domain=p->domain;
            }
        } else {
            root=root->c1;
            Ptable t = lookup(root->c1->value.sval);
            new_code = makecode2(LODA, environment, t->oid);
            domain=t->type->domain;
            if (root->c3 == NULL)
                new_code = concode(5,
                                   new_code,
                                   genCode(root->c2),
                                   makecode(CIDX),
                                   makecode1(IXAD, t->dimension),
                                   makecode2(INDL, 0, t->dimension));

            else {
                Param p = (search_param(t->type, root->c3->value.sval));
                domain=p->domain;
                new_code = concode(4,
                                   new_code,
                                   genCode(root->c2),
                                   makecode(CIDX), makecode1(IXAD, t->dimension),
                                   makecode2(INDL, p->offset, p->dim));
            }
        }
    }
    if (isaddr)
         current_domain=domain;
    else if (!isaddr && current_domain==D_INT && domain==D_REAL)
      new_code=  appcode(new_code,makecode( TOIN));
    else if (!isaddr && current_domain==D_REAL && domain==D_INT)
       new_code=appcode(new_code, makecode(TORE));
    return new_code;
}

Code gen_assign_stat(Pnode root) {
    Code lhs_code= gen_lhs(root->c1, 1);
    return concode(3, lhs_code, genCode(root->c2), makecode(STOR));
}

Code gen_if_stat(Pnode root) {
    Code new_code = genCode(root->c1);
    Code new_code2 = genCode(root->c2);
    for (Pnode n = root->c2->b; n != NULL; n = n->b)
        new_code2 = appcode(new_code2, genCode(n));

    if (root->c3 != NULL) {
        new_code = concode(3, new_code, makecode1(SKPF, new_code2.size + 2), new_code2);
        new_code2 = genCode(root->c3);
        for (Pnode n = root->c2->b; n != NULL; n = n->b)
            new_code2 = appcode(new_code2, genCode(n));
        new_code = concode(3, new_code, makecode1(SKIP, new_code2.size + 1), new_code2);
    } else new_code = concode(3, new_code, makecode1(SKPF, new_code2.size + 1), new_code2);
    return new_code;
}

Code gen_while_stat(Pnode root) {
    Code new_code = genCode(root->c1);
    Code new_code2 = genCode(root->c2);
    for (Pnode n = root->c2->b; n != NULL; n = n->b)
        new_code2 = appcode(new_code2, genCode(n));
    new_code = concode(4,
                       new_code,
                       makecode1(SKPF, new_code2.size + 2),
                       new_code2, makecode1(SKIP, -(new_code.size + new_code2.size + 1)));
    return new_code;
}

Code gen_foreach_stat(Pnode root) {
    Ptable t = lookup(root->c2->value.sval);
    int id1 = lookup(root->c1->value.sval)->oid;
    int id2 = t->oid;
    Ptable t3 = lookup("FOREACH")->formals;
    for (int counter = foreach_lvl; counter > 0; counter--)
        t3 = t3->next;
    int index = t3->oid;
    foreach_lvl++;
    Code new_code = concode(7,
                            makecode2(LODA, 0, index),
                            makecode1(LOCI, 0),
                            makecode(STOR),
                            makecode2(LOAD, 0, index),
                            makecode2(LOAD, 0, id2),
                            makecode(CARD),
                            makecode(LTHI)
    );
    Code new_code2 = genCode(root->c3);
    for (Pnode n = root->c3->b; n != NULL; n = n->b)
        new_code2 = appcode(new_code2, genCode(n));
    new_code = concode(15,
                       new_code,
                       makecode1(SKPF, new_code2.size + 13),
                       makecode2(LODA, 0, id1),
                       makecode2(LODA, 0, id2),
                       makecode2(LOAD, 0, index),
                       makecode1(IXAD, t->dimension),
                       makecode2(INDL, 0, t->dimension),
                       makecode(STOR),
                       new_code2,
                       makecode2(LODA, 0, index),
                       makecode2(LOAD, 0, index),
                       makecode1(LOCI, 1),
                       makecode(ADDI),
                       makecode(STOR),
                       makecode1(SKIP, -(new_code2.size + 16))
    );
    foreach_lvl--;
    return new_code;
}

Code gen_logic_expr(Pnode root) {
    Code new_code = genCode(root->c1);
    Code new_code2 = genCode(root->c2);
    if (root->value.ival == T_AND) {
        new_code = concode(5,
                           new_code,
                           makecode1(SKPF, new_code2.size + 2),
                           new_code2,
                           makecode1(SKIP, 2),
                           makecode1(LOCI, 0)
        );
    } else {
        new_code = concode(5,
                           new_code,
                           makecode1(SKPF, 3),
                           makecode1(LOCI, 1),
                           makecode1(SKIP, 1),
                           new_code2
        );
    }
    return new_code;
}

Code gen_comp_expr(Pnode root) {
    if (root->value.ival != T_EQUAL && root->value.ival != T_NOTEQUAL) {
        Ttype t = checkTree(root->c1); // no control because the typechecking already made in stable
        if (root->value.ival == T_IN )
            return choose_comp_op(root, root->value.ival, t->domain);
        else
        return choose_comp_op(root, root->value.ival, t->domain);
    }
    if (root->value.ival == T_EQUAL)
        return concode(3, genCode(root->c1), genCode(root->c2), makecode(EQUA));
    //if (root->value.ival==T_NOTEQUAL)
    return concode(3, genCode(root->c1), genCode(root->c2), makecode(NEQU));
}

Code gen_math_expr(Pnode root) {
    if (root->value.ival != T_CONCAT) {
        Ttype t = checkTree(root->c1); // no control because the typechecking already made in stable
        return choose_math_op(root, root->value.ival, t->domain);
    }

    return concode(3, genCode(root->c1), genCode(root->c2), makecode(CONC));
}

Code gen_neg_expr(Pnode root) {
    if (root->value.ival == T_NEG_SIGN) {
        if (checkTree(root->c1)->domain == D_INT)
            return appcode(genCode(root->c1), makecode(NEGI));
        return appcode(genCode(root->c1), makecode(NEGR));
    }
    return appcode(genCode(root->c1), makecode(NEGB));
}

Code gen_builtin_expr(Pnode root) {
    Code new_code;
    switch (root->value.ival) {
        case T_CASTINT: new_code = appcode(genCode(root->c1), makecode(TOIN));
            break;
        case T_CASTREAL: new_code = appcode(genCode(root->c1), makecode(TORE));
            break;
        case T_EMPTY: new_code = appcode(genCode(root->c1), makecode(EMPT));
            break;
        case T_HEAD: new_code = appcode(genCode(root->c1), makecode(HEAD));
            break;
        case T_TAIL: new_code = appcode(genCode(root->c1), makecode(TAIL));
            break;
        case T_CARD: new_code = appcode(genCode(root->c1), makecode(T_CARD));
            break;
    }
    return new_code;
}

Code gen_constructor(Pnode root) {
    Code new_code;
    if (root->value.ival == T_ARRAY) {
        int elements = 0;
        int card;
        if (root->c1 != NULL) {
            new_code = genCode(root->c1);
            card = evaluate_dim(checkTree(root->c1));
            elements++;
            for (Pnode p = root->c1->b; p != NULL; p = p->b) {
                card += evaluate_dim(checkTree(root->c1));
                new_code = appcode(new_code, genCode(p));
                elements++;
            }
            new_code = appcode(new_code, makecode3(PACK, elements, card, elements));
        } else new_code = makecode3(PACK, 0, 0, 0);
    }
    //case record:
    else {
        int elements = 0;
        int card;
        new_code = genCode(root->c1);
        card = evaluate_dim(checkTree(root->c1));
        elements++;
        for (Pnode p = root->c1->b; p != NULL; p = p->b) {
            card += evaluate_dim(checkTree(root->c1));
            new_code = appcode(new_code, genCode(p));
            elements++;
        }
        new_code = appcode(new_code, makecode3(PACK, elements, card, 1));
    }
    return new_code;
}

Code gen_cond_expr(Pnode root) {
    Code new_code = genCode(root->c1);
    Code new_code2 = genCode(root->c2);
    new_code = concode(3, new_code, makecode1(SKPF, new_code2.size + 2), new_code2);
    new_code2 = genCode(root->c3);
    new_code = concode(3, new_code, makecode1(SKIP, new_code2.size + 1), new_code2);

    return new_code;
}

Code gen_func_call(Pnode root) {
    Code new_code;
    int numparams=0;
    Tdomain return_domain=D_EMPTY;
    //return_domain=lookup(root->value.sval)->type->domain;
    if (root->c1 != NULL) {
        new_code = genCode(root->c1);
        numparams++;
        for (Pnode p = root->c1->b; p != NULL; p = p->b) {
            new_code = appcode(new_code, genCode(p));
            numparams++;
        }
        pause_current_env();
        new_code = concode(4,
                           new_code,
                           makecode1(PUSH, numparams),
                           makecode1(JUMP, lookup(root->value.sval)->oid),
                           makecode(APOP)
        );
    } else
        new_code = concode(3,
                           makecode1(PUSH, numparams),
                           makecode1(JUMP, lookup(root->value.sval)->oid),
                           makecode(APOP)
        );
    restart_current_env();
     if ( current_domain==REAL && return_domain==D_INT)
       appcode(new_code, makecode(TORE));
     else if ( current_domain==D_INT && return_domain==D_REAL)
       appcode(new_code, makecode(TOIN));
    return new_code;
}

Code gen_string_const(Pnode root) {
    Code code;
    code = makecode(LOCS);
    code.head->arg1.sval = root->value.sval;
    return code;
}

Code gen_int_const(Pnode root) {
    Code code= makecode1(LOCI, root->value.ival);
    if ( current_domain==D_REAL)
       appcode(code, makecode(TORE));
    return code;
}

Code gen_real_const(Pnode root) {
    Code code;
    code = makecode(LOCR);
    code.head->arg1.rval = root->value.rval;
    if ( current_domain==D_INT)
       appcode(code, makecode(TOIN));
    return code;
}

Code gen_bool_const(Pnode root) {
    if (root->value.bval)
        return makecode1(LOCI, 1);
    return makecode1(LOCI, 0);
}

Code genCode(Pnode root) {
    Code new_code;
    switch (root->symbol) {
        case NPROGRAM:
            if (root->c2 != NULL) {
                new_code = genCode(root->c2);
                if (root->c4 != NULL) {
                    Code new_code2 = genCode(root->c4);
                    new_code = concode(3, new_code, new_code2, makecode(HALT));
                }
                if (root->c3 != NULL)
                    new_code = appcode(new_code, genCode(root->c3));
            } else if (root->c4 != NULL) {
                if (root->c4 != NULL)
                    new_code = appcode(genCode(root->c4), makecode(HALT));
                if (root->c3 != NULL)
                    new_code = appcode(new_code, genCode(root->c3));
            } else if (root->c3 != NULL) new_code = genCode(root->c3);
            else generation_error("no executable command found");
            break;

        case NVARSEC:
            new_code = gen_var_section(root);
            if (lookup("FOREACH") != NULL)
                new_code = appcode(new_code, gen_foreach_vars());
            break;


        case NFUNCSEC:
        case NRUNSEC:
            new_code = genCode(root->c1);
            for (Pnode n = root->c1->b; n != NULL; n = n->b)
                new_code = appcode(new_code, genCode(n));
            break;

        case NFUNDECL:
            new_code = gen_func_code(root);
            break;


        case NREAD:
            new_code = gen_read_stat(root);
            break;


        case NWRITE:
            new_code = gen_write_stat(root);
            break;


        case NASSIGN:
            new_code = gen_assign_stat(root);
            break;


        case NLHS:
            new_code = gen_lhs(root, 0);
            break;

        case NIFSTAT:
            new_code = gen_if_stat(root);
            break;


        case NWHILESTAT:
            new_code = gen_while_stat(root);
            break;


        case NFOREACH:
            new_code = gen_foreach_stat(root);
            break;


        case NLOGICEXPR:
            new_code = gen_logic_expr(root);
            break;

        case NCOMPEXPR:
            new_code = gen_comp_expr(root);
            break;

        case NMATHEXPR:
            new_code = gen_math_expr(root);
            break;

        case NNEGEXPR:
            new_code = gen_neg_expr(root);
            break;

        case NBUILTINEXPR:
            new_code = gen_builtin_expr(root);
            break;

        case NCONSTRUCTOR:
            new_code = gen_constructor(root);
            break;

        case NCONDEXPR:
            new_code = gen_cond_expr(root);
            break;

        case NFUNCCALL:
            new_code = gen_func_call(root);
            break;
        case T_STRCONST:
            new_code = gen_string_const(root);
            break;
        case T_INTCONST:
            new_code = gen_int_const(root);
            break;
        case T_REALCONST:
            new_code = gen_real_const(root);
            break;
        case T_BOOLCONST:
            new_code = gen_bool_const(root);
            break;
        default: printf("default case :unknow node");
            break;
    }
    return new_code;
}

void enum_code(Code *code) {
    int count = 0;
    for (Pstat stat = &(*code->head); stat != NULL; stat = stat->next)
        stat->address = count;
}

void evaluate_jumps(Code *code) {
    int count = 0;
    for (Pstat stat = &(*code->head); stat != NULL; stat = stat->next)
        if (stat->op == JUMP) {
            for (Pstat temp = &(*code->head); temp != NULL; temp = temp->next)
                if (temp->op == FUNC && stat->arg1.ival == temp->arg1.ival)
                    stat->arg1.ival = temp->address;
            //non metto più uno perchè subirà il normale incremento del pc nella vm
        }
}

Code editCode(Code code) {
    Code new_code = concode(3,
                            makecode1(CODE, code.size + 1),
                            makecode1(VARS, vars),
                            code);
    evaluate_jumps(&new_code);
    return new_code;
}

Code startGenCode(Pnode root) {
    Code code;
    code = endcode();
    code = genCode(root);
    code = editCode(code);
    return code;
}

// Funzione per stampare i dati di una variabile di tipo Stat su un file
void print_stat_to_file(Code code, FILE *file) {
    for (Pstat stat = code.head; stat != NULL; stat = stat->next) {
        fprintf(file, "%d\t", stat->address);
        fprintf(file, "%d\t", stat->op);
        switch (stat->op) {
            case LOCI:
            case IXAD:
            case SKIP:
            case SKPF:
            case PUSH:
            case JUMP:
            case FUNC:
            case CODE:
            case VARS:
                fprintf(file, "%d\n", stat->arg1.ival);
                break;

                case LOCS:
                    fprintf(file, "\"%s\"\n", stat->arg1.sval);
            break;
            case WRIT:
                fprintf(file, "%s\n", stat->arg1.sval);
                break;
            case LOCR:
                fprintf(file, "%lf\n", stat->arg1.rval);
                break;
            case NEWO:
            case LOAD:
            case LODA:
            case INDL:
                fprintf(file, "%d\t", stat->arg1.ival);
                fprintf(file, "%d\n", stat->arg2.ival);
                break;
            case READ:
                fprintf(file, "%d\t", stat->arg1.ival);
                fprintf(file, "%s\n", stat->arg2.sval);
                break;
            case PACK:
                fprintf(file, "%d\t", stat->arg1.ival);
                fprintf(file, "%d\t", stat->arg2.ival);
                fprintf(file, "%d\n", stat->arg3.ival);
                break;
            default: fprintf(file, "\n");
                break;
        }
    }
}

void print_stat_to_file_extnd(Code code, FILE *file) {
    fprintf(file, "Code size: %d\n\n", code.size);
    for (Pstat stat = code.head; stat != NULL; stat = stat->next) {
        fprintf(file, "%d\t", stat->address);
        fprintf(file, "%s\t", opCodeStrings[stat->op]);
        switch (stat->op) {
            case LOCI:
            case IXAD:
            case SKIP:
            case SKPF:
            case PUSH:
            case JUMP:
            case CODE:
            case VARS:
                fprintf(file, "%d\n", stat->arg1.ival);
                break;

            case FUNC:
                char *s = lookup_oid(stat->arg1.ival)->name;
                fprintf(file, "%s\n", s);
                set_current_env(lookup(s)->formals);
                break;
            case LOCS:
                fprintf(file, "\"%s\"\n", stat->arg1.sval);
            break;
            case WRIT:
                fprintf(file, "%s\n", stat->arg1.sval);
                break;
            case LOCR:
                fprintf(file, "%lf\n", stat->arg1.rval);
                break;
            case NEWO:

            case INDL:
                fprintf(file, "%d\t", stat->arg1.ival);
                fprintf(file, "%d\n", stat->arg2.ival);
                break;
            case LOAD:
            case LODA:
                fprintf(file, "%d\t", stat->arg1.ival);
               Ptable table=lookup_oid(stat->arg2.ival);
               char* name;
            if (table==NULL) {
                Ptable t= lookup("FOREACH");
                for(Ptable p=t->formals;p!=NULL; p=p->next ) {
                if (p->oid==stat->arg2.ival) {
                    name=malloc(strlen(p->name));
                    name=p->name;
                }

                }
            }else {
                name = malloc(strlen(table->name));
                name = table->name;
            }
            fprintf(file, "%s\n", name);
                break;
            case READ:
                fprintf(file, "%s ",lookup_oid(stat->arg1.ival)->name);
                fprintf(file, "%s\n", stat->arg2.sval);
                break;
            case PACK:
                fprintf(file, "%d\t", stat->arg1.ival);
                fprintf(file, "%d\t", stat->arg2.ival);
                fprintf(file, "%d\n", stat->arg3.ival);
                break;
            case RETN: reset_env();
                fprintf(file, "\n");
                break;
            default: fprintf(file, "\n");
                break;
        }
    }
}

// Funzione per creare il file se non esiste e stampare i dati di una variabile di tipo Code
void print_code_to_file(const Code *code, FILE *file, int extnd) {
    // Apre il file in modalità scrittura ("w" lo crea se non esiste)


    extnd ? print_stat_to_file_extnd(*code, file) : print_stat_to_file(*code, file);


    // Chiude il file

}

void printCode_v(Code *code, FILE* outputfile1, FILE* outputfile2) {
    print_code_to_file(code, outputfile1, 0);
    print_code_to_file(code, outputfile2, 1);
}

void printCode(Code *code, FILE* outputfile) {
    print_code_to_file(code, outputfile, 0);
}
