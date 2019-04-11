package org.eclipse.titan.titan_JavaProtocolModules_MQTT.user_provided;

import org.eclipse.titan.runtime.core.TTCN_Logger;
import org.eclipse.titan.runtime.core.TitanOctetString;
import org.eclipse.titan.runtime.core.TTCN_Logger.Severity;
import org.eclipse.titan.runtime.core.TitanInteger;

public class MQTT__v3__1__1__IPL4SizeFunction_externalfunctions {

	public static TitanInteger f__calc__MQTT__length(TitanOctetString stream) {

		int multiplier, value, i, j;
		i = 0; // encoded byte
		j = 2; // additional real size
		multiplier = 1;
		value = 0;
		do {
			i++;
			value += (stream.get_at(i).get_nibble() & 127) * multiplier + j;
			multiplier *= 128;
			if (multiplier > 128*128*128){
				if(TTCN_Logger.log_this_event(Severity.DEBUG_ENCDEC)){
					TTCN_Logger.begin_event(Severity.DEBUG_ENCDEC);
					TTCN_Logger.log_event("Error: Wrong size of the message!");
					TTCN_Logger.end_event();
				}
				return new TitanInteger(-1); //error case, bigger than the MQTT limit
			}
			j = 1;
		}while((stream.get_at(i).get_nibble() & 128) != 0);

		return new TitanInteger(value);
	}
}
