/******************************************************************************
* Copyright (c) 2016  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*  Mate Kovacs - initial implementation and initial documentation
******************************************************************************/
//
//  File:               CoAP_EncDec.cc
//  Rev:                R1A
//  Prodnr:             CNL 113 829

#include "CoAP_Types.hh"

namespace CoAP__Types {

int getOptionCode(CoAP__Options option);
int getOptionLength(CoAP__Options option);
int getIntegerLength(const long long int value, int mode);
void encodeInteger(TTCN_Buffer &stream, const long long int option, const int length);
long long int decodeInteger(OCTETSTRING const &str, const int position, const int length);

INTEGER
f__CoAP__dec(OCTETSTRING const &str, CoAP__Message &msg)
{
  if(TTCN_Logger::log_this_event(TTCN_DEBUG)){
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoding CoAP message: ");
    str.log();
    TTCN_Logger::end_event();
  }

  if(str.lengthof() >= 4){
    const unsigned char* str_ptr = (const unsigned char*) str;
    unsigned char chr;
    int position = 0;
    int token_length = 0;
    int actual_option_code = 0;
    int count_of_options = 0;
    bool payload_marker = false;

    //version, message type and token length
    chr = str_ptr[0];
    msg.msg().header().version() = chr >> 6;
    msg.msg().header().msg__type() = (chr >> 4) & 3;
    token_length = chr & 15;
    //code
    chr = str_ptr[1];
    msg.msg().header().code().class_() = (chr >> 5) & 7;
    msg.msg().header().code().detail() = chr & 31;
    //message ID
    msg.msg().header().message__id() = str_ptr[2] * 256 + str_ptr[3];

    if(str.lengthof() > 4 && msg.msg().header().code().class_() == 0 && msg.msg().header().code().detail() == 0){
	  msg.raw__message() = str;
	  return 1;
    }

    position = 4;
    //token
    if(token_length > 0){
      if(str.lengthof() >= position + token_length){
	    msg.msg().token() = OCTETSTRING(token_length, &str_ptr[position]);
	    position += token_length;
      }else{
        msg.raw__message() = str;
	    return 1;
	  }
    }else{
	  msg.msg().token() = OCTETSTRING(0, 0);
    }

    //options
    msg.msg().options() = OMIT_VALUE;
    if(str.lengthof() > 4){
      while(!payload_marker && str.lengthof() > position){
        int delta = str_ptr[position] >> 4;
	    int length = str_ptr[position] & 15;
	    if(delta == 15 && length != 15){
	      msg.raw__message() = str;
	      return 1;
	    }
        position++;
	    if(delta == 15 && length == 15){
	      payload_marker = true;
	    }else{
	      //optional delta
	      if(delta == 13){
	        delta = str_ptr[position] + 13;
		    position++;
	      }else if(delta == 14){
            delta = (str_ptr[position] << 8) + str_ptr[position+1] + 269;
	        position += 2;
	      }
	      //optional length
	      if(length == 13){
		    length = str_ptr[position] + 13;
		    position++;
	      }else if(length == 14){
		    length = (str_ptr[position] << 8) + str_ptr[position+1] + 269;
		    position += 2;
	      }else if(length == 15){
	        msg.raw__message() = str;
	        return 1;
	      }

	      //value
	      actual_option_code += delta;
	      switch(actual_option_code){
	      case 1:
	    	msg.msg().options()()[count_of_options].if__match() = OCTETSTRING(length, &str_ptr[position]);
		    break;
	      case 3:
	    	msg.msg().options()()[count_of_options].uri__host().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 4:
	    	msg.msg().options()()[count_of_options].etag() = OCTETSTRING(length, &str_ptr[position]);
		    break;
          case 5:
            msg.msg().options()()[count_of_options].if__none__match() = OCTETSTRING(0, 0);
		    break;
	      case 7:
		    msg.msg().options()()[count_of_options].uri__port().set_long_long_val(decodeInteger(str, position, length));
		    break;
	      case 8:
	    	msg.msg().options()()[count_of_options].location__path().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 11:
	    	msg.msg().options()()[count_of_options].uri__path().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 12:
	        msg.msg().options()()[count_of_options].content__format().set_long_long_val(decodeInteger(str, position, length));
	        break;
	      case 14:
		    msg.msg().options()()[count_of_options].max__age().set_long_long_val(decodeInteger(str, position, length));
	        break;
	      case 15:
	    	msg.msg().options()()[count_of_options].uri__query().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 17:
		    msg.msg().options()()[count_of_options].accept().set_long_long_val(decodeInteger(str, position, length));
		    break;
	      case 20:
	    	msg.msg().options()()[count_of_options].location__query().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 35:
	    	msg.msg().options()()[count_of_options].proxy__uri().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 39:
	    	msg.msg().options()()[count_of_options].proxy__scheme().decode_utf8(length, &str_ptr[position]);
		    break;
	      case 60:
		    msg.msg().options()()[count_of_options].size1().set_long_long_val(decodeInteger(str, position, length));
		    break;
	      default:
		    msg.msg().options()()[count_of_options].unknown__option().option__code() = actual_option_code;
		    msg.msg().options()()[count_of_options].unknown__option().option__value() = OCTETSTRING(length, &str_ptr[position]);
		    break;
	      }
	      position += length;
	      count_of_options++;
        }
      }
    }

    //payload
    if(str.lengthof() > position){
	  msg.msg().payload() = OCTETSTRING(str.lengthof() - position, &str_ptr[position]);
	  if(msg.msg().payload()().lengthof() == 0){
	    msg.raw__message() = str;
	    return 1;
	  }
    }else{
	  if(payload_marker){
	    msg.raw__message() = str;
	    return 1;
	  }else{
	    msg.msg().payload() = OMIT_VALUE;
	  }
    }
  }else{
    msg.raw__message() = str;
    return 1;
  }

  if(TTCN_Logger::log_this_event(TTCN_DEBUG)){
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Decoded CoAP message: ");
    msg.log();
    TTCN_Logger::end_event();
  }

  return 0;
}

INTEGER
f__CoAP__enc(CoAP__Message const &msg, OCTETSTRING &str)
{
  TTCN_Buffer stream;
  unsigned char chr = 0;

  if(TTCN_Logger::log_this_event(TTCN_DEBUG)){
    TTCN_Logger::begin_event(TTCN_DEBUG);
    TTCN_Logger::log_event("Encoding CoAP message: ");
    msg.log();
    TTCN_Logger::end_event();
  }

  switch(msg.get_selection()){
  case CoAP__Message::ALT_raw__message:
	  stream.put_os(msg.raw__message());
	  stream.get_string(str);
	  return 0;
	  break;
  case CoAP__Message::ALT_msg:
  default:
	  break;
  }

  //HEADER
    //version
  if(0 <= msg.msg().header().version() && msg.msg().header().version() <= 3){
    chr = msg.msg().header().version() << 6;
  }else{
	return 1;
  }
    //message type
  chr += msg.msg().header().msg__type() << 4;
    //tkl (token length)
  if(msg.msg().token().lengthof() >= 0 && msg.msg().token().lengthof() <= 8){
    chr += msg.msg().token().lengthof();
  }else{
	return 1;
  }
  stream.put_c(chr);
    //code
  if(msg.msg().header().code().class_() >= 0 && msg.msg().header().code().class_() <= 7){
    chr = msg.msg().header().code().class_() << 5;
  }else{
	return 1;
  }
  if(msg.msg().header().code().detail() >= 0 && msg.msg().header().code().detail() <= 31){
    chr += msg.msg().header().code().detail();
  }else{
	return 1;
  }
  stream.put_c(chr);
    //message ID
  if(msg.msg().header().message__id() >= 0 && msg.msg().header().message__id() <= 65535){
    encodeInteger(stream, msg.msg().header().message__id(), 2);
  }else{
	return 1;
  }

  //TOKEN
  stream.put_os(msg.msg().token());

  //OPTIONS
  if(msg.msg().options().ispresent() && msg.msg().options()().size_of() > 0){
	int optionOrder[msg.msg().options()().size_of()];
	int temp;
	for(int i = 0; i < msg.msg().options()().size_of(); i++){
		optionOrder[i] = i;
	}

	//determine the order of options
	for(int j = 0; j < msg.msg().options()().size_of()-1; j++){
      int minOptionCode = getOptionCode(msg.msg().options()()[optionOrder[j]]);
      int minOptionIndex = j;
      for(int i = j+1; i < msg.msg().options()().size_of(); i++){
        if(getOptionCode(msg.msg().options()()[optionOrder[i]]) < minOptionCode){
        	minOptionCode = getOptionCode(msg.msg().options()()[optionOrder[i]]);
        	minOptionIndex = i;
        }
      }
      temp = optionOrder[minOptionIndex];
      optionOrder[minOptionIndex] = optionOrder[j];
      optionOrder[j] = temp;
	}

	//encode options
	int previousOptionCode = 0;
	for(int i = 0; i < msg.msg().options()().size_of(); i++){
      int delta = getOptionCode(msg.msg().options()()[optionOrder[i]]) - previousOptionCode;
      int length = getOptionLength(msg.msg().options()()[optionOrder[i]]);

      previousOptionCode += delta;
      //first byte
      if(delta >= 0 && delta <= 12){
        chr = delta << 4;
      }else if(delta >= 13 && delta <= 268){
        chr = 13 << 4;
      }else if(delta >= 269 && delta <= 65535){
        chr = 14 << 4;
      }else{
    	return 1;
      }
      if(length >= 0 && length <= 12){
        chr += length;
	  }else if(length >= 13 && length <= 268){
	    chr += 13;
	  }else if(length >= 269 && length <= 65535){
	    chr += 14;
	  }else{
		return 1;
	  }
      stream.put_c(chr);

      //optional delta
      if(delta >= 13 && delta <= 268){
        chr = delta - 13;
        stream.put_c(chr);
      }else if(delta >= 269 && delta <= 65535){
        chr = (delta - 269) >> 8;
        stream.put_c(chr);
        chr = (delta - 269) & 255;
        stream.put_c(chr);
      }
      //optional length
      if(length >= 13 && length <= 268){
        chr = length - 13;
        stream.put_c(chr);
      }else if(length >= 269 && length <= 65535){
        chr = (length - 269) >> 8;
        stream.put_c(chr);
        chr = (length - 269) & 255;
        stream.put_c(chr);
      }
      //option value
      if(length > 0){
    	switch(msg.msg().options()()[optionOrder[i]].get_selection()){
    	  case CoAP__Options::ALT_if__match:
    		  stream.put_os(msg.msg().options()()[optionOrder[i]].if__match());
    	    break;
    	  case CoAP__Options::ALT_uri__host:
    		  msg.msg().options()()[optionOrder[i]].uri__host().encode_utf8(stream, false);
    	    break;
		  case CoAP__Options::ALT_etag:
			  stream.put_os(msg.msg().options()()[optionOrder[i]].etag());
			  break;
		  case CoAP__Options::ALT_if__none__match:
			  stream.put_os(msg.msg().options()()[optionOrder[i]].if__none__match());
			  break;
		  case CoAP__Options::ALT_uri__port:
			  encodeInteger(stream, msg.msg().options()()[optionOrder[i]].uri__port(), length);
			  break;
		  case CoAP__Options::ALT_location__path:
			  msg.msg().options()()[optionOrder[i]].location__path().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_uri__path:
			  msg.msg().options()()[optionOrder[i]].uri__path().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_content__format:
			  encodeInteger(stream, msg.msg().options()()[optionOrder[i]].content__format(), length);
			  break;
		  case CoAP__Options::ALT_max__age:
			  encodeInteger(stream, msg.msg().options()()[optionOrder[i]].max__age(), length);
			  break;
		  case CoAP__Options::ALT_uri__query:
			  msg.msg().options()()[optionOrder[i]].uri__query().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_accept:
			  encodeInteger(stream, msg.msg().options()()[optionOrder[i]].accept(), length);
			  break;
		  case CoAP__Options::ALT_location__query:
			  msg.msg().options()()[optionOrder[i]].location__query().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_proxy__uri:
			  msg.msg().options()()[optionOrder[i]].proxy__uri().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_proxy__scheme:
			  msg.msg().options()()[optionOrder[i]].proxy__scheme().encode_utf8(stream, false);
			  break;
		  case CoAP__Options::ALT_size1:
			  encodeInteger(stream, msg.msg().options()()[optionOrder[i]].size1(), length);
			  break;
		  case CoAP__Options::ALT_unknown__option:
			  stream.put_os(msg.msg().options()()[optionOrder[i]].unknown__option().option__value());
			  break;
		  case CoAP__Options::UNBOUND_VALUE:
		  default:
			return 8;
			break;
		}
      }
	}
  }

  //PAYLOAD
  if(msg.msg().payload().ispresent()){
    stream.put_c(255); //payload marker
    stream.put_os(msg.msg().payload()());
  }

  TTCN_Logger::begin_event(TTCN_DEBUG);
  TTCN_Logger::log_event("Encoded CoAP message: ");
  stream.log();
  TTCN_Logger::end_event();

  stream.get_string(str);

  return 0;
}

//helper functions
int getOptionCode(CoAP__Options option){
  switch(option.get_selection()){
    case CoAP__Options::ALT_if__match:
    	    return 1;
        break;
    case CoAP__Options::ALT_uri__host:
        	return 3;
        break;
    case CoAP__Options::ALT_etag:
        	return 4;
        break;
    case CoAP__Options::ALT_if__none__match:
        	return 5;
        break;
    case CoAP__Options::ALT_uri__port:
        	return 7;
        break;
    case CoAP__Options::ALT_location__path:
        	return 8;
        break;
    case CoAP__Options::ALT_uri__path:
        	return 11;
        break;
    case CoAP__Options::ALT_content__format:
        	return 12;
        break;
    case CoAP__Options::ALT_max__age:
        	return 14;
        break;
    case CoAP__Options::ALT_uri__query:
        	return 15;
        break;
    case CoAP__Options::ALT_accept:
        	return 17;
        break;
    case CoAP__Options::ALT_location__query:
        	return 20;
        break;
    case CoAP__Options::ALT_proxy__uri:
        	return 35;
        break;
    case CoAP__Options::ALT_proxy__scheme:
        	return 39;
        break;
    case CoAP__Options::ALT_size1:
        	return 60;
        break;
    case CoAP__Options::ALT_unknown__option:
        	return option.unknown__option().option__code();
        break;
    case CoAP__Options::UNBOUND_VALUE:
    default:
    	TTCN_error("CoAP: Error at getOptionCode!");
    	break;
  }
}

int getOptionLength(CoAP__Options option){
  switch(option.get_selection()){
    case CoAP__Options::ALT_if__match:
    	    return option.if__match().lengthof();
        break;
    case CoAP__Options::ALT_uri__host:
        	return option.uri__host().lengthof();
        break;
    case CoAP__Options::ALT_etag:
        	return option.etag().lengthof();
        break;
    case CoAP__Options::ALT_if__none__match:
        	return option.if__none__match().lengthof();
        break;
    case CoAP__Options::ALT_uri__port:
            return getIntegerLength(option.uri__port().get_long_long_val(), 2);
        break;
    case CoAP__Options::ALT_location__path:
        	return option.location__path().lengthof();
        break;
    case CoAP__Options::ALT_uri__path:
        	return option.uri__path().lengthof();
        break;
    case CoAP__Options::ALT_content__format:
    	return getIntegerLength(option.content__format().get_long_long_val(), 2);
        break;
    case CoAP__Options::ALT_max__age:
    	return getIntegerLength(option.max__age().get_long_long_val(), 4);
        break;
    case CoAP__Options::ALT_uri__query:
        	return option.uri__query().lengthof();;
        break;
    case CoAP__Options::ALT_accept:
    	return getIntegerLength(option.accept().get_long_long_val(), 2);
        break;
    case CoAP__Options::ALT_location__query:
        	return option.location__query().lengthof();
        break;
    case CoAP__Options::ALT_proxy__uri:
        	return option.proxy__uri().lengthof();
        break;
    case CoAP__Options::ALT_proxy__scheme:
        	return option.proxy__scheme().lengthof();
        break;
    case CoAP__Options::ALT_size1:
    	return getIntegerLength(option.size1().get_long_long_val(), 4);
        break;
    case CoAP__Options::ALT_unknown__option:
        	return option.unknown__option().option__value().lengthof();
        break;
    case CoAP__Options::UNBOUND_VALUE:
    default:
    	TTCN_error("CoAP: Error at getOptionLength!");
    	break;
  }
}

int getIntegerLength(const long long int value, int mode){
	if(value == 0){
	  return 0;
	}else if(value / 269 == 0){
	  return 1;
	}else if(value / 65805 == 0){
	  return 2;
	}else if(mode == 4 && value / 16777485 == 0){
      return 3;
	}else if(mode == 4 && value / 4294967296 == 0){
	  return 4;
	}else{
		TTCN_error("CoAP: Error at getIntegerLength!");
	}
}

void encodeInteger(TTCN_Buffer &stream, const long long int option, const int length){
  unsigned char chr;

  for(int i = length-1; i > 0; i--){
	  chr = (option >> (8 * i)) & 255;
	  stream.put_c(chr);
  }
  chr = option & 255;
  stream.put_c(chr);
}

long long int decodeInteger(OCTETSTRING const &str, const int position, const int length){
  int value = 0;

  for(int i = 0; i < length; i++){
	  value += (str[position+i].get_octet() << (8 * (length-i-1)));
  }
  return value;
}

}
