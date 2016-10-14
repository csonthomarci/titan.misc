git clone https://github.com/eclipse/titan.misc

cd titan.misc

Initialize/update submodules


* git submodule init CoAP_Conf/Libraries/titan.Libraries.TCCUsefulFunctions
* git submodule init CoAP_Conf/ProtocolModules/titan.ProtocolModules.CoAP
* git submodule init CoAP_Conf/TestPorts/titan.TestPorts.Common_Components.Socket-API
* git submodule init CoAP_Conf/TestPorts/titan.TestPorts.IPL4asp



* git submodule update CoAP_Conf/Libraries/titan.Libraries.TCCUsefulFunctions
* git submodule update CoAP_Conf/ProtocolModules/titan.ProtocolModules.CoAP
* git submodule update CoAP_Conf/TestPorts/titan.TestPorts.Common_Components.Socket-API
* git submodule update CoAP_Conf/TestPorts/titan.TestPorts.IPL4asp






cd CoAP_Conf/bin

./install.sh #will create symlinks

make

Check that you have Java version at least 1.8
 java -version

Run the Eclipse Californium CoAP server
 java -jar CaliforniumServer.jar



Oct 14, 2016 9:56:13 AM org.eclipse.californium.core.network.config.NetworkConfig createStandardWithFile
INFO: Loading standard properties from file Californium.properties
Oct 14, 2016 9:56:14 AM org.eclipse.californium.core.CoapServer start
INFO: Starting server
Oct 14, 2016 9:56:14 AM org.eclipse.californium.core.CoapServer start
INFO: No endpoints have been defined for server, setting up server endpoint on default port 5,683
Oct 14, 2016 9:56:14 AM org.eclipse.californium.core.network.CoapEndpoint start
INFO: Starting endpoint at 0.0.0.0/0.0.0.0:5683
origin-tracer directory does not exist. Skipping origin traces...
PlugtestServer listening on port 5683


Execute the test cases 

ttcn3_start coaptests coap.cfg


:
:
MC@esekilxxen1841: Terminating MTC.
MTC@esekilxxen1841: Verdict statistics: 0 none (0.00 %), 8 pass (100.00 %), 0 inconc (0.00 %), 0 fail (0.00 %), 0 error (0.00 %).
MTC@esekilxxen1841: Test execution summary: 8 test cases were executed. Overall verdict: pass
MC@esekilxxen1841: MTC terminated.


