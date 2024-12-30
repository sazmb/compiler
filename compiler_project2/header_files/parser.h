/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEF = 258,                     /* DEF  */
    INT = 259,                     /* INT  */
    STRING = 260,                  /* STRING  */
    BOOL = 261,                    /* BOOL  */
    REAL = 262,                    /* REAL  */
    ID = 263,                      /* ID  */
    INTCONST = 264,                /* INTCONST  */
    REALCONST = 265,               /* REALCONST  */
    STRCONST = 266,                /* STRCONST  */
    BOOLCONST = 267,               /* BOOLCONST  */
    TYPES = 268,                   /* TYPES  */
    ASSIGN = 269,                  /* ASSIGN  */
    ERROR = 270,                   /* ERROR  */
    VARIABLES = 271,               /* VARIABLES  */
    FUNCTIONS = 272,               /* FUNCTIONS  */
    IF = 273,                      /* IF  */
    THEN = 274,                    /* THEN  */
    ELSE = 275,                    /* ELSE  */
    END = 276,                     /* END  */
    RUN = 277,                     /* RUN  */
    READ_TOKEN = 278,              /* READ_TOKEN  */
    WRITE = 279,                   /* WRITE  */
    WHILE = 280,                   /* WHILE  */
    FOREACH = 281,                 /* FOREACH  */
    IN = 282,                      /* IN  */
    DO = 283,                      /* DO  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    ADD = 286,                     /* ADD  */
    SUB = 287,                     /* SUB  */
    CONCAT = 288,                  /* CONCAT  */
    EQUAL = 289,                   /* EQUAL  */
    NEQUAL = 290,                  /* NEQUAL  */
    GT = 291,                      /* GT  */
    GE = 292,                      /* GE  */
    LE = 293,                      /* LE  */
    LT = 294,                      /* LT  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MUL = 297,                     /* MUL  */
    DIVIDE = 298,                  /* DIVIDE  */
    NOT = 299,                     /* NOT  */
    MINUSSIGN = 300,               /* MINUSSIGN  */
    CAST_INT = 301,                /* CAST_INT  */
    CAST_REAL = 302,               /* CAST_REAL  */
    EMPTY_TOKEN = 303,             /* EMPTY_TOKEN  */
    HEAD_TOKEN = 304,              /* HEAD_TOKEN  */
    TAIL_TOKEN = 305               /* TAIL_TOKEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */
