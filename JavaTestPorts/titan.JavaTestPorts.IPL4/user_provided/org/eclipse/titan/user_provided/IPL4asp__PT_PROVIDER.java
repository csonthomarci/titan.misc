package org.eclipse.titan.user_provided;

import java.nio.channels.SelectableChannel;

import org.eclipse.titan.generated.IPL4asp__Types.ASP__Send;
import org.eclipse.titan.generated.IPL4asp__Types.ASP__SendTo;
import org.eclipse.titan.runtime.core.TitanPort;

public class IPL4asp__PT_PROVIDER extends TitanPort {

	public IPL4asp__PT_PROVIDER(String port_name) {
		// TODO Auto-generated constructor stub
	}

	@Override
	public void Handle_Event(SelectableChannel channel, boolean is_readable, boolean is_writeable) {
		// TODO Auto-generated method stub
		super.Handle_Event(channel, is_readable, is_writeable);
	}

	@Override
	protected void user_map(String system_port) {
		// TODO Auto-generated method stub
		super.user_map(system_port);
	}

	@Override
	protected void user_unmap(String system_port) {
		// TODO Auto-generated method stub
		super.user_unmap(system_port);
	}

	@Override
	protected void user_start() {
		// TODO Auto-generated method stub
		super.user_start();
	}

	@Override
	protected void user_stop() {
		// TODO Auto-generated method stub
		super.user_stop();
	}
	
	protected void outgoing_send(ASP__SendTo send_par) {
		// TODO Auto-generated method stub
		
	}
	
	protected void outgoing_send(ASP__Send send_par) {
		// TODO Auto-generated method stub
		
	}




}
