package org.eclipse.titan.titan_JavaProtocolModules_MQTT.user_provided;

import org.eclipse.titan.runtime.core.Base_Template.template_sel;
import org.eclipse.titan.runtime.core.TTCN_Buffer;
import org.eclipse.titan.runtime.core.TTCN_Logger;
import org.eclipse.titan.runtime.core.TTCN_Logger.Severity;
import org.eclipse.titan.runtime.core.TitanBitString;
import org.eclipse.titan.runtime.core.TitanCharString.CharCoding;
import org.eclipse.titan.runtime.core.TitanNull_Type;
import org.eclipse.titan.runtime.core.TitanOctetString;
import org.eclipse.titan.runtime.core.TitanUniversalCharString;
import org.eclipse.titan.titan_JavaProtocolModules_MQTT.generated.MQTT__v3__1__1__Types.BIT4n;
import org.eclipse.titan.titan_JavaProtocolModules_MQTT.generated.MQTT__v3__1__1__Types.MQTT__v3__1__1__Message;
import org.eclipse.titan.titan_JavaProtocolModules_MQTT.generated.MQTT__v3__1__1__Types.MQTT__v3__1__1__SubscribePayloadList;
import org.eclipse.titan.titan_JavaProtocolModules_MQTT.generated.MQTT__v3__1__1__Types.QoS;
import org.eclipse.titan.titan_JavaProtocolModules_MQTT.generated.MQTT__v3__1__1__Types.UCHAR0__65535List;

public class MQTT__v3__1__1__Types_externalfunctions {

	public static int f__MQTT__v3__1__1__enc(MQTT__v3__1__1__Message msg, TitanOctetString v__encoded) {

		TTCN_Buffer stream_beginning = new TTCN_Buffer();
		TTCN_Buffer stream = new TTCN_Buffer();
		int chr = 0;
		int length = 0;

		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Encoding MQTT 3.1.1 message: ");
			msg.log();
			TTCN_Logger.end_event();
		}  

		switch(msg.get_selection()){
		case ALT_raw__message:
			stream.put_os(msg.get_field_raw__message());
			stream.get_string(v__encoded);
			return 0;
		case ALT_msg:
		default:
			break;
		}

		switch(msg.get_field_msg().get_selection()){
		case ALT_connect__msg:
			chr = 1 << 4;
			if(msg.get_field_msg().get_field_connect__msg().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_connect__msg().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodeUtf8(stream, msg.get_field_msg().get_field_connect__msg().get_field_name(), length) != 0){
				return 1;
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_protocol__level().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_connect__msg().get_field_protocol__level().is_less_than_or_equal(255)){
				chr = msg.get_field_msg().get_field_connect__msg().get_field_protocol__level().get_int();
				stream.put_c(Character.toChars(chr)[0]);
				length++;
			}else{
				return 1;
			}
			//flags
			if(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_user__name__flag().lengthof().operator_equals(1) && msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_password__flag().lengthof().operator_equals(1) &&
					msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__retain().lengthof().operator_equals(1) && msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__flag().lengthof().operator_equals(1) &&
					msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_clean__session().lengthof().operator_equals(1)) {
				
				
				chr = boolToInt(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_user__name__flag().get_at(0).get_bit()) << 7;
				chr += boolToInt(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_password__flag().get_at(0).get_bit()) << 6;
				chr += boolToInt(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__retain().get_at(0).get_bit()) << 5;
				chr += msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__qos().as_int() << 3;
				chr += boolToInt(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__flag().get_at(0).get_bit()) << 2;
				chr += boolToInt(msg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_clean__session().get_at(0).get_bit()) << 1;
				stream.put_c(Character.toChars(chr)[0]);
				length++;
			}else{
				return 1;
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_keep__alive().is_greater_than_or_equal(0) && msg.get_field_msg().get_field_connect__msg().get_field_keep__alive().is_less_than_or_equal(65535)){
				chr = msg.get_field_msg().get_field_connect__msg().get_field_keep__alive().get_int() >> 8;
				stream.put_c(Character.toChars(chr)[0]);
				chr = msg.get_field_msg().get_field_connect__msg().get_field_keep__alive().get_int();
				stream.put_c(Character.toChars(chr)[0]);
				length += 2;
			}else{
				return 1;
			}
			//payload
			if(encodeUtf8(stream, msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_client__identifier(), length) != 0){
				return 1;
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__topic().ispresent()){
				if(encodeUtf8(stream, msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__topic().get(), length) != 0){
					return 1;
				}
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__message().ispresent()){
				if(encodeOctetstring(stream, msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__message().get(), length) != 0){
					return 1;
				}
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_user__name().ispresent()){
				if(encodeUtf8(stream, msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_user__name().get(), length) != 0){
					return 1;
				}
			}
			if(msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_password().ispresent()){
				if(encodeOctetstring(stream, msg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_password().get(), length) != 0){
					return 1;
				}
			}
			break;
		case ALT_connack:
			chr = 2 << 4;
			if(msg.get_field_msg().get_field_connack().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_connack().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(msg.get_field_msg().get_field_connack().get_field_session__present__flag().lengthof().operator_equals(1)){
				chr = boolToInt(msg.get_field_msg().get_field_connack().get_field_session__present__flag().get_at(0).get_bit());
				stream.put_c(Character.toChars(chr)[0]);
				length++;
			}else{
				return 1;
			}
			if(msg.get_field_msg().get_field_connack().get_field_connect__return__code().get_int() < 0 || 255 < msg.get_field_msg().get_field_connack().get_field_connect__return__code().get_int()){
				return 1;
			}
			chr = msg.get_field_msg().get_field_connack().get_field_connect__return__code().get_int();
			stream.put_c(Character.toChars(chr)[0]);
			length++;
			break;
		case ALT_publish:
			int tmp;
			chr = 3 << 4;
			if(msg.get_field_msg().get_field_publish().get_field_header().get_field_dup__flag().lengthof().operator_equals(1) && msg.get_field_msg().get_field_publish().get_field_header().get_field_retain__flag().lengthof().operator_equals(1)){
				tmp = boolToInt(msg.get_field_msg().get_field_publish().get_field_header().get_field_dup__flag().get_at(0).get_bit());
				chr += tmp << 3;
				chr += msg.get_field_msg().get_field_publish().get_field_header().get_field_qos__level().as_int() << 1;
				tmp = boolToInt(msg.get_field_msg().get_field_publish().get_field_header().get_field_retain__flag().get_at(0).get_bit());
				chr += tmp;
			}else{
				return 1;
			}
			stream_beginning.put_c(Character.toChars(chr)[0]);
			//variable header
			if(encodeUtf8(stream, msg.get_field_msg().get_field_publish().get_field_topic__name(), length) != 0){
				return 1;
			}
			if(msg.get_field_msg().get_field_publish().get_field_packet__identifier().is_present()){
				if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_publish().get_field_packet__identifier().get().get_int(), length) != 0){
					return 1;
				}
			}
			//payload
			stream.put_os(msg.get_field_msg().get_field_publish().get_field_payload());
			length += msg.get_field_msg().get_field_publish().get_field_payload().lengthof().get_int();
			break;
		case ALT_puback:
			chr = 4 << 4;
			if(msg.get_field_msg().get_field_puback().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_puback().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_puback().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			break;
		case ALT_pubrec:
			chr = 5 << 4;
			if(msg.get_field_msg().get_field_pubrec().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_pubrec().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}

			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_pubrec().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			break;
		case ALT_pubrel:
			chr = 6 << 4;
			if(msg.get_field_msg().get_field_pubrel().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_pubrel().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_pubrel().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			break;
		case ALT_pubcomp:
			chr = 7 << 4;
			if(msg.get_field_msg().get_field_pubcomp().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_pubcomp().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_pubcomp().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			break;
		case ALT_subscribe:
			chr = 8 << 4;
			if(msg.get_field_msg().get_field_subscribe().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_subscribe().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_subscribe().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			//payload
			for(int i = 0; msg.get_field_msg().get_field_subscribe().get_field_payload().size_of().is_greater_than(i); i++){
				if(encodeUtf8(stream, msg.get_field_msg().get_field_subscribe().get_field_payload().get_at(i).get_field_topic__filter(), length) != 0){
					return 1;
				}
				chr = msg.get_field_msg().get_field_subscribe().get_field_payload().get_at(i).get_field_requested__qos().as_int();
				stream.put_c(Character.toChars(chr)[0]);
				length++;
			}
			break;
		case ALT_suback:
			chr = 9 << 4;
			if(msg.get_field_msg().get_field_suback().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_suback().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_suback().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			//payload
			for(int i = 0; msg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().size_of().is_greater_than(i); i++){
				if(msg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().get_at(i).is_less_than(0) || msg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().get_at(i).is_greater_than(255)){
					return 1;
				}
				chr = msg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().get_at(i).get_int();
				stream.put_c(Character.toChars(chr)[0]);
				length++;
			}
			break;
		case ALT_unsubscribe:
			chr = 10 << 4;
			if(msg.get_field_msg().get_field_unsubscribe().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_unsubscribe().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_unsubscribe().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			//payload
			for(int i = 0; msg.get_field_msg().get_field_unsubscribe().get_field_payload().get_field_topic__filter().size_of().is_greater_than(i); i++){
				if(encodeUtf8(stream, msg.get_field_msg().get_field_unsubscribe().get_field_payload().get_field_topic__filter().get_at(i), length) != 0){
					return 1;
				}
			}
			break;
		case ALT_unsuback:
			chr = 11 << 4;
			if(msg.get_field_msg().get_field_unsuback().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_unsuback().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			//variable header
			if(encodePacketIdentifier(stream, msg.get_field_msg().get_field_unsuback().get_field_packet__identifier().get_int(), length) != 0){
				return 1;
			}
			break;
		case ALT_pingreq:
			chr = 12 << 4;
			if(msg.get_field_msg().get_field_pingreq().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_pingreq().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			break;
		case ALT_pingresp:
			chr = 13 << 4;
			if(msg.get_field_msg().get_field_pingresp().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_pingresp().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			break;
		case ALT_disconnect__msg:
			chr = 14 << 4;
			if(msg.get_field_msg().get_field_disconnect__msg().get_field_header().get_field_flags().lengthof().operator_equals(4)){
				chr += encodeFlags((BIT4n) msg.get_field_msg().get_field_disconnect__msg().get_field_header().get_field_flags());
				stream_beginning.put_c(Character.toChars(chr)[0]);
			}else{
				return 1;
			}
			break;
		default:
			return 1;
		}
		
		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Encoded MQTT 3.1.1 message: ");
			stream_beginning.log();
			TTCN_Logger.end_event();
		}  

		//set packet length
		do{
			int encodedByte = length % 128;
			length /= 128;
			if(length > 0){
				encodedByte = encodedByte | 128;
			}
			stream_beginning.put_c(Character.toChars(encodedByte)[0]);
		}while(length > 0);
		stream_beginning.put_buf(stream);
		stream_beginning.get_string(v__encoded);

		return 0;
	}

	public static int f__MQTT__v3__1__1__dec(TitanOctetString str, MQTT__v3__1__1__Message v__mqttMsg) {
		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Encoding MQTT 3.1.1 message: ");
			str.log();
			TTCN_Logger.end_event();
		}

		if(str.lengthof().is_greater_than_or_equal(2)){
			final int[] lookup = new int[] {
					0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
					0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf};
			int packetType = str.get_value()[0] >> 4;
			int bitstr = lookup[str.get_value()[0] & 15];
			int position = 1;
			int prePosition = 1;
			int count = 0;
			int multiplier = 1;
			int length = 0;
			int encodedByte;
			int tmpLength;
			int flag;

			//get packet length
			do{
				if(str.lengthof().is_less_than(position)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				encodedByte = str.get_value()[position];
				length += (encodedByte & 127) * multiplier;
				multiplier *= 128;
				if(multiplier > 128*128*128){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				position++;
				prePosition++;
			}while((encodedByte & 128) != 0);

			switch(packetType){
			case 1:
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
				if(str.lengthof().is_less_than(position+1)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+8+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_name().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
				position += 2+tmpLength;
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_protocol__level().operator_assign(decodeInteger(str, position, 1));
				position++;
				//flags
				flag = (str.get_value()[position] & 128) >> 7;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_user__name__flag().operator_assign(new TitanBitString(str.get_nibble(flag)));
			flag = (str.get_value()[position] & 64) >> 6;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_password__flag().operator_assign(new TitanBitString(str.get_nibble(flag)));
			flag = (str.get_value()[position] & 32) >> 5;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__retain().operator_assign(new TitanBitString(str.get_nibble(flag)));
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__qos().operator_assign((str.get_value()[position] >> 3) & 3);
			flag = (str.get_value()[position] & 4) >> 2;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__flag().operator_assign(new TitanBitString(str.get_nibble(flag)));
			flag = (str.get_value()[position] & 2) >> 1;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_clean__session().operator_assign(new TitanBitString(str.get_nibble(flag)));
			position++;
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_keep__alive().operator_assign(decodeInteger(str, position, 2));
			position += 2;
			//payload
			tmpLength = decodeInteger(str, position, 2);
			if(str.lengthof().is_less_than(position+2+tmpLength)){
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_client__identifier().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
			position += 2+tmpLength;
			if(boolToInt(v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_will__flag().get_at(0).get_bit()) == 1) {
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+4+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__topic().get().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
				position += 2+tmpLength;

				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+2+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__message().get().operator_assign(new TitanOctetString(str.get_value()[position+2]));
				position += 2+tmpLength;
			}else{
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__topic().operator_assign(template_sel.OMIT_VALUE);
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_will__message().operator_assign(template_sel.OMIT_VALUE);
			}
			if(boolToInt(v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_user__name__flag().get_at(0).get_bit()) == 1) {
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+2+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_user__name().get().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
				position += 2+tmpLength;
			}else{
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_user__name().operator_assign(template_sel.OMIT_VALUE);
			}
			if(boolToInt(v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_flags().get_field_password__flag().get_at(0).get_bit()) == 1) {
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+2+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_password().get().operator_assign(new TitanOctetString(str.get_value()[position+2]));
				position += 2+tmpLength;
			}else{
				v__mqttMsg.get_field_msg().get_field_connect__msg().get_field_payload().get_field_password().operator_assign(template_sel.OMIT_VALUE);
			}
			break;
		case 2:
			v__mqttMsg.get_field_msg().get_field_connack().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				bitstr = str.get_value()[position] & 1;
				v__mqttMsg.get_field_msg().get_field_connack().get_field_session__present__flag().operator_assign(new TitanBitString(str.get_nibble(bitstr))); 
				v__mqttMsg.get_field_msg().get_field_connack().get_field_connect__return__code().operator_assign(decodeInteger(str, position+1, 1));
				position += 2;
			}
			break;
		case 3:
			v__mqttMsg.get_field_msg().get_field_publish().get_field_header().get_field_dup__flag().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			v__mqttMsg.get_field_msg().get_field_publish().get_field_header().get_field_qos__level().operator_assign(lookup[bitstr & 6] >> 1);
			flag = (bitstr >> 3) & 1;
			v__mqttMsg.get_field_msg().get_field_publish().get_field_header().get_field_retain__flag().operator_assign(new TitanBitString(str.get_nibble(flag)));
			if(str.lengthof().is_less_than(position+2)){
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			tmpLength = decodeInteger(str, position, 2);
			if(str.lengthof().is_less_than(position+2+tmpLength)){
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			v__mqttMsg.get_field_msg().get_field_publish().get_field_topic__name().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
			position += 2+tmpLength;
			if((v__mqttMsg.get_field_msg().get_field_publish().get_field_header().get_field_qos__level().operator_equals(QoS.enum_type.AT__LEAST__ONCE__DELIVERY)) || (v__mqttMsg.get_field_msg().get_field_publish().get_field_header().get_field_qos__level().operator_equals(QoS.enum_type.EXACTLY__ONE__DELIVERY) && str.lengthof().is_greater_than_or_equal(position+2))){
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_publish().get_field_packet__identifier().get().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_msg().get_field_publish().get_field_packet__identifier().operator_assign(template_sel.OMIT_VALUE);
			}
			v__mqttMsg.get_field_msg().get_field_publish().get_field_payload().operator_assign(new TitanOctetString(str.get_value()[position]));
			position += (length - position + prePosition);
			break;
		case 4:
			v__mqttMsg.get_field_msg().get_field_puback().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_puback().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			break;
		case 5:
			v__mqttMsg.get_field_msg().get_field_pubrec().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_pubrec().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			break;
		case 6:
			v__mqttMsg.get_field_msg().get_field_pubrel().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_pubrel().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			break;
		case 7:
			v__mqttMsg.get_field_msg().get_field_pubcomp().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_pubcomp().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			break;
		case 8:
			v__mqttMsg.get_field_msg().get_field_subscribe().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_subscribe().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			while(str.lengthof().is_greater_than(position)){
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+3+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_subscribe().get_field_payload().get_at(count).get_field_topic__filter().decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
				v__mqttMsg.get_field_msg().get_field_subscribe().get_field_payload().get_at(count).get_field_requested__qos().operator_assign(str.get_value()[position+tmpLength+2]);
				count++;
				position += 3+tmpLength;
			}
			if(count == 0){
				v__mqttMsg.get_field_msg().get_field_subscribe().get_field_payload().operator_assign(new MQTT__v3__1__1__SubscribePayloadList(TitanNull_Type.NULL_VALUE));
			}
			break;
		case 9:
			v__mqttMsg.get_field_msg().get_field_suback().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_suback().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			while(str.lengthof().is_greater_than(position)){
				if(str.lengthof().is_less_than(position+1)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().get_at(count).operator_assign(decodeInteger(str, position, 1));
				count++;
				position++;
			}
			if(count == 0){
				v__mqttMsg.get_field_msg().get_field_suback().get_field_payload().get_field_return__code().operator_assign(new MQTT__v3__1__1__SubscribePayloadList(TitanNull_Type.NULL_VALUE));
			}
			break;
		case 10:
			v__mqttMsg.get_field_msg().get_field_unsubscribe().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_unsubscribe().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			while(str.lengthof().is_greater_than(position)){
				if(str.lengthof().is_less_than(position+2)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				tmpLength = decodeInteger(str, position, 2);
				if(str.lengthof().is_less_than(position+2+tmpLength)){
					v__mqttMsg.get_field_raw__message().operator_assign(str);
					return 1;
				}
				v__mqttMsg.get_field_msg().get_field_unsubscribe().get_field_payload().get_field_topic__filter().get_at(count).decode_utf8(new char[] {str.get_nibble(position+2)}, CharCoding.UTF_8, false);
				position += 2+tmpLength;
				count++;
			}
			if(count == 0){
				v__mqttMsg.get_field_msg().get_field_unsubscribe().get_field_payload().get_field_topic__filter().operator_assign(new UCHAR0__65535List(TitanNull_Type.NULL_VALUE));
			}
			break;
		case 11:
			v__mqttMsg.get_field_msg().get_field_unsuback().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));;
			if(str.lengthof().is_greater_than_or_equal(position+2)){
				v__mqttMsg.get_field_msg().get_field_unsuback().get_field_packet__identifier().operator_assign(decodeInteger(str, position, 2));
				position += 2;
			}else{
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
			break;
		case 12:
			v__mqttMsg.get_field_msg().get_field_pingreq().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			break;
		case 13:
			v__mqttMsg.get_field_msg().get_field_pingresp().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			break;
		case 14:
			v__mqttMsg.get_field_msg().get_field_disconnect__msg().get_field_header().get_field_flags().operator_assign(new TitanBitString(str.get_nibble(bitstr)));
			break;
		case 0:
		case 15:
		default:
			v__mqttMsg.get_field_raw__message().operator_assign(str);
			return 0;
			}
			if(str.lengthof().is_greater_than(position) || length != (position-prePosition)){
				v__mqttMsg.get_field_raw__message().operator_assign(str);
				return 1;
			}
		}else{
			v__mqttMsg.get_field_raw__message().operator_assign(str);
			return 1;
		}

		if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
			TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
			TTCN_Logger.log_event("Decoded MQTT 3.1.1 message: ");
			v__mqttMsg.log();
			TTCN_Logger.end_event();
		}

		return 0;
	}
	
	private static int decodeInteger(TitanOctetString str, final int position, final int length){
		int value = 0;

		for(int i = 0; i < length; i++){
			value += (str.get_nibble(position + i) << (8 * (length-i-1)));
		}
		return value;
	}
	
	private static int encodeFlags(BIT4n bits){
		final int chr;
		final int[] lookup = new int[] {
				0x0, 0x8, 0x4, 0xc, 0x2, 0xa, 0x6, 0xe,
				0x1, 0x9, 0x5, 0xd, 0x3, 0xb, 0x7, 0xf};

		chr = boolToInt(bits.get_at(0).get_bit());
		return lookup[chr];
	}

	private static int encodePacketIdentifier(TTCN_Buffer buffer, int identifier, int length){
		if(0 <= identifier && identifier <= 65535){
			int chr;
			chr = (identifier >> 8) & 255;
			buffer.put_c(Character.toChars(chr)[0]);
			chr = identifier & 255;
			buffer.put_c(Character.toChars(chr)[0]);
			length += 2;
			return 0;
		}else{
			return 1;
		}
	}

	private static int encodeUtf8(TTCN_Buffer stream, TitanUniversalCharString str, int length){
		if(str.lengthof().is_greater_than_or_equal(0) && str.lengthof().is_greater_than_or_equal(65535)){
			int chr = str.lengthof().get_int() >> 8;
			stream.put_c(Character.toChars(chr)[0]);
			chr = str.lengthof().get_int();
			stream.put_c(Character.toChars(chr)[0]);
			str.encode_utf8(stream, false);
			length += 2 + str.lengthof().get_int();
			return 0;
		}else{
			return 1;
		}
	}

	private static int encodeOctetstring(TTCN_Buffer stream, TitanOctetString str, int length){
		if(str.lengthof().is_greater_than_or_equal(0) && str.lengthof().is_greater_than_or_equal(65535)){
			int chr = str.lengthof().get_int() >> 8;
		stream.put_c(Character.toChars(chr)[0]);
		chr = str.lengthof().get_int();
		stream.put_c(Character.toChars(chr)[0]);
		stream.put_os(str);
		length += 2 + str.lengthof().get_int();
		return 0;
		}else{
			return 1;
		}
	}
	
	private static int boolToInt(boolean b) {
	    return b ? 1 : 0;
	}
}

