package org.eclipse.titan.user_provided;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.StandardSocketOptions;
import java.nio.ByteBuffer;
import java.nio.channels.SelectableChannel;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import org.eclipse.titan.generated.TCPasp__PortType.TCPasp__PT_BASE;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Close;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Connect;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Connect__result;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Connected;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Listen;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Listen__result;
import org.eclipse.titan.generated.TCPasp__Types.ASP__TCP__Shutdown;
import org.eclipse.titan.runtime.core.Optional;
import org.eclipse.titan.runtime.core.TTCN_Logger;
import org.eclipse.titan.runtime.core.TTCN_Logger.Severity;
import org.eclipse.titan.runtime.core.TitanCharString;
import org.eclipse.titan.runtime.core.TitanInteger;
import org.eclipse.titan.runtime.core.TitanOctetString;
import org.eclipse.titan.runtime.core.TtcnError;

public class TCPasp__PT extends TCPasp__PT_BASE {

	HashMap<Integer,SelectableChannel> conn_list;
	//Set<SelectableChannel> listeningChannel = new HashSet<SelectableChannel>() {
	Thread listeningThread;
	BlockingQueue<ASP__TCP__Listen__result> ListenResultQ = new ArrayBlockingQueue<>(1);
	BlockingQueue<SocketChannel> IncomingConnectionsQ = new ArrayBlockingQueue<>(10);
		
	public TCPasp__PT(String port_name) {
		super(port_name);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void set_parameter(String parameter_name, String parameter_value) {
		// TODO Auto-generated method stub
		super.set_parameter(parameter_name, parameter_value);
	}

	@Override
	protected void user_map(String system_port) {
		conn_list = new HashMap<Integer,SelectableChannel>();
		super.user_map(system_port);
	}

	@Override
	protected void user_unmap(String system_port) {
		// TODO Auto-generated method stub
		if (conn_list != null && !conn_list.isEmpty()) {
			Collection<SelectableChannel> channels = conn_list.values();
			Iterator<SelectableChannel> clIterator = channels.iterator(); 
			while (clIterator.hasNext()) {
				try {
					SelectableChannel c = clIterator.next(); 
					if (c.isOpen()) { c.close(); };
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			conn_list = null;
		}
	}

	@Override
	protected void outgoing_send(ASP__TCP__Connect send_par) {
		String remoteHostname = send_par.constGethostname().getValue().toString();
		int remotePort = send_par.getportnumber().getInt();
		
		Optional<TitanCharString> optLocalhostname = send_par.getlocal__hostname(); 
		Optional<TitanInteger> optLocalport = send_par.getlocal__portnumber();
		
		InetSocketAddress isa = new InetSocketAddress(remoteHostname, remotePort); 
		try {
				SocketChannel sc = SocketChannel.open(isa);
				if (optLocalhostname.isPresent() && optLocalport.isPresent()) {
					InetSocketAddress lisa = new InetSocketAddress(optLocalhostname.get().getValue().toString(), 
							                                       optLocalport.get().getInt());
					sc.bind(lisa);
				}
				conn_list.put(sc.hashCode(), sc);
				installHandler(conn_list);
				ASP__TCP__Connect__result cr = new ASP__TCP__Connect__result(new TitanInteger(sc.hashCode()));
				incoming_message(cr);
		} catch (IOException e) {
			throw new TtcnError("Exception in ASP__TCP__Connect: Unable to set up socket" + e.getMessage());
		}
		
	}

	@Override
	protected void outgoing_send(ASP__TCP__Listen send_par) {
		Optional<TitanCharString> optLocalhostname = send_par.getlocal__hostname(); 
		Optional<TitanInteger> optLocalport = send_par.getportnumber();
		
		String localhostname = optLocalhostname.isPresent() ? optLocalhostname.get().getValue().toString() : "localhost";
		
		int localport = optLocalport.isPresent() ? optLocalport.get().getInt() : 0;
		ServerSocketChannel ssc;
		try {
			ssc = ServerSocketChannel.open();
			ssc.configureBlocking(false);
			ssc.setOption(StandardSocketOptions.SO_REUSEADDR, true);
			InetSocketAddress isa = new InetSocketAddress(localhostname, localport); 
			ssc.bind(isa);
			
			//TODO: Try
			conn_list.put(ssc.hashCode(), ssc);							
			installHandler(conn_list);
			
			InetSocketAddress sscAddr = (InetSocketAddress)ssc.getLocalAddress();
			
			TitanInteger tPortNum = new TitanInteger(sscAddr.getPort());
			ASP__TCP__Listen__result res = new ASP__TCP__Listen__result(tPortNum);
			
			incoming_message(res);
		} catch (IOException e) {
			throw new TtcnError("Exception in ASP__TCP__Listen: Unable to open socket" + e.getMessage());
		}
	}

	@Override
	protected void outgoing_send(ASP__TCP__Shutdown send_par) {
		if (!conn_list.isEmpty()) {
			Iterator<SelectableChannel> it = conn_list.values().iterator();
			while(it.hasNext()) {
				try {
					SelectableChannel c = it.next();
					c.close();
					conn_list.remove(c.hashCode());
					installHandler(conn_list);
				} catch (IOException e) {
					throw new TtcnError("Exception in ASP__TCP__Shutdown: Unable to close socket" + e.getMessage());
				}
			}
			conn_list.clear();
			installHandler(conn_list);
		}
	}

	@Override
	protected void outgoing_send(ASP__TCP send_par) {
		char[] toSend = send_par.getdata().getValue();
		if (send_par.getclient__id().isPresent()) {
			  SelectableChannel sc = conn_list.get(send_par.getclient__id().get().getInt());
			  SocketChannel socC = (SocketChannel)sc;
			  sendOnChannel(toSend, socC);
		} else { //No clientId specified
			if (conn_list.values().size() == 1) {
				sendOnChannel(toSend, (SocketChannel)conn_list.values().toArray()[0]);
			} else if(conn_list.isEmpty()) {
				throw new TtcnError("There is no connection alive, use a Connect ASP before sending anything.");
			} else { //more than one connection
				throw new TtcnError("Client Id not specified altough not only 1 client exists");
			}
		}
		
	}
	
	private void sendOnChannel(char[] toSend, SocketChannel soc) {
		try {
			soc.write(ByteBuffer.wrap(octetCharArrayToByteArray(toSend)));
		} catch (IOException e) {
			throw new TtcnError("Exception in outgoing_send(ASP__TCP send_par): " + e.getMessage());
		}
	}

	@Override
	protected void outgoing_send(ASP__TCP__Close send_par) {
		if (send_par.getclient__id().isPresent()) {
			int clId = send_par.getclient__id().get().getInt();
			try {
				conn_list.get(clId).close();
				conn_list.remove(clId);
			} catch (IOException e) {
				throw new TtcnError("Exception in ASP__TCP__Close: Unable to close socket" + e.getMessage());
			}
		} else {
			if (!conn_list.isEmpty()) {
				Iterator<SelectableChannel> it = conn_list.values().iterator();
				while(it.hasNext()) {
					try {
						it.next().close();
					} catch (IOException e) {
						throw new TtcnError("Exception in ASP__TCP__Close: Unable to close all sockets" + e.getMessage());
					}
				}
				conn_list.clear();
			}
		}
		installHandler(conn_list);
	}
		
	private byte[] octetCharArrayToByteArray(char[] in) {
		byte[] out = new byte[in.length];
		for (int i = 0;i<in.length;i++) {
			out[i] = (byte) in[i];
		}
		return out;
	}
	
	private char[] byteArrayToOctetCharArray(byte[] in) {
		char[] out = new char[in.length];
		for (int i = 0;i<in.length;i++) {
			out[i] = (char) in[i];
		}
		return out;
	}

	private Set<SelectableChannel> collectionToSet(Collection<SelectableChannel> input) 
	{
		Set<SelectableChannel> output = new HashSet<SelectableChannel>();
		Iterator<SelectableChannel> it = input.iterator();
		while (it.hasNext()) {
			output.add(it.next());
		}
		return output;
	}
	
	private void installHandler(HashMap<Integer,SelectableChannel> conn_list) {
		try {
			Uninstall_Handler();
			if (!conn_list.isEmpty()) {
				Install_Handler(collectionToSet(conn_list.values()), null, 0.0);
			}
		} catch (IOException e) {
			throw new TtcnError("IOException: " + e.getMessage());
		}
	}
	
	@Override
	protected void outgoing_send(TitanCharString send_par) {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public void Handle_Event(SelectableChannel channel, boolean is_readable, boolean is_writeable) {
		if (channel instanceof ServerSocketChannel) { //Server channel, connection request from outside
			try {
				SocketChannel incomingChannel = ((ServerSocketChannel) channel).accept();
				if (incomingChannel != null) {
					conn_list.put(incomingChannel.hashCode(), incomingChannel);
					installHandler(conn_list);
					
					InetSocketAddress incomingRemoteAddr = (InetSocketAddress)incomingChannel.getRemoteAddress();
					
					TitanCharString tHostname = new TitanCharString(incomingRemoteAddr.getHostName());
					TitanInteger tPortNum     = new TitanInteger(incomingRemoteAddr.getPort());
					TitanInteger tClientID    = new TitanInteger(incomingChannel.hashCode());
					
					ASP__TCP__Connected connected = new ASP__TCP__Connected(tHostname, tPortNum, tClientID);
					incoming_message(connected);
				}
			} catch (IOException e) {
				throw new TtcnError("Error while receiving incoming connection: " + e.getMessage());
			}
			
			
		} else if (channel instanceof SocketChannel) { //Communication socket
			SocketChannel socketChannel = (SocketChannel)channel;
			
			
			
			ByteBuffer buffer = ByteBuffer.allocate(65535);
			try {
				int bytesRead = socketChannel.read(buffer);
				if (bytesRead > 0) {
					TTCN_Logger.begin_event(Severity.LOG_ALL_IMPORTANT);
					TTCN_Logger.log_event("bytesRead: {0}", bytesRead);
					TTCN_Logger.end_event();
					byte[] received = new byte[bytesRead];
					buffer.rewind();
					buffer.get(received, 0, bytesRead);
					TitanOctetString incoming = new TitanOctetString(byteArrayToOctetCharArray(received));
					Optional<TitanInteger> optClientId = new Optional<TitanInteger>(TitanInteger.class);
					TitanInteger tintClientID = new TitanInteger(channel.hashCode());
					optClientId.assign(tintClientID);
					ASP__TCP incomingMessage = new ASP__TCP(optClientId, incoming);
					incoming_message(incomingMessage);
				} else if (bytesRead == -1) {
					Optional<TitanInteger> optClientID = new Optional<TitanInteger>(TitanInteger.class);
					int clientID = socketChannel.hashCode();
					optClientID.assign(new TitanInteger(clientID));
					ASP__TCP__Close close = new ASP__TCP__Close(optClientID);
					incoming_message(close);
					conn_list.remove(clientID);
					installHandler(conn_list);
					socketChannel.close();
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (Exception ex) {
				throw new TtcnError("Error while receiving message " + ex.getMessage());
			}
			
			
		} else {
			throw new TtcnError("FATAL ERROR: incorrect channel received");
		}
		
		
	}


	

}
