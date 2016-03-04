# titan.misc

This repo is intended to collect TTCN-3 based applications, demo and instructional code etc.

# VSBOT is a Vulnerability Scanner Based On TTCN-3. 
Currently scans for web application vulnerabilities, namely directory traversal, SQL injection and XSS; next to this, it also contains a SYN Flood generator. This is not necessarily meant for industrial usage, it's rather a prototype that can constitute a good starting point to build your own vulnerability scanning application.
The execution is based on TTCN-3 code executed by Titan, with a number of building blocks from the Titan toolbox(test ports etc.)  and it also has a Python-based GUI.


Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.


# SIP_ETSI is based on Session Initiation Protocol (SIP) Test Suite from ETSI  (http://www.ttcn-3.org/index.php/downloads/publicts/publicts-etsi/27-publicts-sip)  
edited to be compatible with Titan and the SIPmsg test port.

Note: As this repository includes submodules, after cloning it, a 'git submodule init' and a 'git submodule update' 
will have to be issued.


Main project page:

https://projects.eclipse.org/projects/tools.titan

The source code of the TTCN-3 compiler and executor:

https://github.com/eclipse/titan.core
