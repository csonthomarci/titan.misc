/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 206 "SDP_parse_.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE SDP_parse_lval;


