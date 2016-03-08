/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
******************************************************************************/
//
//  File:               SDP_EncDec.cc
//  Rev:                R12A
//  Prodnr:             CNL 113 353
//  Updated:            2012-02-07
//  Contact:            http://ttcn.ericsson.se
//  Reference:          ITU-T SDP
#include "SDP_Types.hh"

// function to encode SDP contact (email or telephone no)
namespace SDP__Types{

CHARSTRING enc_Message (const SDP__Message& message, bool RFC822Name = false)
{
    SDP__Message message2 = message;
    if(message2.emails().ispresent())
    {
        SDP__email__list& emails = message2.emails();
        for(int i = 0; i < emails.size_of(); i++)
        {
            if(emails[i].disp__name().ispresent())
            {
                if(!RFC822Name)
                {
                    //encode e=mjh@isi.edu (Mark Handley)
                    CHARSTRING& disp_name = emails[i].disp__name();
                    disp_name = " (" + disp_name + ")";
                }
                else
                {
                    //encode e=Mark Handley <mjh@isi.edu> by swapping the fields
                    CHARSTRING tmp = emails[i].addr__or__phone();
                    CHARSTRING& addr_or_phone = emails[i].addr__or__phone();
                    addr_or_phone = emails[i].disp__name();
                    CHARSTRING& disp_name = emails[i].disp__name();
                    disp_name = " <" + tmp + ">";
                }
            }
        }
    }
    if(message.phone__numbers().ispresent())
    {
        SDP__phone__list& phone_numbers = message2.phone__numbers();
        for(int i = 0; i < phone_numbers.size_of(); i++)
        {
            if(phone_numbers[i].disp__name().ispresent())
            {
                if(!RFC822Name)
                {
                    //encode e=mjh@isi.edu (Mark Handley)
                    CHARSTRING& disp_name = phone_numbers[i].disp__name();
                    disp_name = " (" + disp_name + ")";
                }
                else
                {
                    //encode e=Mark Handley <mjh@isi.edu> by swapping the fields
                    CHARSTRING tmp = phone_numbers[i].addr__or__phone();
                    CHARSTRING& addr_or_phone = phone_numbers[i].addr__or__phone();
                    addr_or_phone = phone_numbers[i].disp__name();
                    CHARSTRING& disp_name = phone_numbers[i].disp__name();
                    disp_name = " <" + tmp + ">";
                }
            }
        }
    }

    TTCN_Buffer bb;
    message2.encode(SDP__Message_descr_ , bb, TTCN_EncDec::CT_TEXT);

    return CHARSTRING (bb.get_len(),(char *)bb.get_data());
}

CHARSTRING f__SDP__enc__Message__RFC822Name (const SDP__Message& message)
{
    return enc_Message (message, true);
}

CHARSTRING f__SDP__enc__Message (const SDP__Message& message)
{
    return enc_Message (message, false);
}

SRTP__Crypto f__SDP__dec__SRTP__Crypto(const CHARSTRING& input)
{
if (TTCN_Logger::log_this_event(TTCN_Logger::DEBUG_ENCDEC)) {
TTCN_Logger::begin_event(TTCN_Logger::DEBUG_ENCDEC);
TTCN_Logger::log_event_str("f_SDP_dec_SRTP_Crypto(): Stream before decoding: ");
input.log();
TTCN_Logger::end_event();
}
TTCN_EncDec::set_error_behavior(TTCN_EncDec::ET_ALL, TTCN_EncDec::EB_DEFAULT);
TTCN_EncDec::clear_error();
TTCN_Buffer ttcn_buffer(input);
SRTP__Crypto ret_val;
ret_val.decode(SRTP__Crypto_descr_, ttcn_buffer, TTCN_EncDec::CT_TEXT);
if (TTCN_Logger::log_this_event(TTCN_Logger::DEBUG_ENCDEC)) {
TTCN_Logger::begin_event(TTCN_Logger::DEBUG_ENCDEC);
TTCN_Logger::log_event_str("f_SDP_dec_SRTP_Crypto(): Decoded @SDP_Types.SRTP_Crypto: ");
ret_val.log();
TTCN_Logger::end_event();
}
if (TTCN_EncDec::get_last_error_type() == TTCN_EncDec::ET_NONE) {
if (ttcn_buffer.get_pos() < ttcn_buffer.get_len()-1 && TTCN_Logger::log_this_event(TTCN_WARNING)) {
ttcn_buffer.cut();
CHARSTRING remaining_stream;
ttcn_buffer.get_string(remaining_stream);
TTCN_Logger::begin_event(TTCN_WARNING);
TTCN_Logger::log_event_str("f_SDP_dec_SRTP_Crypto(): Warning: Data remained at the end of the stream after successful decoding: ");
remaining_stream.log();
TTCN_Logger::end_event();
}
}
return ret_val;
}

TTCN_Module SDPEncDec("SDPEncDec", __DATE__, __TIME__);
}
