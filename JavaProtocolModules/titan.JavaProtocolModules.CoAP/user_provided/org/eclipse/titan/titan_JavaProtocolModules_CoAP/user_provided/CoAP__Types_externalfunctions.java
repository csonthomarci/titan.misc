package org.eclipse.titan.titan_JavaProtocolModules_CoAP.user_provided;

import org.eclipse.titan.runtime.core.Base_Template.template_sel;
import org.eclipse.titan.runtime.core.TTCN_Buffer;
import org.eclipse.titan.runtime.core.TTCN_Logger;
import org.eclipse.titan.runtime.core.TTCN_Logger.Severity;
import org.eclipse.titan.runtime.core.TitanCharString.CharCoding;
import org.eclipse.titan.runtime.core.TitanOctetString;
import org.eclipse.titan.runtime.core.TtcnError;
import org.eclipse.titan.titan_JavaProtocolModules_CoAP.generated.CoAP__Types.BlockOption;
import org.eclipse.titan.titan_JavaProtocolModules_CoAP.generated.CoAP__Types.CoAP__Message;
import org.eclipse.titan.titan_JavaProtocolModules_CoAP.generated.CoAP__Types.CoAP__Options;


public class CoAP__Types_externalfunctions {

	public static int f__CoAP__enc(CoAP__Message msg, TitanOctetString v__encoded) {
		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Encoding CoAP message: ");
			msg.log();
			TTCN_Logger.end_event();
		}
		TTCN_Buffer stream = new TTCN_Buffer();
		int chr = 0;
		switch(msg.get_selection()){
		case ALT_raw__message:
			stream.put_os(msg.get_field_raw__message());
			stream.get_string(v__encoded);
			return 0;
		case ALT_msg:
		default:
			break;
		}
		//HEADER
		//version
		if(msg.get_field_msg().get_field_header().get_field_version().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_header().get_field_version().is_less_than_or_equal(3)){
			chr = msg.get_field_msg().get_field_header().get_field_version().get_int() << 6;
		}else{
			return 1;
		}
		//message type
		chr += msg.get_field_msg().get_field_header().get_field_msg__type().as_int() << 4;
		//token length
		if(msg.get_field_msg().get_field_token().lengthof().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_token().lengthof().is_less_than_or_equal(8)){
			chr += msg.get_field_msg().get_field_token().lengthof().get_int();
		}else{
			return 1;
		}

		stream.put_c(Character.toChars(chr)[0]);
		//code
		if(msg.get_field_msg().get_field_header().get_field_code().get_field_class_().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_header().get_field_code().get_field_class_().is_less_than_or_equal(7)){
			chr = msg.get_field_msg().get_field_header().get_field_code().get_field_class_().get_int() << 5;
		}else{
			return 1;
		}
		if(msg.get_field_msg().get_field_header().get_field_code().get_field_detail().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_header().get_field_code().get_field_detail().is_less_than_or_equal(31)){
			chr += msg.get_field_msg().get_field_header().get_field_code().get_field_detail().get_int();
		}else{
			return 1;
		}
		stream.put_c(Character.toChars(chr)[0]);
		//message ID
		if(msg.get_field_msg().get_field_header().get_field_message__id().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_header().get_field_message__id().is_less_than_or_equal(65535)){
			encodeInteger(stream, msg.get_field_msg().get_field_header().get_field_message__id().get_int(), 2);
		}else{
			return 1;
		}
		//TOKEN
		stream.put_os(msg.get_field_msg().get_field_token());
		//OPTIONS
		if(msg.get_field_msg().get_field_options().ispresent() && msg.get_field_msg().get_field_options().get().size_of().is_greater_than(0)){
			int[] optionOrder = new int[msg.get_field_msg().get_field_options().get().size_of().get_int()];
			int temp;
			for(int i = 0; i < msg.get_field_msg().get_field_options().get().size_of().get_int(); i++){
				optionOrder[i] = i;
			}
			//determine the order of options
			for(int j = 0; j < msg.get_field_msg().get_field_options().get().size_of().get_int() - 1; j++){
				int minOptionCode = getOptionCode(msg.get_field_msg().get_field_options().get().get_at(optionOrder[j]));
				int minOptionIndex = j;
				for(int i = j+1; i < msg.get_field_msg().get_field_options().get().size_of().get_int(); i++){
					if(getOptionCode(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i])) < minOptionCode){
						minOptionCode = getOptionCode(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]));
						minOptionIndex = i;
					}
				}
				temp = optionOrder[minOptionIndex];
				optionOrder[minOptionIndex] = optionOrder[j];
				optionOrder[j] = temp;
			}
			//encode options
			int previousOptionCode = 0;
			for(int i = 0; i < msg.get_field_msg().get_field_options().get().size_of().get_int(); i++){
				int delta = getOptionCode(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i])) - previousOptionCode;
				int length = getOptionLength(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]));
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
				stream.put_c(Character.toChars(chr)[0]);
				//optional delta
				if(delta >= 13 && delta <= 268){
					chr = delta - 13;
					stream.put_c(Character.toChars(chr)[0]);
				}else if(delta >= 269 && delta <= 65535){
					chr = (delta - 269) >> 8;
				stream.put_c(Character.toChars(chr)[0]);
				chr = (delta - 269) & 255;
				stream.put_c(Character.toChars(chr)[0]);
				}
				//optional length
				if(length >= 13 && length <= 268){
					chr = length - 13;
					stream.put_c(Character.toChars(chr)[0]);
				}else if(length >= 269 && length <= 65535){
					chr = (length - 269) >> 8;
				stream.put_c(Character.toChars(chr)[0]);
				chr = (length - 269) & 255;
				stream.put_c(Character.toChars(chr)[0]);
				}
				//option value
				if(length > 0){
					switch(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_selection()){
					case ALT_if__match:
						stream.put_os(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_if__match());
						break;
					case ALT_uri__host:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_uri__host().encode_utf8(stream, false);
						break;
					case ALT_etag:
						stream.put_os(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_etag());
						break;
					case ALT_if__none__match:
						stream.put_os(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_if__none__match());
						break;
					case ALT_observe:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_observe().get_int(), length);
						break;
					case ALT_uri__port:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_uri__port().get_int(), length);
						break;
					case ALT_location__path:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_location__path().encode_utf8(stream, false);
						break;
					case ALT_uri__path:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_uri__path().encode_utf8(stream, false);
						break;
					case ALT_content__format:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_content__format().get_int(), length);
						break;
					case ALT_max__age:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_max__age().get_int(), length);
						break;
					case ALT_uri__query:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_uri__query().encode_utf8(stream, false);
						break;
					case ALT_accept:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_accept().get_int(), length);
						break;
					case ALT_location__query:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_location__query().encode_utf8(stream, false);
						break;
					case ALT_block1:
						encodeBlock(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_block1(), length);
						break;
					case ALT_block2:
						encodeBlock(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_block2(), length);
						break;
					case ALT_proxy__uri:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_proxy__uri().encode_utf8(stream, false);
						break;
					case ALT_proxy__scheme:
						msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_proxy__scheme().encode_utf8(stream, false);
						break;
					case ALT_size1:
						encodeInteger(stream, msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_size1().get_int(), length);
						break;
					case ALT_unknown__option:
						stream.put_os(msg.get_field_msg().get_field_options().get().get_at(optionOrder[i]).get_field_unknown__option().get_field_option__value());
						break;
					case UNBOUND_VALUE:
					default:
						return 8;
					}
				}
			}
		}

		//PAYLOAD
		if(msg.get_field_msg().get_field_payload().ispresent()){
			stream.put_c((char)255); //payload marker
			stream.put_os(msg.get_field_msg().get_field_payload().get());
		}

		TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
		TTCN_Logger.log_event("Encoded CoAP message: ");
		stream.log();
		TTCN_Logger.end_event();

		v__encoded.operator_assign(new TitanOctetString(stream.get_data()));

		return 0;
	}
	public static int f__CoAP__dec(TitanOctetString v__enc, CoAP__Message v__dec) {
		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Decoding CoAP message: ");
			v__enc.log();
			TTCN_Logger.end_event();
		}
		if(v__enc.lengthof().is_greater_than_or_equal(4)){
			int chr;
			int position = 0;
			int token_length = 0;
			int actual_option_code = 0;
			int count_of_options = 0;
			boolean payload_marker = false;
			//version, message type and token length
			chr = v__enc.get_nibble(0);
			v__dec.get_field_msg().get_field_header().get_field_version().operator_assign(chr >> 6);
			v__dec.get_field_msg().get_field_header().get_field_msg__type().operator_assign((chr >> 4) & 3);
			token_length = chr & 15;
			//code
			chr = v__enc.get_nibble(1);
			v__dec.get_field_msg().get_field_header().get_field_code().get_field_class_().operator_assign((chr >> 5) & 7);
			v__dec.get_field_msg().get_field_header().get_field_code().get_field_detail().operator_assign(chr & 31);
			//message ID
			v__dec.get_field_msg().get_field_header().get_field_message__id().operator_assign(v__enc.get_nibble(2) * 256 + v__enc.get_nibble(3));
			if(v__enc.lengthof().is_greater_than(4) && v__dec.get_field_msg().get_field_header().get_field_code().get_field_class_().operator_equals(0) && v__dec.get_field_msg().get_field_header().get_field_code().get_field_detail().operator_equals(0)) {
				v__dec.get_field_raw__message().operator_assign(v__enc);
				return 1;
			}
			position = 4;
			//token
			if(token_length > 0){
				if(v__enc.lengthof().is_greater_than_or_equal(position + token_length)) {
					v__dec.get_field_msg().get_field_token().operator_assign(new TitanOctetString(v__enc.get_nibble(position)));
					position += token_length;
				}else{
					v__dec.get_field_raw__message().operator_assign(v__enc);
					return 1;
				}
			}else{
				v__dec.get_field_msg().get_field_token().operator_assign(new TitanOctetString(""));
			}
			//options
			v__dec.get_field_msg().get_field_options().operator_assign(template_sel.OMIT_VALUE);
			if(v__enc.lengthof().is_greater_than(4)) {
				while(!payload_marker && v__enc.lengthof().is_greater_than(position)) {
					char d = v__enc.get_nibble(position);
					int delta = d >> 4;
					int length = v__enc.get_nibble(position) & 15;
					if(delta == 15 && length != 15){
						v__dec.get_field_raw__message().operator_assign(v__enc);
						return 1;
					}
					position++;
					if(delta == 15 && length == 15){
						payload_marker = true;
					}else{
						//optional delta
						if(delta == 13){
							delta = v__enc.get_nibble(position) + 13;
							position++;
						}else if(delta == 14){
							delta = (v__enc.get_nibble(position) << 8) + v__enc.get_nibble(position+1) + 269;
							position += 2;
						}
						//optional length
						if(length == 13){
							length = v__enc.get_nibble(position) + 13;
							position++;
						}else if(length == 14){
							length = (v__enc.get_nibble(position) << 8) + v__enc.get_nibble(position + 1) + 269;
							position += 2;
						}else if(length == 15){
							v__dec.get_field_raw__message().operator_assign(v__enc);
							return 1; //void function cannot return
						}
				//value
						actual_option_code += delta;
						switch(actual_option_code){
						case 1:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_if__match().operator_assign(new TitanOctetString(v__enc.get_nibble(position)));
							break;
						case 3:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_uri__host().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 4:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_etag().operator_assign(new TitanOctetString(subCharArray(position, length, v__enc.get_value())));
							break;
						case 5:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_if__none__match().operator_assign(new TitanOctetString(""));
							break;
						case 6:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_observe().operator_assign(decodeInteger(v__enc, position, length));
							break;
						case 7:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_uri__port().operator_assign(decodeInteger(v__enc, position, length));
							break;
						case 8:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_location__path().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 11:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_uri__path().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 12:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_content__format().operator_assign(decodeInteger(v__enc, position, length));
							break;
						case 14:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_max__age().operator_assign(decodeInteger(v__enc, position, length));
							break;
						case 15:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_uri__query().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 17:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_accept().operator_assign(decodeInteger(v__enc, position, length));
							break;
						case 20:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_location__query().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 23: // Block2 RFC 7959
							decodeBlock(v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_block2(), v__enc, position, length);
							break;
						case 27: // Block1 RFC 7959
							decodeBlock(v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_block1(), v__enc, position, length);
							break;
						case 35:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_proxy__uri().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 39:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_proxy__scheme().decode_utf8(subCharArray(position, length, v__enc.get_value()), CharCoding.UTF_8, false);
							break;
						case 60:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_size1().operator_assign(decodeInteger(v__enc, position, length));
							break;
						default:
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_unknown__option().get_field_option__code().operator_assign(actual_option_code);
							v__dec.get_field_msg().get_field_options().get().get_at(count_of_options).get_field_unknown__option().get_field_option__value().operator_assign(new TitanOctetString(subCharArray(position, length, v__enc.get_value())));
							break;
						}
						position += length;
						count_of_options++;
					}
				}
			}
			//payload
			if(v__enc.lengthof().is_greater_than(position)) {
				char[] enc = v__enc.get_value();
				char[] pl = new char[enc.length-position];

				System.arraycopy(enc, position, pl, 0, enc.length-position);

				v__dec.get_field_msg().get_field_payload().operator_assign(new TitanOctetString(pl));
				if(v__dec.get_field_msg().get_field_payload().get().lengthof().operator_equals(0)) { 
					v__dec.get_field_raw__message().operator_assign(v__enc);
					return 1;
				}
			} else {
				if(payload_marker){
					v__dec.get_field_raw__message().operator_assign(v__enc);
					return 1;
				}else{
					v__dec.get_field_msg().get_field_payload().operator_assign(template_sel.OMIT_VALUE);
				}
			}
		} else{
			v__dec.get_field_raw__message().operator_assign(v__enc);
			return 1;
		}
		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Decoded CoAP message: ");
			v__enc.log();
			TTCN_Logger.end_event();
		}
		return 0;
	}

	private static int decodeInteger(TitanOctetString str, int position, int length) {
		int value = 0;
		for(int i = 0; i < length; i++) {
			value += (str.get_nibble(position + i) << (8 * (length-i-1)));
		}

		return value;
	}

	private static void decodeBlock(BlockOption block, TitanOctetString str, int position, int length) {
		int num = 0;
		for(int i = 0; i < length-1; i++) {
			num += (str.get_nibble(position + i) << (8 * (length-i-1) - 4));
		}
		num += (str.get_nibble(position + length-1) >> 4) & 0x0f;
		int szx = 0;
		szx = str.get_nibble(position + length - 1) & 0x07;
		int m = 0;
		m = str.get_nibble(position+length - 1) & 0x08;
		block.get_field_num().operator_assign(num);
		block.get_field_szx().operator_assign(szx);
		block.get_field_m().operator_assign(intToBoolean(m));
	}
	private static boolean intToBoolean(int value) {
		return value > 0 ? true : false;
	}

	private static void encodeInteger(TTCN_Buffer stream, final int option, final int length){
		int chr;
		for(int i = length-1; i > 0; i--){
			chr = (option >> (8 * i)) & 255;
			stream.put_c(Character.toChars(chr)[0]);
		}
		chr = option & 255;
		stream.put_c(Character.toChars(chr)[0]);
	}

	private static int getOptionCode(CoAP__Options option){
		switch(option.get_selection()){
		case ALT_if__match:
			return 1;
		case ALT_uri__host:
			return 3;
		case ALT_etag:
			return 4;
		case ALT_if__none__match:
			return 5;
		case ALT_observe:
			return 6;
		case ALT_uri__port:
			return 7;
		case ALT_location__path:
			return 8;
		case ALT_uri__path:
			return 11;
		case ALT_content__format:
			return 12;
		case ALT_max__age:
			return 14;
		case ALT_uri__query:
			return 15;
		case ALT_accept:
			return 17;
		case ALT_location__query:
			return 20;
		case ALT_block1: // RFC 7959
			return 27;
		case ALT_block2: // RFC 7959
			return 23;
		case ALT_proxy__uri:
			return 35;
		case ALT_proxy__scheme:
			return 39;
		case ALT_size1:
			return 60;
		case ALT_unknown__option:
			return option.get_field_unknown__option().get_field_option__code().get_int();
		case UNBOUND_VALUE:
		default:
			throw new TtcnError("CoAP: Error at getOptionCode!");
		}
	}
	private static int getOptionLength(CoAP__Options option){
		switch(option.get_selection()){
		case ALT_if__match:
			return option.get_field_if__match().lengthof().get_int();
		case ALT_uri__host:
			return option.get_field_uri__host().lengthof().get_int();
		case ALT_etag:
			return option.get_field_etag().lengthof().get_int();
		case ALT_if__none__match:
			return option.get_field_if__none__match().lengthof().get_int();
		case ALT_observe:
			return get_integerLength(option.get_field_observe().get_long(), 3);
		case ALT_uri__port:
			return get_integerLength(option.get_field_uri__port().get_long(), 2);
		case ALT_location__path:
			return option.get_field_location__path().lengthof().get_int();
		case ALT_uri__path:
			return option.get_field_uri__path().lengthof().get_int();
		case ALT_content__format:
			return get_integerLength(option.get_field_content__format().get_long(), 2);
		case ALT_max__age:
			return get_integerLength(option.get_field_max__age().get_long(), 4);
		case ALT_uri__query:
			return option.get_field_uri__query().lengthof().get_int();
		case ALT_accept:
			return get_integerLength(option.get_field_accept().get_long(), 2);
		case ALT_location__query:
			return option.get_field_location__query().lengthof().get_int();
		case ALT_block1:
			return getBlockLengthForNum(option.get_field_block1().get_field_num().get_long());
		case ALT_block2:
			return getBlockLengthForNum(option.get_field_block2().get_field_num().get_long());
		case ALT_proxy__uri:
			return option.get_field_proxy__uri().lengthof().get_int();
		case ALT_proxy__scheme:
			return option.get_field_proxy__scheme().lengthof().get_int();
		case ALT_size1:
			return get_integerLength(option.get_field_size1().get_long(), 4);
		case ALT_unknown__option:
			return option.get_field_unknown__option().get_field_option__value().lengthof().get_int();
		case UNBOUND_VALUE:
		default:
			throw new TtcnError("CoAP: Error at getOptionLength!");
		}
	}
	private static int get_integerLength(final long value, int mode){
		if(value == 0){
			return 0;
		}else if(value / 269.0 == 0){
			return 1;
		}else if(value / 65805.0 == 0){
			return 2;
		}else if(mode == 4 && value / 16777485.0 == 0){
			return 3;
		}else if(mode == 4 && value / 4294967296L == 0){
			return 4;
		}else{
			throw new TtcnError("CoAP: Error at get_integerLength!");
		}
	}

	// RFC 7959
	private static int getBlockLengthForNum(final long num) {
		if (num < 0 || num > 1048575)
			throw new TtcnError("CoAP: Error at getBlockLengthForNum: num must larger than 0 and smaller than 1048576!");
		if (num <= 15) { // 2^4-1
			return 1;
		}
		else if (num <= 1023) { // 2^10-1
			return 2;
		}
		else if (num <= 1048575) { // 2^20-1
			return 3;
		}
		return 0;
	}
	// RFC 7959
	private static void encodeBlock(TTCN_Buffer stream, final BlockOption option, final int length) {
		int chr;
		int num_val = option.get_field_num().get_int();
		int szx;
		szx = option.get_field_szx().get_int() & 0x07; // szx_val & 00000111b
		char m;
		if (option.get_field_m().get_value())
			m = 0x08; // 00001000b
		else
			m = 0x00; // 00000000b
		int num;
		for(int i = length-1; i > 0; i--){
			num = (num_val >> (8 * i - 4)) & 0xff;
			stream.put_c(Character.toChars(num)[0]);			
		}
		num = (num_val << 4) & 0xf0; // num_val & 11110000b
		chr = num | m | szx;
		stream.put_c(Character.toChars(chr)[0]);
	}
	
	private static char[] subCharArray(int start, int length, final char[] in) {
		char[] subChrArray = new char[length];
		
		for (int i = 0; i<length; i++) {
			subChrArray[i] = in[start + i];
		}
		return subChrArray;
	}
}