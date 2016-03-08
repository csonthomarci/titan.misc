%{
/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
******************************************************************************/
//
//  File:               SDP_parser.l
//  Rev:                R12A
//  Prodnr:             CNL 113 353
//  Updated:            2013-11-20
//  Contact:            http://ttcn.ericsson.se
//  Reference:          ITU-T SDP

#include "SDP_parse_parser.h"
#include "SDP_parse_.tab.h"

using namespace SDP__Types;

extern int SDP_parse_parse();
static int chr_pos;
static int error_handling;
static int error_occured;
int SDP_parse_error(const char *s) {
	if (SDP_parse_text[0]=='\n') {
    	if(error_handling){
      	TTCN_error("SDP EncDec:  %s in \"\\n\" at position %d",s,chr_pos);
    	} else {
      	TTCN_warning("SDP EncDec:  %s in \"\\n\" at position %d",s,chr_pos);
      	error_occured=1;
    	}
  }
	else if (SDP_parse_text[0]=='\r') {
    	if(error_handling){
       	TTCN_error("SDP EncDec:  %s in \"\\r\" at position %d",s,chr_pos);
    	} else {
       	TTCN_warning("SDP EncDec:  %s in \"\\r\" at position %d",s,chr_pos);
      	error_occured=1;
    	}
  }
 	else {
    	if(error_handling){
        	TTCN_error("SDP EncDec:  %s in \"%s\" -> unexpected token at position %d",s,SDP_parse_text,chr_pos);
    	} else {
        	TTCN_warning("SDP EncDec:  %s in \"%s\" -> unexpected token at position %d",s,SDP_parse_text,chr_pos);
      	error_occured=1;
     	}
  }
	return 0;
}

%}

%option noyywrap
%option nounput

%x FIELD
%x A_FIELD
%x A_FIELD_VAL
%x KEY_FIELD
%x EMAIL_FIELD
%x C_FIELD
%x V_FIELD
%x S_FIELD
%x T_FIELD
%x AA_FIELD
%x A_MAXPRATE_F

%%

<INITIAL>"v=" {chr_pos+=SDP_parse_leng;BEGIN(V_FIELD);return VEQ;}
<INITIAL>"o=" {chr_pos+=SDP_parse_leng;BEGIN(T_FIELD);return OEQ;}
<INITIAL>"s=" {chr_pos+=SDP_parse_leng;BEGIN(S_FIELD);return SEQ;}
<INITIAL>"i=" {chr_pos+=SDP_parse_leng;BEGIN(S_FIELD);return IEQ;}
<INITIAL>"u=" {chr_pos+=SDP_parse_leng;BEGIN(S_FIELD);return UEQ;}
<INITIAL>"e=" {chr_pos+=SDP_parse_leng;BEGIN(EMAIL_FIELD);return EEQ;}
<INITIAL>"p=" {chr_pos+=SDP_parse_leng;BEGIN(FIELD);return PEQ;}
<INITIAL>"c=" {chr_pos+=SDP_parse_leng;BEGIN(C_FIELD);return CEQ;}
<INITIAL>"b=" {chr_pos+=SDP_parse_leng;BEGIN(A_FIELD);return BEQ;}
<INITIAL>"t=" {chr_pos+=SDP_parse_leng;BEGIN(T_FIELD);return TEQ;}
<INITIAL>"z=" {chr_pos+=SDP_parse_leng;BEGIN(V_FIELD);return ZEQ;}
<INITIAL>"r=" {chr_pos+=SDP_parse_leng;BEGIN(V_FIELD);return REQ;}
<INITIAL>"k=" {chr_pos+=SDP_parse_leng;BEGIN(A_FIELD);return KEQ;}
<INITIAL>"a=" {chr_pos+=SDP_parse_leng;BEGIN(AA_FIELD);return AEQ;}
<INITIAL>"m=" {chr_pos+=SDP_parse_leng;BEGIN(C_FIELD);return MEQ;}

<EMAIL_FIELD>[^ \r\n\0<>()]+\@[^ \r\n\0<>()]+ {
	chr_pos+=SDP_parse_leng;BEGIN(FIELD);
	SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text);
	return EMAIL;
}

<C_FIELD>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
"/" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SLASH;}
[^ \r\n/]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}
<T_FIELD>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
[^ \r\n]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}

<A_FIELD>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
":" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return COLON;}
[^ \r\n:]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}

<A_FIELD_VAL>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
[^ \r\n]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}

<A_MAXPRATE_F>{
"." {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return PERIOD;}
[^\r\n.]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}
<S_FIELD>{
[^\r\n]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text); return TOKEN;}
}


<V_FIELD>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
[-0-9]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.intnum = new INTEGER(SDP_parse_text); return INTTOKEN;}
[a-zA-Z]  {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return ALPHA;}
}

<FIELD,EMAIL_FIELD>{
"0" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 0; return _ZERO;}
"1" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 1; return _ONE;}
"2" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 2; return _TWO;}
"3" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 3; return _THREE;}
"4" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 4; return _FOUR;}
"5" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 5; return _FIVE;}
"6" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 6; return _SIX;}
"7" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 7; return _SEVEN;}
"8" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 8; return _EIGHT;}
"9" {chr_pos+=SDP_parse_leng;SDP_parse_lval.number = 9; return _NINE;}


[A-Za-z] {SDP_parse_lval.byte = *SDP_parse_text; return ALPHA;}
"_"	{chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return UNDERSCORE;}
"."	{chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return PERIOD;}
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
"(" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return LBRACE;}
")" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return RBRACE;}
"<" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return LT;}
">" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return GT;}
"+" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return PLUS;}
"-" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return HYPHEN;}
"/" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SLASH;}
":" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return COLON;}
"\0" {TTCN_error("Null byte in input string.");}
.	{chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return ANYBYTE;}
}

<AA_FIELD>{
" " {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; return SPACE;}
":" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text;  BEGIN(S_FIELD); return COLON;}
"cat:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CAT;}
"keywds:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_KEYWDS;}
"tool:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_TOOL;}
"ptime:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_PTIME;}
"recvonly" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_RECVONLY;}
"sendrecv" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_SENDRECV;}
"sendonly" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_SENDONLY;}
"orient:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_ORIENT;}
"type:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_TYPE;}
"charset:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CHARSET;}
"sdplang:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_SDLANG;}
"lang:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_LANG;}
"framerate:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FRAMERATE;}
"quality:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_QUALITY;}
"fmtp:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FMTP;}
"curr:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CURR;}
"des:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_DES;}
"conf:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CONF;}
"rtpmap:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_RTMAP;}
"rtcp:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_RTCP;}
"max-size:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_MAX_SIZE;}
"path:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_PATH;}
"accept-types:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_ACCEPT_TYPES;}
"accept-wrapped-types:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_ACCEPT_WRAPPED_TYPES;}
"maxprate:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_MAXPRATE_F); return A_MAXPRATE;}
"mid:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_MID;}
"group:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_GROUP;}
"file-selector:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_SELECTOR;}
"file-transfer-id:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_TRANSFER_ID;}
"inactive" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(C_FIELD); return A_INACTIVE;}
"setup:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_SETUP;}
"connection:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CONNECTION;}
"crypto:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CRYPTO;}

"content:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CONTENT;}
"label:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_LABEL;}
"floorctrl:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FLOORCTRL;}
"confid:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_CONFID;}
"userid:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_USERID;}
"floorid:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FLOORID;}
"fingerprint:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FINGERPRINT;}
"ice-ufrag:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_ICE_UFRAG;}
"ice-pwd:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_ICE_PWD;}
"candidate:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_CANDIDATE;}
"ice-lite" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_ICE_LITE;}
"ice-mismatch" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_ICE_MISMATCH;}
"remote-candidates:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_REMOTE_CANDIDATE;}
"ice-options:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_ICE_OPTIONS;}
"rtcp-fb:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_RTCP_FB;} 
"maxptime:" {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_MAXPTIME;}

"T38FaxVersion:"          {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_VERSION;}
"T38MaxBitRate:"          {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_BITRATE;}
"T38FaxFillBitRemoval:"   {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_BITREMOVAL;}
"T38FaxTranscodingMMR:"   {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_MMR;}
"T38FaxTranscodingJBIG:"  {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_JBIG;}
"T38FaxRateManagement:"   {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_RATEMANAGEMENT;}
"T38FaxMaxBuffer:"        {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_MAXBUFFER;}
"T38FaxMaxDatagram:"      {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_MAXDATAGRAM;}
"T38FaxMaxIFP:"           {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_IFP;}
"T38FaxUdpEC:"            {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_EC;}
"T38FaxUdpECDepth:"       {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_T38_ECDEPTH;}
"T38FaxUdpFECMaxSpan:"    {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_FEC;}
"T38VendorInfo:"          {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(A_FIELD_VAL); return A_T38_VENDORINFO;}
"T38ModemType:"           {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_T38_MODEM;} 

"file-disposition:"       {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_DISPOSITION;} 
"file-date:"              {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_DATE;} 
"file-icon:"              {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_ICON;} 
"file-range:"             {chr_pos+=SDP_parse_leng;SDP_parse_lval.byte = *SDP_parse_text; BEGIN(S_FIELD); return A_FILE_RANGE;} 

[^ \r\n:]+ {chr_pos+=SDP_parse_leng;SDP_parse_lval.t_charstring = new CHARSTRING(SDP_parse_leng, (const char*)SDP_parse_text);return TOKEN;}
}


<*>"\n" {chr_pos+=SDP_parse_leng;BEGIN(INITIAL); SDP_parse_lval.byte = *SDP_parse_text; return CRLF;}
<*>"\r\n" {chr_pos+=SDP_parse_leng;BEGIN(INITIAL); return CRLF;}


%%
/*user code*/

SDP__Message SDP__Types::f__SDP__dec__Message (const CHARSTRING& input) {

	SDP_parse__scan_bytes ((const char*)input, input.lengthof());
//	SDP_parse_debug=1;
	chr_pos=0;
	error_handling=1;
	SDP__Message parsed_msg;
	SDP_parse_set_parsed_message(&parsed_msg);
	
	SDP_parse_parse();
	
	
	return parsed_msg;
}

INTEGER SDP__Types::f__SDP__decodeMessage(const CHARSTRING& input, SDP__Types::SDP__Message& msg){

	SDP_parse__scan_bytes ((const char*)input, input.lengthof());
	
//	SDP_parse_debug=1;
	chr_pos=0;
	error_occured=0;
	error_handling=0;
	SDP_parse_set_parsed_message(&msg);
	
	SDP_parse_parse();
	yylex_destroy();
	
	
	return  error_occured;
;

}

