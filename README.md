# titan.misc

This repo is intended to collect TTCN-3 based applications, demo and instructional code etc.


# VSBOT is a vulnerability scanner based on TTCN-3 
Currently scans for web application vulnerabilities, namely directory traversal, SQL injection and XSS; next to this, it also contains a SYN Flood generator. This is not necessarily meant for industrial usage, it's rather a prototype that can constitute a good starting point to build your own vulnerability scanning application.
The execution is based on TTCN-3 code executed by Titan, with a number of building blocks from the Titan toolbox(test ports etc.)  and it also has a Python-based GUI.


Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.


# SIP_ETSI is based on Session Initiation Protocol (SIP) Test Suite from ETSI 
(http://www.ttcn-3.org/index.php/downloads/publicts/publicts-etsi/27-publicts-sip)  
edited to be compatible with Titan and the SIPmsg test port.

Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.

# DIAMETER_Rx_ETSI is based on the DIAMETER Rx Test Suite from ETSI 
(http://webapp.etsi.org/WorkProgram/Frame_WorkItemList.asp?SearchPage=TRUE&qSORT=DocNbr&qINCLUDE_SUB_TB=True&qETSI_STANDARD_TYPE=%27TS%27&qETSI_NUMBER=101580&qMILESTONE=&qREPORT_TYPE=SUMMARY&optDisplay=ALL&includeNonActiveTB=FALSE)  
edited to be compatible with Titan and the SIPmsg test port.

Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.


#CoAP Conformance test cases 
based on http://www.etsi.org/plugtests/CoAP/Document/CoAP_TestDescriptions_v015.pdf

Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.


# NTAF Conformance test cases
based on 
http://ntaforum.org/TS-001%20Tool%20Registration%20and%20Discovery.pdf
http://ntaforum.org/TS-002%20Tool%20Automation%20Harness.pdf
http://ntaforum.org/TS-003%20Resource.pdf
http://ntaforum.org/TS-004%20Inventory.pdf

Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.
Afetr that, 
cd NTAF_Conformance
mkdir bin
cd bin
../src/install.script
make
will do the job


# JavaTestPorts 

EXPERIMENTAL test ports for the java runtime

Main project page:

https://projects.eclipse.org/projects/tools.titan

The source code of the TTCN-3 compiler and executor:

https://github.com/eclipse/titan.core
