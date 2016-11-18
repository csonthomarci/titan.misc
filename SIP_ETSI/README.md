git clone https://github.com/eclipse/titan.misc

cd titan.misc

Initialize/update submodules:


* git submodule init SIP_ETSI/Libraries/titan.Libraries.TCCUsefulFunctions
* git submodule init SIP_ETSI/TestPorts/titan.TestPorts.SIPmsg



* git submodule update SIP_ETSI/Libraries/titan.Libraries.TCCUsefulFunctions
* git submodule update SIP_ETSI/TestPorts/titan.TestPorts.SIPmsg






cd SIP_ETSI

./install.script   #will create symlinks

make


