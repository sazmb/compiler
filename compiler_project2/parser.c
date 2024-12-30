/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 85 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEF = 3,                        /* DEF  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_BOOL = 6,                       /* BOOL  */
  YYSYMBOL_REAL = 7,                       /* REAL  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_INTCONST = 9,                   /* INTCONST  */
  YYSYMBOL_REALCONST = 10,                 /* REALCONST  */
  YYSYMBOL_STRCONST = 11,                  /* STRCONST  */
  YYSYMBOL_BOOLCONST = 12,                 /* BOOLCONST  */
  YYSYMBOL_TYPES = 13,                     /* TYPES  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_ERROR = 15,                     /* ERROR  */
  YYSYMBOL_VARIABLES = 16,                 /* VARIABLES  */
  YYSYMBOL_FUNCTIONS = 17,                 /* FUNCTIONS  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_END = 21,                       /* END  */
  YYSYMBOL_RUN = 22,                       /* RUN  */
  YYSYMBOL_READ_TOKEN = 23,                /* READ_TOKEN  */
  YYSYMBOL_WRITE = 24,                     /* WRITE  */
  YYSYMBOL_WHILE = 25,                     /* WHILE  */
  YYSYMBOL_FOREACH = 26,                   /* FOREACH  */
  YYSYMBOL_IN = 27,                        /* IN  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_ADD = 31,                       /* ADD  */
  YYSYMBOL_SUB = 32,                       /* SUB  */
  YYSYMBOL_CONCAT = 33,                    /* CONCAT  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 35,                    /* NEQUAL  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_GE = 37,                        /* GE  */
  YYSYMBOL_LE = 38,                        /* LE  */
  YYSYMBOL_LT = 39,                        /* LT  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_NOT = 44,                       /* NOT  */
  YYSYMBOL_MINUSSIGN = 45,                 /* MINUSSIGN  */
  YYSYMBOL_CAST_INT = 46,                  /* CAST_INT  */
  YYSYMBOL_CAST_REAL = 47,                 /* CAST_REAL  */
  YYSYMBOL_EMPTY_TOKEN = 48,               /* EMPTY_TOKEN  */
  YYSYMBOL_HEAD_TOKEN = 49,                /* HEAD_TOKEN  */
  YYSYMBOL_TAIL_TOKEN = 50,                /* TAIL_TOKEN  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* '('  */
  YYSYMBOL_59_ = 59,                       /* ')'  */
  YYSYMBOL_60_ = 60,                       /* '|'  */
  YYSYMBOL_61_ = 61,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_type_section = 64,              /* type_section  */
  YYSYMBOL_type_decl_list = 65,            /* type_decl_list  */
  YYSYMBOL_type_decl = 66,                 /* type_decl  */
  YYSYMBOL_id_list = 67,                   /* id_list  */
  YYSYMBOL_68_1 = 68,                      /* @1  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_atomic_type = 70,               /* atomic_type  */
  YYSYMBOL_record_type = 71,               /* record_type  */
  YYSYMBOL_atomic_decl_list = 72,          /* atomic_decl_list  */
  YYSYMBOL_atomic_decl = 73,               /* atomic_decl  */
  YYSYMBOL_74_2 = 74,                      /* @2  */
  YYSYMBOL_array_type = 75,                /* array_type  */
  YYSYMBOL_array_elem_type = 76,           /* array_elem_type  */
  YYSYMBOL_var_section = 77,               /* var_section  */
  YYSYMBOL_var_decl_list = 78,             /* var_decl_list  */
  YYSYMBOL_var_decl = 79,                  /* var_decl  */
  YYSYMBOL_func_section = 80,              /* func_section  */
  YYSYMBOL_fun_decl_list = 81,             /* fun_decl_list  */
  YYSYMBOL_fun_decl = 82,                  /* fun_decl  */
  YYSYMBOL_83_3 = 83,                      /* @3  */
  YYSYMBOL_opt_formal_decl_list = 84,      /* opt_formal_decl_list  */
  YYSYMBOL_formal_decl_list = 85,          /* formal_decl_list  */
  YYSYMBOL_formal_decl = 86,               /* formal_decl  */
  YYSYMBOL_87_4 = 87,                      /* @4  */
  YYSYMBOL_expr = 88,                      /* expr  */
  YYSYMBOL_bool_op = 89,                   /* bool_op  */
  YYSYMBOL_bool_term = 90,                 /* bool_term  */
  YYSYMBOL_comp_op = 91,                   /* comp_op  */
  YYSYMBOL_comp_term = 92,                 /* comp_term  */
  YYSYMBOL_add_op = 93,                    /* add_op  */
  YYSYMBOL_term = 94,                      /* term  */
  YYSYMBOL_mul_op = 95,                    /* mul_op  */
  YYSYMBOL_factor = 96,                    /* factor  */
  YYSYMBOL_unary_op = 97,                  /* unary_op  */
  YYSYMBOL_built_in = 98,                  /* built_in  */
  YYSYMBOL_atomic_constant = 99,           /* atomic_constant  */
  YYSYMBOL_record_constructor = 100,       /* record_constructor  */
  YYSYMBOL_expr_list = 101,                /* expr_list  */
  YYSYMBOL_cond_expr = 102,                /* cond_expr  */
  YYSYMBOL_func_call = 103,                /* func_call  */
  YYSYMBOL_104_5 = 104,                    /* @5  */
  YYSYMBOL_opt_expr_list = 105,            /* opt_expr_list  */
  YYSYMBOL_array_constructor = 106,        /* array_constructor  */
  YYSYMBOL_run_section = 107,              /* run_section  */
  YYSYMBOL_stat_list = 108,                /* stat_list  */
  YYSYMBOL_stat = 109,                     /* stat  */
  YYSYMBOL_read_stat = 110,                /* read_stat  */
  YYSYMBOL_write_stat = 111,               /* write_stat  */
  YYSYMBOL_assign_stat = 112,              /* assign_stat  */
  YYSYMBOL_lhs = 113,                      /* lhs  */
  YYSYMBOL_114_6 = 114,                    /* @6  */
  YYSYMBOL_opt_fielding = 115,             /* opt_fielding  */
  YYSYMBOL_indexing = 116,                 /* indexing  */
  YYSYMBOL_117_7 = 117,                    /* @7  */
  YYSYMBOL_if_stat = 118,                  /* if_stat  */
  YYSYMBOL_else_part = 119,                /* else_part  */
  YYSYMBOL_while_stat = 120,               /* while_stat  */
  YYSYMBOL_foreach_stat = 121,             /* foreach_stat  */
  YYSYMBOL_122_8 = 122,                    /* @8  */
  YYSYMBOL_123_9 = 123                     /* @9  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    59,     2,     2,    52,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    60,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    29,    29,    37,    40,    43,    46,    48,    53,    53,
      56,    58,    60,    62,    65,    66,    67,    68,    69,    71,
      74,    76,    78,    78,    82,    85,    86,    88,    90,    92,
      95,    97,   100,   102,   104,   107,   109,   109,   115,   116,
     118,   121,   123,   123,   127,   132,   135,   136,   138,   143,
     146,   147,   148,   149,   150,   151,   152,   154,   158,   161,
     162,   163,   165,   169,   172,   173,   175,   179,   181,   184,
     186,   190,   192,   194,   196,   198,   201,   202,   204,   205,
     206,   207,   208,   210,   211,   212,   213,   215,   219,   221,
     223,   228,   228,   232,   234,   236,   240,   242,   244,   246,
     248,   249,   250,   251,   252,   253,   255,   258,   261,   265,
     265,   269,   272,   274,   276,   276,   282,   287,   289,   291,
     295,   295,   295
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEF", "INT", "STRING",
  "BOOL", "REAL", "ID", "INTCONST", "REALCONST", "STRCONST", "BOOLCONST",
  "TYPES", "ASSIGN", "ERROR", "VARIABLES", "FUNCTIONS", "IF", "THEN",
  "ELSE", "END", "RUN", "READ_TOKEN", "WRITE", "WHILE", "FOREACH", "IN",
  "DO", "AND", "OR", "ADD", "SUB", "CONCAT", "EQUAL", "NEQUAL", "GT", "GE",
  "LE", "LT", "PLUS", "MINUS", "MUL", "DIVIDE", "NOT", "MINUSSIGN",
  "CAST_INT", "CAST_REAL", "EMPTY_TOKEN", "HEAD_TOKEN", "TAIL_TOKEN",
  "';'", "','", "'{'", "'}'", "':'", "'['", "']'", "'('", "')'", "'|'",
  "'.'", "$accept", "program", "type_section", "type_decl_list",
  "type_decl", "id_list", "@1", "type", "atomic_type", "record_type",
  "atomic_decl_list", "atomic_decl", "@2", "array_type", "array_elem_type",
  "var_section", "var_decl_list", "var_decl", "func_section",
  "fun_decl_list", "fun_decl", "@3", "opt_formal_decl_list",
  "formal_decl_list", "formal_decl", "@4", "expr", "bool_op", "bool_term",
  "comp_op", "comp_term", "add_op", "term", "mul_op", "factor", "unary_op",
  "built_in", "atomic_constant", "record_constructor", "expr_list",
  "cond_expr", "func_call", "@5", "opt_expr_list", "array_constructor",
  "run_section", "stat_list", "stat", "read_stat", "write_stat",
  "assign_stat", "lhs", "@6", "opt_fielding", "indexing", "@7", "if_stat",
  "else_part", "while_stat", "foreach_stat", "@8", "@9", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-115)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    23,    33,    20,   -13,  -103,    23,    28,  -103,    23,
      30,    -2,  -103,    13,     3,  -103,    23,    55,    46,    23,
    -103,  -103,  -103,  -103,  -103,    63,    22,    39,  -103,  -103,
    -103,    13,  -103,  -103,  -103,    55,    80,  -103,  -103,  -103,
      43,    25,  -103,  -103,    53,  -103,    62,    71,  -103,    68,
       4,   122,     4,     4,   129,   118,    89,  -103,  -103,  -103,
     128,  -103,  -103,  -103,  -103,    88,  -103,    63,  -103,  -103,
     144,    92,    98,  -103,  -103,    51,  -103,  -103,  -103,  -103,
       4,  -103,  -103,  -103,  -103,  -103,     4,     4,     4,     4,
      26,  -103,    81,    58,  -103,     4,    99,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,    97,    66,  -103,  -103,    80,     4,
     143,  -103,  -103,    96,  -103,   106,   148,  -103,     4,   103,
      57,    50,   108,  -103,   107,     8,     5,    80,  -103,  -103,
       4,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,     4,     4,  -103,  -103,     4,  -103,     4,    80,   133,
    -103,    97,  -103,   110,   111,   144,  -103,    -6,     4,     4,
       4,  -103,  -103,  -103,  -103,   147,  -103,    95,    58,  -103,
      14,   142,   160,    13,    13,  -103,    92,   112,    54,  -103,
      80,   149,  -103,  -103,  -103,  -103,     4,  -103,  -103,     4,
    -103,  -103,   141,   102,   104,    80,  -103,  -103,   151,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,    28,    10,     3,     6,     0,     1,     0,
      33,     0,     5,     0,     0,    27,    30,     0,    97,     0,
      14,    16,    17,    15,    18,     0,     0,     0,    11,    12,
      13,     0,    29,    36,    32,    35,     0,     2,     9,    22,
       0,    21,    25,    26,     0,     7,     0,     0,    34,   109,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
       0,   111,   103,   104,   105,     0,    19,     0,    24,    31,
      39,   113,     0,    78,    79,   109,    84,    85,    86,    83,
       0,    77,    76,    80,    81,    82,     0,    94,     0,     0,
       0,    45,    49,    58,    63,     0,     0,    71,    72,    74,
      75,    73,    69,   106,   107,     0,   120,    96,    99,     0,
       0,    20,    42,     0,    38,    41,     0,   110,     0,     0,
       0,    89,     0,    93,     0,     0,     0,     0,    47,    46,
       0,    56,    61,    50,    51,    52,    53,    54,    55,    59,
      60,     0,     0,    64,    65,     0,    66,     0,     0,     0,
      98,   108,    23,     0,     0,     0,   112,     0,    94,     0,
       0,    87,    95,    67,    68,   118,    44,    48,    57,    62,
       0,     0,     0,     0,     0,    40,   113,     0,     0,    88,
       0,     0,    70,   119,   121,    43,     0,   115,    92,     0,
     117,   116,     0,     0,     0,     0,    37,    90,     0,   122
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,   167,  -103,    73,  -103,   -28,   -25,   150,
     113,  -103,  -103,  -103,  -103,  -103,   158,  -103,  -103,   140,
    -103,  -103,  -103,    24,  -103,  -103,   -48,  -103,    47,  -103,
      37,  -103,    40,  -103,   -86,  -103,  -103,  -103,  -103,   -79,
    -103,  -103,  -103,    27,  -103,  -103,  -102,  -103,  -103,  -103,
    -103,   -36,  -103,     7,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,     7,    11,    27,    28,    29,
      40,    41,    65,    30,    44,    10,    15,    16,    18,    34,
      35,    47,   113,   114,   115,   153,   121,   130,    91,   141,
      92,   142,    93,   145,    94,    95,    96,    97,    98,   123,
      99,   100,   119,   124,   101,    37,    55,    56,    57,    58,
      59,   102,    71,   117,    61,    72,    62,   181,    63,    64,
     149,   192
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    42,    90,    46,   104,   105,   150,   122,    73,   146,
       1,    74,    75,    76,    77,    78,    79,    20,    21,    22,
      23,    24,    80,   128,   129,   165,    20,    21,    22,    23,
      24,     4,   120,     8,   128,   129,     9,   128,   129,    -8,
     125,   126,    13,   128,   129,   127,   171,    17,    81,    82,
      19,   176,    83,    84,    85,   128,   129,    86,    31,   169,
      87,   151,    88,    33,    89,   164,    25,   163,    36,    26,
     157,    39,    60,   182,   189,    25,   159,    67,   190,   128,
     129,   179,    14,   128,   129,   152,   128,   129,    49,    14,
      45,    60,    38,   198,   148,   128,   129,    66,    50,   170,
     143,   144,   160,    51,    52,    53,    54,  -114,   131,   -91,
      68,   178,    60,    69,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   196,  -114,   197,   128,   129,   132,    70,
     103,   128,   129,   128,   129,   139,   140,   106,   193,   107,
     108,   194,   109,   110,    60,   185,   186,    20,    21,    22,
      23,    24,   112,   116,   118,   154,   156,   147,   155,    60,
     172,   158,   161,   183,   162,   173,   174,   180,   184,   195,
     191,   188,   199,    12,    32,    48,    43,   166,   167,   175,
     111,     0,   168,   187,     0,   177
};

static const yytype_int16 yycheck[] =
{
      36,    26,    50,    31,    52,    53,   108,    86,     4,    95,
      13,     7,     8,     9,    10,    11,    12,     4,     5,     6,
       7,     8,    18,    29,    30,   127,     4,     5,     6,     7,
       8,     8,    80,     0,    29,    30,    16,    29,    30,    52,
      88,    89,    14,    29,    30,    19,   148,    17,    44,    45,
      52,    57,    48,    49,    50,    29,    30,    53,    55,   145,
      56,   109,    58,     8,    60,    60,    53,    59,    22,    56,
     118,     8,   108,    59,    20,    53,    19,    52,   180,    29,
      30,   160,     9,    29,    30,   110,    29,    30,     8,    16,
      51,   127,    19,   195,    28,    29,    30,    54,    18,   147,
      42,    43,    52,    23,    24,    25,    26,    56,    27,    58,
      57,   159,   148,    51,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    21,    56,    21,    29,    30,    33,    58,
       8,    29,    30,    29,    30,    40,    41,     8,   186,    21,
      51,   189,    14,    55,   180,   173,   174,     4,     5,     6,
       7,     8,     8,    61,    56,    59,     8,    58,    52,   195,
      27,    58,    54,    21,    57,    55,    55,    20,     8,    28,
      21,    59,    21,     6,    16,    35,    26,   130,   141,   155,
      67,    -1,   142,   176,    -1,   158
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    63,    64,     8,    65,    66,    67,     0,    16,
      77,    68,    65,    14,    67,    78,    79,    17,    80,    52,
       4,     5,     6,     7,     8,    53,    56,    69,    70,    71,
      75,    55,    78,     8,    81,    82,    22,   107,    67,     8,
      72,    73,    70,    71,    76,    51,    69,    83,    81,     8,
      18,    23,    24,    25,    26,   108,   109,   110,   111,   112,
     113,   116,   118,   120,   121,    74,    54,    52,    57,    51,
      58,   114,   117,     4,     7,     8,     9,    10,    11,    12,
      18,    44,    45,    48,    49,    50,    53,    56,    58,    60,
      88,    90,    92,    94,    96,    97,    98,    99,   100,   102,
     103,   106,   113,     8,    88,    88,     8,    21,    51,    14,
      55,    72,     8,    84,    85,    86,    61,   115,    56,   104,
      88,    88,   101,   101,   105,    88,    88,    19,    29,    30,
      89,    27,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    91,    93,    42,    43,    95,    96,    58,    28,   122,
     108,    88,    70,    87,    59,    52,     8,    88,    58,    19,
      52,    54,    57,    59,    60,   108,    90,    92,    94,    96,
      88,   108,    27,    55,    55,    85,    57,   105,    88,   101,
      20,   119,    59,    21,     8,    69,    69,   115,    59,    20,
     108,    21,   123,    88,    88,    28,    21,    21,   108,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    65,    65,    66,    68,    67,
      67,    69,    69,    69,    70,    70,    70,    70,    70,    71,
      72,    72,    74,    73,    75,    76,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    81,    83,    82,    84,    84,
      85,    85,    87,    86,    88,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,    99,   100,   101,   101,
     102,   104,   103,   105,   105,   106,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   110,   111,   112,   114,
     113,   113,   115,   115,   117,   116,   118,   119,   119,   120,
     122,   123,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     0,     2,     1,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     0,     4,     3,     1,     1,     2,     0,     2,
       1,     4,     2,     0,     2,     1,     0,     9,     1,     0,
       3,     1,     0,     4,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     3,     3,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       7,     0,     5,     1,     0,     3,     3,     0,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     0,
       3,     1,     2,     0,     0,     6,     6,     2,     0,     5,
       0,     0,     9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: type_section var_section func_section run_section  */
#line 29 "parser.y"
                                                            {  currentRule="program";

                                                             root=yyval= nontermnode(NPROGRAM);
                                                            yyval->c1=yyvsp[-3];
                                                            yyval->c2=yyvsp[-2];
                                                            yyval->c3=yyvsp[-1];
                                                            yyval->c4=yyvsp[0];}
#line 1351 "parser.c"
    break;

  case 3: /* type_section: TYPES type_decl_list  */
#line 37 "parser.y"
                                    { currentRule="type_section_1";
                                      yyval= nontermnode(NTYPESEC);
                                      yyval->c1=yyvsp[0];}
#line 1359 "parser.c"
    break;

  case 4: /* type_section: %empty  */
#line 40 "parser.y"
               {currentRule="type_section_2";
                yyval=NULL;}
#line 1366 "parser.c"
    break;

  case 5: /* type_decl_list: type_decl type_decl_list  */
#line 43 "parser.y"
                                        {currentRule="type_decl_list_1";yyval=yyvsp[-1];
                                         yyval->b=yyvsp[0];
                                         }
#line 1374 "parser.c"
    break;

  case 6: /* type_decl_list: type_decl  */
#line 46 "parser.y"
                          {currentRule="type_decl_list_2"; yyval=yyvsp[0];}
#line 1380 "parser.c"
    break;

  case 7: /* type_decl: id_list ASSIGN type ';'  */
#line 48 "parser.y"
                                   { currentRule="type_decl_1";
                                    yyval=nontermnode(NTYPEDECL);
                                     yyval->c1=yyvsp[-3];
                                     yyval->c2=yyvsp[-1];}
#line 1389 "parser.c"
    break;

  case 8: /* @1: %empty  */
#line 53 "parser.y"
           {yyval= idnode();}
#line 1395 "parser.c"
    break;

  case 9: /* id_list: ID @1 ',' id_list  */
#line 53 "parser.y"
                                      { currentRule="id_list_1";
                                        yyval=yyvsp[-2];
                                        yyval->b=yyvsp[0];}
#line 1403 "parser.c"
    break;

  case 10: /* id_list: ID  */
#line 56 "parser.y"
          {currentRule="id_list_2";yyval=idnode();}
#line 1409 "parser.c"
    break;

  case 11: /* type: atomic_type  */
#line 58 "parser.y"
                  { currentRule="type_1";
                    yyval=yyvsp[0];}
#line 1416 "parser.c"
    break;

  case 12: /* type: record_type  */
#line 60 "parser.y"
                   { currentRule="type_2";
                                       yyval=yyvsp[0];}
#line 1423 "parser.c"
    break;

  case 13: /* type: array_type  */
#line 62 "parser.y"
                  { currentRule="type_3";
                                      yyval=yyvsp[0];}
#line 1430 "parser.c"
    break;

  case 14: /* atomic_type: INT  */
#line 65 "parser.y"
                   {currentRule="atomic_type_1";yyval = keynode(T_INTEGER);}
#line 1436 "parser.c"
    break;

  case 15: /* atomic_type: REAL  */
#line 66 "parser.y"
                     {currentRule="atomic_type_2";yyval = keynode(T_REAL);}
#line 1442 "parser.c"
    break;

  case 16: /* atomic_type: STRING  */
#line 67 "parser.y"
                       {currentRule="atomic_type_3";yyval = keynode(T_STRING);}
#line 1448 "parser.c"
    break;

  case 17: /* atomic_type: BOOL  */
#line 68 "parser.y"
                    {currentRule="atomic_type_4";yyval = keynode(T_BOOLEAN);}
#line 1454 "parser.c"
    break;

  case 18: /* atomic_type: ID  */
#line 69 "parser.y"
                  {currentRule="atomic_type_5";yyval = idnode();}
#line 1460 "parser.c"
    break;

  case 19: /* record_type: '{' atomic_decl_list '}'  */
#line 71 "parser.y"
                                      {currentRule="record_type_1";yyval=nontermnode(NRECTYPE);
                                       yyval->c1=yyvsp[-1];}
#line 1467 "parser.c"
    break;

  case 20: /* atomic_decl_list: atomic_decl ',' atomic_decl_list  */
#line 74 "parser.y"
                                                   {currentRule="atomic_decl_list_1"; yyval=yyvsp[-2];
                                                     yyval->b=yyvsp[0];}
#line 1474 "parser.c"
    break;

  case 21: /* atomic_decl_list: atomic_decl  */
#line 76 "parser.y"
                              {currentRule="atomic_decl_list_2"; yyval=yyvsp[0];}
#line 1480 "parser.c"
    break;

  case 22: /* @2: %empty  */
#line 78 "parser.y"
               {yyval= idnode();}
#line 1486 "parser.c"
    break;

  case 23: /* atomic_decl: ID @2 ':' atomic_type  */
#line 78 "parser.y"
                                              {currentRule="atomic_decl_1";yyval=nontermnode(NATOMDECL);
                                               yyval->c1=yyvsp[-2];
                                               yyval->c2= yyvsp[0];}
#line 1494 "parser.c"
    break;

  case 24: /* array_type: '[' array_elem_type ']'  */
#line 82 "parser.y"
                                    {currentRule="array_type_1";yyval=nontermnode(NARRAYTYPE);
                                     yyval->c1=yyvsp[-1];}
#line 1501 "parser.c"
    break;

  case 25: /* array_elem_type: atomic_type  */
#line 85 "parser.y"
                             {currentRule="array_elem_type_1"; yyval=yyvsp[0];}
#line 1507 "parser.c"
    break;

  case 26: /* array_elem_type: record_type  */
#line 86 "parser.y"
                             {currentRule="array_elem_type_2"; yyval=yyvsp[0];}
#line 1513 "parser.c"
    break;

  case 27: /* var_section: VARIABLES var_decl_list  */
#line 88 "parser.y"
                                     { currentRule="var_section_1";yyval= nontermnode(NVARSEC);
                                       yyval->c1=yyvsp[0];}
#line 1520 "parser.c"
    break;

  case 28: /* var_section: %empty  */
#line 90 "parser.y"
              {currentRule="var_section_2";yyval=NULL;}
#line 1526 "parser.c"
    break;

  case 29: /* var_decl_list: var_decl var_decl_list  */
#line 92 "parser.y"
                                     {currentRule="var_decl_list_1";yyval=yyvsp[-1];
                                      yyval->b=yyvsp[0];
                                         }
#line 1534 "parser.c"
    break;

  case 30: /* var_decl_list: var_decl  */
#line 95 "parser.y"
                         {currentRule="var_decl_list_2"; yyval=yyvsp[0];}
#line 1540 "parser.c"
    break;

  case 31: /* var_decl: id_list ':' type ';'  */
#line 97 "parser.y"
                               { currentRule="var_decl_1";yyval=nontermnode(NVARDECL);
                                 yyval->c1=yyvsp[-3];
                                 yyval->c2=yyvsp[-1];}
#line 1548 "parser.c"
    break;

  case 32: /* func_section: FUNCTIONS fun_decl_list  */
#line 100 "parser.y"
                                      { currentRule="func_section_1";yyval= nontermnode(NFUNCSEC);
                                        yyval->c1=yyvsp[0];}
#line 1555 "parser.c"
    break;

  case 33: /* func_section: %empty  */
#line 102 "parser.y"
              {currentRule="func_section_2";yyval=NULL;}
#line 1561 "parser.c"
    break;

  case 34: /* fun_decl_list: fun_decl fun_decl_list  */
#line 104 "parser.y"
                                     {currentRule="fun_decl_list_1";yyval=yyvsp[-1];
                                      yyval->b=yyvsp[0];
                                         }
#line 1569 "parser.c"
    break;

  case 35: /* fun_decl_list: fun_decl  */
#line 107 "parser.y"
                         {currentRule="fun_decl_list_2"; yyval=yyvsp[0];}
#line 1575 "parser.c"
    break;

  case 36: /* @3: %empty  */
#line 109 "parser.y"
            {yyval=idnode();}
#line 1581 "parser.c"
    break;

  case 37: /* fun_decl: ID @3 '(' opt_formal_decl_list ')' ':' type expr END  */
#line 109 "parser.y"
                                                                          { currentRule="fun_decl_1";yyval=nontermnode(NFUNDECL);
                                                                            yyval->value.sval=yyvsp[-7]->value.sval;
                                                                            yyval->c1=yyvsp[-5];
                                                                            yyval->c2=yyvsp[-2];
                                                                            yyval->c3=yyvsp[-1];}
#line 1591 "parser.c"
    break;

  case 38: /* opt_formal_decl_list: formal_decl_list  */
#line 115 "parser.y"
                                       {currentRule="opt_formal_decl_list";yyval=yyvsp[0];}
#line 1597 "parser.c"
    break;

  case 39: /* opt_formal_decl_list: %empty  */
#line 116 "parser.y"
                      {currentRule="opt_formal_decl_list_2";yyval=NULL;}
#line 1603 "parser.c"
    break;

  case 40: /* formal_decl_list: formal_decl ',' formal_decl_list  */
#line 118 "parser.y"
                                                   {currentRule="formal_decl_list_1";yyval=yyvsp[-2];
                                                    yyval->b=yyvsp[0];
                                                    }
#line 1611 "parser.c"
    break;

  case 41: /* formal_decl_list: formal_decl  */
#line 121 "parser.y"
                             { currentRule="formal_decl_list_2";yyval=yyvsp[0];}
#line 1617 "parser.c"
    break;

  case 42: /* @4: %empty  */
#line 123 "parser.y"
               {yyval=idnode();}
#line 1623 "parser.c"
    break;

  case 43: /* formal_decl: ID @4 ':' type  */
#line 123 "parser.y"
                                       {currentRule="formal_decl_1";yyval=nontermnode(NFORMALDECL);
                                       yyval->c1=yyvsp[-2];
                                       yyval->c2=yyvsp[0];}
#line 1631 "parser.c"
    break;

  case 44: /* expr: expr bool_op bool_term  */
#line 127 "parser.y"
                             {currentRule="expr_1";
                              yyval=nontermnode(NLOGICEXPR);
                              yyval->c1=yyvsp[-2];
                              yyval->c2=yyvsp[0];
                              yyval->value.ival=yyvsp[-1]->symbol;}
#line 1641 "parser.c"
    break;

  case 45: /* expr: bool_term  */
#line 132 "parser.y"
               {currentRule="expr_2";
                yyval=yyvsp[0];}
#line 1648 "parser.c"
    break;

  case 46: /* bool_op: OR  */
#line 135 "parser.y"
            {currentRule="bool_op_1";yyval=keynode(T_OR);}
#line 1654 "parser.c"
    break;

  case 47: /* bool_op: AND  */
#line 136 "parser.y"
            {currentRule="bool_op_2";yyval=keynode(T_AND);}
#line 1660 "parser.c"
    break;

  case 48: /* bool_term: comp_term comp_op comp_term  */
#line 138 "parser.y"
                                      {currentRule="bool_term_1";yyval=nontermnode(NCOMPEXPR);
                                        yyval->c1=yyvsp[-2];
                                        yyval->c2=yyvsp[0];
                                        yyval->value.ival=yyvsp[-1]->symbol;}
#line 1669 "parser.c"
    break;

  case 49: /* bool_term: comp_term  */
#line 143 "parser.y"
                    {currentRule="bool_term_2";
                     yyval=yyvsp[0];}
#line 1676 "parser.c"
    break;

  case 50: /* comp_op: EQUAL  */
#line 146 "parser.y"
               {currentRule="comp_op_1";yyval=keynode(T_EQUAL);}
#line 1682 "parser.c"
    break;

  case 51: /* comp_op: NEQUAL  */
#line 147 "parser.y"
               {currentRule="comp_op_2";yyval=keynode(T_NOTEQUAL);}
#line 1688 "parser.c"
    break;

  case 52: /* comp_op: GT  */
#line 148 "parser.y"
           {currentRule="comp_op_3";yyval=keynode(T_GT);}
#line 1694 "parser.c"
    break;

  case 53: /* comp_op: GE  */
#line 149 "parser.y"
           {currentRule="comp_op_4";yyval=keynode(T_GE);}
#line 1700 "parser.c"
    break;

  case 54: /* comp_op: LE  */
#line 150 "parser.y"
           {currentRule="comp_op_5";yyval=keynode(T_LE);}
#line 1706 "parser.c"
    break;

  case 55: /* comp_op: LT  */
#line 151 "parser.y"
           {currentRule="comp_op_6";yyval=keynode(T_LT);}
#line 1712 "parser.c"
    break;

  case 56: /* comp_op: IN  */
#line 152 "parser.y"
           {currentRule="comp_op_7";yyval=keynode(T_IN);}
#line 1718 "parser.c"
    break;

  case 57: /* comp_term: comp_term add_op term  */
#line 154 "parser.y"
                                 {currentRule="comp_term_1";yyval=nontermnode(NMATHEXPR);
                                  yyval->c1=yyvsp[-2];
                                  yyval->c2=yyvsp[0];
                                  yyval->value.ival=yyvsp[-1]->symbol;}
#line 1727 "parser.c"
    break;

  case 58: /* comp_term: term  */
#line 158 "parser.y"
                 {currentRule="comp_term_2";
                 yyval=yyvsp[0];}
#line 1734 "parser.c"
    break;

  case 59: /* add_op: PLUS  */
#line 161 "parser.y"
             {currentRule="add_op_1";yyval=keynode(T_PLUS);}
#line 1740 "parser.c"
    break;

  case 60: /* add_op: MINUS  */
#line 162 "parser.y"
              {currentRule="add_op_2";yyval=keynode(T_MINUS);}
#line 1746 "parser.c"
    break;

  case 61: /* add_op: CONCAT  */
#line 163 "parser.y"
               {currentRule="add_op_3";yyval=keynode(T_CONCAT);}
#line 1752 "parser.c"
    break;

  case 62: /* term: term mul_op factor  */
#line 165 "parser.y"
                         {currentRule="term_1";yyval=nontermnode(NMATHEXPR);
                          yyval->c1=yyvsp[-2];
                          yyval->c2=yyvsp[0];
                          yyval->value.ival=yyvsp[-1]->symbol;}
#line 1761 "parser.c"
    break;

  case 63: /* term: factor  */
#line 169 "parser.y"
             {currentRule="term_2";
              yyval=yyvsp[0];}
#line 1768 "parser.c"
    break;

  case 64: /* mul_op: MUL  */
#line 172 "parser.y"
            {currentRule="mul_op_1";yyval=keynode(T_MUL);}
#line 1774 "parser.c"
    break;

  case 65: /* mul_op: DIVIDE  */
#line 173 "parser.y"
              {currentRule="mul_op_2";yyval=keynode(T_DIVIDE);}
#line 1780 "parser.c"
    break;

  case 66: /* factor: unary_op factor  */
#line 175 "parser.y"
                                  {currentRule="factor_1";yyval=nontermnode(NNEGEXPR);
                        yyval->c1=yyvsp[0];
                        yyval->value.ival=yyvsp[-1]->symbol;
                        }
#line 1789 "parser.c"
    break;

  case 67: /* factor: '(' expr ')'  */
#line 179 "parser.y"
                      {currentRule="factor_2";
                                 yyval=yyvsp[-1];}
#line 1796 "parser.c"
    break;

  case 68: /* factor: '|' expr '|'  */
#line 181 "parser.y"
                      {currentRule="factor_3";yyval=nontermnode(NBUILTINEXPR);
                       yyval->c1=yyvsp[-1];
                       yyval->value.ival=T_CARD;}
#line 1804 "parser.c"
    break;

  case 69: /* factor: lhs  */
#line 184 "parser.y"
              {currentRule="factor_4";
              yyval=yyvsp[0];}
#line 1811 "parser.c"
    break;

  case 70: /* factor: built_in '(' expr ')'  */
#line 186 "parser.y"
                               {currentRule="factor_5";
                                 yyval=nontermnode(NBUILTINEXPR);
                                 yyval->c1=yyvsp[-1];
                                 yyval->value.ival=yyvsp[-3]->symbol;}
#line 1820 "parser.c"
    break;

  case 71: /* factor: atomic_constant  */
#line 190 "parser.y"
                         {currentRule="factor_6";
                          yyval=yyvsp[0];}
#line 1827 "parser.c"
    break;

  case 72: /* factor: record_constructor  */
#line 192 "parser.y"
                            {currentRule="factor_7";
                             yyval=yyvsp[0];}
#line 1834 "parser.c"
    break;

  case 73: /* factor: array_constructor  */
#line 194 "parser.y"
                           {currentRule="factor_8";
                           yyval=yyvsp[0];}
#line 1841 "parser.c"
    break;

  case 74: /* factor: cond_expr  */
#line 196 "parser.y"
                   {currentRule="factor_9";
                   yyval=yyvsp[0];}
#line 1848 "parser.c"
    break;

  case 75: /* factor: func_call  */
#line 198 "parser.y"
                   {currentRule="factor_10";
                    yyval=yyvsp[0];}
#line 1855 "parser.c"
    break;

  case 76: /* unary_op: MINUSSIGN  */
#line 201 "parser.y"
                    {currentRule="unary_op_1";yyval=keynode(T_NEG_SIGN);}
#line 1861 "parser.c"
    break;

  case 77: /* unary_op: NOT  */
#line 202 "parser.y"
              {currentRule="unary_op_2";yyval=keynode(T_NOT);}
#line 1867 "parser.c"
    break;

  case 78: /* built_in: INT  */
#line 204 "parser.y"
              {currentRule="built_in_1";yyval=keynode(T_CASTINT);}
#line 1873 "parser.c"
    break;

  case 79: /* built_in: REAL  */
#line 205 "parser.y"
               {currentRule="built_in_2";yyval=keynode(T_CASTREAL);}
#line 1879 "parser.c"
    break;

  case 80: /* built_in: EMPTY_TOKEN  */
#line 206 "parser.y"
                      {currentRule="built_in_3";yyval=keynode(T_EMPTY);}
#line 1885 "parser.c"
    break;

  case 81: /* built_in: HEAD_TOKEN  */
#line 207 "parser.y"
                     {currentRule="built_in_4";yyval=keynode(T_HEAD);}
#line 1891 "parser.c"
    break;

  case 82: /* built_in: TAIL_TOKEN  */
#line 208 "parser.y"
                     {currentRule="built_in_5";yyval=keynode(T_TAIL);}
#line 1897 "parser.c"
    break;

  case 83: /* atomic_constant: BOOLCONST  */
#line 210 "parser.y"
                           {currentRule="atomic_constant_1";yyval=boolconstnode();}
#line 1903 "parser.c"
    break;

  case 84: /* atomic_constant: INTCONST  */
#line 211 "parser.y"
                          {currentRule="atomic_constant_2";yyval=intconstnode();}
#line 1909 "parser.c"
    break;

  case 85: /* atomic_constant: REALCONST  */
#line 212 "parser.y"
                           {currentRule="atomic_constant_3";yyval=realconstnode();}
#line 1915 "parser.c"
    break;

  case 86: /* atomic_constant: STRCONST  */
#line 213 "parser.y"
                          {currentRule="atomic_constant_4";yyval=strconstnode();}
#line 1921 "parser.c"
    break;

  case 87: /* record_constructor: '{' expr_list '}'  */
#line 215 "parser.y"
                                      {currentRule="record_constructor_1";yyval=nontermnode(NCONSTRUCTOR);
yyval->value.ival=T_RECORD;
yyval->c1=yyvsp[-1];}
#line 1929 "parser.c"
    break;

  case 88: /* expr_list: expr ',' expr_list  */
#line 219 "parser.y"
                              { currentRule="expr_list_1";yyval=yyvsp[-2];
                                yyval->b=yyvsp[0];}
#line 1936 "parser.c"
    break;

  case 89: /* expr_list: expr  */
#line 221 "parser.y"
                 {currentRule="expr_list_2";yyval=yyvsp[0];}
#line 1942 "parser.c"
    break;

  case 90: /* cond_expr: IF expr THEN expr ELSE expr END  */
#line 223 "parser.y"
                                           {currentRule="cond_expr_1";yyval=nontermnode(NCONDEXPR);
                                            yyval->c1=yyvsp[-5];
                                            yyval->c2=yyvsp[-3];
                                            yyval->c3=yyvsp[-1];}
#line 1951 "parser.c"
    break;

  case 91: /* @5: %empty  */
#line 228 "parser.y"
              {yyval=idnode();}
#line 1957 "parser.c"
    break;

  case 92: /* func_call: ID @5 '(' opt_expr_list ')'  */
#line 228 "parser.y"
                                                   {currentRule="func_call_1";yyval=nontermnode(NFUNCCALL);
                                                   yyval->value.sval=yyvsp[-3]->value.sval;
                                                   yyval->c1=yyvsp[-1];}
#line 1965 "parser.c"
    break;

  case 93: /* opt_expr_list: expr_list  */
#line 232 "parser.y"
                         {currentRule="opt_expr_list_1";yyval=yyvsp[0];
                          }
#line 1972 "parser.c"
    break;

  case 94: /* opt_expr_list: %empty  */
#line 234 "parser.y"
               { currentRule="opt_expr_list_2";yyval=NULL;}
#line 1978 "parser.c"
    break;

  case 95: /* array_constructor: '[' opt_expr_list ']'  */
#line 236 "parser.y"
                                         {currentRule="array_constructor_1";yyval=nontermnode(NCONSTRUCTOR);
                                          yyval->c1=yyvsp[-1];
                                          yyval->value.ival=T_ARRAY;}
#line 1986 "parser.c"
    break;

  case 96: /* run_section: RUN stat_list END  */
#line 240 "parser.y"
                               {currentRule="run_section_1";yyval=nontermnode(NRUNSEC);
yyval->c1=yyvsp[-1];}
#line 1993 "parser.c"
    break;

  case 97: /* run_section: %empty  */
#line 242 "parser.y"
              { currentRule="opt_expr_list_2";yyval=NULL;}
#line 1999 "parser.c"
    break;

  case 98: /* stat_list: stat ';' stat_list  */
#line 244 "parser.y"
                                 {currentRule="stat_list_1";yyval=yyvsp[-2];
                                 yyval->b=yyvsp[0];}
#line 2006 "parser.c"
    break;

  case 99: /* stat_list: stat ';'  */
#line 246 "parser.y"
                    {currentRule="stat_list_2";yyval=yyvsp[-1];}
#line 2012 "parser.c"
    break;

  case 100: /* stat: read_stat  */
#line 248 "parser.y"
                {currentRule="stat_1";yyval=yyvsp[0];}
#line 2018 "parser.c"
    break;

  case 101: /* stat: write_stat  */
#line 249 "parser.y"
                 {currentRule="stat_2";yyval=yyvsp[0];}
#line 2024 "parser.c"
    break;

  case 102: /* stat: assign_stat  */
#line 250 "parser.y"
                  {currentRule="stat_3";yyval=yyvsp[0];}
#line 2030 "parser.c"
    break;

  case 103: /* stat: if_stat  */
#line 251 "parser.y"
              {currentRule="stat_4";yyval=yyvsp[0];}
#line 2036 "parser.c"
    break;

  case 104: /* stat: while_stat  */
#line 252 "parser.y"
                 {currentRule="stat_5";yyval=yyvsp[0];}
#line 2042 "parser.c"
    break;

  case 105: /* stat: foreach_stat  */
#line 253 "parser.y"
                   {currentRule="stat_6";yyval=yyvsp[0];}
#line 2048 "parser.c"
    break;

  case 106: /* read_stat: READ_TOKEN ID  */
#line 255 "parser.y"
                         {currentRule="read_stat_1";yyval=nontermnode(NREAD); //////////giust0???
                    yyval->c1=idnode();}
#line 2055 "parser.c"
    break;

  case 107: /* write_stat: WRITE expr  */
#line 258 "parser.y"
                       {currentRule="write_stat_1";yyval= nontermnode(NWRITE);
                        yyval->c1= yyvsp[0];}
#line 2062 "parser.c"
    break;

  case 108: /* assign_stat: lhs ASSIGN expr  */
#line 261 "parser.y"
                             {currentRule="assign_stat_1";yyval=nontermnode(NASSIGN);
                            yyval->c1=yyvsp[-2];
                            yyval->c2=yyvsp[0];}
#line 2070 "parser.c"
    break;

  case 109: /* @6: %empty  */
#line 265 "parser.y"
       {yyval=idnode();}
#line 2076 "parser.c"
    break;

  case 110: /* lhs: ID @6 opt_fielding  */
#line 265 "parser.y"
                                   {currentRule="lhs_1";
                                    yyval= nontermnode(NLHS);
                                    yyval->c1=yyvsp[-1];
                                    yyval->c2=yyvsp[0];}
#line 2085 "parser.c"
    break;

  case 111: /* lhs: indexing  */
#line 269 "parser.y"
              {currentRule="lhs_2";yyval= nontermnode(NLHS);
               yyval->c1=yyvsp[0];}
#line 2092 "parser.c"
    break;

  case 112: /* opt_fielding: '.' ID  */
#line 272 "parser.y"
                     {currentRule="opt_fielding_1";
                      yyval=idnode();}
#line 2099 "parser.c"
    break;

  case 113: /* opt_fielding: %empty  */
#line 274 "parser.y"
              {currentRule="opt_fielding_2";yyval=NULL;}
#line 2105 "parser.c"
    break;

  case 114: /* @7: %empty  */
#line 276 "parser.y"
             {yyval=idnode();}
#line 2111 "parser.c"
    break;

  case 115: /* indexing: ID @7 '[' expr ']' opt_fielding  */
#line 276 "parser.y"
                                                      {currentRule="indexing_1";yyval= nontermnode(NINDEXING);
                                                     yyval->c1=yyvsp[-4];
                                                     yyval->c2=yyvsp[-2];
                                                     yyval->c3=yyvsp[0];
                                                     }
#line 2121 "parser.c"
    break;

  case 116: /* if_stat: IF expr THEN stat_list else_part END  */
#line 282 "parser.y"
                                              {currentRule="if_stat_1";yyval= nontermnode (NIFSTAT);
                                               yyval->c1=yyvsp[-4];
                                               yyval->c2=yyvsp[-2];
                                               yyval->c3 =yyvsp[-1];}
#line 2130 "parser.c"
    break;

  case 117: /* else_part: ELSE stat_list  */
#line 287 "parser.y"
                          {currentRule="else_part_1";yyval=yyvsp[0];
                         }
#line 2137 "parser.c"
    break;

  case 118: /* else_part: %empty  */
#line 289 "parser.y"
           {yyval=NULL;}
#line 2143 "parser.c"
    break;

  case 119: /* while_stat: WHILE expr DO stat_list END  */
#line 291 "parser.y"
                                        {currentRule="while_stat_1";yyval=nontermnode(NWHILESTAT);
                                         yyval->c1=yyvsp[-3];
                                         yyval->c2=yyvsp[-1];}
#line 2151 "parser.c"
    break;

  case 120: /* @8: %empty  */
#line 295 "parser.y"
                         {yyval=idnode();}
#line 2157 "parser.c"
    break;

  case 121: /* @9: %empty  */
#line 295 "parser.y"
                                              {yyval=idnode();}
#line 2163 "parser.c"
    break;

  case 122: /* foreach_stat: FOREACH ID @8 IN ID @9 DO stat_list END  */
#line 295 "parser.y"
                                                                              { currentRule="foreach_stat_1";yyval=nontermnode(NFOREACH);
                                                                              yyval->c1=yyvsp[-6];
                                                                              yyval->c2= yyvsp[-3];
                                                                              yyval->c3=yyvsp[-1];
                                                                              }
#line 2173 "parser.c"
    break;


#line 2177 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 302 "parser.y"

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
void tracciaVar(){
}
Pnode generate_abstree(FILE *input)
{
 int result;
 yyin = input;
 result = yyparse();
 //printf("analisi finita\n");
 return root;
}
void yyerror()
{
 fprintf(stderr, "Line %d: syntax error on symbol \"%s\" on BNF rule \"%s\"\n", line, yytext, currentRule);
 exit(2);
}
