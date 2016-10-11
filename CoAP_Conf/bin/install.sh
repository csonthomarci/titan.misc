#!/bin/sh

ln -s ../src/CoapApplication.ttcn  .
ln -s ../src/CoapCommon.ttcn  .
ln -s ../src/CoapFramework.ttcn  .
ln -s ../src/CoapPeer.ttcn  .
ln -s ../src/CoapTestSuite_Etsi.ttcn  .
ln -s ../src/CoapTestSuite_Fw.ttcn  .

ln -s ../cfg/coap.cfg  .

ln  -s ../ProtocolModules/titan.ProtocolModules.CoAP/src/CoAP_Types.ttcn .
ln  -s ../ProtocolModules/titan.ProtocolModules.CoAP/src/CoAP_EncDec.cc .


ln  -s ../TestPorts/titan.TestPorts.Common_Components.Socket-API/src/Socket_API_Definitions.ttcn .

ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_Functions.ttcn  .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_PortType.ttcn .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_PT.cc .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_PT.hh .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_Types.ttcn .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_discovery.cc .
ln  -s ../TestPorts/titan.TestPorts.IPL4asp/src/IPL4asp_protocol_L234.hh  .


ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCMessageHandling.cc .
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCMessageHandling_Functions.ttcn .
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCConversion.cc .
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCConversion_Functions.ttcn
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCInterface.cc .
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCInterface_Functions.ttcn
ln -s  ../Libraries/titan.Libraries.TCCUsefulFunctions/src/TCCInterface_ip.h

