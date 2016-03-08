/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
******************************************************************************/
//
//  File:               SDP_parse_parse.h
//  Rev:                R12A
//  Prodnr:             CNL 113 353
//  Updated:            2012-02-07
//  Contact:            http://ttcn.ericsson.se
//  Reference:          ITU-T SDP
#ifndef SDP_parse_parser_H
#define SDP_parse_parser_H
#include "SDP_Types.hh"
int SDP_parse_parse();

SDP__Types::SDP__Message* SDP_parse_get_parsed_message();
void SDP_parse_set_parsed_message(SDP__Types::SDP__Message* pdu);

void sdplog(const char* fmt, ...);

int SDP_parse_lex();

int SDP_parse_error(const char *s);

#endif
