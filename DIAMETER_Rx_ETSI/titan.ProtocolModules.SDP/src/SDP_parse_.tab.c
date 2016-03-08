/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         SDP_parse_parse
#define yylex           SDP_parse_lex
#define yyerror         SDP_parse_error
#define yylval          SDP_parse_lval
#define yychar          SDP_parse_char
#define yydebug         SDP_parse_debug
#define yynerrs         SDP_parse_nerrs


/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "SDP_parser.y"

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// Copyright Test Competence Center (TCC) ETH 2013                           //
//                                                                           //
// The copyright to the computer  program(s) herein  is the property of TCC. //
// The program(s) may be used and/or copied only with the written permission //
// of TCC or in accordance with  the terms and conditions  stipulated in the //
// agreement/contract under which the program(s) has been supplied.          //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
//
//  File:               SDP_parser.y
//  Rev:                R12A
//  Prodnr:             CNL 113 353
//  Updated:            2013-11-20
//  Contact:            http://ttcn.ericsson.se
//  Reference:          ITU-T SDP
/*C declarations*/

#include "SDP_parse_parser.h"
#include <stdarg.h>
#define YYDEBUG 1
using namespace SDP__Types;

extern int SDP_parse_lex();
extern int SDP_parse_error(char *s);

SDP__Message* SDP_parse_parsed_message;

SDP__Message* SDP_parse_get_parsed_message() {
	return SDP_parse_parsed_message;
}

void SDP_parse_set_parsed_message(SDP__Message* pdu) {
	SDP_parse_parsed_message=pdu;
}




/* Line 268 of yacc.c  */
#line 121 "SDP_parse_.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ZERO = 258,
     _ONE = 259,
     _TWO = 260,
     _THREE = 261,
     _FOUR = 262,
     _FIVE = 263,
     _SIX = 264,
     _SEVEN = 265,
     _EIGHT = 266,
     _NINE = 267,
     CRLF = 268,
     ALPHA = 269,
     SPACE = 270,
     UNDERSCORE = 271,
     PERIOD = 272,
     ANYBYTE = 273,
     LBRACE = 274,
     RBRACE = 275,
     LT = 276,
     GT = 277,
     PLUS = 278,
     HYPHEN = 279,
     SLASH = 280,
     COLON = 281,
     EMAIL = 282,
     TOKEN = 283,
     INTTOKEN = 284,
     VEQ = 285,
     OEQ = 286,
     SEQ = 287,
     IEQ = 288,
     UEQ = 289,
     EEQ = 290,
     PEQ = 291,
     CEQ = 292,
     BEQ = 293,
     BW_CT = 294,
     BW_AS = 295,
     TEQ = 296,
     ZEQ = 297,
     REQ = 298,
     KEQ = 299,
     AEQ = 300,
     MEQ = 301,
     A_CAT = 302,
     A_KEYWDS = 303,
     A_TOOL = 304,
     A_PTIME = 305,
     A_RECVONLY = 306,
     A_SENDRECV = 307,
     A_SENDONLY = 308,
     A_ORIENT = 309,
     A_TYPE = 310,
     A_CHARSET = 311,
     A_SDLANG = 312,
     A_LANG = 313,
     A_FRAMERATE = 314,
     A_QUALITY = 315,
     A_FMTP = 316,
     A_CURR = 317,
     A_DES = 318,
     A_CONF = 319,
     A_RTMAP = 320,
     A_RTCP = 321,
     A_MAX_SIZE = 322,
     A_PATH = 323,
     A_ACCEPT_TYPES = 324,
     A_ACCEPT_WRAPPED_TYPES = 325,
     A_MAXPRATE = 326,
     A_MID = 327,
     A_GROUP = 328,
     A_FILE_SELECTOR = 329,
     A_FILE_TRANSFER_ID = 330,
     A_INACTIVE = 331,
     A_SETUP = 332,
     A_CONNECTION = 333,
     A_CRYPTO = 334,
     A_CONTENT = 335,
     A_LABEL = 336,
     A_FLOORCTRL = 337,
     A_CONFID = 338,
     A_USERID = 339,
     A_FLOORID = 340,
     A_FINGERPRINT = 341,
     A_ICE_UFRAG = 342,
     A_ICE_PWD = 343,
     A_CANDIDATE = 344,
     A_ICE_LITE = 345,
     A_ICE_MISMATCH = 346,
     A_REMOTE_CANDIDATE = 347,
     A_ICE_OPTIONS = 348,
     A_RTCP_FB = 349,
     A_MAXPTIME = 350,
     A_T38_VERSION = 351,
     A_T38_BITRATE = 352,
     A_T38_BITREMOVAL = 353,
     A_T38_MMR = 354,
     A_T38_JBIG = 355,
     A_T38_RATEMANAGEMENT = 356,
     A_T38_MAXBUFFER = 357,
     A_T38_MAXDATAGRAM = 358,
     A_T38_IFP = 359,
     A_T38_EC = 360,
     A_T38_ECDEPTH = 361,
     A_T38_FEC = 362,
     A_T38_VENDORINFO = 363,
     A_T38_MODEM = 364,
     A_FILE_DISPOSITION = 365,
     A_FILE_DATE = 366,
     A_FILE_ICON = 367,
     A_FILE_RANGE = 368
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 44 "SDP_parser.y"

	int number;
	INTEGER* intnum;
	char byte;
	CHARSTRING* t_charstring;
	SDP__Types::SDP__Message* t_sdp_message;
	SDP__Types::SDP__Origin* t_sdp_origin;
	SDP__Types::SDP__contact* t_sdp_contact;
	SDP__Types::SDP__email__list* t_sdp_email_list;
	SDP__Types::SDP__phone__list* t_sdp_phone_list;
	SDP__Types::SDP__connection* t_sdp_connection;
	SDP__Types::SDP__connection__list* t_sdp_connection_list;
	SDP__Types::SDP__conn__addr* t_sdp_conn_addr;
	SDP__Types::SDP__bandwidth* t_sdp_bandwidth;
	SDP__Types::SDP__time__list* t_sdp_time_list;
	SDP__Types::SDP__time* t_sdp_time;
	SDP__Types::SDP__time__field* t_sdp_time_field;
	SDP__Types::SDP__repeat* t_sdp_repeat;
	SDP__Types::SDP__repeat__list* t_sdp_repeat_list;
	SDP__Types::SDP__timezone__list* t_sdp_timezone_list;
	SDP__Types::SDP__timezone* t_sdp_timezone;
	SDP__Types::SDP__typed__time* t_sdp_typed_time;
	SDP__Types::SDP__typed__time__list* t_sdp_typed_time_list;
	SDP__Types::SDP__key* t_sdp_key;
	SDP__Types::SDP__attribute* t_sdp_attribute;
	SDP__Types::SDP__attribute__list* t_sdp_attribute_list;
	SDP__Types::SDP__media__desc* t_sdp_media_desc;
	SDP__Types::SDP__media__desc__list* t_sdp_media_desc_list;
	SDP__Types::SDP__media__field* t_sdp_media_field;
	SDP__Types::SDP__fmt__list* t_sdp_fmt_list;
	SDP__Types::SDP__bandwidth__list* t_bandwidth_list;
	SDP__Types::SDP__url__list* t_url_list;
	SDP__Types::SDP__media__type__list* t_type_list;
	SDP__Types::SDP__id__tag__list* t_id_list;
	SDP__Types::SDP__Remote__candidate__list* t_candidate_list;	
	SDP__Types::SDP__Remote__candidate* t_candidate;	
	SDP__Types::SDP__extension__list* t_extension_list;	
	SDP__Types::SDP__extension* t_extension;
	SDP__Types::SDP__ice__options__list* t_sdp_ice_option_list;		



/* Line 293 of yacc.c  */
#line 313 "SDP_parse_.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 325 "SDP_parse_.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNRULES -- Number of states.  */
#define YYNSTATES  382

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   368

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    18,    19,    22,    29,    41,    51,    53,
      57,    59,    63,    64,    67,    71,    74,    77,    80,    83,
      85,    87,    89,    92,    95,    98,   101,   104,   107,   110,
     113,   116,   119,   122,   125,   128,   131,   134,   137,   140,
     143,   148,   151,   154,   159,   162,   165,   167,   170,   173,
     176,   179,   182,   185,   188,   191,   194,   197,   200,   203,
     223,   225,   227,   230,   233,   236,   239,   242,   245,   248,
     251,   254,   257,   260,   263,   266,   269,   272,   277,   280,
     287,   290,   293,   296,   299,   302,   306,   308,   310,   314,
     316,   320,   326,   327,   332,   333,   338,   339,   342,   347,
     349,   353,   355,   359,   361,   365,   366,   370,   372,   376,
     378,   381,   384,   385,   388,   396,   398,   402,   403,   407,
     409,   413,   417,   419,   422,   428,   429,   432,   438,   439,
     442,   443,   451,   459,   461,   465,   471,   472,   475,   479,
     481,   486,   491,   493,   494,   497,   501,   503,   509,   515,
     519,   520,   524,   525,   529,   533,   537,   551,   553,   556,
     558,   560,   562,   564,   566,   568,   570,   572,   574,   576,
     578,   580,   582,   584,   586,   588,   590,   592,   594,   596,
     598
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     115,     0,    -1,   162,   163,   161,   160,   159,   156,   152,
     149,   146,   136,   141,   134,   121,   116,    -1,    -1,   116,
     117,    -1,   118,   160,   148,   146,   134,   121,    -1,    46,
      28,    15,    28,    25,    28,    15,   119,    15,   120,    13,
      -1,    46,    28,    15,    28,    15,   119,    15,   120,    13,
      -1,    28,    -1,   119,    25,    28,    -1,    28,    -1,   120,
      15,    28,    -1,    -1,   121,   122,    -1,    45,   123,    13,
      -1,    47,    28,    -1,    48,    28,    -1,    49,    28,    -1,
      50,    28,    -1,    51,    -1,    52,    -1,    53,    -1,    54,
      28,    -1,    55,    28,    -1,    56,    28,    -1,    57,    28,
      -1,    58,    28,    -1,    59,    28,    -1,    60,    28,    -1,
      61,    28,    -1,    62,    28,    -1,    63,    28,    -1,    64,
      28,    -1,    65,    28,    -1,    66,    28,    -1,    67,    28,
      -1,    68,   131,    -1,    69,   133,    -1,    70,   133,    -1,
      71,    28,    -1,    71,    28,    17,    28,    -1,    72,    28,
      -1,    73,    28,    -1,    73,    28,    15,   132,    -1,    74,
      28,    -1,    75,    28,    -1,    76,    -1,    77,    28,    -1,
      78,    28,    -1,    79,    28,    -1,    80,    28,    -1,    81,
      28,    -1,    82,    28,    -1,    83,    28,    -1,    84,    28,
      -1,    85,    28,    -1,    86,    28,    -1,    87,    28,    -1,
      88,    28,    -1,    89,    28,    15,    28,    15,    28,    15,
      28,    15,    28,    15,    28,    15,    28,    15,    28,   127,
     128,   129,    -1,    90,    -1,    91,    -1,    92,   125,    -1,
      93,   124,    -1,    94,    28,    -1,    95,    28,    -1,    96,
      28,    -1,    97,    28,    -1,    98,    28,    -1,    99,    28,
      -1,   100,    28,    -1,   101,    28,    -1,   102,    28,    -1,
     103,    28,    -1,   104,    28,    -1,   105,    28,    -1,   106,
      28,    -1,   106,    28,    15,    28,    -1,   107,    28,    -1,
     108,    28,    15,    28,    15,    28,    -1,   109,    28,    -1,
     110,    28,    -1,   111,    28,    -1,   112,    28,    -1,   113,
      28,    -1,    28,    26,    28,    -1,    28,    -1,    28,    -1,
     124,    15,    28,    -1,   126,    -1,   125,    15,   126,    -1,
      28,    15,    28,    15,    28,    -1,    -1,    15,    28,    15,
      28,    -1,    -1,    15,    28,    15,    28,    -1,    -1,   129,
     130,    -1,    15,    28,    15,    28,    -1,    28,    -1,   131,
      15,    28,    -1,    28,    -1,   132,    15,    28,    -1,    28,
      -1,   133,    15,    28,    -1,    -1,    44,   135,    13,    -1,
      28,    -1,    28,    26,    28,    -1,   137,    -1,   136,   137,
      -1,   145,   138,    -1,    -1,   138,   139,    -1,    43,   144,
      15,   144,    15,   140,    13,    -1,   144,    -1,   140,    15,
     144,    -1,    -1,    42,   142,    13,    -1,   143,    -1,   142,
      15,   143,    -1,    29,    15,   144,    -1,    29,    -1,    29,
      14,    -1,    41,    28,    15,    28,    13,    -1,    -1,   146,
     147,    -1,    38,    28,    26,    28,    13,    -1,    -1,   148,
     150,    -1,    -1,    37,    28,    15,    28,    15,   151,    13,
      -1,    37,    28,    15,    28,    15,   151,    13,    -1,    28,
      -1,    28,    25,    28,    -1,    28,    25,    28,    25,    28,
      -1,    -1,   152,   153,    -1,    36,   154,    13,    -1,   155,
      -1,   155,    19,   164,    20,    -1,   155,    21,   155,    22,
      -1,   164,    -1,    -1,   156,   157,    -1,    35,   158,    13,
      -1,    27,    -1,    27,    15,    19,   164,    20,    -1,   164,
      15,    21,    27,    22,    -1,    21,    27,    22,    -1,    -1,
      34,    28,    13,    -1,    -1,    33,    28,    13,    -1,    32,
      28,    13,    -1,    30,    29,    13,    -1,    31,    28,    15,
      28,    15,    28,    15,    28,    15,    28,    15,    28,    13,
      -1,   168,    -1,   164,   168,    -1,    14,    -1,   166,    -1,
       3,    -1,   167,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,   165,    -1,    16,    -1,    17,    -1,    24,    -1,
      23,    -1,    25,    -1,    26,    -1,    18,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   259,   260,   272,   309,   323,   337,   338,
     346,   351,   358,   361,   374,   378,   383,   388,   393,   398,
     402,   406,   410,   415,   420,   425,   430,   435,   440,   445,
     450,   455,   460,   465,   470,   475,   480,   485,   490,   495,
     501,   508,   513,   519,   526,   531,   536,   540,   545,   550,
     555,   560,   565,   570,   575,   580,   585,   590,   595,   600,
     636,   640,   644,   650,   655,   660,   665,   670,   675,   680,
     685,   690,   695,   700,   705,   710,   715,   721,   728,   733,
     742,   747,   752,   757,   762,   768,   775,   782,   787,   794,
     799,   806,   816,   817,   823,   824,   829,   830,   843,   852,
     857,   864,   869,   876,   881,   889,   890,   895,   901,   911,
     916,   923,   934,   935,   949,   960,   965,   971,   972,   976,
     981,   988,   996,  1002,  1009,  1017,  1018,  1032,  1041,  1042,
    1056,  1057,  1068,  1077,  1084,  1092,  1103,  1104,  1116,  1120,
    1126,  1134,  1143,  1160,  1161,  1174,  1178,  1185,  1192,  1199,
    1209,  1210,  1215,  1216,  1220,  1224,  1226,  1248,  1249,  1258,
    1259,  1262,  1263,  1265,  1266,  1267,  1268,  1269,  1270,  1271,
    1272,  1273,  1277,  1278,  1279,  1280,  1281,  1282,  1283,  1284,
    1285
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ZERO", "_ONE", "_TWO", "_THREE",
  "_FOUR", "_FIVE", "_SIX", "_SEVEN", "_EIGHT", "_NINE", "CRLF", "ALPHA",
  "SPACE", "UNDERSCORE", "PERIOD", "ANYBYTE", "LBRACE", "RBRACE", "LT",
  "GT", "PLUS", "HYPHEN", "SLASH", "COLON", "EMAIL", "TOKEN", "INTTOKEN",
  "VEQ", "OEQ", "SEQ", "IEQ", "UEQ", "EEQ", "PEQ", "CEQ", "BEQ", "BW_CT",
  "BW_AS", "TEQ", "ZEQ", "REQ", "KEQ", "AEQ", "MEQ", "A_CAT", "A_KEYWDS",
  "A_TOOL", "A_PTIME", "A_RECVONLY", "A_SENDRECV", "A_SENDONLY",
  "A_ORIENT", "A_TYPE", "A_CHARSET", "A_SDLANG", "A_LANG", "A_FRAMERATE",
  "A_QUALITY", "A_FMTP", "A_CURR", "A_DES", "A_CONF", "A_RTMAP", "A_RTCP",
  "A_MAX_SIZE", "A_PATH", "A_ACCEPT_TYPES", "A_ACCEPT_WRAPPED_TYPES",
  "A_MAXPRATE", "A_MID", "A_GROUP", "A_FILE_SELECTOR",
  "A_FILE_TRANSFER_ID", "A_INACTIVE", "A_SETUP", "A_CONNECTION",
  "A_CRYPTO", "A_CONTENT", "A_LABEL", "A_FLOORCTRL", "A_CONFID",
  "A_USERID", "A_FLOORID", "A_FINGERPRINT", "A_ICE_UFRAG", "A_ICE_PWD",
  "A_CANDIDATE", "A_ICE_LITE", "A_ICE_MISMATCH", "A_REMOTE_CANDIDATE",
  "A_ICE_OPTIONS", "A_RTCP_FB", "A_MAXPTIME", "A_T38_VERSION",
  "A_T38_BITRATE", "A_T38_BITREMOVAL", "A_T38_MMR", "A_T38_JBIG",
  "A_T38_RATEMANAGEMENT", "A_T38_MAXBUFFER", "A_T38_MAXDATAGRAM",
  "A_T38_IFP", "A_T38_EC", "A_T38_ECDEPTH", "A_T38_FEC",
  "A_T38_VENDORINFO", "A_T38_MODEM", "A_FILE_DISPOSITION", "A_FILE_DATE",
  "A_FILE_ICON", "A_FILE_RANGE", "$accept", "announcement",
  "media_descriptions", "media_description", "media_field", "transport",
  "fmt_list", "attribute_fields", "attribute_field", "attribute",
  "ice_option_list", "candidate_list", "candidate", "rel_addr", "rel_port",
  "extension_list", "extension", "url_list", "id_list", "type_list",
  "key_field", "key_type", "time_list", "time", "repeat_list", "repeat",
  "offsets", "timezones_field", "timezone_list", "timezone", "typed_time",
  "time_field", "bandwidth_list", "bandwidth_field", "connection_fields",
  "connection_field_lonely", "connection_field", "conn_address",
  "phone_fields", "phone_field", "phone_number", "phone", "email_fields",
  "email_field", "email_address", "uri_field", "information_field",
  "session_name_field", "proto_version", "origin_field", "email_text",
  "alpha_numeric", "digit", "pos_digit", "email_byte", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   116,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   125,
     125,   126,   127,   127,   128,   128,   129,   129,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   138,   138,   139,   140,   140,   141,   141,   142,
     142,   143,   144,   144,   145,   146,   146,   147,   148,   148,
     149,   149,   150,   151,   151,   151,   152,   152,   153,   154,
     154,   154,   155,   156,   156,   157,   158,   158,   158,   158,
     159,   159,   160,   160,   161,   162,   163,   164,   164,   165,
     165,   166,   166,   167,   167,   167,   167,   167,   167,   167,
     167,   167,   168,   168,   168,   168,   168,   168,   168,   168,
     168
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    14,     0,     2,     6,    11,     9,     1,     3,
       1,     3,     0,     2,     3,     2,     2,     2,     2,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     2,     2,     4,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    19,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     4,     2,     6,
       2,     2,     2,     2,     2,     3,     1,     1,     3,     1,
       3,     5,     0,     4,     0,     4,     0,     2,     4,     1,
       3,     1,     3,     1,     3,     0,     3,     1,     3,     1,
       2,     2,     0,     2,     7,     1,     3,     0,     3,     1,
       3,     3,     1,     2,     5,     0,     2,     5,     0,     2,
       0,     7,     7,     1,     3,     5,     0,     2,     3,     1,
       4,     4,     1,     0,     2,     3,     1,     5,     5,     3,
       0,     3,     0,     3,     3,     3,    13,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     1,     0,     0,   155,     0,
       0,   152,     0,     0,     0,   150,     0,   154,     0,     0,
     143,     0,   153,     0,   136,     0,   151,     0,   130,   144,
       0,   161,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   159,   180,   173,   174,   179,     0,   176,   175,   177,
     178,   146,     0,     0,   172,   160,   162,   157,     0,     0,
     125,   137,     0,     0,     0,   145,   180,   158,     0,   139,
     142,     0,     0,     0,   149,     0,     0,   138,     0,     0,
       0,     0,     0,   117,   109,   112,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,   105,   111,     0,
     147,   148,   140,   141,     0,     0,     0,     0,     0,   119,
       0,    12,     0,   113,     0,   133,     0,     0,     0,     0,
     118,     0,   107,     0,     3,   122,     0,   156,     0,   131,
     127,   124,   121,   120,     0,   106,     0,     2,    13,   123,
       0,   134,   108,    86,     0,     0,     0,     0,    19,    20,
      21,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,   152,     0,     0,     0,    15,    16,
      17,    18,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    99,    36,   103,    37,
      38,    39,    41,    42,    44,    45,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
      62,    89,    87,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    78,     0,    80,
      81,    82,    83,    84,    14,     0,   128,     0,   135,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   115,   100,   104,    40,   101,    43,     0,
       0,    90,    88,    77,     0,     0,     0,   105,   129,   114,
       0,     0,     0,     0,     0,     0,     0,     0,    12,   116,
     102,     0,    91,    79,     8,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,    10,     0,     9,     0,     0,
       0,     7,     0,     0,     0,     0,    11,     0,   132,     0,
       6,     0,     0,     0,     0,    92,     0,    94,     0,     0,
      96,     0,     0,    59,    93,     0,     0,    97,    95,     0,
       0,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   137,   213,   214,   335,   346,   124,   138,   211,
     263,   260,   261,   367,   370,   373,   377,   237,   308,   239,
     111,   123,    83,    84,    98,   113,   302,    97,   108,   109,
     126,    85,    72,    86,   301,    60,   318,   116,    28,    61,
      68,    69,    24,    29,    52,    20,    15,    11,     3,     7,
      70,    54,    55,    56,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yytype_int16 yypact[] =
{
     -24,    72,   120,    90,   109,  -120,    96,    91,  -120,   111,
     100,    97,   101,   118,   105,    98,   119,  -120,   122,   108,
    -120,   110,  -120,   126,   116,   142,  -120,    88,   -27,  -120,
     131,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   133,  -120,  -120,  -120,
    -120,   150,   153,   199,  -120,  -120,  -120,  -120,   223,   139,
    -120,  -120,   164,   163,   168,  -120,   167,  -120,   180,    -4,
     223,   179,   -33,   169,  -120,   223,   171,  -120,   223,   223,
     172,   184,   190,   -22,  -120,  -120,  -120,   181,   138,   173,
     166,   177,   204,   194,   206,   207,  -120,   198,   200,   216,
    -120,  -120,  -120,  -120,   217,   222,   224,   236,     3,  -120,
     225,  -120,   226,  -120,   241,   231,   244,   245,   246,   226,
    -120,   207,   234,   248,   218,   250,   247,  -120,   237,  -120,
    -120,  -120,  -120,  -120,   238,  -120,   -25,   221,  -120,  -120,
     226,   243,  -120,   249,   242,   251,   252,   253,  -120,  -120,
    -120,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   269,   270,   271,
     272,   273,   274,  -120,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,  -120,  -120,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   325,   311,  -120,    97,   326,   312,   314,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,   328,  -120,   329,
     329,   330,  -120,   331,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,   333,   334,
     335,  -120,  -120,   336,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,   337,  -120,   338,  -120,
    -120,  -120,  -120,  -120,  -120,   339,  -120,   226,  -120,  -120,
     317,   327,   332,   340,   341,   342,   288,   343,   344,   345,
     346,   232,    95,  -120,  -120,  -120,  -120,  -120,   347,   348,
     349,  -120,  -120,  -120,   350,   -14,   351,   -31,  -120,  -120,
     226,   352,   353,   354,   355,   356,   357,   360,  -120,  -120,
    -120,   361,  -120,  -120,  -120,   -13,   362,   358,   218,   359,
     363,   364,   356,   373,   374,  -120,   103,  -120,   -11,   217,
     365,  -120,   366,   363,   377,   380,  -120,   104,  -120,   368,
    -120,   382,   370,   384,   372,   386,   375,   387,   389,   378,
    -120,   379,   390,   393,  -120,   381,   383,  -120,  -120,   395,
     385,  -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,   -71,   -81,   -55,  -120,  -120,
    -120,  -120,   -20,  -120,  -120,  -120,  -120,  -120,  -120,   107,
     -40,  -120,  -120,   195,  -120,  -120,  -120,  -120,  -120,   235,
    -119,  -120,    56,  -120,  -120,  -120,  -120,     9,  -120,  -120,
    -120,   367,  -120,  -120,  -120,  -120,   145,  -120,  -120,  -120,
      62,  -120,  -120,  -120,    37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     132,   325,   340,   143,   353,    81,     1,    81,    82,    58,
      59,   326,   341,   110,   341,    78,   120,    79,   121,    82,
      95,   215,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    53,
      67,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     4,    41,    42,    43,    44,    45,    67,   319,    46,
     320,    47,    48,    49,    50,    51,   351,   360,   352,   352,
       5,     6,     8,    10,     9,    67,    12,    67,    13,    16,
      14,    17,    19,    18,    21,    22,    23,    88,    25,    26,
      90,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    27,    41,    42,    43,    44,    45,    30,   100,    62,
      63,    47,    48,    49,    50,    64,    65,    71,   303,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    73,
      41,    42,    43,    44,    45,    74,   102,    75,    76,    47,
      48,    49,    50,    77,    80,   101,    99,    87,    89,   103,
      92,   329,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    93,    41,    66,    43,    44,    45,    94,   104,
     105,   106,    47,    48,    49,    50,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   107,    41,    42,    43,
      44,    45,   110,   112,   114,   115,    47,    48,    49,    50,
     117,   119,   118,   122,   127,   125,   128,   129,   130,   131,
     134,   135,   140,   136,   139,   141,   142,   212,   216,   316,
     218,   348,   357,   338,   240,   217,   311,   328,    96,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   238,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   262,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     288,   287,   289,   290,   291,   304,   293,   292,   294,   295,
     296,   297,   298,   299,   300,   305,   133,   317,   354,   286,
     306,     0,   321,   322,   323,   324,     0,     0,   307,   309,
     310,   312,   313,   314,   315,   337,   339,   342,     0,   327,
     330,   331,   332,   333,   334,   336,   343,   344,   349,   350,
     358,   345,   347,   355,   356,   359,   361,   362,   363,   364,
     365,   366,   369,   368,   371,   375,   372,   374,   376,   378,
     380,   379,     0,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-120))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     119,    15,    15,    28,    15,    38,    30,    38,    41,    36,
      37,    25,    25,    44,    25,    19,    13,    21,    15,    41,
      42,   140,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    27,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    29,    14,    15,    16,    17,    18,    70,    13,    21,
      15,    23,    24,    25,    26,    27,    13,    13,    15,    15,
       0,    31,    13,    32,    28,    88,    15,    90,    28,    28,
      33,    13,    34,    28,    15,    13,    28,    75,    28,    13,
      78,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    35,    14,    15,    16,    17,    18,    15,    20,    28,
      27,    23,    24,    25,    26,    15,    13,    28,   287,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    15,
      14,    15,    16,    17,    18,    22,    20,    19,    21,    23,
      24,    25,    26,    13,    15,    22,    15,    28,    27,    22,
      28,   320,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    28,    14,    15,    16,    17,    18,    28,    15,
      26,    15,    23,    24,    25,    26,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    29,    14,    15,    16,
      17,    18,    44,    43,    28,    28,    23,    24,    25,    26,
      28,    15,    28,    28,    13,    29,    25,    13,    13,    13,
      26,    13,    15,    45,    14,    28,    28,    46,    25,    37,
      28,   342,   353,   328,   167,    26,   296,   317,    83,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    13,    28,
      28,    15,    28,    15,    15,    28,    15,    17,    15,    15,
      15,    15,    15,    15,    15,    28,   121,   301,   349,   214,
      28,    -1,    15,    15,    15,    15,    -1,    -1,    28,    28,
      28,    28,    28,    28,    28,    15,    15,    15,    -1,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    15,    15,
      13,    28,    28,    28,    28,    15,    28,    15,    28,    15,
      28,    15,    15,    28,    15,    15,    28,    28,    15,    28,
      15,    28,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    30,   115,   162,    29,     0,    31,   163,    13,    28,
      32,   161,    15,    28,    33,   160,    28,    13,    28,    34,
     159,    15,    13,    28,   156,    28,    13,    35,   152,   157,
      15,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    14,    15,    16,    17,    18,    21,    23,    24,    25,
      26,    27,   158,   164,   165,   166,   167,   168,    36,    37,
     149,   153,    28,    27,    15,    13,    15,   168,   154,   155,
     164,    28,   146,    15,    22,    19,    21,    13,    19,    21,
      15,    38,    41,   136,   137,   145,   147,    28,   164,    27,
     164,   155,    28,    28,    28,    42,   137,   141,   138,    15,
      20,    22,    20,    22,    15,    26,    15,    29,   142,   143,
      44,   134,    43,   139,    28,    28,   151,    28,    28,    15,
      13,    15,    28,   135,   121,    29,   144,    13,    25,    13,
      13,    13,   144,   143,    26,    13,    45,   116,   122,    14,
      15,    28,    28,    28,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   123,    46,   117,   118,   144,    25,    26,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,   131,    28,   133,
     133,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
     125,   126,    28,   124,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    13,    28,   160,    15,    28,    28,
      15,    15,    17,    15,    15,    15,    15,    15,    15,    15,
      15,   148,   140,   144,    28,    28,    28,    28,   132,    28,
      28,   126,    28,    28,    28,    28,    37,   146,   150,    13,
      15,    15,    15,    15,    15,    15,    25,    28,   134,   144,
      28,    28,    28,    28,    28,   119,    28,    15,   121,    15,
      15,    25,    15,    28,    28,    28,   120,    28,   119,    15,
      15,    13,    15,    15,   151,    28,    28,   120,    13,    15,
      13,    28,    15,    28,    15,    28,    15,   127,    28,    15,
     128,    15,    28,   129,    28,    15,    15,   130,    28,    28,
      15,    28
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
      int yyn = yypact[*yyssp];
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
      yychar = YYLEX;
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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

/* Line 1806 of yacc.c  */
#line 184 "SDP_parser.y"
    {
//				SDP_parse_parsed_message = new SDP__Message;
				(*SDP_parse_parsed_message).protocol__version() = (yyvsp[(1) - (14)].number);
				(*SDP_parse_parsed_message).origin() = *(yyvsp[(2) - (14)].t_sdp_origin);
				delete (yyvsp[(2) - (14)].t_sdp_origin);
				(*SDP_parse_parsed_message).session__name() = *(yyvsp[(3) - (14)].t_charstring);
				delete (yyvsp[(3) - (14)].t_charstring);

				if ((yyvsp[(4) - (14)].t_charstring) != NULL) { // information field present
					(*SDP_parse_parsed_message).information() = *(yyvsp[(4) - (14)].t_charstring);
					delete (yyvsp[(4) - (14)].t_charstring);
				} else
					(*SDP_parse_parsed_message).information() = OMIT_VALUE;

				if ((yyvsp[(5) - (14)].t_charstring) != NULL) { // uri field present
					(*SDP_parse_parsed_message).uri() = *(yyvsp[(5) - (14)].t_charstring);
					delete (yyvsp[(5) - (14)].t_charstring);
				} else
					(*SDP_parse_parsed_message).uri() = OMIT_VALUE;
				if ((yyvsp[(6) - (14)].t_sdp_email_list) != NULL) { //email fields present
					(*SDP_parse_parsed_message).emails() = *(yyvsp[(6) - (14)].t_sdp_email_list);
					delete (yyvsp[(6) - (14)].t_sdp_email_list);
				} else
					(*SDP_parse_parsed_message).emails() = OMIT_VALUE;
				if ((yyvsp[(7) - (14)].t_sdp_phone_list) != NULL) { // phone fields present
					(*SDP_parse_parsed_message).phone__numbers() = *(yyvsp[(7) - (14)].t_sdp_phone_list);
					delete (yyvsp[(7) - (14)].t_sdp_phone_list);
				} else
					(*SDP_parse_parsed_message).phone__numbers() = OMIT_VALUE;
				
				
				if ((yyvsp[(8) - (14)].t_sdp_connection) != NULL) { // connection fields present
				(*SDP_parse_parsed_message).connection() = (*(yyvsp[(8) - (14)].t_sdp_connection));
				delete (yyvsp[(8) - (14)].t_sdp_connection);
				} else 
				  (*SDP_parse_parsed_message).connection() = OMIT_VALUE;
				  
				if ((yyvsp[(9) - (14)].t_bandwidth_list) != NULL) {
					(*SDP_parse_parsed_message).bandwidth() = *(yyvsp[(9) - (14)].t_bandwidth_list);
					delete (yyvsp[(9) - (14)].t_bandwidth_list);
				} else
					(*SDP_parse_parsed_message).bandwidth() = OMIT_VALUE;

				(*SDP_parse_parsed_message).times() = *(yyvsp[(10) - (14)].t_sdp_time_list);
					delete (yyvsp[(10) - (14)].t_sdp_time_list);

				if ((yyvsp[(11) - (14)].t_sdp_timezone_list) != NULL) {
					(*SDP_parse_parsed_message).timezone__adjustments() = *(yyvsp[(11) - (14)].t_sdp_timezone_list);
					delete (yyvsp[(11) - (14)].t_sdp_timezone_list);
				} else
					(*SDP_parse_parsed_message).timezone__adjustments() = OMIT_VALUE;

				
				if ((yyvsp[(12) - (14)].t_sdp_key) != NULL) {
					(*SDP_parse_parsed_message).key () = *(yyvsp[(12) - (14)].t_sdp_key);
					delete (yyvsp[(12) - (14)].t_sdp_key);
				} else {
					(*SDP_parse_parsed_message).key() = OMIT_VALUE;
				}
				
				if ((yyvsp[(13) - (14)].t_sdp_attribute_list) != NULL) {
					(*SDP_parse_parsed_message).attributes() = *(yyvsp[(13) - (14)].t_sdp_attribute_list);
					delete (yyvsp[(13) - (14)].t_sdp_attribute_list);
				} else {
					(*SDP_parse_parsed_message).attributes() = OMIT_VALUE;
				}
				if ((yyvsp[(14) - (14)].t_sdp_media_desc_list) != NULL) {
					(*SDP_parse_parsed_message).media__list() = *(yyvsp[(14) - (14)].t_sdp_media_desc_list);
					delete (yyvsp[(14) - (14)].t_sdp_media_desc_list);
				} else 
					(*SDP_parse_parsed_message).media__list() = OMIT_VALUE;
				
				YYACCEPT;
			  }
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 259 "SDP_parser.y"
    {(yyval.t_sdp_media_desc_list) = NULL;}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 260 "SDP_parser.y"
    {
						if ((yyvsp[(1) - (2)].t_sdp_media_desc_list) != NULL) {
							int media_num = (*(yyvsp[(1) - (2)].t_sdp_media_desc_list)).size_of();
							(*(yyvsp[(1) - (2)].t_sdp_media_desc_list))[media_num] = *(yyvsp[(2) - (2)].t_sdp_media_desc);
							delete (yyvsp[(2) - (2)].t_sdp_media_desc);
						} else {
							(yyval.t_sdp_media_desc_list) = new SDP__media__desc__list();
							(*(yyval.t_sdp_media_desc_list))[0] = *(yyvsp[(2) - (2)].t_sdp_media_desc);
							delete (yyvsp[(2) - (2)].t_sdp_media_desc);
						}
					}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 278 "SDP_parser.y"
    {
						(yyval.t_sdp_media_desc) = new SDP__media__desc();
						(*(yyval.t_sdp_media_desc)).media__field() = *(yyvsp[(1) - (6)].t_sdp_media_field);
						delete (yyvsp[(1) - (6)].t_sdp_media_field);
						if ((yyvsp[(2) - (6)].t_charstring) != NULL) {
							(*(yyval.t_sdp_media_desc)).information() = *(yyvsp[(2) - (6)].t_charstring);
							delete (yyvsp[(2) - (6)].t_charstring);
						} else
							(*(yyval.t_sdp_media_desc)).information() = OMIT_VALUE;
						if ((yyvsp[(3) - (6)].t_sdp_connection_list) != NULL) {
							(*(yyval.t_sdp_media_desc)).connections() = *(yyvsp[(3) - (6)].t_sdp_connection_list);
							delete (yyvsp[(3) - (6)].t_sdp_connection_list);
						} else 
							(*(yyval.t_sdp_media_desc)).connections() = OMIT_VALUE;
						if ((yyvsp[(4) - (6)].t_bandwidth_list) != NULL) {
							(*(yyval.t_sdp_media_desc)).bandwidth() = *(yyvsp[(4) - (6)].t_bandwidth_list);
							delete (yyvsp[(4) - (6)].t_bandwidth_list);
						} else
							(*(yyval.t_sdp_media_desc)).bandwidth() = OMIT_VALUE;
						if ((yyvsp[(5) - (6)].t_sdp_key) != NULL) {
							(*(yyval.t_sdp_media_desc)).key() = *(yyvsp[(5) - (6)].t_sdp_key);
							delete (yyvsp[(5) - (6)].t_sdp_key);
						} else
							(*(yyval.t_sdp_media_desc)).key() = OMIT_VALUE;
						if ((yyvsp[(6) - (6)].t_sdp_attribute_list) != NULL) {
							(*(yyval.t_sdp_media_desc)).attributes() = *(yyvsp[(6) - (6)].t_sdp_attribute_list);
							delete (yyvsp[(6) - (6)].t_sdp_attribute_list);
						} else
							(*(yyval.t_sdp_media_desc)).attributes()=  OMIT_VALUE;
					}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 310 "SDP_parser.y"
    {
						(yyval.t_sdp_media_field) = new SDP__media__field();
						(*(yyval.t_sdp_media_field)).media() = *(yyvsp[(2) - (11)].t_charstring);
						delete (yyvsp[(2) - (11)].t_charstring);
						(*(yyval.t_sdp_media_field)).ports().port__number() = str2int(*(yyvsp[(4) - (11)].t_charstring));
						delete (yyvsp[(4) - (11)].t_charstring);
						(*(yyval.t_sdp_media_field)).ports().num__of__ports() = str2int(*(yyvsp[(6) - (11)].t_charstring));
						delete (yyvsp[(6) - (11)].t_charstring);
						(*(yyval.t_sdp_media_field)).transport() = *(yyvsp[(8) - (11)].t_charstring);
						delete (yyvsp[(8) - (11)].t_charstring);
						(*(yyval.t_sdp_media_field)).fmts() = *(yyvsp[(10) - (11)].t_sdp_fmt_list);
						delete (yyvsp[(10) - (11)].t_sdp_fmt_list);
					}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 324 "SDP_parser.y"
    {
						(yyval.t_sdp_media_field) = new SDP__media__field();
						(*(yyval.t_sdp_media_field)).media() = *(yyvsp[(2) - (9)].t_charstring);
						delete (yyvsp[(2) - (9)].t_charstring);
						(*(yyval.t_sdp_media_field)).ports().port__number() = str2int(*(yyvsp[(4) - (9)].t_charstring));
						delete (yyvsp[(4) - (9)].t_charstring);
						(*(yyval.t_sdp_media_field)).ports().num__of__ports() = OMIT_VALUE;
						(*(yyval.t_sdp_media_field)).transport() = *(yyvsp[(6) - (9)].t_charstring);
						delete (yyvsp[(6) - (9)].t_charstring);
						(*(yyval.t_sdp_media_field)).fmts() = *(yyvsp[(8) - (9)].t_sdp_fmt_list);
						delete (yyvsp[(8) - (9)].t_sdp_fmt_list);
					}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 337 "SDP_parser.y"
    { (yyval.t_charstring)=(yyvsp[(1) - (1)].t_charstring);}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 338 "SDP_parser.y"
    {
         const CHARSTRING& str = *(yyvsp[(1) - (3)].t_charstring)+CHARSTRING(1,"/")+*(yyvsp[(3) - (3)].t_charstring);
         delete (yyvsp[(1) - (3)].t_charstring);
         delete (yyvsp[(3) - (3)].t_charstring);
         (yyval.t_charstring) = new CHARSTRING(str);
         
       }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 346 "SDP_parser.y"
    {
				(yyval.t_sdp_fmt_list) = new SDP__fmt__list();
				(*(yyval.t_sdp_fmt_list))[0] = *(yyvsp[(1) - (1)].t_charstring);
				delete (yyvsp[(1) - (1)].t_charstring);
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 351 "SDP_parser.y"
    {
				int fmt_num = (*(yyvsp[(1) - (3)].t_sdp_fmt_list)).size_of();
				(*(yyvsp[(1) - (3)].t_sdp_fmt_list))[fmt_num] = *(yyvsp[(3) - (3)].t_charstring);
				delete (yyvsp[(3) - (3)].t_charstring);
				(yyval.t_sdp_fmt_list) = (yyvsp[(1) - (3)].t_sdp_fmt_list);
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 358 "SDP_parser.y"
    {
						(yyval.t_sdp_attribute_list) = NULL;
					}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 361 "SDP_parser.y"
    {
						if ((yyvsp[(1) - (2)].t_sdp_attribute_list) != NULL) {
							int att_num = (*(yyvsp[(1) - (2)].t_sdp_attribute_list)).size_of();
							(*(yyvsp[(1) - (2)].t_sdp_attribute_list))[att_num] = *(yyvsp[(2) - (2)].t_sdp_attribute);
							delete (yyvsp[(2) - (2)].t_sdp_attribute);
						} else {
							(yyval.t_sdp_attribute_list) = new SDP__attribute__list();
							(*(yyval.t_sdp_attribute_list))[0] = *(yyvsp[(2) - (2)].t_sdp_attribute);
							delete (yyvsp[(2) - (2)].t_sdp_attribute);
						}
					}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 374 "SDP_parser.y"
    {
						(yyval.t_sdp_attribute) = (yyvsp[(2) - (3)].t_sdp_attribute);
					}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 378 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).cat().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 383 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).keywds().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 388 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).tool().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 393 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).ptime().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 398 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).recvonly() = SDP__attribute__recvonly(NULL_VALUE);
				}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 402 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).sendrecv() = SDP__attribute__sendrecv(NULL_VALUE);
				}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 406 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).sendonly() = SDP__attribute__sendonly(NULL_VALUE);
				}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 410 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).orient().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 415 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).sdp__type().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 420 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).charset().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 425 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).sdplang().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 430 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).lang().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 435 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).framerate().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 440 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).quality().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 445 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).fmtp().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 450 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).curr().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 455 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).des().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 460 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).conf().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 465 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).rtpmap().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 470 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).rtcp().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 475 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).max__size().max__size() = str2int(*(yyvsp[(2) - (2)].t_charstring));
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 480 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).path().path__list() = *(yyvsp[(2) - (2)].t_url_list);
					delete (yyvsp[(2) - (2)].t_url_list);
				}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 485 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).accept__types().attr__value() = *(yyvsp[(2) - (2)].t_type_list);
					delete (yyvsp[(2) - (2)].t_type_list);
				}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 490 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).accept__wrapped__types().attr__value() = *(yyvsp[(2) - (2)].t_type_list);
					delete (yyvsp[(2) - (2)].t_type_list);
				}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 495 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).maxprate().prate__integer__part() = str2int(*(yyvsp[(2) - (2)].t_charstring));
					(*(yyval.t_sdp_attribute)).maxprate().prate__fraction__part() = OMIT_VALUE;
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 501 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).maxprate().prate__integer__part() = str2int(*(yyvsp[(2) - (4)].t_charstring));
					(*(yyval.t_sdp_attribute)).maxprate().prate__fraction__part() = str2int(*(yyvsp[(4) - (4)].t_charstring));
					delete (yyvsp[(2) - (4)].t_charstring);
					delete (yyvsp[(4) - (4)].t_charstring);
				}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 508 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).mid().id__tag() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 513 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).group__attr().semantics() = *(yyvsp[(2) - (2)].t_charstring);
					(*(yyval.t_sdp_attribute)).group__attr().id__tag()=OMIT_VALUE;
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 519 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).group__attr().semantics() = *(yyvsp[(2) - (4)].t_charstring);
					(*(yyval.t_sdp_attribute)).group__attr().id__tag()=*(yyvsp[(4) - (4)].t_id_list);
					delete (yyvsp[(2) - (4)].t_charstring);
					delete (yyvsp[(4) - (4)].t_id_list);
				}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 526 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__selector().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 531 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__transfer__id().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 536 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).inactive() = SDP__attribute__inactive(NULL_VALUE);
				}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 540 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).setup().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 545 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).connection().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 550 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).crypto().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 555 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).content().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 560 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).attr__label().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 565 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).floorctrl().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 570 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).confid().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 575 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).userid().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 580 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).floorid().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 585 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).fingerprint().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 590 "SDP_parser.y"
    {
				        (yyval.t_sdp_attribute) = new SDP__attribute();
				        (*(yyval.t_sdp_attribute)).ice__ufrag().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 595 "SDP_parser.y"
    {
				        (yyval.t_sdp_attribute) = new SDP__attribute();
				        (*(yyval.t_sdp_attribute)).ice__pwd().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 602 "SDP_parser.y"
    {
				        (yyval.t_sdp_attribute) = new SDP__attribute();
				        (*(yyval.t_sdp_attribute)).candidate().foundation() = *(yyvsp[(2) - (19)].t_charstring); 
				        delete (yyvsp[(2) - (19)].t_charstring);
			                (*(yyval.t_sdp_attribute)).candidate().component__id() = str2int(*(yyvsp[(4) - (19)].t_charstring));
			                delete (yyvsp[(4) - (19)].t_charstring);
			                (*(yyval.t_sdp_attribute)).candidate().transport() = *(yyvsp[(6) - (19)].t_charstring); 
			                delete (yyvsp[(6) - (19)].t_charstring);
			                (*(yyval.t_sdp_attribute)).candidate().priority() = str2int(*(yyvsp[(8) - (19)].t_charstring));
				        delete (yyvsp[(8) - (19)].t_charstring);
					(*(yyval.t_sdp_attribute)).candidate().connection__address() = *(yyvsp[(10) - (19)].t_charstring);  
				        delete (yyvsp[(10) - (19)].t_charstring);
					(*(yyval.t_sdp_attribute)).candidate().connection__port() = str2int(*(yyvsp[(12) - (19)].t_charstring)); 
					delete (yyvsp[(12) - (19)].t_charstring);					  
					delete (yyvsp[(14) - (19)].t_charstring);
					(*(yyval.t_sdp_attribute)).candidate().candidate__type() = *(yyvsp[(16) - (19)].t_charstring);  
					delete (yyvsp[(16) - (19)].t_charstring);					
					if ((yyvsp[(17) - (19)].t_charstring) != NULL) {
							(*(yyval.t_sdp_attribute)).candidate().rel__address() = *(yyvsp[(17) - (19)].t_charstring);
							delete (yyvsp[(17) - (19)].t_charstring);
						} else
							(*(yyval.t_sdp_attribute)).candidate().rel__address() = OMIT_VALUE;
                                        if ((yyvsp[(18) - (19)].t_charstring) != NULL) {
							(*(yyval.t_sdp_attribute)).candidate().rel__port() = *(yyvsp[(18) - (19)].t_charstring);
							delete (yyvsp[(18) - (19)].t_charstring);
						} else
							(*(yyval.t_sdp_attribute)).candidate().rel__port() = OMIT_VALUE;					
				
				        if ((yyvsp[(19) - (19)].t_extension_list) != NULL) {
							(*(yyval.t_sdp_attribute)).candidate().extensions() = *(yyvsp[(19) - (19)].t_extension_list);
							delete (yyvsp[(19) - (19)].t_extension_list);
						} else
							(*(yyval.t_sdp_attribute)).candidate().extensions() = OMIT_VALUE;	
				}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 636 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).ice__lite() = SDP__attribute__ice__lite(NULL_VALUE);
				}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 640 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).ice__mismatch() = SDP__attribute__ice__mismatch(NULL_VALUE);
				}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 645 "SDP_parser.y"
    {   
				        (yyval.t_sdp_attribute) = new SDP__attribute();
                                        (*(yyval.t_sdp_attribute)).remote__candidate().attr__value() = *(yyvsp[(2) - (2)].t_candidate_list);
                                        delete (yyvsp[(2) - (2)].t_candidate_list);
                                }
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 650 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).ice__options().attr__value() = *(yyvsp[(2) - (2)].t_sdp_ice_option_list);
					delete (yyvsp[(2) - (2)].t_sdp_ice_option_list);
				}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 655 "SDP_parser.y"
    {
				        (yyval.t_sdp_attribute) = new SDP__attribute();
				        (*(yyval.t_sdp_attribute)).rtcp__fb().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 660 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).maxptime().attr__value() = *(yyvsp[(2) - (2)].t_charstring);				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 665 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__version().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 670 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__bit__rate().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 675 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__fill__bit__removal().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 680 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__transcoding__mmr().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 685 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__transcoding__jbig().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 690 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__rate__management().attr__value() = *(yyvsp[(2) - (2)].t_charstring);				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 695 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__max__buffer().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 700 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__max__datagram().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 705 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__max__ifp().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 710 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__udp__ec().attr__value() = *(yyvsp[(2) - (2)].t_charstring);				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 715 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__udp__ec__depth().minred() = str2int(*(yyvsp[(2) - (2)].t_charstring));
                                        (*(yyval.t_sdp_attribute)).t38__udp__ec__depth().maxred() = OMIT_VALUE;				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 721 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__udp__ec__depth().minred() = str2int(*(yyvsp[(2) - (4)].t_charstring));
                                        (*(yyval.t_sdp_attribute)).t38__udp__ec__depth().maxred() = str2int(*(yyvsp[(4) - (4)].t_charstring));				
					delete (yyvsp[(2) - (4)].t_charstring);
                                        delete (yyvsp[(4) - (4)].t_charstring);
				}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 728 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__udp__fec__max__spam().attr__value() = str2int(*(yyvsp[(2) - (2)].t_charstring));				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 733 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
                                        (*(yyval.t_sdp_attribute)).t38__vendor__info().t35country__code() = str2int(*(yyvsp[(2) - (6)].t_charstring));
                                        (*(yyval.t_sdp_attribute)).t38__vendor__info().t35extension() = str2int(*(yyvsp[(4) - (6)].t_charstring));
                                        (*(yyval.t_sdp_attribute)).t38__vendor__info().manufacturer__code() = str2int(*(yyvsp[(6) - (6)].t_charstring));				
                                        delete (yyvsp[(2) - (6)].t_charstring);
                                        delete (yyvsp[(4) - (6)].t_charstring);				
					delete (yyvsp[(6) - (6)].t_charstring);
				}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 742 "SDP_parser.y"
    {				
				        (yyval.t_sdp_attribute) = new SDP__attribute();				
				        (*(yyval.t_sdp_attribute)).t38__modem__type().attr__value() = *(yyvsp[(2) - (2)].t_charstring);				
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 747 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__disposition().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 752 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__date().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 757 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__icon().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 762 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).file__range().attr__value() = *(yyvsp[(2) - (2)].t_charstring);
					delete (yyvsp[(2) - (2)].t_charstring);
				}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 768 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).unknown().name() = *(yyvsp[(1) - (3)].t_charstring);
					delete (yyvsp[(1) - (3)].t_charstring);
					(*(yyval.t_sdp_attribute)).unknown().attr__value() = *(yyvsp[(3) - (3)].t_charstring);
					delete (yyvsp[(3) - (3)].t_charstring);
                                }
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 775 "SDP_parser.y"
    {
					(yyval.t_sdp_attribute) = new SDP__attribute();
					(*(yyval.t_sdp_attribute)).unknown().name() = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
					(*(yyval.t_sdp_attribute)).unknown().attr__value() = OMIT_VALUE;
				}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 782 "SDP_parser.y"
    {
					(yyval.t_sdp_ice_option_list) = new SDP__ice__options__list();
					(*(yyval.t_sdp_ice_option_list))[0] = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
				}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 787 "SDP_parser.y"
    {
					int ice_option_num = (*(yyvsp[(1) - (3)].t_sdp_ice_option_list)).size_of();
					(*(yyvsp[(1) - (3)].t_sdp_ice_option_list))[ice_option_num] = *(yyvsp[(3) - (3)].t_charstring);
					delete (yyvsp[(3) - (3)].t_charstring);
					(yyval.t_sdp_ice_option_list) = (yyvsp[(1) - (3)].t_sdp_ice_option_list);
				}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 794 "SDP_parser.y"
    {
					(yyval.t_candidate_list) = new SDP__Remote__candidate__list();
					(*(yyval.t_candidate_list))[0] = *(yyvsp[(1) - (1)].t_candidate);
					delete (yyvsp[(1) - (1)].t_candidate);
				}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 799 "SDP_parser.y"
    {
					int candidate_num = (*(yyvsp[(1) - (3)].t_candidate_list)).size_of();
					(*(yyvsp[(1) - (3)].t_candidate_list))[candidate_num] = *(yyvsp[(3) - (3)].t_candidate);
					delete (yyvsp[(3) - (3)].t_candidate);
					(yyval.t_candidate_list) = (yyvsp[(1) - (3)].t_candidate_list);
				}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 806 "SDP_parser.y"
    {
						(yyval.t_candidate) = new SDP__Remote__candidate();
						(*(yyval.t_candidate)).component__Id() = *(yyvsp[(1) - (5)].t_charstring);
						delete (yyvsp[(1) - (5)].t_charstring);
						(*(yyval.t_candidate)).connection__address() = *(yyvsp[(3) - (5)].t_charstring);
						delete (yyvsp[(3) - (5)].t_charstring);
					        (*(yyval.t_candidate)).portValue() = str2int(*(yyvsp[(5) - (5)].t_charstring));
						delete (yyvsp[(5) - (5)].t_charstring);							
					}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 816 "SDP_parser.y"
    {(yyval.t_charstring) = NULL;}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 817 "SDP_parser.y"
    {
			      delete (yyvsp[(2) - (4)].t_charstring);
	                      (yyval.t_charstring) = (yyvsp[(4) - (4)].t_charstring);			     
			}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 823 "SDP_parser.y"
    {(yyval.t_charstring) = NULL;}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 824 "SDP_parser.y"
    {
			      delete (yyvsp[(2) - (4)].t_charstring);
	                      (yyval.t_charstring) = (yyvsp[(4) - (4)].t_charstring);
			}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 829 "SDP_parser.y"
    {(yyval.t_extension_list) = NULL;}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 830 "SDP_parser.y"
    {
			 if ((yyvsp[(1) - (2)].t_extension_list) != NULL) {
						int extension_num = (*(yyvsp[(1) - (2)].t_extension_list)).size_of();
						(*(yyvsp[(1) - (2)].t_extension_list))[extension_num] = *(yyvsp[(2) - (2)].t_extension);
						delete (yyvsp[(2) - (2)].t_extension);
						(yyval.t_extension_list) = (yyvsp[(1) - (2)].t_extension_list);
					} else {
						(yyval.t_extension_list) = new SDP__extension__list();
						(*(yyval.t_extension_list))[0] = *(yyvsp[(2) - (2)].t_extension);
						delete (yyvsp[(2) - (2)].t_extension);
					}
				}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 843 "SDP_parser.y"
    {
						(yyval.t_extension) = new SDP__extension();
						(*(yyval.t_extension)).extension__attr__name() = *(yyvsp[(2) - (4)].t_charstring);
						delete (yyvsp[(2) - (4)].t_charstring);
						(*(yyval.t_extension)).extension__attr__value() = *(yyvsp[(4) - (4)].t_charstring);
						delete (yyvsp[(4) - (4)].t_charstring);
					}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 852 "SDP_parser.y"
    {
					(yyval.t_url_list) = new SDP__url__list();
					(*(yyval.t_url_list))[0] = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
				}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 857 "SDP_parser.y"
    {
					int url_num = (*(yyvsp[(1) - (3)].t_url_list)).size_of();
					(*(yyvsp[(1) - (3)].t_url_list))[url_num] = *(yyvsp[(3) - (3)].t_charstring);
					delete (yyvsp[(3) - (3)].t_charstring);
					(yyval.t_url_list) = (yyvsp[(1) - (3)].t_url_list);
				}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 864 "SDP_parser.y"
    {
					(yyval.t_id_list) = new SDP__id__tag__list();
					(*(yyval.t_id_list))[0] = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
				}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 869 "SDP_parser.y"
    {
					int id_num = (*(yyvsp[(1) - (3)].t_id_list)).size_of();
					(*(yyvsp[(1) - (3)].t_id_list))[id_num] = *(yyvsp[(3) - (3)].t_charstring);
					delete (yyvsp[(3) - (3)].t_charstring);
					(yyval.t_id_list) = (yyvsp[(1) - (3)].t_id_list);
				}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 876 "SDP_parser.y"
    {
					(yyval.t_type_list) = new SDP__media__type__list();
					(*(yyval.t_type_list))[0] = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
				}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 881 "SDP_parser.y"
    {
					int url_num = (*(yyvsp[(1) - (3)].t_type_list)).size_of();
					(*(yyvsp[(1) - (3)].t_type_list))[url_num] = *(yyvsp[(3) - (3)].t_charstring);
					delete (yyvsp[(3) - (3)].t_charstring);
					(yyval.t_type_list) = (yyvsp[(1) - (3)].t_type_list);
				}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 889 "SDP_parser.y"
    {(yyval.t_sdp_key) = NULL;}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 890 "SDP_parser.y"
    {
				(yyval.t_sdp_key) = (yyvsp[(2) - (3)].t_sdp_key);
				
			}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 895 "SDP_parser.y"
    {
				(yyval.t_sdp_key) = new SDP__key();
				(*(yyval.t_sdp_key)).method() = *(yyvsp[(1) - (1)].t_charstring);
				delete (yyvsp[(1) - (1)].t_charstring);
				(*(yyval.t_sdp_key)).key() = OMIT_VALUE;
			}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 901 "SDP_parser.y"
    {
				(yyval.t_sdp_key) = new SDP__key();
				(*(yyval.t_sdp_key)).method() = *(yyvsp[(1) - (3)].t_charstring);
				delete (yyvsp[(1) - (3)].t_charstring);
				(*(yyval.t_sdp_key)).key() = *(yyvsp[(3) - (3)].t_charstring);
				delete (yyvsp[(3) - (3)].t_charstring);
			}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 911 "SDP_parser.y"
    {
					(yyval.t_sdp_time_list) = new SDP__time__list();
					(*(yyval.t_sdp_time_list))[0] = *(yyvsp[(1) - (1)].t_sdp_time);
					delete (yyvsp[(1) - (1)].t_sdp_time);
				}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 916 "SDP_parser.y"
    {
					int time_num = (*(yyvsp[(1) - (2)].t_sdp_time_list)).size_of();
					(*(yyvsp[(1) - (2)].t_sdp_time_list))[time_num] = *(yyvsp[(2) - (2)].t_sdp_time);
					delete (yyvsp[(2) - (2)].t_sdp_time);
					(yyval.t_sdp_time_list) = (yyvsp[(1) - (2)].t_sdp_time_list);
				}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 923 "SDP_parser.y"
    {
				(yyval.t_sdp_time) = new SDP__time;
				(*(yyval.t_sdp_time)).time__field() = *(yyvsp[(1) - (2)].t_sdp_time_field);
				delete (yyvsp[(1) - (2)].t_sdp_time_field);
				if ((yyvsp[(2) - (2)].t_sdp_repeat_list) != NULL) {
					(*(yyval.t_sdp_time)).time__repeat() = *(yyvsp[(2) - (2)].t_sdp_repeat_list);
					delete (yyvsp[(2) - (2)].t_sdp_repeat_list);
				} else
					(*(yyval.t_sdp_time)).time__repeat() = OMIT_VALUE;
			}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 934 "SDP_parser.y"
    {(yyval.t_sdp_repeat_list) = NULL;}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 935 "SDP_parser.y"
    {
					if ((yyvsp[(1) - (2)].t_sdp_repeat_list) != NULL) {
						int repeat_num = (*(yyvsp[(1) - (2)].t_sdp_repeat_list)).size_of();
						(*(yyvsp[(1) - (2)].t_sdp_repeat_list))[repeat_num] = *(yyvsp[(2) - (2)].t_sdp_repeat);
						delete (yyvsp[(2) - (2)].t_sdp_repeat);
						(yyval.t_sdp_repeat_list) = (yyvsp[(1) - (2)].t_sdp_repeat_list);
					} else {
						(yyval.t_sdp_repeat_list) = new SDP__repeat__list();
						(*(yyval.t_sdp_repeat_list))[0] = *(yyvsp[(2) - (2)].t_sdp_repeat);
						delete (yyvsp[(2) - (2)].t_sdp_repeat);
					}
				}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 949 "SDP_parser.y"
    {
				(yyval.t_sdp_repeat) = new SDP__repeat();
				(*(yyval.t_sdp_repeat)).repeat__interval() = *(yyvsp[(2) - (7)].t_sdp_typed_time);
				delete (yyvsp[(2) - (7)].t_sdp_typed_time);
				(*(yyval.t_sdp_repeat)).active() = *(yyvsp[(4) - (7)].t_sdp_typed_time);
				delete (yyvsp[(4) - (7)].t_sdp_typed_time);
				(*(yyval.t_sdp_repeat)).offsets() = *(yyvsp[(6) - (7)].t_sdp_typed_time_list);
				delete (yyvsp[(6) - (7)].t_sdp_typed_time_list);
			}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 960 "SDP_parser.y"
    {
				(yyval.t_sdp_typed_time_list) = new SDP__typed__time__list();
				(*(yyval.t_sdp_typed_time_list))[0] = *(yyvsp[(1) - (1)].t_sdp_typed_time);
				delete (yyvsp[(1) - (1)].t_sdp_typed_time);
			}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 965 "SDP_parser.y"
    {
				int off_size = (*(yyvsp[(1) - (3)].t_sdp_typed_time_list)).size_of();
				(*(yyval.t_sdp_typed_time_list))[off_size] = *(yyvsp[(3) - (3)].t_sdp_typed_time);
				delete (yyvsp[(3) - (3)].t_sdp_typed_time);
			}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 971 "SDP_parser.y"
    {(yyval.t_sdp_timezone_list) = NULL;}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 972 "SDP_parser.y"
    {
					(yyval.t_sdp_timezone_list) = (yyvsp[(2) - (3)].t_sdp_timezone_list);
				}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 976 "SDP_parser.y"
    {
					(yyval.t_sdp_timezone_list) = new SDP__timezone__list();
					(*(yyval.t_sdp_timezone_list))[0] = *(yyvsp[(1) - (1)].t_sdp_timezone);
					delete (yyvsp[(1) - (1)].t_sdp_timezone);
				}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 981 "SDP_parser.y"
    {
					int tz_num = (*(yyvsp[(1) - (3)].t_sdp_timezone_list)).size_of();
					(*(yyvsp[(1) - (3)].t_sdp_timezone_list))[tz_num] = *(yyvsp[(3) - (3)].t_sdp_timezone);
					delete (yyvsp[(3) - (3)].t_sdp_timezone);
					(yyval.t_sdp_timezone_list) = (yyvsp[(1) - (3)].t_sdp_timezone_list);
				}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 988 "SDP_parser.y"
    {
					(yyval.t_sdp_timezone) = new SDP__timezone();
					(*(yyval.t_sdp_timezone)).adjustment__time() = int2str(*(yyvsp[(1) - (3)].intnum));
					delete (yyvsp[(1) - (3)].intnum);
					(*(yyval.t_sdp_timezone)).offset() = *(yyvsp[(3) - (3)].t_sdp_typed_time);
					delete (yyvsp[(3) - (3)].t_sdp_typed_time);
				}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 996 "SDP_parser.y"
    {
					(yyval.t_sdp_typed_time) = new SDP__typed__time();
					(*(yyval.t_sdp_typed_time)).time() = *(yyvsp[(1) - (1)].intnum);
					delete (yyvsp[(1) - (1)].intnum);
					(*(yyval.t_sdp_typed_time)).unit() = OMIT_VALUE;
				}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1002 "SDP_parser.y"
    {
					(yyval.t_sdp_typed_time) = new SDP__typed__time();
					(*(yyval.t_sdp_typed_time)).time() = *(yyvsp[(1) - (2)].intnum);
					delete (yyvsp[(1) - (2)].intnum);
					(*(yyval.t_sdp_typed_time)).unit() = CHARSTRING(1, (const char*)&(yyvsp[(2) - (2)].byte));
				}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1009 "SDP_parser.y"
    { // start_time SPACE stop_time
					(yyval.t_sdp_time_field) = new SDP__time__field();
					(*(yyval.t_sdp_time_field)).start__time() = (*(yyvsp[(2) - (5)].t_charstring));
					delete (yyvsp[(2) - (5)].t_charstring);
					(*(yyval.t_sdp_time_field)).stop__time() = (*(yyvsp[(4) - (5)].t_charstring));
					delete (yyvsp[(4) - (5)].t_charstring);
				}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1017 "SDP_parser.y"
    {(yyval.t_bandwidth_list) = NULL;}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1018 "SDP_parser.y"
    {
					if ((yyvsp[(1) - (2)].t_bandwidth_list) != NULL) {
						int bandwidth_num = (*(yyvsp[(1) - (2)].t_bandwidth_list)).size_of();
						(*(yyvsp[(1) - (2)].t_bandwidth_list))[bandwidth_num] = *(yyvsp[(2) - (2)].t_sdp_bandwidth);
						delete (yyvsp[(2) - (2)].t_sdp_bandwidth);
						(yyval.t_bandwidth_list) = (yyvsp[(1) - (2)].t_bandwidth_list);
					} else {
						(yyval.t_bandwidth_list) = new SDP__bandwidth__list();
						(*(yyval.t_bandwidth_list))[0] = *(yyvsp[(2) - (2)].t_sdp_bandwidth);
						delete (yyvsp[(2) - (2)].t_sdp_bandwidth);
					}
				}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1032 "SDP_parser.y"
    {
						(yyval.t_sdp_bandwidth) = new SDP__bandwidth();
						(*(yyval.t_sdp_bandwidth)).modifier() = *(yyvsp[(2) - (5)].t_charstring);
						delete (yyvsp[(2) - (5)].t_charstring);
						(*(yyval.t_sdp_bandwidth)).bandwidth() = str2int(*(yyvsp[(4) - (5)].t_charstring));
						delete (yyvsp[(4) - (5)].t_charstring);
					}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 1041 "SDP_parser.y"
    {(yyval.t_sdp_connection_list) = NULL;}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 1042 "SDP_parser.y"
    {
						if ((yyvsp[(1) - (2)].t_sdp_connection_list) != NULL) {
							int con_num = (*(yyvsp[(1) - (2)].t_sdp_connection_list)).size_of();
							(*(yyvsp[(1) - (2)].t_sdp_connection_list))[con_num] = *(yyvsp[(2) - (2)].t_sdp_connection);
							delete (yyvsp[(2) - (2)].t_sdp_connection);
							(yyval.t_sdp_connection_list) = (yyvsp[(1) - (2)].t_sdp_connection_list);
						} else {
							(yyval.t_sdp_connection_list) = new SDP__connection__list();
							(*(yyval.t_sdp_connection_list))[0] = *(yyvsp[(2) - (2)].t_sdp_connection);
							delete (yyvsp[(2) - (2)].t_sdp_connection);
						}
					}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 1056 "SDP_parser.y"
    {(yyval.t_sdp_connection) = NULL;}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 1057 "SDP_parser.y"
    {
						(yyval.t_sdp_connection) = new SDP__connection();
						(*(yyval.t_sdp_connection)).net__type() = *(yyvsp[(2) - (7)].t_charstring);
						delete (yyvsp[(2) - (7)].t_charstring);
						(*(yyval.t_sdp_connection)).addr__type() = *(yyvsp[(4) - (7)].t_charstring);
						delete (yyvsp[(4) - (7)].t_charstring);
						(*(yyval.t_sdp_connection)).conn__addr() = (*(yyvsp[(6) - (7)].t_sdp_conn_addr));
						delete (yyvsp[(6) - (7)].t_sdp_conn_addr);
					}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 1068 "SDP_parser.y"
    {
						(yyval.t_sdp_connection) = new SDP__connection();
						(*(yyval.t_sdp_connection)).net__type() = *(yyvsp[(2) - (7)].t_charstring);
						delete (yyvsp[(2) - (7)].t_charstring);
						(*(yyval.t_sdp_connection)).addr__type() = *(yyvsp[(4) - (7)].t_charstring);
						delete (yyvsp[(4) - (7)].t_charstring);
						(*(yyval.t_sdp_connection)).conn__addr() = (*(yyvsp[(6) - (7)].t_sdp_conn_addr));
						delete (yyvsp[(6) - (7)].t_sdp_conn_addr);
					}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 1077 "SDP_parser.y"
    {
					(yyval.t_sdp_conn_addr) = new SDP__conn__addr();
					(*(yyval.t_sdp_conn_addr)).addr() = (*(yyvsp[(1) - (1)].t_charstring));
					delete (yyvsp[(1) - (1)].t_charstring);
					(*(yyval.t_sdp_conn_addr)).ttl() = OMIT_VALUE;
					(*(yyval.t_sdp_conn_addr)).num__of__addr() = OMIT_VALUE;
				}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 1084 "SDP_parser.y"
    {
					(yyval.t_sdp_conn_addr) = new SDP__conn__addr();
					(*(yyval.t_sdp_conn_addr)).addr() = (*(yyvsp[(1) - (3)].t_charstring));
					delete (yyvsp[(1) - (3)].t_charstring);
					(*(yyval.t_sdp_conn_addr)).ttl() = str2int(*(yyvsp[(3) - (3)].t_charstring));
					(*(yyval.t_sdp_conn_addr)).num__of__addr() = OMIT_VALUE;
					delete (yyvsp[(3) - (3)].t_charstring);
				}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 1092 "SDP_parser.y"
    {
					(yyval.t_sdp_conn_addr) = new SDP__conn__addr();
					(*(yyval.t_sdp_conn_addr)).addr() = (*(yyvsp[(1) - (5)].t_charstring));
					delete (yyvsp[(1) - (5)].t_charstring);
					(*(yyval.t_sdp_conn_addr)).ttl() = str2int(*(yyvsp[(3) - (5)].t_charstring));
					(*(yyval.t_sdp_conn_addr)).num__of__addr() = str2int(*(yyvsp[(5) - (5)].t_charstring));
					delete (yyvsp[(3) - (5)].t_charstring);
					delete (yyvsp[(5) - (5)].t_charstring);
				}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 1103 "SDP_parser.y"
    {(yyval.t_sdp_phone_list) = NULL;}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 1104 "SDP_parser.y"
    {
					if ((yyval.t_sdp_phone_list) == NULL) {
						(yyval.t_sdp_phone_list) = new SDP__phone__list();
						(*(yyval.t_sdp_phone_list))[0] = *(yyvsp[(2) - (2)].t_sdp_contact);
						delete (yyvsp[(2) - (2)].t_sdp_contact);
					} else {
						int num_of_phonenumbers = (*(yyvsp[(1) - (2)].t_sdp_phone_list)).size_of();
						(*(yyvsp[(1) - (2)].t_sdp_phone_list))[num_of_phonenumbers]  =*(yyvsp[(2) - (2)].t_sdp_contact);
						delete (yyvsp[(2) - (2)].t_sdp_contact);
					}
				}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 1116 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = (yyvsp[(2) - (3)].t_sdp_contact);
				}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 1120 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = (*(yyvsp[(1) - (1)].t_charstring));
					delete (yyvsp[(1) - (1)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = OMIT_VALUE;
				}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 1126 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(1) - (4)].t_charstring);
					delete (yyvsp[(1) - (4)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = *(yyvsp[(3) - (4)].t_charstring);
					delete (yyvsp[(3) - (4)].t_charstring);
				}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 1134 "SDP_parser.y"
    {
					/* phone is any charstring, but with trailing space removed*/
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(3) - (4)].t_charstring);
					delete (yyvsp[(3) - (4)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = *(yyvsp[(1) - (4)].t_charstring);
					delete (yyvsp[(1) - (4)].t_charstring);
				}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 1143 "SDP_parser.y"
    {
			/* remove trailing space, if any */
/* This is a rather ugly post-processing, but otherwise SDP can not
be parsed with an LR(1) parser. Reason: phone number may contain spaces, 
and delimiter between the phone number and the rest of the phone field may be a space*/

			int size = (*(yyvsp[(1) - (1)].t_charstring)).lengthof();
			
			const char* buf = (const char*)(*(yyvsp[(1) - (1)].t_charstring));
			
			if (buf[size-1] == ' ') {
				(yyval.t_charstring) = new CHARSTRING(size-1, (const char*)(*(yyvsp[(1) - (1)].t_charstring)));
				delete (yyvsp[(1) - (1)].t_charstring);
			} else
				(yyval.t_charstring) = (yyvsp[(1) - (1)].t_charstring);
		}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 1160 "SDP_parser.y"
    {(yyval.t_sdp_email_list) = NULL;}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1161 "SDP_parser.y"
    {
					if ((yyvsp[(1) - (2)].t_sdp_email_list) == NULL) {
						(yyval.t_sdp_email_list) = new SDP__email__list();
						(*(yyval.t_sdp_email_list))[0] = *(yyvsp[(2) - (2)].t_sdp_contact);
						delete (yyvsp[(2) - (2)].t_sdp_contact);
					} else {
						int num_of_emails = (*(yyvsp[(1) - (2)].t_sdp_email_list)).size_of();
						// indexing begins with 0
						(*(yyvsp[(1) - (2)].t_sdp_email_list))[num_of_emails] = *(yyvsp[(2) - (2)].t_sdp_contact);
						delete (yyvsp[(2) - (2)].t_sdp_contact);
					}
				}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 1174 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = (yyvsp[(2) - (3)].t_sdp_contact);
				}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 1178 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(1) - (1)].t_charstring);
					delete (yyvsp[(1) - (1)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = OMIT_VALUE;
				}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1185 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(1) - (5)].t_charstring);
					delete (yyvsp[(1) - (5)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = *(yyvsp[(4) - (5)].t_charstring);
					delete (yyvsp[(4) - (5)].t_charstring);
				}
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 1192 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(4) - (5)].t_charstring);
					delete (yyvsp[(4) - (5)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = *(yyvsp[(1) - (5)].t_charstring);
					delete (yyvsp[(1) - (5)].t_charstring);
				}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1199 "SDP_parser.y"
    {
					(yyval.t_sdp_contact) = new SDP__contact();
					(*(yyval.t_sdp_contact)).addr__or__phone() = *(yyvsp[(2) - (3)].t_charstring);
					delete (yyvsp[(2) - (3)].t_charstring);
					(*(yyval.t_sdp_contact)).disp__name() = OMIT_VALUE;
				}
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 1209 "SDP_parser.y"
    {(yyval.t_charstring) = NULL;}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1210 "SDP_parser.y"
    {
				(yyval.t_charstring) = (yyvsp[(2) - (3)].t_charstring);
			}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1215 "SDP_parser.y"
    {(yyval.t_charstring) = NULL;}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1216 "SDP_parser.y"
    {
						(yyval.t_charstring) = (yyvsp[(2) - (3)].t_charstring);
					}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1220 "SDP_parser.y"
    {
						(yyval.t_charstring) = (yyvsp[(2) - (3)].t_charstring);
				 }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1224 "SDP_parser.y"
    {(yyval.number) = *(yyvsp[(2) - (3)].intnum); delete (yyvsp[(2) - (3)].intnum);}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1227 "SDP_parser.y"
    {
					(yyval.t_sdp_origin) = new SDP__Origin();
					(*(yyval.t_sdp_origin)).user__name() = *(yyvsp[(2) - (13)].t_charstring);
					delete (yyvsp[(2) - (13)].t_charstring);
					(*(yyval.t_sdp_origin)).session__id() = *(yyvsp[(4) - (13)].t_charstring);
					delete (yyvsp[(4) - (13)].t_charstring);
					(*(yyval.t_sdp_origin)).session__version() = *(yyvsp[(6) - (13)].t_charstring);
					delete (yyvsp[(6) - (13)].t_charstring);
					(*(yyval.t_sdp_origin)).net__type() = *(yyvsp[(8) - (13)].t_charstring);
					delete (yyvsp[(8) - (13)].t_charstring);
					(*(yyval.t_sdp_origin)).addr__type() = *(yyvsp[(10) - (13)].t_charstring);
					delete (yyvsp[(10) - (13)].t_charstring);
					(*(yyval.t_sdp_origin)).addr() = *(yyvsp[(12) - (13)].t_charstring);
					delete (yyvsp[(12) - (13)].t_charstring);
				}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1248 "SDP_parser.y"
    {(yyval.t_charstring) = new CHARSTRING(1, (const char*)&(yyvsp[(1) - (1)].byte));}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1249 "SDP_parser.y"
    {
				const CHARSTRING& str = *(yyvsp[(1) - (2)].t_charstring) + CHARSTRING(1, (const char*)&(yyvsp[(2) - (2)].byte));
				delete (yyvsp[(1) - (2)].t_charstring);
				(yyval.t_charstring) = new CHARSTRING(str);
			}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1258 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1259 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].number) + 0x30;}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1262 "SDP_parser.y"
    {(yyval.number) = 0;}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1263 "SDP_parser.y"
    {(yyval.number) = (yyvsp[(1) - (1)].number);}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1265 "SDP_parser.y"
    {(yyval.number) = 1;}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1266 "SDP_parser.y"
    {(yyval.number) = 2;}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1267 "SDP_parser.y"
    {(yyval.number) = 3;}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1268 "SDP_parser.y"
    {(yyval.number) = 4;}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1269 "SDP_parser.y"
    {(yyval.number) = 5;}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1270 "SDP_parser.y"
    {(yyval.number) = 6;}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1271 "SDP_parser.y"
    {(yyval.number) = 7;}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1272 "SDP_parser.y"
    {(yyval.number) = 8;}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1273 "SDP_parser.y"
    {(yyval.number) = 9;}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1277 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1278 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1279 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 175:

/* Line 1806 of yacc.c  */
#line 1280 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1281 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1282 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1283 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1284 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1285 "SDP_parser.y"
    {(yyval.byte) = (yyvsp[(1) - (1)].byte);}
    break;



/* Line 1806 of yacc.c  */
#line 4011 "SDP_parse_.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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
        yyerror (yymsgp);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 1287 "SDP_parser.y"


/*Additional C code*/

