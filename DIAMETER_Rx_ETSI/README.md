git clone https://github.com/eclipse/titan.misc

cd titan.misc

Initialize/update submodules


* git submodule init DIAMETER_Rx_ETSI/titan.Libraries.TCCUsefulFunctions
* git submodule init DIAMETER_Rx_ETSI/titan.ProtocolModules.MIME
* git submodule init DIAMETER_Rx_ETSI/titan.ProtocolModules.SDP
* git submodule init DIAMETER_Rx_ETSI/titan.TestPorts.Common_Components.Abstract_Socket
* git submodule init DIAMETER_Rx_ETSI/titan.TestPorts.SCTPasp
* git submodule init DIAMETER_Rx_ETSI/titan.TestPorts.SIPmsg
* git submodule init DIAMETER_Rx_ETSI/titan.TestPorts.TCPasp


* git submodule update DIAMETER_Rx_ETSI/titan.Libraries.TCCUsefulFunctions
* git submodule update DIAMETER_Rx_ETSI/titan.ProtocolModules.MIME
* git submodule update DIAMETER_Rx_ETSI/titan.ProtocolModules.SDP
* git submodule update DIAMETER_Rx_ETSI/titan.TestPorts.Common_Components.Abstract_Socket
* git submodule update DIAMETER_Rx_ETSI/titan.TestPorts.SCTPasp
* git submodule update DIAMETER_Rx_ETSI/titan.TestPorts.SIPmsg
* git submodule update DIAMETER_Rx_ETSI/titan.TestPorts.TCPasp




cd DIAMETER_Rx_ETSI/LibIms

./install.sh #will create symlinks

make


