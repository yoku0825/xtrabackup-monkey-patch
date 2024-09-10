/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         HINT_PARSER_parse
#define yylex           HINT_PARSER_lex
#define yyerror         HINT_PARSER_error
#define yydebug         HINT_PARSER_debug
#define yynerrs         HINT_PARSER_nerrs

/* First part of user prologue.  */
#line 28 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"

#include <assert.h>
#include <climits>
#include <cstdlib>

#include "lex_string.h"
#include "m_string.h"

#include "my_double2ulonglong.h"
#include "my_inttypes.h"  // TODO: replace with cstdint
#include "mysqld_error.h"
#include "sql/derror.h"
#include "sql/item.h"
#include "sql/item_subselect.h"
#include "sql/lexer_yystype.h"
#include "sql/opt_hints.h"
#include "sql/parse_tree_helpers.h"  // check_resource_group_name_len
#include "sql/parse_tree_hints.h"
#include "sql/parser_yystype.h"
#include "sql/sql_class.h"
#include "sql/sql_const.h"
#include "sql/sql_error.h"
#include "sql/sql_hints.yy.h"
#include "sql/sql_lex_hints.h"

#define NEW_PTN new (thd->mem_root)

static bool parse_int(longlong *to, const char *from, size_t from_length)
{
  int error;
  const char *end= from + from_length;
  *to= my_strtoll10(from, &end, &error);
  return error != 0 || end != from + from_length;
}


#line 112 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_HINT_PARSER_MNT_JENKINS_WORKSPACE_PERCONA_XTRABACKUP_8_0_RELEASE_TEST_PERCONA_XTRABACKUP_SQL_SQL_HINTS_YY_H_INCLUDED
# define YY_HINT_PARSER_MNT_JENKINS_WORKSPACE_PERCONA_XTRABACKUP_8_0_RELEASE_TEST_PERCONA_XTRABACKUP_SQL_SQL_HINTS_YY_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int HINT_PARSER_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAX_EXECUTION_TIME_HINT = 1000,
    RESOURCE_GROUP_HINT = 1001,
    BKA_HINT = 1002,
    BNL_HINT = 1003,
    DUPSWEEDOUT_HINT = 1004,
    FIRSTMATCH_HINT = 1005,
    INTOEXISTS_HINT = 1006,
    LOOSESCAN_HINT = 1007,
    MATERIALIZATION_HINT = 1008,
    NO_BKA_HINT = 1009,
    NO_BNL_HINT = 1010,
    NO_ICP_HINT = 1011,
    NO_MRR_HINT = 1012,
    NO_RANGE_OPTIMIZATION_HINT = 1013,
    NO_SEMIJOIN_HINT = 1014,
    MRR_HINT = 1015,
    QB_NAME_HINT = 1016,
    SEMIJOIN_HINT = 1017,
    SUBQUERY_HINT = 1018,
    DERIVED_MERGE_HINT = 1019,
    NO_DERIVED_MERGE_HINT = 1020,
    JOIN_PREFIX_HINT = 1021,
    JOIN_SUFFIX_HINT = 1022,
    JOIN_ORDER_HINT = 1023,
    JOIN_FIXED_ORDER_HINT = 1024,
    INDEX_MERGE_HINT = 1025,
    NO_INDEX_MERGE_HINT = 1026,
    SET_VAR_HINT = 1027,
    SKIP_SCAN_HINT = 1028,
    NO_SKIP_SCAN_HINT = 1029,
    HASH_JOIN_HINT = 1030,
    NO_HASH_JOIN_HINT = 1031,
    HINT_ARG_NUMBER = 1032,
    HINT_ARG_IDENT = 1033,
    HINT_ARG_QB_NAME = 1034,
    HINT_ARG_TEXT = 1035,
    HINT_IDENT_OR_NUMBER_WITH_SCALE = 1036,
    HINT_CLOSE = 1037,
    HINT_ERROR = 1038,
    INDEX_HINT = 1039,
    NO_INDEX_HINT = 1040,
    JOIN_INDEX_HINT = 1041,
    NO_JOIN_INDEX_HINT = 1042,
    GROUP_INDEX_HINT = 1043,
    NO_GROUP_INDEX_HINT = 1044,
    ORDER_INDEX_HINT = 1045,
    NO_ORDER_INDEX_HINT = 1046,
    DERIVED_CONDITION_PUSHDOWN_HINT = 1047,
    NO_DERIVED_CONDITION_PUSHDOWN_HINT = 1048,
    HINT_ARG_FLOATING_POINT_NUMBER = 1049,
    YYUNDEF = 1150
  };
#endif
/* Tokens.  */
#define MAX_EXECUTION_TIME_HINT 1000
#define RESOURCE_GROUP_HINT 1001
#define BKA_HINT 1002
#define BNL_HINT 1003
#define DUPSWEEDOUT_HINT 1004
#define FIRSTMATCH_HINT 1005
#define INTOEXISTS_HINT 1006
#define LOOSESCAN_HINT 1007
#define MATERIALIZATION_HINT 1008
#define NO_BKA_HINT 1009
#define NO_BNL_HINT 1010
#define NO_ICP_HINT 1011
#define NO_MRR_HINT 1012
#define NO_RANGE_OPTIMIZATION_HINT 1013
#define NO_SEMIJOIN_HINT 1014
#define MRR_HINT 1015
#define QB_NAME_HINT 1016
#define SEMIJOIN_HINT 1017
#define SUBQUERY_HINT 1018
#define DERIVED_MERGE_HINT 1019
#define NO_DERIVED_MERGE_HINT 1020
#define JOIN_PREFIX_HINT 1021
#define JOIN_SUFFIX_HINT 1022
#define JOIN_ORDER_HINT 1023
#define JOIN_FIXED_ORDER_HINT 1024
#define INDEX_MERGE_HINT 1025
#define NO_INDEX_MERGE_HINT 1026
#define SET_VAR_HINT 1027
#define SKIP_SCAN_HINT 1028
#define NO_SKIP_SCAN_HINT 1029
#define HASH_JOIN_HINT 1030
#define NO_HASH_JOIN_HINT 1031
#define HINT_ARG_NUMBER 1032
#define HINT_ARG_IDENT 1033
#define HINT_ARG_QB_NAME 1034
#define HINT_ARG_TEXT 1035
#define HINT_IDENT_OR_NUMBER_WITH_SCALE 1036
#define HINT_CLOSE 1037
#define HINT_ERROR 1038
#define INDEX_HINT 1039
#define NO_INDEX_HINT 1040
#define JOIN_INDEX_HINT 1041
#define NO_JOIN_INDEX_HINT 1042
#define GROUP_INDEX_HINT 1043
#define NO_GROUP_INDEX_HINT 1044
#define ORDER_INDEX_HINT 1045
#define NO_ORDER_INDEX_HINT 1046
#define DERIVED_CONDITION_PUSHDOWN_HINT 1047
#define NO_DERIVED_CONDITION_PUSHDOWN_HINT 1048
#define HINT_ARG_FLOATING_POINT_NUMBER 1049
#define YYUNDEF 1150

/* Value type.  */



int HINT_PARSER_parse (class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret);

#endif /* !YY_HINT_PARSER_MNT_JENKINS_WORKSPACE_PERCONA_XTRABACKUP_8_0_RELEASE_TEST_PERCONA_XTRABACKUP_SQL_SQL_HINTS_YY_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYUNDEFTOK  2
#define YYMAXUTOK   1151


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
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
      53,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   208,   210,   215,   221,   229,   230,   231,
     232,   233,   234,   235,   240,   260,   261,   265,   271,   280,
     281,   285,   291,   300,   301,   305,   311,   320,   324,   332,
     340,   341,   349,   350,   354,   361,   368,   375,   382,   389,
     396,   403,   410,   417,   426,   427,   431,   438,   439,   440,
     441,   445,   447,   452,   458,   465,   471,   481,   488,   498,
     502,   506,   510,   514,   521,   525,   529,   533,   537,   544,
     548,   552,   556,   560,   564,   568,   572,   579,   583,   587,
     591,   595,   599,   603,   607,   614,   623,   632,   644,   645,
     649,   664,   668,   703,   704,   708,   716,   717
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAX_EXECUTION_TIME_HINT",
  "RESOURCE_GROUP_HINT", "BKA_HINT", "BNL_HINT", "DUPSWEEDOUT_HINT",
  "FIRSTMATCH_HINT", "INTOEXISTS_HINT", "LOOSESCAN_HINT",
  "MATERIALIZATION_HINT", "NO_BKA_HINT", "NO_BNL_HINT", "NO_ICP_HINT",
  "NO_MRR_HINT", "NO_RANGE_OPTIMIZATION_HINT", "NO_SEMIJOIN_HINT",
  "MRR_HINT", "QB_NAME_HINT", "SEMIJOIN_HINT", "SUBQUERY_HINT",
  "DERIVED_MERGE_HINT", "NO_DERIVED_MERGE_HINT", "JOIN_PREFIX_HINT",
  "JOIN_SUFFIX_HINT", "JOIN_ORDER_HINT", "JOIN_FIXED_ORDER_HINT",
  "INDEX_MERGE_HINT", "NO_INDEX_MERGE_HINT", "SET_VAR_HINT",
  "SKIP_SCAN_HINT", "NO_SKIP_SCAN_HINT", "HASH_JOIN_HINT",
  "NO_HASH_JOIN_HINT", "HINT_ARG_NUMBER", "HINT_ARG_IDENT",
  "HINT_ARG_QB_NAME", "HINT_ARG_TEXT", "HINT_IDENT_OR_NUMBER_WITH_SCALE",
  "HINT_CLOSE", "HINT_ERROR", "INDEX_HINT", "NO_INDEX_HINT",
  "JOIN_INDEX_HINT", "NO_JOIN_INDEX_HINT", "GROUP_INDEX_HINT",
  "NO_GROUP_INDEX_HINT", "ORDER_INDEX_HINT", "NO_ORDER_INDEX_HINT",
  "DERIVED_CONDITION_PUSHDOWN_HINT", "NO_DERIVED_CONDITION_PUSHDOWN_HINT",
  "HINT_ARG_FLOATING_POINT_NUMBER", "YYUNDEF", "'('", "')'", "','", "'='",
  "$accept", "start", "hint_list", "hint", "max_execution_time_hint",
  "opt_hint_param_table_list", "hint_param_table_list",
  "opt_hint_param_table_list_empty_qb", "hint_param_table_list_empty_qb",
  "opt_hint_param_index_list", "hint_param_index_list", "hint_param_index",
  "hint_param_table_empty_qb", "hint_param_table", "hint_param_table_ext",
  "opt_qb_name", "qb_level_hint", "semijoin_strategies",
  "semijoin_strategy", "subquery_strategy", "table_level_hint",
  "index_level_hint", "table_level_hint_type_on",
  "table_level_hint_type_off", "key_level_hint_type_on",
  "key_level_hint_type_off", "qb_name_hint", "set_var_hint",
  "resource_group_hint", "set_var_ident", "set_var_num_item",
  "set_var_text_value", "set_var_string_item", "set_var_arg", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,  1151,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1150,    40,    41,    44,    61
};
# endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      50,   -34,   -18,   -16,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -14,   -65,    35,    37,    54,   -65,   -65,    56,    58,
      63,    71,   -65,   -65,    80,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   104,
      -1,   -65,   -65,   -65,   -65,   -65,    81,    82,    83,    84,
     -65,   -65,   -65,   -65,    17,   103,   105,   107,   105,   105,
     -27,    22,    51,   105,    -2,   -65,   100,   -65,   -65,    79,
      92,    94,    94,    86,    89,   -65,   116,    90,   116,    26,
     105,   110,    93,    91,   -65,   110,    95,   110,    96,    97,
     -65,   -65,    98,   -65,   110,    99,   110,   101,   113,   -65,
     117,   117,   -65,   -65,   -65,   -65,   -65,   -65,     5,   -65,
     -65,    77,   -65,   -65,   102,   -65,   -65,   106,   108,   -65,
     -65,   122,   111,   -65,   112,   -65,   -65,    67,   114,   -65,
     115,   -65,   -65,   -65,   118,   109,   -65,   119,   -65,   116,
     -65,   -65,   -65,   110,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   120,   -65,   -65,   -65,   117,
     -65,   -65,   -65,   -65,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    59,    60,    64,    65,    77,    78,
      70,     0,    69,     0,     0,     0,    62,    67,     0,     0,
       0,     0,    71,    79,     0,    72,    80,    61,    66,    73,
      81,    74,    82,    75,    83,    76,    84,    63,    68,     0,
       0,     5,    11,     9,     8,     7,     0,     0,     0,     0,
      10,    12,    13,     4,     0,     0,    32,     0,    32,    32,
      15,    15,    15,    32,     0,     1,     0,     2,     6,    15,
      15,     0,     0,     0,     0,    33,    44,     0,    44,     0,
      32,    19,     0,    16,    17,    19,     0,    19,     0,     0,
      89,    88,     0,     3,    19,     0,    19,     0,     0,    30,
      23,    23,    14,    87,    50,    47,    48,    49,     0,    45,
      85,     0,    52,    51,     0,    29,    28,     0,    20,    21,
      37,     0,     0,    39,     0,    41,    43,     0,     0,    53,
       0,    55,    31,    27,     0,    24,    25,     0,    35,     0,
      34,    36,    38,     0,    18,    40,    42,    90,    93,    94,
      92,    91,    97,    95,    96,     0,    54,    56,    57,     0,
      58,    46,    22,    86,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   123,   -65,    52,   -65,    24,   -65,    59,
     -65,     0,    19,   -64,   121,    27,   -65,   124,    29,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    39,    40,    41,    42,    82,    83,   117,   118,   134,
     135,   136,   119,    84,   100,    76,    43,   108,   109,   114,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    92,
     152,   153,   154,   155
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    90,     2,     3,     4,     5,    53,    99,    99,    80,
      81,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    91,   112,    54,   113,    55,    67,
      56,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     1,    73,     2,     3,     4,     5,   144,    80,    85,
     138,   139,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    78,    79,    80,    87,    57,
      89,    58,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   147,   148,    65,   149,   150,   115,    59,   122,
      60,   124,    61,    86,    88,    80,    94,    62,   128,   151,
     130,    95,    97,   104,   105,    63,   106,   107,    80,    96,
      80,    98,   140,   139,    64,    69,    70,    71,    72,    74,
      93,   102,    75,    77,   103,   110,   116,   121,   120,   132,
     123,   125,   126,   133,   129,   127,   131,   141,    80,   164,
     137,   142,   162,    68,   143,   159,   145,   146,   161,   156,
     157,     0,     0,   158,   160,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,   111
};

static const yytype_int16 yycheck[] =
{
       1,     3,     3,     4,     5,     6,    40,    71,    72,    36,
      37,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    36,     9,    54,    11,    54,    40,
      54,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     1,    35,     3,     4,     5,     6,   121,    36,    37,
      55,    56,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    58,    59,    36,    37,    54,
      63,    54,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    35,    36,     0,    38,    39,    80,    54,    85,
      54,    87,    54,    61,    62,    36,    37,    54,    94,    52,
      96,    69,    70,     7,     8,    54,    10,    11,    36,    37,
      36,    37,    55,    56,    54,    54,    54,    54,    54,    36,
      40,    55,    37,    36,    55,    55,    36,    56,    55,    36,
      55,    55,    55,    36,    55,    57,    55,    55,    36,   159,
     101,    55,   143,    40,    56,    56,    55,    55,   139,    55,
      55,    -1,    -1,    55,    55,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    59,
      60,    61,    62,    74,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    40,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,     0,     1,    40,    61,    54,
      54,    54,    54,    35,    36,    37,    73,    36,    73,    73,
      36,    37,    63,    64,    71,    37,    63,    37,    63,    73,
       3,    36,    87,    40,    37,    63,    37,    63,    37,    71,
      72,    72,    55,    55,     7,     8,    10,    11,    75,    76,
      55,    75,     9,    11,    77,    73,    36,    65,    66,    70,
      55,    56,    65,    55,    65,    55,    55,    57,    65,    55,
      65,    55,    36,    36,    67,    68,    69,    67,    55,    56,
      55,    55,    55,    56,    71,    55,    55,    35,    36,    38,
      39,    52,    88,    89,    90,    91,    55,    55,    55,    56,
      55,    76,    70,    55,    69
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    70,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    83,
      83,    83,    83,    83,    83,    84,    85,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    91,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     1,     1,     3,     0,
       1,     1,     3,     0,     1,     1,     3,     1,     1,     2,
       1,     2,     0,     1,     5,     5,     5,     4,     5,     4,
       5,     4,     5,     4,     0,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     5,     4,     5,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (thd, scanner, ret, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, thd, scanner, ret); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (thd);
  YYUSE (scanner);
  YYUSE (ret);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, thd, scanner, ret);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , thd, scanner, ret);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, thd, scanner, ret); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
{
  YYUSE (yyvaluep);
  YYUSE (thd);
  YYUSE (scanner);
  YYUSE (ret);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (class THD *thd, class Hint_scanner *scanner, class PT_hint_list **ret)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 207 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          { *ret= (yyvsp[-1].hint_list); }
#line 1674 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 3:
#line 209 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          { *ret= (yyvsp[-2].hint_list); }
#line 1680 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 4:
#line 211 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          { *ret= NULL; }
#line 1686 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 5:
#line 216 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_list)= NEW_PTN PT_hint_list(thd->mem_root);
            if ((yyval.hint_list) == NULL || (yyval.hint_list)->push_back((yyvsp[0].hint)))
              YYABORT; // OOM
          }
#line 1696 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 6:
#line 222 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyvsp[-1].hint_list)->push_back((yyvsp[0].hint));
            (yyval.hint_list)= (yyvsp[-1].hint_list);
          }
#line 1705 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 14:
#line 241 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            longlong n;
            if (parse_int(&n, (yyvsp[-1].lexer.hint_string).str, (yyvsp[-1].lexer.hint_string).length) || n > UINT_MAX32)
            {
              scanner->syntax_warning(ER_THD(thd,
                                             ER_WARN_BAD_MAX_EXECUTION_TIME));
              (yyval.hint)= NULL;
            }
            else
            {
              (yyval.hint)= NEW_PTN PT_hint_max_execution_time(n);
              if ((yyval.hint) == NULL)
                YYABORT; // OOM
            }
          }
#line 1725 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 15:
#line 260 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                 { (yyval.hint_param_table_list).init(thd->mem_root); }
#line 1731 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 17:
#line 266 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_table_list).init(thd->mem_root);
            if ((yyval.hint_param_table_list).push_back((yyvsp[0].hint_param_table)))
              YYABORT; // OOM
          }
#line 1741 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 18:
#line 272 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            if ((yyvsp[-2].hint_param_table_list).push_back((yyvsp[0].hint_param_table)))
              YYABORT; // OOM
            (yyval.hint_param_table_list)= (yyvsp[-2].hint_param_table_list);
          }
#line 1751 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 19:
#line 280 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                 { (yyval.hint_param_table_list).init(thd->mem_root); }
#line 1757 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 21:
#line 286 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_table_list).init(thd->mem_root);
            if ((yyval.hint_param_table_list).push_back((yyvsp[0].hint_param_table)))
              YYABORT; // OOM
          }
#line 1767 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 22:
#line 292 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            if ((yyvsp[-2].hint_param_table_list).push_back((yyvsp[0].hint_param_table)))
              YYABORT; // OOM
            (yyval.hint_param_table_list)= (yyvsp[-2].hint_param_table_list);
          }
#line 1777 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 23:
#line 300 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                 { (yyval.hint_param_index_list).init(thd->mem_root); }
#line 1783 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 25:
#line 306 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_index_list).init(thd->mem_root);
            if ((yyval.hint_param_index_list).push_back((yyvsp[0].lexer.hint_string)))
              YYABORT; // OOM
          }
#line 1793 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 26:
#line 312 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            if ((yyvsp[-2].hint_param_index_list).push_back((yyvsp[0].lexer.hint_string)))
              YYABORT; // OOM
            (yyval.hint_param_index_list)= (yyvsp[-2].hint_param_index_list);
          }
#line 1803 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 28:
#line 325 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_table).table= (yyvsp[0].lexer.hint_string);
            (yyval.hint_param_table).opt_query_block= NULL_CSTR;
          }
#line 1812 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 29:
#line 333 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_table).table= (yyvsp[-1].lexer.hint_string);
            (yyval.hint_param_table).opt_query_block= (yyvsp[0].lexer.hint_string);
          }
#line 1821 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 31:
#line 342 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_param_table).table= (yyvsp[0].lexer.hint_string);
            (yyval.hint_param_table).opt_query_block= (yyvsp[-1].lexer.hint_string);
          }
#line 1830 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 32:
#line 349 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                 { (yyval.lexer.hint_string)= NULL_CSTR; }
#line 1836 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 34:
#line 355 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), true, SEMIJOIN_HINT_ENUM, (yyvsp[-1].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1846 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 35:
#line 362 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), false, SEMIJOIN_HINT_ENUM, (yyvsp[-1].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1856 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 36:
#line 369 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), true, SUBQUERY_HINT_ENUM, (yyvsp[-1].ulong_num));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1866 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 37:
#line 376 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, true, JOIN_PREFIX_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1876 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 38:
#line 383 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), true, JOIN_PREFIX_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1886 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 39:
#line 390 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, true, JOIN_SUFFIX_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1896 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 40:
#line 397 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), true, JOIN_SUFFIX_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1906 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 41:
#line 404 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint(NULL_CSTR, true, JOIN_ORDER_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1916 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 42:
#line 411 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-2].lexer.hint_string), true, JOIN_ORDER_HINT_ENUM, (yyvsp[-1].hint_param_table_list));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1926 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 43:
#line 418 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_qb_level_hint((yyvsp[-1].lexer.hint_string), true, JOIN_FIXED_ORDER_HINT_ENUM, 0);
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 1936 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 44:
#line 426 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                 { (yyval.ulong_num)= 0; }
#line 1942 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 45:
#line 428 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.ulong_num)= (yyvsp[0].ulong_num);
          }
#line 1950 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 46:
#line 432 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.ulong_num)= (yyvsp[-2].ulong_num) | (yyvsp[0].ulong_num);
          }
#line 1958 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 47:
#line 438 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)= OPTIMIZER_SWITCH_FIRSTMATCH; }
#line 1964 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 48:
#line 439 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)= OPTIMIZER_SWITCH_LOOSE_SCAN; }
#line 1970 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 49:
#line 440 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)= OPTIMIZER_SWITCH_MATERIALIZATION; }
#line 1976 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 50:
#line 441 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)= OPTIMIZER_SWITCH_DUPSWEEDOUT; }
#line 1982 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 51:
#line 445 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)=
                                   static_cast<long>(Subquery_strategy::SUBQ_MATERIALIZATION); }
#line 1989 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 52:
#line 447 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
                               { (yyval.ulong_num)= static_cast<long>(Subquery_strategy::SUBQ_EXISTS); }
#line 1995 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 53:
#line 453 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_table_level_hint(NULL_CSTR, (yyvsp[-1].hint_param_table_list), true, (yyvsp[-3].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2005 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 54:
#line 460 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_table_level_hint((yyvsp[-2].lexer.hint_string), (yyvsp[-1].hint_param_table_list), true, (yyvsp[-4].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2015 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 55:
#line 466 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_table_level_hint(NULL_CSTR, (yyvsp[-1].hint_param_table_list), false, (yyvsp[-3].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2025 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 56:
#line 473 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_table_level_hint((yyvsp[-2].lexer.hint_string), (yyvsp[-1].hint_param_table_list), false, (yyvsp[-4].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2035 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 57:
#line 483 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_key_level_hint((yyvsp[-2].hint_param_table), (yyvsp[-1].hint_param_index_list), true, (yyvsp[-4].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2045 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 58:
#line 490 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_key_level_hint((yyvsp[-2].hint_param_table), (yyvsp[-1].hint_param_index_list), false, (yyvsp[-4].hint_type));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2055 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 59:
#line 499 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= BKA_HINT_ENUM;
          }
#line 2063 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 60:
#line 503 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= BNL_HINT_ENUM;
          }
#line 2071 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 61:
#line 507 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= HASH_JOIN_HINT_ENUM;
          }
#line 2079 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 62:
#line 511 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= DERIVED_MERGE_HINT_ENUM;
          }
#line 2087 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 63:
#line 515 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= DERIVED_CONDITION_PUSHDOWN_HINT_ENUM;
          }
#line 2095 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 64:
#line 522 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= BKA_HINT_ENUM;
          }
#line 2103 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 65:
#line 526 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= BNL_HINT_ENUM;
          }
#line 2111 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 66:
#line 530 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= HASH_JOIN_HINT_ENUM;
          }
#line 2119 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 67:
#line 534 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= DERIVED_MERGE_HINT_ENUM;
          }
#line 2127 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 68:
#line 538 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= DERIVED_CONDITION_PUSHDOWN_HINT_ENUM;
          }
#line 2135 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 69:
#line 545 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= MRR_HINT_ENUM;
          }
#line 2143 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 70:
#line 549 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= NO_RANGE_HINT_ENUM;
          }
#line 2151 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 71:
#line 553 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= INDEX_MERGE_HINT_ENUM;
          }
#line 2159 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 72:
#line 557 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= SKIP_SCAN_HINT_ENUM;
          }
#line 2167 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 73:
#line 561 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= INDEX_HINT_ENUM;
          }
#line 2175 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 74:
#line 565 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= JOIN_INDEX_HINT_ENUM;
          }
#line 2183 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 75:
#line 569 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= GROUP_INDEX_HINT_ENUM;
          }
#line 2191 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 76:
#line 573 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= ORDER_INDEX_HINT_ENUM;
          }
#line 2199 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 77:
#line 580 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= ICP_HINT_ENUM;
          }
#line 2207 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 78:
#line 584 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= MRR_HINT_ENUM;
          }
#line 2215 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 79:
#line 588 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= INDEX_MERGE_HINT_ENUM;
          }
#line 2223 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 80:
#line 592 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= SKIP_SCAN_HINT_ENUM;
          }
#line 2231 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 81:
#line 596 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= INDEX_HINT_ENUM;
          }
#line 2239 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 82:
#line 600 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= JOIN_INDEX_HINT_ENUM;
          }
#line 2247 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 83:
#line 604 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= GROUP_INDEX_HINT_ENUM;
          }
#line 2255 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 84:
#line 608 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint_type)= ORDER_INDEX_HINT_ENUM;
          }
#line 2263 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 85:
#line 615 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_hint_qb_name((yyvsp[-1].lexer.hint_string));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2273 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 86:
#line 624 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.hint)= NEW_PTN PT_hint_sys_var((yyvsp[-3].lexer.hint_string), (yyvsp[-1].item));
            if ((yyval.hint) == NULL)
              YYABORT; // OOM
          }
#line 2283 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 87:
#line 633 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
         {
           if (check_resource_group_name_len((yyvsp[-1].lexer.hint_string), Sql_condition::SL_WARNING))
             YYERROR;

           (yyval.hint)= NEW_PTN PT_hint_resource_group((yyvsp[-1].lexer.hint_string));
           if ((yyval.hint) == nullptr)
              YYABORT; // OOM
         }
#line 2296 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 90:
#line 650 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            longlong n;
            if (parse_int(&n, (yyvsp[0].lexer.hint_string).str, (yyvsp[0].lexer.hint_string).length))
            {
              scanner->syntax_warning(ER_THD(thd, ER_WRONG_SIZE_NUMBER));
              (yyval.item)= NULL;
            }
            else
            {
              (yyval.item)= NEW_PTN Item_int((ulonglong)n);
              if ((yyval.item) == NULL)
                YYABORT; // OOM
            }
          }
#line 2315 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 91:
#line 665 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            (yyval.item)= NEW_PTN Item_float((yyvsp[0].lexer.hint_string).str, (yyvsp[0].lexer.hint_string).length);
          }
#line 2323 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 92:
#line 669 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
          {
            longlong n;
            if (parse_int(&n, (yyvsp[0].lexer.hint_string).str, (yyvsp[0].lexer.hint_string).length - 1))
            {
              scanner->syntax_warning(ER_THD(thd, ER_WRONG_SIZE_NUMBER));
              (yyval.item)= NULL;
            }
            else
            {
              int multiplier;
              switch ((yyvsp[0].lexer.hint_string).str[(yyvsp[0].lexer.hint_string).length - 1]) {
              case 'K': multiplier= 1024; break;
              case 'M': multiplier= 1024 * 1024; break;
              case 'G': multiplier= 1024 * 1024 * 1024; break;
              default:
                assert(0); // should not happen
                YYABORT;        // for sure
              }
              if (1.0L * n * multiplier > LLONG_MAX_DOUBLE)
              {
                scanner->syntax_warning(ER_THD(thd, ER_WRONG_SIZE_NUMBER));
                (yyval.item)= NULL;
              }
              else
              {
                (yyval.item)= NEW_PTN Item_int((ulonglong)n * multiplier);
                if ((yyval.item) == NULL)
                  YYABORT; // OOM
              }
            }
          }
#line 2359 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;

  case 95:
#line 709 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy"
        {
          (yyval.item)= NEW_PTN Item_string((yyvsp[0].lexer.hint_string).str, (yyvsp[0].lexer.hint_string).length, thd->charset());
          if ((yyval.item) == NULL)
            YYABORT; // OOM
        }
#line 2369 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"
    break;


#line 2373 "/mnt/jenkins/workspace/percona-xtrabackup-8.0-RELEASE/test/percona-xtrabackup/sql/sql_hints.yy.cc"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (thd, scanner, ret, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (thd, scanner, ret, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, thd, scanner, ret);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp, thd, scanner, ret);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (thd, scanner, ret, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, thd, scanner, ret);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, thd, scanner, ret);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
