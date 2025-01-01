#include <string.h>
# include "header_files/symbolTable.h"
# include "header_files/def.h"
char* classTerms[]=
    {
   "TYPE",
   "VAR",
   "FUNCT",
   "PARAM"
   };
char* domainTerms[]=
 {
   "BOOLEAN",
   "INTEGER",
   "REAL",
   "STRING",
   "RECORD",
   "ARRAY",
   "EMPTY"
   };

typedef struct snavigator {
   Ptable current;
   struct snavigator *next;
}*Navigator;
Table *tableHead = NULL;
Ptable tableTail= NULL;
Table *local_env=NULL;
Table *current_env=NULL;
int oid=0;
int current_line=0;
int innestedForeach=0;
int innestedForeach_max=0;
Ptable foreach_tail=NULL;
char* concatena_stringa(char* buffer,  char* aggiunta) {

      // Calcoliamo la nuova lunghezza necessaria
      size_t lunghezza_iniziale = (buffer ? strlen(buffer) : 0);
      size_t nuova_lunghezza = lunghezza_iniziale + strlen(aggiunta) + 1; // +1 per il terminatore '\0'
      char* new_buffer=(char*) malloc (nuova_lunghezza);
      // Riallociamo la memoria per il buffer

      strcpy(new_buffer, buffer);
      if (new_buffer == NULL) {
         perror("Errore nella riallocazione della memoria");
         exit(EXIT_FAILURE);
      }

      // Se il buffer è stato appena creato (era NULL), dobbiamo assicurarci che contenga una stringa vuota
      if (lunghezza_iniziale == 0) {
         buffer[0] = '\0'; // Impostiamo il terminatore di stringa iniziale
      }


      strcat(new_buffer, aggiunta);

      return new_buffer;


}
void tableError(const char* messaggio, char* name) {
   // Stampa il messaggio di errore
   if (name!=NULL)
   fprintf(stderr, "Errore: [ %s ] %s -- at line %d \n",name ,  messaggio, current_line);
   else
      fprintf(stderr, "Errore:  %s -- at line %d \n" , messaggio, current_line);
   // Termina il programma con uno stato di uscita non zero (indica errore)
   exit(3);
}

void set_current_env(Ptable t) {
   current_env=t;

}
void reset_env() {
   current_env=tableHead;
}
void pause_current_env() {
   local_env=current_env;
   current_env=tableHead;
}
void restart_current_env() {
   current_env=local_env;
}


Ptable lookup (char *name) {
   if (current_env==NULL )
      current_env=tableHead;
   if (tableHead==NULL)
      return  NULL;
   Ptable result=NULL;
      for(Ptable t=current_env; t!=NULL; t=t->next ){
         if (strcmp(t->name, name)==0)
            result=t;}



   return result;
}
Ttype create_type(Tdomain domain, Tdomain child) {
   Ttype  t= malloc(sizeof ( struct sdomain));
   t->domain=domain;
   t->child=child;
   t->fields=NULL;
   return  t;
}

Ptable  lookup_oid(int oid) {
   if (current_env==NULL )
      current_env=NULL;
   if (tableHead==NULL)
      return  NULL;
   Ptable result=NULL;
   for(Ptable t=current_env; t!=NULL; t=t->next ){
      if (t->oid==oid)
         result=t;}

   return result;
}
void copy_type(Ttype* t1, Ttype* t2) {
   (*t1)->domain=(*t2)->domain;
   (*t1)->child=(*t2)->child;
   (*t1)->fields=(*t2)->fields;
}
int evaluate_dim_2(Tdomain domain) {
   switch (domain) {
      case D_INT:
         case D_BOOL:
         return 4;
      case D_REAL:
         return 8;
      case D_STRING:
         return 8;
      default:
         return 0;
   }
   return 1;
}
Param createParam(Pnode node,int offset){
   Param root= malloc (sizeof(struct sparam));
   root->name=node->c1->value.sval;
   root->domain=select_type(node->c2, 2 )->domain;
   root->next=NULL;
   root->dim=(evaluate_dim_2(root->domain));
   root->offset=offset;
   root->next_offset=offset+root->dim;

   return root;}

Param createParam_for_rec_constr(Ttype type) {
   Param root= malloc (sizeof(struct sparam));
   root->name=NULL;
   root->domain=type->domain;
   root->next=NULL;
   return root;
}

Ptable createEntry (char  *name, Tclass tclass,int dim,  Ttype type, int oid, Ptable  formals){
   Ptable table= malloc (sizeof(struct sTable));
   table->name=name;
   table->tclass=tclass;
   table->type=type;
   table->dimension=dim;
   table->oid=oid;
   table->formals=formals;
   table->next=NULL;
   return table;}
void  upgrade_innested_foreach() {
   innestedForeach++;
   if(innestedForeach_max==0) {
      insert("FOREACH",PARAM_CLASS, create_type(D_INT,D_EMPTY),-1);
      innestedForeach_max=innestedForeach;
      char* buffer="0";
      sprintf(buffer, "%d", innestedForeach_max);
      Ptable t=lookup("FOREACH");
     t->formals=createEntry(concatena_stringa("index_",buffer),PARAM_CLASS,4, create_type(D_INT,D_EMPTY),oid++,NULL);
      foreach_tail=t->formals->next;
   }
  else if( innestedForeach>innestedForeach_max) {
      innestedForeach_max=innestedForeach;
      char* buffer="0";
      sprintf(buffer, "%d", innestedForeach_max);
      foreach_tail=createEntry(concatena_stringa("index_",buffer),PARAM_CLASS,4, create_type(D_INT,D_EMPTY),oid++,NULL);
      foreach_tail=foreach_tail->next;
  }
}
void downgrade_innested_foreach() {
   innestedForeach--;
}



int evaluate_dim(Ttype type) {
   int count=0;
   switch (type->domain) {
      case D_INT:
         case D_STRING:
         case D_BOOL:
      case D_REAL:
         return evaluate_dim_2(type->domain);
      case D_ARRAY:
         if (type->child<D_ARRAY)
            return evaluate_dim_2(type->child);
         if (type->child==D_RECORD)
            for (Param p=type->fields;p!=NULL;p=p->next)
            count+=evaluate_dim_2(p->domain);
         return count;

      case D_RECORD:

      for (Param p=type->fields;p!=NULL;p=p->next)
         count+=evaluate_dim_2(p->domain);
      return count;
      default:return  0;
   }

}

Ptable createFields (Pnode node, char* func_name){
int param_oid=0;
Ttype pType=select_type(node->c2,0);
Ptable pHead=createEntry(node->c1->value.sval,PARAM_CLASS,evaluate_dim(pType),pType, param_oid++, NULL);
Ptable pTail=pHead;

for(Pnode n=node->b; n!=NULL; n=n->b) {
   pType=select_type(n->c2,0 );
   set_current_env(pHead);
   Ptable temp_table=lookup(n->c1->value.sval);
   if (temp_table==NULL || (temp_table->tclass!=PARAM_CLASS)){
      Ptable t =createEntry(n->c1->value.sval,PARAM_CLASS,evaluate_dim(pType), pType, param_oid++, NULL);
      pTail->next=t;
      pTail=pTail->next;}
   else tableError("[%s] there are two parameter with the same name in function ", func_name);
}
   reset_env();
return pHead;}



Ttype save_type(Ttype t1) {
   Ttype new_ttype=create_type(t1->domain,t1->child);
   if(t1->fields!=NULL)
      new_ttype->fields=t1->fields;
   return new_ttype;
}

Ttype select_type(Pnode node, int complexdomain){

Ttype t=create_type(D_EMPTY, D_EMPTY);
switch  (node->symbol){
   case T_INTEGER : t->domain=D_INT;
               return t;
   case T_BOOLEAN : t->domain=D_BOOL;
   return t;
   case T_REAL : t->domain=D_REAL;
   return t;
   case T_STRING: t->domain=D_STRING;
   return t;

   case T_ID :
      Ptable table=lookup(node->value.sval);
      if(table==NULL || table->tclass!=TYPE_CLASS)
      tableError("[%s]type not yet defined",node->value.sval);
      else if(complexdomain==1 && table->type->domain==D_ARRAY)
         tableError("[%s] are you trying to create an array of array",node->value.sval);
      else if(complexdomain==2 && (table->type->domain==D_ARRAY || table->type->domain==D_RECORD))
         tableError("[%s] are you trying to create an complex record",node->value.sval);
   else t=table->type;

   return t;
    case NRECTYPE: t->domain= D_RECORD;
   node=node->c1;
   t->fields=createParam(node, 0);

   Param paramHead = t->fields;
                   for (Pnode n=node->b; n!=NULL; n=n->b){
                      if(search_param(t, n->c1->value.sval)==NULL) {
                         paramHead->next=createParam(n, paramHead->next_offset);
                         paramHead=paramHead->next;
                      }
                      else tableError("different fields have the same name in REC-TYPE-DECL", NULL);
                   }
   return t;

   case NARRAYTYPE:t->domain= D_ARRAY;
                  if (node->c1==NULL){
                  t->child= D_EMPTY;
                  return t;
                  }
                  else {Ttype t2=select_type(node->c1, 1);
                   t->child=t2->domain;
                  if (t->child==D_RECORD)
                   t->fields=t2->fields;
                   return t ;}
   default:   tableError("caso default",NULL);
   break;

}
 return NULL;}


void insert (char  *name, Tclass tclass,  Ttype type, int oid){
if(tableHead==NULL)
   tableHead=tableTail=createEntry(name, tclass, evaluate_dim(type), type, oid, NULL);

else {
   tableTail->next=createEntry(name, tclass,   evaluate_dim(type),type, oid, NULL);
   tableTail=tableTail->next;
}

}

void insert_functions (char  *name, Tclass tclass,  Ttype type, int oid, Ptable formals) {
   if(tableHead==NULL)
      tableHead=tableTail=createEntry(name, tclass, 0, type, oid, formals);
   else {
      tableTail->next=createEntry(name, tclass, 0, type, oid, formals);
      tableTail=tableTail->next;
   }
}

int  typecmp(Ttype type_a, Ttype type_b) {
   int i=1;
   //check if type1(atomic domain) compatible with array
   if (type_a->domain<D_REAL && type_b->domain==D_ARRAY && type_a->domain==type_b->child)
      return 2;

   if (type_a->domain==D_RECORD && type_b->domain==D_ARRAY && type_b->child==D_RECORD){
      //the case the child is a record
         for (Param p1=type_a->fields, p2=type_b->fields;
             p1!=NULL && p2!=NULL;
             p1=p1->next, p2=p2->next) {
            if((p1->next==NULL && p2->next!=NULL) || (p1->next!=NULL && p2->next==NULL)
                || strcmp(p1->name,p2->name)!=0)
               return 0;
             }
   }
   //check if type1 and type2 dont have the same domain
   if (type_a->domain!=type_b->domain)
      i=  0;
   //if they have check the case they are arrays and check if they have the same children dom
   if (type_a->domain==D_ARRAY ) {
         if(type_a->child!=type_b->child && (type_a->child!=D_EMPTY && type_b->child!=D_EMPTY))
            i= 0;
         //the case the child is a record
         if (type_a->child==D_RECORD) {
            for (Param p1=type_a->fields, p2=type_b->fields;
                p1!=NULL && p2!=NULL;
                p1=p1->next, p2=p2->next) {
               if((p1->next==NULL && p2->next!=NULL) || (p1->next!=NULL && p2->next==NULL)
                   || strcmp(p1->name,p2->name)!=0)
                  i= 0;
            }

         }

   }
   //entrambi sono record
   if (type_a->domain==D_RECORD && type_b->domain==D_RECORD && ( type_a->child!=D_RECORD && type_b->child!=D_RECORD)) {
      for (Param p1=type_a->fields, p2=type_b->fields;
                p1!=NULL && p2!=NULL;
                p1=p1->next, p2=p2->next)
         if((p1->next==NULL && p2->next!=NULL) || (p1->next!=NULL && p2->next==NULL)
                   || (strcmp(p1->name,p2->name)!=0))
            i= 0;
   }else if  (type_a->domain==D_RECORD && type_b->domain==D_RECORD && ( type_a->child!=D_RECORD || type_b->child!=D_RECORD)) {
      for (Param p1=type_a->fields, p2=type_b->fields;
                p1!=NULL && p2!=NULL;
                p1=p1->next, p2=p2->next)
         if((p1->next==NULL && p2->next!=NULL) || (p1->next!=NULL && p2->next==NULL)
                   || p1->domain!=p2->domain)
            i= 0;
   }
   return i;
}

Ttype search_param_type(Ttype type, char *param_name ) {
   //se si trattasse di un array di record allora devo controllare il campo child
   if (type->domain==D_RECORD || type->child==D_RECORD ){
   for(Param p =type->fields; p!=NULL;p=p->next)
      if(strcmp(p->name,param_name)==0) {
         Ttype  t=malloc(sizeof ( struct sdomain));
         t->domain=p->domain;
         t->child=D_EMPTY;
         t->fields=NULL;
         return t;
      }
}else tableError("[ %s ] this type is not a RECORD", NULL);
   tableError("[ %s ] this param not exisist in this RECORD ", param_name);
   return NULL;
}
Param search_param(Ttype type, char *param_name ) {
   if (type->domain==D_RECORD || type->child==D_RECORD  ) {
      ;
      for(Param p =type->fields; p!=NULL;p=p->next)
         if(strcmp(p->name,param_name)==0) {
            return p;
         }
   }
   else tableError("this type is not a RECORD ", NULL);
   return NULL;
}
void check_ntypedecl(Pnode root) {
   Ttype type=select_type( root->c2, 0 );
   for (Pnode p=root->c1; p!=NULL; p=p->b){
      if(lookup(p->value.sval)==NULL)
         insert(p->value.sval,TYPE_CLASS, type, -1);
      else  tableError(" this type already declared", p->value.sval);
   }

}

void check_nvardecl(Pnode root) {

   Ttype type=select_type( root->c2,0 );
   for ( Pnode p=root->c1; p!=NULL; p=p->b) {
      if( lookup(p->value.sval)==NULL)
         insert(p->value.sval,VAR_CLASS, type, oid++);
      else  tableError(" this var already declared", p->value.sval);
   }
}

void check_nfundecl(Pnode root) {


   if (lookup(root->value.sval)==NULL){

    Ttype  typ1=select_type( root->c2,0);
    Ptable  table = createFields(root->c1, root->value.sval);
      insert_functions(root->value.sval, FUNCT_CLASS, typ1, oid++, table);
      set_current_env(table);
      Ttype typ2=checkTree(root->c3);
      reset_env();
      if (typecmp(typ1, typ2)==0)
         tableError("the type returned from the func is not the same that is declared", root->value.sval);
     }

   else tableError("[ %s ] this name func already declared", root->value.sval);

}

void check_nreadstat (Pnode root) {
   if (lookup(root->c1->value.sval)==NULL)
      tableError("[ %s ] this name is not declared (READSTAT)", root->c1->value.sval);
}

void check_nassignstat(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   Ttype type1=save_type(typ1);
   free(typ1);
   Ttype typ2=checkTree (root->c2);
   if ( typecmp(type1, typ2)==0)
   tableError("mismatch in ASSIGNSTAT",NULL);
}

Ttype check_nlhs(Pnode root) {
   //save type è stato creato per non passare il type salvato nella tabella ma una sua copia
   //cosi da evitare che venga cancellato dai vari free che ho inserito
   if(root->c1->symbol==T_ID) {
      Ptable table=lookup(root->c1->value.sval);
      if (table==NULL)
         tableError(" this name is not declared (NHLSSTAT)", root->c1->value.sval);
      else if (root->c2==NULL) //caso dell'id di atomic domain
         return save_type(table->type);
      else return save_type(search_param_type(table->type, root->c2->value.sval)); //caso del record
   }
   else {
      root=root->c1;
      Ptable table=lookup(root->c1->value.sval);
      if (table==NULL)
         tableError("[ %s ] this name is not declared (NHLSSTAT)", root->c1->c1->value.sval);
      else if (table->type->domain!=D_ARRAY)
         tableError("[ %s ] this name is not an ARRAY (NHLSSTAT)", root->c1->c1->value.sval);
      else if (root->c3==NULL) { //caso di array di atomic
         Ttype typ1=checkTree(root->c2);
         if(typ1->domain!=D_INT)
            tableError("[ %s ] invalid type of expr to access to ARRAY (NHLSSTAT)", root->c1->c1->value.sval);
         else {//caso di array di record
            Ttype temp= create_type(table->type->child,table->type->child);
            return temp;
         }
      }
      else return save_type(search_param_type(table->type, root->c1->c3->value.sval));
   }
   return NULL;
}

void check_nifstat(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   if (typ1->domain==D_BOOL) {
      for(Pnode n=root->c2;n!=NULL;n=n->b)
      checkTree(n);
      for(Pnode n=root->c3;n!=NULL;n=n->b)
         checkTree(n);
   }
   else tableError("this expr type is not a boolean(IFSTAT)",NULL);
}

void check_nwhilestat(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   if (typ1->domain==D_BOOL)
      for(Pnode n=root->c2;n!=NULL;n=n->b)
         checkTree(n);
   tableError("this expr type is not a boolean(WHILESTAT)",NULL);
}

void check_nforeachstat(Pnode root) {
   Ptable table=lookup (root->c2->value.sval);
   if (table!=NULL) {
      Ttype typ2=table->type;
      if ( typ2->domain==D_ARRAY ) {
         if(lookup(root->c1->value.sval)!=NULL) {
            //Ttype typ1 = create_type(typ2->child, D_EMPTY);
            //insert(root->c1->value.sval, PARAM_CLASS, typ1, oid++ );
            upgrade_innested_foreach();
            for(Pnode n=root->c3;n!=NULL;n=n->b)
               checkTree(n);
            downgrade_innested_foreach();
         }
         else tableError("[%s] is already defined in FOREACHSTAT",root->c1->value.sval);

      }
      else tableError(" is not an array in FOREACHSTAT",root->c2->value.sval);
   }
   else tableError(" is not defined array in FOREACHSTAT",root->c2->value.sval);
}

Ttype check_nlogicexpr(Pnode root) {
   Ttype t1=checkTree (root->c1);
   Ttype type1=save_type(t1);
   free(t1);
   Ttype t2=checkTree (root->c2);

   if (type1->domain==D_BOOL || t2->domain==D_BOOL) {

      type1->domain=D_BOOL;
      type1->child=D_EMPTY;
      type1->fields=NULL;

      return type1;
   }
   tableError("mismatch in logicexpr",NULL);
   return NULL;
}

Ttype check_ncompexpr(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   Ttype type1=save_type(typ1);
   free(typ1);
   Ttype typ2=checkTree (root->c2);
   if(root->value.ival!=T_IN) {
      if(  root->value.ival==T_NOTEQUAL || root->value.ival==T_EQUAL)
      {

         if ( typecmp(type1,typ2)>0){
            type1->domain=D_BOOL;
            type1->child=D_EMPTY;
            type1->fields=NULL;
            return type1;
         }
         else tableError("mismatch in NCOMPEXPR",NULL);
      }
      else if (type1->domain==typ2->domain && type1->domain==D_INT || type1->domain==D_REAL ||  type1->domain==D_STRING)
      {  type1->domain=D_BOOL;
         type1->child=D_EMPTY;
         type1->fields=NULL;
         return  type1;
   }
      else tableError("mismatch in NCOMPEXPR",NULL);
   }

   else{
      if ( typ2->domain==D_ARRAY && typecmp(type1,typ2)==1) {
         type1->domain=D_BOOL;
         type1->child=D_EMPTY;
         type1->fields=NULL;
         return  type1;
      }
     else tableError("mismatch in NCOMPEXPR",NULL);
   }
   return NULL;
}

Ttype check_nmathexpr(Pnode root) {
   if(root->value.ival!=T_CONCAT) {
      Ttype typ1=checkTree (root->c1);
      Ttype type1=save_type(typ1);
      free(typ1);
      Ttype typ2=checkTree (root->c2);
      if ( typecmp(type1,typ2)>0) {
         if(type1->domain==D_INT ||type1->domain==D_REAL )
            return type1;
         tableError("the type of expr is not correct in NMATHEXPR",NULL);
      }

      tableError("mismatch in NMATHEXPR",NULL);
   }
   else {
      Ttype typ1=checkTree (root->c1);
      Ttype type1=save_type(typ1);
      free(typ1);
      Ttype typ2=checkTree (root->c2);
      if (type1->domain==D_ARRAY && typ2->domain==D_ARRAY && (typecmp(type1,typ2)>0 || typ2->child==D_EMPTY)) {
         return type1;
      }
      tableError("mismatch in NMATHEXPR",NULL);
   }
   return  NULL;
}

Ttype check_nnegexpr(Pnode root) {
   if(root->value.ival==T_NOT) {
      Ttype typ1=checkTree (root->c1);

      if (typ1->domain==D_BOOL)
         return typ1;
      tableError("mismatch in NEGEXPR",NULL);
   }
   else {
      Ttype typ1=checkTree (root->c1);
      if (typ1->domain==D_INT || typ1->domain==D_REAL) {
         return typ1;
      }
      tableError("mismatch in NEGEXPR",NULL);
   }
return NULL;
}

Ttype check_nbuiltinexpr(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   Ttype temp=save_type(typ1);
   free(typ1);
   if(root->value.ival==T_CASTINT ) {

      if ( temp->domain==D_REAL || temp->domain==D_INT) {
         temp->domain= D_INT;
         temp->child= D_EMPTY;
         temp->fields= NULL;
         return temp;
      }
      tableError("mismatch in NBUILTINEXPR",NULL);
   }
   else if(root->value.ival==T_CASTREAL ) {

      if ( temp->domain==D_REAL || temp->domain==D_INT) {
         temp->domain= D_REAL;
         temp->child= D_EMPTY;
         temp->fields= NULL;
         return temp;
      }
      tableError("mismatch in NBUILTINEXPR",NULL);
   }
   else if (root->value.ival==T_EMPTY)
   {
      if (temp->domain==D_ARRAY) {
         temp->domain= D_BOOL;
         temp->child=D_EMPTY;
         temp->fields=NULL;
         return temp;            }
      tableError("mismatch in NMATHEXPR",NULL);
   }
   else if (root->value.ival==T_HEAD)
   {
      int domainType=temp->child;
      if (temp->domain==D_ARRAY) {
         temp->domain= domainType;
         temp->child=D_EMPTY;
         temp->fields=NULL;
         return temp;            }
      tableError("mismatch in NMATHEXPR",NULL);
   }
   else if (root->value.ival==T_TAIL)
   {
      if (temp->domain==D_ARRAY) {
         temp->domain=temp->domain;
         temp->child=temp->child;
         temp->fields=temp->fields;
         return temp;           }
      tableError("mismatch in NMATHEXPR",NULL);
   }
   else if (root->value.ival==T_CARD)
   {
      if (temp->domain==D_ARRAY) {
         temp->domain=D_INT;
         temp->child=D_EMPTY;
         temp->fields=NULL;
         return temp;            }
      tableError("mismatch in NMATHEXPR",NULL);
   }
   return NULL;
}

Ttype check_nconstructor(Pnode root) {

if(root->value.ival==T_ARRAY) {
   if (root->c1!=NULL) {
      Ttype typ1=checkTree(root->c1);
      Ttype type1=save_type(typ1);
      free(typ1);
      if(type1->domain==D_ARRAY)
         tableError("array of arrays not allowed in NCONSTRUCTOR",NULL);
      for(Pnode p=root->c1->b; p!=NULL; p=p->b) {
         Ttype typ2=checkTree(p);
         if (typecmp(type1,typ2)==0)
            tableError("not all the expr have the same type in NCONSTRUCTOR",NULL);
      }


      type1->child=type1->domain;
      type1->domain=D_ARRAY;
      if(type1->child!=D_RECORD)
         type1->fields=NULL;
      return type1;
   }
    return create_type(D_ARRAY,D_EMPTY);

}
//caso sia record
else {
   Ttype temp=create_type(D_RECORD, D_RECORD);
   Param paramHead;
   Ttype typ1=checkTree(root->c1);
   Ttype type1=save_type(typ1);
   free(typ1);
   temp->fields=paramHead= createParam_for_rec_constr(type1);
   for (Pnode n=root->c1->b; n!=NULL; n=n->b){
      Ttype typ2=checkTree(n);
      paramHead->next=createParam_for_rec_constr(typ2);
      paramHead=paramHead->next;
   }
   return temp;
}

}

Ttype check_ncondexpr(Pnode root) {
   Ttype typ1=checkTree (root->c1);
   Ttype type1=save_type(typ1);
   free(typ1);
   Ttype typ2=checkTree (root->c2);
   Ttype type2=save_type(typ2);
   free(typ2);
   Ttype typ3=checkTree (root->c3);
   if (type1->domain==D_BOOL && typecmp(type2, typ3))
      return type2;
   tableError("mismatch in NCONDEXPR",NULL);

return NULL;
}

Ttype check_nfuncall(Pnode root) {
   pause_current_env();
   Ptable table_func=lookup(root->value.sval);
   restart_current_env();
   if(table_func==NULL)
      tableError("name of the function not found in FUNCALL ",root->value.sval);
   Ptable table=table_func->formals;
   for(Pnode p=root->c1; p!=NULL;p=p->b,table=table->next) {

      if (typecmp(checkTree(p), table->type)==0)
         tableError("values dont corrispond to func signature in FUNCALL",root->value.sval);

   }

   return table_func->type;
return  NULL;
}

Ttype check_tstringconst(Pnode root) {
   return create_type(D_STRING,D_EMPTY);
}
Ttype check_tintconst(Pnode root) {
   return create_type(D_INT,D_EMPTY);
}
Ttype check_trealconst(Pnode root) {
   return create_type(D_REAL,D_EMPTY);
}
Ttype check_tboolconst(Pnode root) {
   return create_type(D_BOOL,D_EMPTY);
}

Ttype checkTree (Pnode root) {
   current_line=root->line;

   switch (root->symbol) {
      case NPROGRAM:
         if (root->c1!=NULL) checkTree(root->c1);
      if (root->c2!=NULL)checkTree(root->c2);
      if (root->c3!=NULL)checkTree(root->c3);
      if (root->c4!=NULL)checkTree(root->c4);
      return NULL;


      case NTYPESEC:
         case NVARSEC:
      case NFUNCSEC:
      case NRUNSEC:
         for (Pnode p=root->c1; p!=NULL; p=p->b) checkTree(p);
      return NULL;


      case NTYPEDECL:
         check_ntypedecl(root);
      return NULL;


      case NVARDECL:
         check_nvardecl(root);
      return NULL;


      case NFUNDECL:
         check_nfundecl(root);
      return NULL;


      case NREAD:
         check_nreadstat(root);
      return NULL;


      case NWRITE:
         checkTree(root->c1);
      return NULL;


      case NASSIGN:
         check_nassignstat(root);
      return NULL;


      case NLHS:
         return check_nlhs(root);


      case NIFSTAT:
         check_nifstat(root);
      return NULL;


      case NWHILESTAT:
         check_nwhilestat(root);
      return NULL;


      case NFOREACH:
         check_nforeachstat(root);
      return NULL;


      case NLOGICEXPR:
         return check_nlogicexpr(root);

      case NCOMPEXPR:
         return check_ncompexpr(root);


      case NMATHEXPR:
         return check_nmathexpr(root);


      case NNEGEXPR:
         return check_nnegexpr(root);


      case NBUILTINEXPR:
         return  check_nbuiltinexpr(root);

      case NCONSTRUCTOR:
         return check_nconstructor(root);

      case NCONDEXPR:
         return check_ncondexpr(root);

      case NFUNCCALL:
         return  check_nfuncall(root);
      case T_STRCONST:
         return  check_tstringconst(root);
      case T_INTCONST:
         return  check_tintconst(root);
      case T_REALCONST:
            return  check_trealconst(root);
      case T_BOOLCONST:
         return  check_tboolconst(root);
      default: tableError("default case :unknow node",NULL);
      return NULL;
   }
}

int check_nothing(int i) {

   if(i==0)
      return 0;
   if(i==1)
     return 0;
   return 1;

}

Ptable generate_symboltable(Pnode root) {
   checkTree(root);
   return tableHead;
}

char* printTypes(Ttype type){
   return domainTerms[type->domain];
}

void printTable (Ptable t ){

   for(Ptable t1=t; t1!=NULL; t1=t1->next){
      printf("[name]: %s\t\t, [class]: %s\t\t, [type]: %s\t\t, [oid]: %d\n"
              , t1->name,   classTerms [t1->tclass], printTypes(t1->type), t1->oid);
      if(t->tclass==FUNCT_CLASS){
         for(Ptable t2=t1->formals; t2!=NULL; t2=t2->next)
            printf("\t[name]: %s\t, [class]: %s\t, [type]: %s\t, [oid]: %d\n"
                    , t1->name,   classTerms [t1->tclass], printTypes(t1->type), t1->oid);}
   }
}


